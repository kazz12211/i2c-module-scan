// Reference code from https://www.gvc-on.net/?page_id=123

#include <Wire.h>

void module_scan(byte from_id, byte to_id) {
  char module_id;
  byte data;
  byte result;
  Wire.begin();

  for(module_id = from_id; module_id <= to_id; module_id++) {
    Wire.beginTransmission(module_id);
    Wire.write(&data, 0);
    result = Wire.endTransmission();
    // module found
    if(result == 0) {
      Serial.print("I2C Module Found! ID = ");
      Serial.println(module_id, HEX);
    }
  }
}
void setup() {
  Serial.begin(9600);
  Serial.print(  "Start Wire(I2C) ID Scan ----------\n");
  module_scan(1, 120);
  Serial.println("End ------------------------------\n");
  Serial.flush();
}

void loop() {
  delay(1000);
}
