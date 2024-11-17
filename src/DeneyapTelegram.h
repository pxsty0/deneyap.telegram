
#ifndef DeneyapTelegram_h
#define DeneyapTelegram_h

#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

class DeneyapTelegram
{
public:
  void begin(String token);
  bool send(String id, String content);
private:
  String token;
};

#endif
