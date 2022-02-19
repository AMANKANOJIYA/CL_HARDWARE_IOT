#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;


void setup() {
  Serial.begin(115200);
  WiFi.begin("IIT-ISM-LIB", "IIT#1234");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(2000);
    Serial.print("..");
  }
  Serial.println("ESP32 is connected!");
  Serial.println(WiFi.localIP());
  bme.begin();

}

void loop() {
  float h = bme.readHumidity();
  float t = bme.readTemperature();
  float a = bme.readAltitude(SEALEVELPRESSURE_HPA);
  float p = bme.readPressure();


  
  if(WiFi.status() == WL_CONNECTED){
      HTTPClient http;
      String sendLink = String("http://")+ String("172.17.29.160")+ String(":3000/senddata?") + String("temp=") + String(t) + String("&hum=") + String(h) + String("&pres=")+ String(p)+ String("&alt=") + String(a);
      Serial.println(sendLink);
      http.begin(sendLink); 
      int httpCode = http.GET();
      Serial.println("GET SEND");
      if (httpCode >= 200){
        delay(5000);
      }else{
        http.end();
      }
  }
}
