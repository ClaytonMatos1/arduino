#define PWM 3
#define POT A0

int readingPot = 0;
int readingPotMap = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);
  pinMode(POT, INPUT);
}

void loop() {
//  for (int x = 0; x <= 255; x++) {
//    analogWrite(PWM, x);
//    delay(50);
//    Serial.println(x);
//  }
//
//  for (int x = 255; x >= 0; x--) {
//    analogWrite(PWM, x);
//    delay(50);
//    Serial.println(x);
//  }

  readingPot = analogRead(POT);
  readingPotMap = map(readingPot, 0, 1023, 0, 255);
  analogWrite(PWM, readingPotMap);
  Serial.println(readingPotMap);
}
