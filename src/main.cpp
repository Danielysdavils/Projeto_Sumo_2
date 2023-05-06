#include <Arduino.h>
#include <GP2Y0E03-Arduino.h>
GP2Y0E03 _sensor(A0);

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

//Sensor
int IN5 = 2;

void setup() {
 
  Serial.begin(9600);

  //Motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 

  //Sensores
  pinMode(IN5, INPUT); 
}

void loop() {
  int val = _sensor.read();
  Serial.println("Sensor: ");
  Serial.println(val);

  if(val <= 10) {
    //Se o valor do sensor menor que 10 gira o motor A no sentido h
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(300);

    //Gira o motor B no sentido h
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(300);

  } else {
    //Se no, para o motor A
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    delay(300);

    //Se no, para o motor B
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(300);
  } 
}