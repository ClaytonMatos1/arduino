const int pinoLDR = A0; // pino onde o LDR está conectado
const int pinoLED = 7; // pino do LED
int leitura = 0; // variavel para armazenar o valor lido pelo ADC
float tensao = 0.0; // variavel para armazenar a tensao

void setup() {
  // inicia e configura a Serial
  Serial.begin(9600);

  // configura o pino com LDR como entrada, LED como saida
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  // le o valor de tensao no pino de LDR
  leitura = analogRead(pinoLDR);

  // imprime o valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); // tabulacao

  // converte e imprime o valor em tensao eletrica
  tensao = leitura * 5.0 / 1024.0;
  Serial.print("Tensão: ");
  Serial.print(tensao);
  Serial.print("V");

  Serial.println();

  if (leitura < 100) {
    digitalWrite(pinoLED, HIGH); // acende o LED
  } else {
    digitalWrite(pinoLED, LOW); // apaga o LED
  }

  delay(100);
}
