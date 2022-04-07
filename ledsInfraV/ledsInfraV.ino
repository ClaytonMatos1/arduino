#define RECEPTOR A0

int readingSensor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RECEPTOR, INPUT);
}

void loop() {
  Serial.print("Valor lido: ");
  readingSensor = analogRead(RECEPTOR);
  Serial.println(readingSensor);
  delay(300);
}
