#define BUZZER 10
#define PLUS_BUTTON 11
#define LESS_BUTTON 9

int frequency = 200;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT); // configura o pino com o buzzer como saida
  pinMode(PLUS_BUTTON, INPUT_PULLUP);
  pinMode(LESS_BUTTON, INPUT_PULLUP);
}

void loop() {
  Serial.println(frequency);
  if (digitalRead(PLUS_BUTTON) == LOW) {
    frequency = frequency + 100;
  }

  if (digitalRead(LESS_BUTTON) == LOW) {
    frequency = frequency - 100;
  }
  
  tone(BUZZER, frequency); // gera frequencia no buzzer
  delay(1000);
  noTone(BUZZER);
  delay(1000);
}
