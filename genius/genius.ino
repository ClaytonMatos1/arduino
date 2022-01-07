#define ERRO 13
#define LED_GREEN 12
#define LED_BLUE 11
#define LED_YELLOW 10

#define BUZZER 7

#define b1 6
#define b2 5
#define b3 4

const int c = 261; // Do
const int d = 293; // Re
const int e = 329; // Mi
const int b = 493; // Si

int level = 0, i, compara = 0; 
long notas[50] , resultado[50];

bool flag = LOW, flag_b1 = LOW, flag_b2 = LOW, flag_b3 = LOW, decrease = LOW;

void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(ERRO, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));

}

void loop() {
  notas[level] = random(1, 4);
  delay(10);
  for ( i = 0; i < level; i++) {
    if (notas[i] == 1) {
      tone(BUZZER, c);
      digitalWrite(LED_GREEN, HIGH);
      delay(500);
      noTone(BUZZER);
      digitalWrite(LED_GREEN, LOW);
    }
    else if (notas[i] == 2) {
      tone(BUZZER, d);
      digitalWrite(LED_BLUE, HIGH);
      delay(500);
      noTone(BUZZER);
      digitalWrite(LED_BLUE, LOW);
    }
    else {
      tone(BUZZER, e);
      digitalWrite(LED_YELLOW, HIGH);
      delay(500);
      noTone(BUZZER);
      digitalWrite(LED_YELLOW, LOW);
    }
    delay(500);
  }
  flag = HIGH;
  i = 0;
  compara = 0;

  while (flag == HIGH) {
    bool leitura_b1 = digitalRead(b1);
    bool leitura_b2 = digitalRead(b2);
    bool leitura_b3 = digitalRead(b3);
    if ( i < level) {
      if (leitura_b1 == LOW) {
        flag_b1 = HIGH;
        
        tone(BUZZER, c);
        digitalWrite(LED_GREEN, HIGH);
        delay(500);
        noTone(BUZZER);
        digitalWrite(LED_GREEN, LOW);
        
        while(digitalRead(b1) == LOW){}
      } else if (leitura_b1 == HIGH && flag_b1 == HIGH) {
        resultado[i] = 1;
        i++;
        flag_b1 = LOW;
      }
      if (leitura_b2 == LOW) {
        flag_b2 = HIGH;

        tone(BUZZER, d);
        digitalWrite(LED_BLUE, HIGH);
        delay(500);
        noTone(BUZZER);
        digitalWrite(LED_BLUE, LOW);
        
        while(digitalRead(b2) == LOW){}
      } else if (leitura_b2 == HIGH && flag_b2 == HIGH) {
        resultado[i] = 2;
        i++;
        flag_b2 = LOW;
      }
      if (leitura_b3 == LOW) {
        flag_b3 = HIGH;

        tone(BUZZER, e);
        digitalWrite(LED_YELLOW, HIGH);
        delay(500);
        noTone(BUZZER);
        digitalWrite(LED_YELLOW, LOW);
        
        while(digitalRead(b3) == LOW){}
      } else if (leitura_b3 == HIGH && flag_b3 == HIGH) {
        resultado[i] = 3;
        i++;
        flag_b3 = LOW;
      }
      delay(100);
    } else {
      for (int i = 0; i < level; i++) {
        resultado[i] = (resultado[i] - notas[i]);
        if (resultado[i] < 0) {
          resultado[i] = resultado[i] * -1;
        }
        compara = compara + resultado[i];
        if (compara > 0) {
          decrease = HIGH;
        } else {
          decrease = LOW;
        }
      }
      if (decrease == HIGH) {
        level = 0;
        decrease = LOW;
        Serial.println("Voce errou !");
        for (i = 0; i < 2; i++) {
          tone(BUZZER, b);
          digitalWrite(ERRO, HIGH);
          delay(500);
          noTone(BUZZER);
          delay(50);
          digitalWrite(ERRO, LOW);
          delay(50);
        }
      } else {
        level++;
        Serial.print("Parabens! Voce avancou para o proximo level ");
        Serial.println(level);
      }
      flag = LOW;
      delay(500);
    }
  }
}
