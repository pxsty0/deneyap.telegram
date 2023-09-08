#include <WiFi.h>
#include <DeneyapTelegram.h>

DeneyapTelegram telegram;

#define WIFI_SSID "" // Wifi Adı
#define WIFI_PASS "" // Wifi Şifresi

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Wi-Fi Baglanıyor...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
  }
  Serial.println("Baglandi");
  telegram.begin(""); // Telegram Bot Tokeniniz
  // telegram.kurulum(""); // Telegram Bot Tokeniniz
  telegram.send("", ""); // Kanal ID ve Mesaj
  // telegram.gonder("", ""); // Kanal ID ve Mesaj
}

void loop()
{
}