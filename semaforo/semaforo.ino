#define GREEN_CROSSWALK 9
#define RED_CROSSWALK 10
#define GREEN_TRAFFIC_LIGHT 11
#define YELLOW_TRAFFIC_LIGHT 12
#define RED_TRAFFIC_LIGHT 13

void setup() {
  Serial.begin(9600);
  // Configura os pinos dos LEDs como saída

  // Semaforo pedestres
  pinMode(GREEN_CROSSWALK, OUTPUT); // LED verde
  pinMode(RED_CROSSWALK, OUTPUT); // LED vermelho

  // Semaforo carros
  pinMode(GREEN_TRAFFIC_LIGHT, OUTPUT); // LED verde
  pinMode(YELLOW_TRAFFIC_LIGHT, OUTPUT); // LED amarelo
  pinMode(RED_TRAFFIC_LIGHT, OUTPUT); // LED vermelho
}

void loop() {
  Serial.println(GREEN_TRAFFIC_LIGHT);
  // Sinal aberto: apaga LED vermelho, acende LED verde
  // Carros
  digitalWrite(GREEN_TRAFFIC_LIGHT, HIGH);
  digitalWrite(YELLOW_TRAFFIC_LIGHT, LOW);
  digitalWrite(RED_TRAFFIC_LIGHT, LOW);
  // Pedestre: apaga LED verde, acende LED vermelho
  digitalWrite(GREEN_CROSSWALK, LOW);
  digitalWrite(RED_CROSSWALK, HIGH);
  delay(3000);

  // Sinal fechando: apaga LED verde, acende LED amarelo
  digitalWrite(GREEN_TRAFFIC_LIGHT, LOW);
  digitalWrite(YELLOW_TRAFFIC_LIGHT, HIGH);
  digitalWrite(RED_TRAFFIC_LIGHT, LOW);
  delay(2000);

  // Sinal fechado: apaga LED amarelo, acende LED vermelho
  digitalWrite(GREEN_TRAFFIC_LIGHT, LOW);
  digitalWrite(YELLOW_TRAFFIC_LIGHT, LOW);
  digitalWrite(RED_TRAFFIC_LIGHT, HIGH);
  // Pedestre: apaga LED vermelho, acende LED verde
  digitalWrite(GREEN_CROSSWALK, HIGH);
  digitalWrite(RED_CROSSWALK, LOW);
  delay(5000);

  piscarLedPedestre();
}

void piscarLedPedestre() {
  // apaga LED verde
  digitalWrite(GREEN_CROSSWALK, LOW);
  // piscar LED vermelho
  for (int i = 0; i < 8; i++) {
    if (i % 2 == 0) {
      digitalWrite(RED_CROSSWALK, HIGH);
    } else {
      digitalWrite(RED_CROSSWALK, LOW);
    }
    delay(500);
  }
}
