#define POT A0
#define BTN_HORARIO 7
#define BTN_ANTI 6

int i;
int pins[] = {8,9,10,11};
int side = 0;
int speedMotor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(POT, INPUT);

  pinMode(BTN_HORARIO, INPUT_PULLUP);
  pinMode(BTN_ANTI, INPUT_PULLUP);

  for (i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  speedMotor = analogRead(POT);
  speedMotor = map(speedMotor, 0, 1023, 1, 100);

  if (digitalRead(BTN_HORARIO) == LOW) {
    Serial.println("Horario");
    Serial.println(speedMotor);
    for (i = 0; i < 4; i++) {
      digitalWrite(pins[i], HIGH);
      delay(100-speedMotor);
      digitalWrite(pins[i], LOW);
    }
  }
  if (digitalRead(BTN_ANTI) == LOW) {
    Serial.println("Anti-Horario");
    Serial.println(speedMotor);
    for (i = 4; i >= 0; i--) {
      digitalWrite(pins[i], HIGH);
      delay(100-speedMotor);
      digitalWrite(pins[i], LOW);
    }
  }
}
