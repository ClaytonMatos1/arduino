#define BUTTON 9

#define BUZZER 10

// frequencia de cada nota musical
const int c = 261; // dó
const int d = 293; // ré
const int e = 329; // mi
const int f = 349; // fá
const int g = 391; // sol
const int a = 440; // lá
const int b = 493; // dó

const int tempo = 1000;

int notas[] = {c, d, e, g, g, e, f, f, 0, c, d, e, g, g, f, e, 0, c, c, d, e, g, 0, g, f, e, c, f, 0, f, e, d, d, e, 0, d, d, c, c, 0};
int tempos[] = {4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 1, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 1, 6};
int tamanho = 0, i;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  tamanho = sizeof(notas) / 2;
  for (i = 0; i < tamanho; i++) {
    tempos[i] = tempo/tempos[i];
  }
}

void loop() {
  bool stateButton = digitalRead(BUTTON);
  if (stateButton == LOW) {
    for (i = 0; i < tamanho; i++) {
      if (notas[i] == 0) {
        noTone(BUZZER);
        delay(tempos[i]);
      } else {
        tone(BUZZER, notas[i]);
        delay(tempos[i]);
      }
    }
  }
}
