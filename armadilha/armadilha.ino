#include <Servo.h>

#define SERVO 9

#define SW 2
#define VRY A4
#define VRX A5

#define BUZZER 5

#define BTN A0

#define LEDR A1
#define LEDG A2

#define TRIG 3
#define ECHO 4

#define DISPLAY_A 13
#define DISPLAY_B 12
#define DISPLAY_C 11
#define DISPLAY_D 10
#define DISPLAY_E 8
#define DISPLAY_F 7
#define DISPLAY_G 6

#define POT A3

const int CLOSE = 150;
const int OPEN = 100;

int reading_vrx;
int reading_vry;
unsigned int distance;

boolean flag = 0;
boolean flagBuzzer = 0;

int quantities = 0;

int volume = 0;
int intensityLed = 0;

Servo servo_motor;

void setup() {
  Serial.begin(9600);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);

  servo_motor.attach(SERVO);
  servo_motor.write(OPEN);

  pinMode(BUZZER, OUTPUT);

  pinMode(BTN, INPUT);
  digitalWrite(BTN, HIGH);

  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(DISPLAY_A, OUTPUT);
  pinMode(DISPLAY_B, OUTPUT);
  pinMode(DISPLAY_C, OUTPUT);
  pinMode(DISPLAY_D, OUTPUT);
  pinMode(DISPLAY_E, OUTPUT);
  pinMode(DISPLAY_F, OUTPUT);
  pinMode(DISPLAY_G, OUTPUT);
  changeDisplay(quantities);

  pinMode(POT, INPUT);
}

void loop() {
  reading_vry = analogRead(VRY);
  reading_vrx = analogRead(VRX);

  distance = sensor(TRIG, ECHO);
  if (distance <= 4) Serial.println(distance);
  modifyValues();

  if (flagBuzzer == 1) {
    ringAlarm();
  }
  
  if (digitalRead(SW) == 0) {
    resetConfig();
  }
  
  if (analogRead(BTN) < 20) {
    changeDisplay(0);
    quantities = 0;
  }

  if (flag == 0) {
    if (distance >= 2 && distance <= 4) {
      moveClaw(CLOSE);
      flagBuzzer = 1;
      quantities = quantities + 1;
      if (quantities == 10) quantities = 0;
      changeDisplay(quantities);
    } else if (reading_vry >= 620 || reading_vrx >= 620) {
      moveClaw(OPEN);
    } else if (reading_vry <= 420 || reading_vrx <= 420) {
      moveClaw(CLOSE);
    } 
  }
}

int sensor(int pintrig, int pinecho) {
  digitalWrite(pintrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pintrig, LOW);

  return pulseIn(pinecho, HIGH)/58;
}

void modifyValues() {
  int readingPot = analogRead(POT);
  volume = map(readingPot, 0, 1023, 0, 600);
  intensityLed = map(readingPot, 0, 1023, 0, 255);
  if (flag == 1) {
    analogWrite(LEDR, intensityLed);
    analogWrite(LEDG, 0); 
  } else {
    analogWrite(LEDR, 0);
    analogWrite(LEDG, intensityLed);
  }
}

void moveClaw(int movement) {
  flag = 1;
  servo_motor.write(movement);
  delay(10);
}

void ringAlarm() {
  tone(BUZZER, volume);
  delay(500);
  noTone(BUZZER);
  delay(500);
}

void resetConfig() {
  flag = 0;
  flagBuzzer = 0;
  noTone(BUZZER);
  delay(10);
}

void changeDisplay(int num) {
  switch (num) {
    case 0:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, HIGH);
      digitalWrite(DISPLAY_E, HIGH);
      digitalWrite(DISPLAY_F, HIGH);
      digitalWrite(DISPLAY_G, LOW);
     break;
     case 1:
      digitalWrite(DISPLAY_A, LOW);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, LOW);
      digitalWrite(DISPLAY_E, LOW);
      digitalWrite(DISPLAY_F, LOW);
      digitalWrite(DISPLAY_G, LOW);
     break;
     case 2:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, LOW);
      digitalWrite(DISPLAY_D, HIGH);
      digitalWrite(DISPLAY_E, HIGH);
      digitalWrite(DISPLAY_F, LOW);
      digitalWrite(DISPLAY_G, HIGH);
     break;
     case 3:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, HIGH);
      digitalWrite(DISPLAY_E, LOW);
      digitalWrite(DISPLAY_F, LOW);
      digitalWrite(DISPLAY_G, HIGH);
     break;
     case 4:
      digitalWrite(DISPLAY_A, LOW);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, LOW);
      digitalWrite(DISPLAY_E, LOW);
      digitalWrite(DISPLAY_F, HIGH);
      digitalWrite(DISPLAY_G, HIGH);
     break;
     case 5:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, LOW);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, HIGH);
      digitalWrite(DISPLAY_E, LOW);
      digitalWrite(DISPLAY_F, HIGH);
      digitalWrite(DISPLAY_G, HIGH);
     break;
     case 6:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, LOW);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, HIGH);
      digitalWrite(DISPLAY_E, HIGH);
      digitalWrite(DISPLAY_F, HIGH);
      digitalWrite(DISPLAY_G, HIGH);
     break;
     case 7:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, LOW);
      digitalWrite(DISPLAY_E, LOW);
      digitalWrite(DISPLAY_F, LOW);
      digitalWrite(DISPLAY_G, LOW);
     break;
     case 8:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, HIGH);
      digitalWrite(DISPLAY_E, HIGH);
      digitalWrite(DISPLAY_F, HIGH);
      digitalWrite(DISPLAY_G, HIGH);
     break;
     case 9:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, HIGH);
      digitalWrite(DISPLAY_E, LOW);
      digitalWrite(DISPLAY_F, HIGH);
      digitalWrite(DISPLAY_G, HIGH);
     break;
     default:
      digitalWrite(DISPLAY_A, HIGH);
      digitalWrite(DISPLAY_B, HIGH);
      digitalWrite(DISPLAY_C, HIGH);
      digitalWrite(DISPLAY_D, HIGH);
      digitalWrite(DISPLAY_E, HIGH);
      digitalWrite(DISPLAY_F, HIGH);
      digitalWrite(DISPLAY_G, LOW);
     break;
  }
}
