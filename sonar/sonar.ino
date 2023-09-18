#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(4, 5);  // Initialize sensor that uses digital pins 13 and 12.

#define pinSOM01 8
#define pinSOM02 11
//int frequencia = 0;
int Pinofalante = 10;
#define tempo 10

void tom(int frequencia)
{
  //for (frequencia = 1800; frequencia > 150; frequencia -= 1) 
  for (int vezes = 50; vezes > 10; vezes -= 1) 
  {
    tone(pinSOM02, (frequencia*50)+150, tempo); 
    delay(1);
  }
}

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
    pinMode(pinSOM01,OUTPUT); //Pino do buzzer
    pinMode(pinSOM02,OUTPUT); //Pino do buzzer
    digitalWrite(pinSOM01,LOW);
    digitalWrite(pinSOM02,LOW);
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    int distancia = distanceSensor.measureDistanceCm();
    Serial.println(distancia);    
    delay(500);
    tom(distancia);
}
