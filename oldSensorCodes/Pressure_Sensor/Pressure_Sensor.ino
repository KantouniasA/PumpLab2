#include<MsTimer2.h>
#define period 10 //ms

int sensorPin = A0;


int sensorValue;
double voltage;
double pressure;
bool loopC = true;

void Measurement(){

  sensorValue = analogRead(sensorPin);
  
  voltage  =  (double) sensorValue/1023.0*5.0; //[V]
  String str = String(millis(),4) ;//+ ", " + String(voltage,4);
  Serial.println(str);

};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10000);

  while(!Serial){
    delay(1);
  }
  Serial.println("Ready");

  //Timers for constant sampring rate
  MsTimer2::set(period, Measurement); //  period
  MsTimer2::start();
}

void loop() {


//  pressure =  (double) sensorValue/1023.0*60.0; // [bar]
//  Serial.println(pressure)

  
}
