#include <Pixy.h>

Pixy pixy;

void setup() {
  Serial.begin(9600);
  pixy.init();
}

void loop() {
  int i;
  int blocks = pixy.getBlocks();
  
  if (blocks) {
    for (i = 0; i < blocks; i++) {
      Serial.print(pixy.blocks[i].m_signature);
      Serial.print(": ");
      Serial.print("X=");
      Serial.print(pixy.blocks[i].m_x);
      Serial.print(" Y=");
      Serial.print(pixy.blocks[i].m_y);
      Serial.print(" ");
      Serial.println("detected");
    }
  }
  delay(200);
}
