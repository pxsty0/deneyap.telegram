
#ifndef DeneyapTelegram_h
#define DeneyapTelegram_h

#include <Arduino.h>

#if defined(ESP32)
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#else
#warning "Kütüphane Sadece Deneyap Kartlar İle Çalışmaktadır"
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#endif

class DeneyapTelegram
{
public:
  void begin(String token);
  void kurulum(String token);

  bool send(String id, String content);
  bool gonder(String id, String content);

private:
  String token;
};

#endif