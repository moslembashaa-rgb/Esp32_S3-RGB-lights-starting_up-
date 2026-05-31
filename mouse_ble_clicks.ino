#include <HijelHID_BLEMouse.h>

const int left = 4;
const int right = 0;

HijelBLEMouse ble("moslem mouse");

void setup() {
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);

  ble.begin();
  
}

void loop() {
  if (ble.isConnected()){
    if (digitalRead(left) == LOW){
      ble.press(MouseButton::Left);
      while(digitalRead(left) == 0){
        delay(10);
      }
      ble.release(MouseButton::Left);
    }

    if (digitalRead(right) == LOW){
      ble.press(MouseButton::Right);
      while(digitalRead(right) == LOW){
        delay(10);
      }
      ble.release(MouseButton::Right);
    }
  
  }
  delay(10);
}
