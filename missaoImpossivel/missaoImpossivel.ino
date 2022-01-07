#define LDR A0
#define BUZZER 9
#define BUTTON 8

int readLDR = 0; // armazena o valor lido pelo ADC
int readBTN = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  readLDR = analogRead(LDR);
  readBTN = digitalRead(BUTTON);

  Serial.print("Leitura: ");
  Serial.print(readLDR);
  Serial.print("\t");

  // imprime se existe ou nao um obstaculo
  Serial.print("Obstáculo: ");
  if (readLDR <= 512) {
    Serial.print("Sim");
    tone(BUZZER, 500);
  } else if (readBTN == LOW) {
    noTone(BUZZER);
  } else {
    Serial.print("Não");
  }

  Serial.println();
  delay(500);
}
