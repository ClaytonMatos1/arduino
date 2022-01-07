#define VRX A4
#define VRY A5
#define SW 2

int read_btn = 0, read_vrx, read_vry;

void setup() {
  Serial.begin(9600);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  read_vrx = analogRead(VRX);
  read_vry = analogRead(VRY);
  read_btn = digitalRead(SW);

  Serial.print("Leitura em VRX: ");
  Serial.print("\t");
  Serial.print(read_vrx);
  Serial.print("\t");

  Serial.print("Leitura em VRY: ");
  Serial.print("\t");
  Serial.print(read_vry);
  Serial.print("\t");

  Serial.print("Leitura do botão: ");
  Serial.println(read_btn);

  delay(100);
}
