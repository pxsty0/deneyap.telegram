#include "DeneyapTelegram.h"

void DeneyapTelegram::begin(String token)
{
  DeneyapTelegram::token = token;
}

bool DeneyapTelegram::send(String id, String content)
{

  WiFiClientSecure *client = new WiFiClientSecure;
  bool ok = false;
  if (client)
  {
    client->setInsecure();

    HTTPClient https;
    // Begin HTTPS requests
    if (https.begin(*client, "https://api.telegram.org/bot" + DeneyapTelegram::token + "/sendMessage?text=" + content + "&chat_id=" + id))
    {

      int httpCode = https.GET();
      if (httpCode > 0)
      {
        if (httpCode == HTTP_CODE_OK ||
            httpCode == HTTP_CODE_MOVED_PERMANENTLY ||
            httpCode == HTTP_CODE_NO_CONTENT)
        {
          ok = true;
        }
        else
        {
          ok = false;
        }
        https.end();
      }
      else
      {
        ok = false;
      }
    }
    else
    {
      ok = false;
    }
  }
  else
  {
    ok = false;
  }
  return ok;
}
