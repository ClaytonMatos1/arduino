#define LEDR 11
#define LEDG 10
#define LEDB 9

#define BUTTONR 7
#define BUTTONG 6
#define BUTTONB 5
#define BUTTONA 4

#define POTENTIOMETER A0

int stateButtonR;
int stateButtonG;
int stateButtonB;
int stateButtonA;

int statePotentiometer;

int pwmR = 255;
int pwmG = 255;
int pwmB = 255;

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  pinMode(BUTTONR, INPUT_PULLUP);
  pinMode(BUTTONG, INPUT_PULLUP);
  pinMode(BUTTONB, INPUT_PULLUP);
  pinMode(BUTTONA, INPUT_PULLUP);

  pinMode(POTENTIOMETER, INPUT);
}

void loop() {
  stateButtonR = digitalRead(BUTTONR);
  stateButtonG = digitalRead(BUTTONG);
  stateButtonB = digitalRead(BUTTONB);
  stateButtonA = digitalRead(BUTTONA);

  statePotentiometer = analogRead(POTENTIOMETER);

  if (stateButtonR == LOW) {
    if (stateButtonA == LOW) {
      pwmR = map(statePotentiometer, 0, 1023, 0, 255);
    } else {
      pwmR = 255;
    }
    analogWrite(LEDR, pwmR);
  } else {
    analogWrite(LEDR, 0);
  }

  if (stateButtonG == LOW) {
    if (stateButtonA == LOW) {
      pwmG = map(statePotentiometer, 0, 1023, 0, 255);
    } else {
      pwmG = 255;
    }
    analogWrite(LEDG, pwmG);
  } else {
    analogWrite(LEDG, 0);
  }

  if (stateButtonB == LOW) {
    if (stateButtonA == LOW) {
      pwmB = map(statePotentiometer, 0, 1023, 0, 255);
    } else {
      pwmB = 255;
    }
    analogWrite(LEDB, pwmB);
  } else {
    analogWrite(LEDB, 0);
  }

  delay(100);
}
