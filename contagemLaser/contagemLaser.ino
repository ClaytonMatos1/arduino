#define LDR A0
#define BUTTON 8
#define BUZZER 9

int readLDR = 0; // armazena o valor lido pelo ADC
int readBTN = 0;
int score = 0;
bool flag = false;

void setup() {
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  readLDR = analogRead(LDR);
  readBTN = digitalRead(BUTTON);

  if (readLDR <= 512 && flag == false) {
    score = score + 1;
    flag = true;
    Serial.print("Contagem: ");
    Serial.print(score);
    Serial.println();
    tone(BUZZER, 500);
    delay(10);
    noTone(BUZZER);
  } else if (readLDR > 512 && flag == true) {
    flag = false;
  }

  if (readBTN == LOW) {
    score = 0;
    Serial.print("Contagem: ");
    Serial.print(score);
    Serial.println();
  }
  

  delay(10);
}
