#include <Servo.h>

#define SW 2
#define SERVO 9
#define VRY A4
#define VRX A5

const int CLOSE = 150;
const int OPEN = 100;

int reading_vrx;
int reading_vry;
int reading_sw;

boolean flag = 0;

Servo servo_motor;

void setup() {
  Serial.begin(9600);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
  servo_motor.attach(SERVO);
}

void loop() {
  reading_vry = analogRead(VRY);
  reading_vrx = analogRead(VRX);
  
  reading_sw = digitalRead(SW);
  if (reading_sw == 0) {
    flag = 0;
  }

  if (flag == 0) {
    reading_vrx = map(reading_vrx, 0, 1023, CLOSE, OPEN);

    servo_motor.write(reading_vrx);
    delay(10); 
  }

  if (reading_vry >= 620 && flag == 0) {
    flag = 1;
    servo_motor.write(OPEN);
    delay(10);
  } else if (reading_vry <= 420 && flag == 0) {
    flag = 1;
    servo_motor.write(CLOSE);
    delay(10); 
  }
}
