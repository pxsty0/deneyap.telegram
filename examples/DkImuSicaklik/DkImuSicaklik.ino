// Bu proje Deneyap Kart'ın dahili IMU sensörü kullanılarak yapılmıştır.
#include <DeneyapTelegram.h>
#include <lsm6dsm.h>

#define WIFI_SSID "******"        // Wifi Adı
#define WIFI_PASS "************"  // Wifi Şifresi

int a = 0;
int b = 0;
String ID = "**********";     // Telegram @myidbot botundan aldığınız ID numaranız
String begin = "**************"; // Telegram botunuzun API Adresi
float sicaklik;
unsigned long timer1 = 0;
unsigned long timer2 = 0;

DeneyapTelegram telegram;
LSM6DSM IMU;
void setup() {
  Serial.begin(115200);
  IMU.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Wi-Fi Baglanıyor...");
  while (WiFi.status() != WL_CONNECTED){
    delay(100);
    Serial.print(".");
  }
  Serial.println("Baglandi");
  telegram.begin(begin); // Telegram Bot Tokeniniz
  telegram.send(ID, "DK Telegrama bağlandı."); // Kanal ID ve Mesaj
  sicaklik = IMU.readTempC();
  sicaklik = round(sicaklik * 100) / 100;
  telegram.send(ID, "Sıcaklık: " + String(sicaklik) + " C°");
}

void loop() {
  sicaklik = IMU.readTempC();
  sicaklik = round(sicaklik * 100) / 100;
  if (millis() - timer1 >= 1000) {   // a değişkeni saniye olarak atanmıştır.
    a++;
    Serial.print("Sıcaklık: " + String(sicaklik));
    Serial.println("\t Saniye: " + String(a));
    timer1 = millis();
  }
  if (a == 300) {  // Saniye 300(5 dk) olduğunda telegrama veri gönderir projenize göre değiştirebilirsiniz.
    telegram.send(ID, "Sıcaklık: " + String(sicaklik) + " C°");
    a = 0;
  }
  if (sicaklik >= 35) {
    if (millis() - timer2 >= 1000) {
      b++;
      timer2 = millis();
    }
    if (b == 60) { // sıcaklık 35 derecenin üstüne çıktığında 60 saniyede bir veri gönderir.
      telegram.send(ID, "Sıcaklık: " + String(sicaklik) + " C° yükseldi.");
      b = 0;
    }
  }
  if (sicaklik <= 25) {
    if (millis() - timer2 >= 1000) {
      b++;
      timer2 = millis();
    }
    if (b == 60) { // sıcaklık 25 derecenin altına düştüğünde 60 saniyede bir veri gönderir.
      telegram.send(ID, "Sıcaklık: " + String(sicaklik) + " C° düştü.");
      b = 0;
    }
  }
}
