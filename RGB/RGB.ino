#define LEDR 11
#define LEDG 10
#define LEDB 9

#define BUTTONR 7
#define BUTTONG 6
#define BUTTONB 5

int stateButtonR;
int stateButtonG;
int stateButtonB;

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  pinMode(BUTTONR, INPUT_PULLUP);
  pinMode(BUTTONG, INPUT_PULLUP);
  pinMode(BUTTONB, INPUT_PULLUP);
}

void loop() {
  stateButtonR = digitalRead(BUTTONR);
  stateButtonG = digitalRead(BUTTONG);
  stateButtonB = digitalRead(BUTTONB);

  if (stateButtonR == LOW) {
    analogWrite(LEDR, 255);
  } else {
    analogWrite(LEDR, 0);
  }

  if (stateButtonG == LOW) {
    analogWrite(LEDG, 255);
  } else {
    analogWrite(LEDG, 0);
  }

  if (stateButtonB == LOW) {
    analogWrite(LEDB, 255);
  } else {
    analogWrite(LEDB, 0);
  }

  delay(100);
}
