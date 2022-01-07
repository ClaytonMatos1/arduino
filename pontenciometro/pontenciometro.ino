#define POTENTIOMETER A0

int reading = 0;
float voltage = 0.0;

void setup() {
  Serial.begin(9600);

  pinMode(POTENTIOMETER, INPUT);
}

void loop() {
  reading = analogRead(POTENTIOMETER);
  // converte e imprime o valor em tensao eletrica
  voltage = reading * 5.0 / 1024.0;

  Serial.print(reading);
  Serial.print(" ");
  Serial.print(voltage);
  Serial.print(" ");
  Serial.print(voltage * 100);
  Serial.print(" ");
  Serial.print(voltage * 90);
  Serial.print(" ");
  Serial.print(reading/2);
  Serial.print(" ");
  Serial.println(voltage * 80);

  delay(100);
}
