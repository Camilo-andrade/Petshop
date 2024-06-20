#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600); 
  sensors.begin(); 
}

void loop() {
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0); 

  Serial.print("Temperatura: ");
  Serial.print(temperatureC); // Imprime a temperatura em Celsius
  Serial.println(" °C"); 

  delay(1000); // Sem espaço não-quebrável aqui!
}