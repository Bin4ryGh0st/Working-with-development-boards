#include<ESP8266WiFi.h>
#define ssid "*****"
#define password "012345687109"
#define server "api.thingspeak.com"
IPAddress ip(34,226,44,238);

WiFiClient esp;
void setup() 
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
  }
  Serial.println("Connected To WiFi");
}

void loop() 
{
  Serial.println("Connecting To Server...");
  if (esp.connect(ip,80))
  {
    Serial.println("Connected");
    esp.println("GET /apps/thinghttp/send_request?api_key=AK1ESEA8IH49NQ51 HTTP/1.1"); //add link to application
    esp.print("HOST: https://api.thingspeak.com");
    esp.println();
  }
  else
  {
    Serial.println("Failed To Connect");  
  }
  while(esp.available())
    {
      String response = esp.readString();
      Serial.println(response);
    }
}
