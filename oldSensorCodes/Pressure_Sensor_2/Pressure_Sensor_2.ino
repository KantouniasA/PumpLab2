#include<MsTimer2.h>
#define period 10 //ms
#define samples 400

int sensorPin = A0;
int ledPin = 13;
bool Flag = true;

//int sensorValue;
//double voltage;
//double pressure;
//bool loopC = true;

int* measurements = (int *) malloc(sizeof(int)*samples);
int count = 0;


void Measurement(){

  measurements[count] = analogRead(sensorPin);
  count ++;
//  Serial.println(count);
  
//  voltage  =  (double) sensorValue/1023.0*5.0; //[V]
//
//  Serial.println(voltage);

};

void blink(int t1,int t2){
  digitalWrite(ledPin,HIGH);
  delay(t1);
  digitalWrite(ledPin,LOW);
  delay(t2);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(9000);

  // wait until serial is ready
  while(!Serial){
    delay(1);
  }
  Serial.println("Ready");

  if( measurements == NULL){
    Serial.print("Failed mallock");
    Flag = false;
  }else{

  //blink to signal
  pinMode(ledPin,OUTPUT);
  blink(500,500);

  //Timers for constant sampring rate
  MsTimer2::set(period, Measurement); //  period
  MsTimer2::start();
  }
}

void loop() {

if (count > samples){
  if (Flag){ 
    MsTimer2::stop(); 
    blink(1000,10);
    for (int i=0; i< samples;i++){
      Serial.println(measurements[i]);
    }
    Flag = false;
  }
  blink(1000,1000);
  
}

  
}
