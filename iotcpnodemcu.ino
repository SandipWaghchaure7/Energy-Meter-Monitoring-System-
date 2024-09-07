#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>


const char *ssid = "Hotspot";
const char *password = "Abhyaskar";
int YourChannelID =  2528684;

char thingSpeakAddress[] = "api.thingspeak.com";
String apiKey = "1500D6LKAG9FJMP8";
const int updateInterval = 15000; 


float voltage;
float current;
float power;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(10);

  
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  //ThingSpeak.begin(client);
}

void loop() {
  
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    sscanf(data.c_str(), "%f,%f,%f", &voltage, &current, &power);
    

    
    Serial.print("Received: ");
    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.print("V, Current: ");
    Serial.print(current);
    Serial.print("A, Power: ");
    Serial.print(power);
    Serial.println("W");

    
ThingSpeak.writeField(YourChannelID, 1, voltage, apiKey.c_str());
ThingSpeak.writeField(YourChannelID, 2, current, apiKey.c_str());
ThingSpeak.writeField(YourChannelID, 3, power, apiKey.c_str());


    delay(updateInterval); 
  }
}








