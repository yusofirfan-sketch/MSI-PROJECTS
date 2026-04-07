/*
  Lab 6: Wireless Temperature Monitoring with ESP32 and ThingSpeak
  Sensor: LM35
  Data transmitted via Wi-Fi to ThingSpeak
*/

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI_SSID";        // Replace with your WiFi SSID
const char* password = "YOUR_WIFI_PASS";    // Replace with your WiFi password
const char* thingSpeakAPIKey = "YOUR_API_KEY"; // Replace with your ThingSpeak API Key
const char* server = "http://api.thingspeak.com/update";

const int LM35Pin = 34; // Analog pin on ESP32 for LM35

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");
}

void loop() {
  // Read LM35 sensor value
  int analogValue = analogRead(LM35Pin);
  float voltage = analogValue * (3.3 / 4095.0); // ESP32 ADC conversion (3.3V, 12-bit)
  float temperatureC = voltage * 100.0;        // LM35 gives 10mV per °C

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(server) + "?api_key=" + thingSpeakAPIKey + "&field1=" + temperatureC;
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      Serial.print("Data sent to ThingSpeak, response: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }

  delay(20000); // ThingSpeak allows 15-sec minimum update interval
}
