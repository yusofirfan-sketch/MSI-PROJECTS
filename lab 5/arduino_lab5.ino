/*
  Lab 5: Arduino DAQ System
  Sensors: LDR (light), LM35 (temperature)
  Output: Serial data to PLX-DAQ
*/

const int LDRPin = A0;    // LDR connected to analog pin A0
const int LM35Pin = A1;   // LM35 temperature sensor connected to analog pin A1

void setup() {
  Serial.begin(9600);  // Start serial communication for PLX-DAQ
  delay(2000);         // Give PLX-DAQ time to connect
}

void loop() {
  // Read analog values
  int ldrValue = analogRead(LDRPin);
  int tempValue = analogRead(LM35Pin);

  // Convert LM35 reading to temperature in Celsius
  float voltage = tempValue * (5.0 / 1023.0);  // Arduino ADC conversion
  float temperatureC = voltage * 100.0;        // LM35 gives 10mV per °C

  // Format data for PLX-DAQ
  // Example: DATA,TIME,VALUE1,VALUE2
  Serial.print("DATA,"); 
  Serial.print(millis() / 1000); // Time in seconds
  Serial.print(",");
  Serial.print(ldrValue);        // LDR value
  Serial.print(",");
  Serial.println(temperatureC); // Temperature value in °C

  delay(1000);  // 1-second sampling interval
}
