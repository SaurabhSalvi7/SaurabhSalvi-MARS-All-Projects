/*
Saurabh Salvi

MARS Project-2

Project to have a perfect water temperature for taking bath
using temperature sensor and for emergency(over hot!),
using gas sensor
*/

int buzzer = 12;
int hot = 7;
int cold = 8;
int gasSensor;
float vread;
float vfinal;
float temp;
int led = 4;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(hot, OUTPUT);
  pinMode(cold, OUTPUT);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  vread = analogRead(A1);
  vfinal = (vread/1023)*5000;
  temp = (vfinal-500)/10 ;
  
  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.print(" ; ");
  
  if(temp <= 32){
  		digitalWrite(hot, HIGH);
   		digitalWrite(cold, LOW);
  }
  else if(temp >= 40){
  		digitalWrite(hot, LOW);
   		digitalWrite(cold, HIGH);
  } 
  else{
  		digitalWrite(hot, HIGH);
   		digitalWrite(cold, HIGH);
  }
  
  //emergency system 
  gasSensor = analogRead(A0);
  Serial.print("Gas Sensor value : ");
  Serial.println(gasSensor);
  
  if(gasSensor >= 42){
  		digitalWrite(buzzer, HIGH);
   		digitalWrite(led, HIGH);
  }
  else{
  		digitalWrite(buzzer, LOW);
    	digitalWrite(led, LOW);
  }
}
