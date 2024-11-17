# deneyap.telegram
## Telegram Library for ESP32 / Deneyap Cards
Örnek Kullanım / Example Usage

```cpp
#include <WiFi.h>
#include <DeneyapTelegram.h>

DeneyapTelegram telegram;

#define WIFI_SSID "WIFI ADI" 
#define WIFI_PASS "WIFI SİFRESİ" 

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
  telegram.begin("TELEGRAM BOT TOKENİNİNZ"); // Telegram BOTFATHER ile alınacak
  // telegram.kurulum("TELEGRAM BOT TOKENİNİNZ"); 
  telegram.send("CHAT IDNİZ", "Merhaba !"); // Telegram GET MY ID bot üzerinden /start komutu ile alınacak
  // telegram.gonder("CHAT IDNİZ", "Merhaba !"); // Kanal ID ve Mesaj
}

void loop()
{
}


```
