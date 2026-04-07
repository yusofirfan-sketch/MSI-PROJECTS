#include <Arduino.h>
#include <OpenPLC_Arduino.h>  // Make sure OpenPLC library installed

void setup() {
  Serial.begin(9600);
  OpenPLC_Init();  // Initialize OpenPLC runtime
}

void loop() {
  OpenPLC_Run();   // Run the PLC cycle
}
