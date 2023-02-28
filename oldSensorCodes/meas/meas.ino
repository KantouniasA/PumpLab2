#include <stdlib.h>

int sensorPin = A0;


int sensorValue;
double voltage;

unsigned long t1;
unsigned long t2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ready");
  delay(10000);

  t2 = millis();
}

void loop() {
  // put your main code here, to run repeatedly:

  
  sensorValue = analogRead(sensorPin);
  
  voltage  =  (double) sensorValue/1023.0*5.0; //[V]
  

//  String str = String(millis()) + ", " + String(voltage,4);
//  
//  Serial.println(millis());
//  Serial.print(", ");
  Serial.println(voltage);

//  Serial.println(str);
  
  while(millis() < t2+12){}
  
  t2 = millis();
}
