/* 
Saurabh Salvi

MARS Project - 1 

Code to control the turn of the car when 
an obstacle comes near the car
*/

int Trig = 7;
int Echo = 6;
int motor = 3;
float time;
float distance;
int potVal;

void setup()
{
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(Trig, LOW);// Clearing purpose
  delayMicroseconds(10);
  
  digitalWrite(Trig, HIGH);//On the trig pin
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  delayMicroseconds(10);
  
  time = pulseIn(Echo, HIGH);
  distance = (time * 0.034)/2 ;
  
  Serial.print(distance);
  Serial.print("  ");
  
  if(distance <= 100){
  		potVal = analogRead(A0);
    	analogWrite(motor, potVal/4);
    	Serial.println(potVal);
  } 
  else{
  		analogWrite(motor, 0);
    	Serial.println(potVal);
  }
}
