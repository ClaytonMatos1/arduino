#include <Servo.h>

#define POT A5

Servo servo_motor;

int reading_pot, reading_servo;

void setup() {
  Serial.begin(9600);
  pinMode(POT, INPUT);
  
  // informa qual pino sera usado para o servo motor
  servo_motor.attach(9);
  // informa ao servo que devera se posicionar a 10 graus
   servo_motor.write(100);
}

void loop() {
  // faz a leitura do potenciometro
  reading_pot = analogRead(POT);
  // converte a leitura para a posicao do servomotor
  reading_servo = map(reading_pot, 0, 1023, 10, 170);
  Serial.print("Leitura potenciometro: ");
  Serial.print(reading_pot);
  Serial.print("\t");
  Serial.print("Leitura convertida para o servomotor: ");
  Serial.println(reading_servo);
  // informa ao servomotor a posicao conforme a leitura do potenciometro
//  servo_motor.write(reading_servo);

  delay(100);
}
