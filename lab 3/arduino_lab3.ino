#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
const int threshold = 1000; // Adjust as needed
int previousGesture = -1;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
}

void loop() {
  int gesture = detectGesture();
  if (gesture != previousGesture) {
    Serial.print("Detected Gesture: ");
    if (gesture == 1) {
      Serial.println("Gesture 1");
      // Perform action for Gesture 1
    } else if (gesture == 2) {
      Serial.println("Gesture 2");
      // Perform action for Gesture 2
    }
    previousGesture = gesture;
  }
}

int detectGesture() {
  int ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Simple threshold-based gesture recognition
  if (ax > threshold && ay < threshold) {
    return 1; // Gesture 1
  } else if (ax < -threshold && ay > threshold) {
    return 2; // Gesture 2
  }

  return 0; // No gesture detected
}
