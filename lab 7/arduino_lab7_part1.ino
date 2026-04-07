#include <Arduino.h>

// Example for TCS230 color sensor
// Pins for TCS230
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define OUT 8

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Set frequency scaling
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  // Select red filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int red = pulseIn(OUT, digitalRead(OUT) == HIGH ? HIGH : LOW);

  // Select green filter
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int green = pulseIn(OUT, digitalRead(OUT) == HIGH ? HIGH : LOW);

  // Select blue filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int blue = pulseIn(OUT, digitalRead(OUT) == HIGH ? HIGH : LOW);

  Serial.print("R:");
  Serial.print(red);
  Serial.print(" G:");
  Serial.print(green);
  Serial.print(" B:");
  Serial.println(blue);

  delay(500); // update rate
}
