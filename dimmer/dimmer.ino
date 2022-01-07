#define POTENTIOMETER A0
#define LED 12
#define LED_PWM 11
#define PERIOD 1023

int timeON, timeOFF;
int reading = 0;
int pwm = 0;

void setup() {
  Serial.begin(9600);
  pinMode(POTENTIOMETER, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED_PWM, OUTPUT);
}

void loop() {
  // LED no pino 12
//  withoutPWM();

  // LED no pino 11
  withPWM();
}

void withoutPWM() {
  timeON = analogRead(POTENTIOMETER); // le o valor de tensao do potenciometro
  timeOFF = PERIOD - timeON; // atribui a variavel timeOFF, quanto tempo o LED devera permanecer desligado
  digitalWrite(LED, HIGH); // aciona o LED
  delayMicroseconds(timeON); // aguarda o valor lido no pino do potenciometro em milissegundos
  digitalWrite(LED, LOW); // apaga o LED
  delayMicroseconds(timeOFF); // aguarda o valor lido no pino do potenciometro em milissegundos
  
  Serial.print(timeON);
  Serial.print("\t");
  Serial.println(timeOFF);
}

void withPWM() {
  reading = analogRead(POTENTIOMETER);
  // converte o valor do potenciometro de 0 a 1023 em um valor de 0 a 255
  // Variável_Recebedora = map(Valor_Lido, Mínimo_Potenciômetro, Máximo_Potenciômetro, Novo_Mínimo, Novo_Máximo)
  pwm = map(reading, 0 , 1023, 0, 255);
  // atualiza a razao ciclica do pino 11 variando a intensidade do LED
  analogWrite(LED_PWM, pwm);
}
