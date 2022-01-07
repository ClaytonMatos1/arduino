const int TRIG = 3;
const int ECHO = 2;
const int obstacle_distance = 20;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  int distance = sensor(TRIG, ECHO);
  if (distance <= obstacle_distance) {
    Serial.print("Com obstáculo: ");
    Serial.print(distance);
    Serial.println("cm");
  } else {
    Serial.print("Sem obstáculo: ");
    Serial.print(distance);
    Serial.println("cm");
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
