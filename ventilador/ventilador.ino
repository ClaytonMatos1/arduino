#include <Servo.h>

Servo servo;
int pos = 0;

void setup() {
  servo.attach(9);
//  servo.write(0);
}

void loop() {
//  servo.write(0);
//  delay(500);
//  servo.write(180);
//  delay(500);
  for (pos = 0; pos < 180; pos += 1) {
    servo.write(pos);
    delay(10);
  }

  for (pos = 180; pos >= 1; pos -= 1) {
    servo.write(pos);
    delay(10);
  }
}
