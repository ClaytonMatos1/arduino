#define BUTTON 10
#define LED_RED 13

void setup() {
  // utilizando o pull up do arduino
  pinMode(BUTTON, INPUT_PULLUP); // configura o pino com o botao como entrada
  pinMode(13, OUTPUT); // configura o pino com o LED como saida
}

void loop() {
  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(LED_RED, HIGH);
  } else {
    digitalWrite(LED_RED, LOW);
  }
}
