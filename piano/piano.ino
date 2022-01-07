#define BUTTON1 7
#define BUTTON2 8
#define BUTTON3 9

#define BUZZER 10

#define LED1 11
#define LED2 12
#define LED3 13

// frequencia de cada nota musical
const int c = 261; // dó
const int d = 293; // ré
const int e = 329; // mi
const int f = 349; // fá
const int g = 391; // sol
const int a = 440; // lá
const int b = 493; // dó

const int intervalDelay = 1000;

void setup() {
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  
  pinMode(BUZZER, OUTPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
//  reproduzir as notas
//  executeNotes();

  // salva estado de cada botao
  bool stateButton1 = digitalRead(BUTTON1);
  bool stateButton2 = digitalRead(BUTTON2);
  bool stateButton3 = digitalRead(BUTTON3);

  if (stateButton1 == LOW) {
    tone(BUZZER, c);
    digitalWrite(LED1, HIGH);
  } else if (stateButton2 == LOW) {
    tone(BUZZER, d);
    digitalWrite(LED2, HIGH);
  } else if (stateButton3 == LOW) {
    tone(BUZZER, d);
    digitalWrite(LED3, HIGH);
  } else {
    noTone(BUZZER);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

//  noTone(BUZZER);
//  delay(2000);
}

void executeNotes() {
  tone(BUZZER, c);
  delay(intervalDelay);

  tone(BUZZER, d);
  delay(intervalDelay);

  tone(BUZZER, e);
  delay(intervalDelay);

  tone(BUZZER, f);
  delay(intervalDelay);

  tone(BUZZER, g);
  delay(intervalDelay);

  tone(BUZZER, a);
  delay(intervalDelay);

  tone(BUZZER, b);
  delay(intervalDelay);
}
