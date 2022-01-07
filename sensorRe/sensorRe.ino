#define LED_GREEN1 8
#define LED_GREEN2 9
#define LED_GREEN3 10
#define LED_YELLOW1 11
#define LED_YELLOW2 12
#define LED_RED1 13

const int TRIG = 3;
const int ECHO = 2;
const int BUZZER = 7;

unsigned int interval, distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(LED_GREEN1, OUTPUT);
  pinMode(LED_GREEN2, OUTPUT);
  pinMode(LED_GREEN3, OUTPUT);
  pinMode(LED_YELLOW1, OUTPUT);
  pinMode(LED_YELLOW2, OUTPUT);
  pinMode(LED_RED1, OUTPUT);
}

void loop() {
  distance = sensor(TRIG, ECHO);
  Serial.println(distance);
  if (distance <= 10) {
    digitalWrite(LED_RED1, HIGH);
    digitalWrite(LED_YELLOW2, HIGH);
    digitalWrite(LED_YELLOW1, HIGH);
    digitalWrite(LED_GREEN3, HIGH);
    digitalWrite(LED_GREEN2, HIGH);
    digitalWrite(LED_GREEN1, HIGH);
    tone(BUZZER, 200);
  } else if (distance > 60) {
    digitalWrite(LED_RED1, LOW);
    digitalWrite(LED_YELLOW2, LOW);
    digitalWrite(LED_YELLOW1, LOW);
    digitalWrite(LED_GREEN3, LOW);
    digitalWrite(LED_GREEN2, LOW);
    digitalWrite(LED_GREEN1, LOW);
    noTone(BUZZER);
  } else {
    if (distance <= 20) {
      digitalWrite(LED_RED1, LOW);
      digitalWrite(LED_YELLOW2, HIGH);
      digitalWrite(LED_YELLOW1, HIGH);
      digitalWrite(LED_GREEN3, HIGH);
      digitalWrite(LED_GREEN2, HIGH);
      digitalWrite(LED_GREEN1, HIGH);
      interval = 100;  
    } else if (distance <= 30) {
      digitalWrite(LED_RED1, LOW);
      digitalWrite(LED_YELLOW2, LOW);
      digitalWrite(LED_YELLOW1, HIGH);
      digitalWrite(LED_GREEN3, HIGH);
      digitalWrite(LED_GREEN2, HIGH);
      digitalWrite(LED_GREEN1, HIGH);
      interval = 150; 
    } else if (distance <= 40) {
      digitalWrite(LED_RED1, LOW);
      digitalWrite(LED_YELLOW2, LOW);
      digitalWrite(LED_YELLOW1, LOW);
      digitalWrite(LED_GREEN3, HIGH);
      digitalWrite(LED_GREEN2, HIGH);
      digitalWrite(LED_GREEN1, HIGH);
      interval = 200; 
    } else if (distance <= 50) {
      digitalWrite(LED_RED1, LOW);
      digitalWrite(LED_YELLOW2, LOW);
      digitalWrite(LED_YELLOW1, LOW);
      digitalWrite(LED_GREEN3, LOW);
      digitalWrite(LED_GREEN2, HIGH);
      digitalWrite(LED_GREEN1, HIGH);
      interval = 250; 
    } else if (distance <= 60) {
      digitalWrite(LED_RED1, LOW);
      digitalWrite(LED_YELLOW2, LOW);
      digitalWrite(LED_YELLOW1, LOW);
      digitalWrite(LED_GREEN3, LOW);
      digitalWrite(LED_GREEN2, LOW);
      digitalWrite(LED_GREEN1, HIGH);
      interval = 300; 
    }
    tone(BUZZER, 200);
    delay(interval);
    noTone(BUZZER);
    delay(interval);
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
