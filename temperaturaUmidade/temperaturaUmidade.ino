#include <DHT_U.h>
#include <DHT.h>

const int pino_dht = 9;
float temperature;
float humidity;
DHT dht(pino_dht, DHT11);

void setup() {
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  delay(2000);

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha na leitura do Sensor DHT!");
  } else {
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.print(" *C");

    Serial.print("\t");

    Serial.print("Umidade: ");
    Serial.print(humidity);
    Serial.print(" %\t");

    Serial.println();
  }
}
