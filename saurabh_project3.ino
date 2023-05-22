/*
Saurabh Salvi

MARS Project-3

This is a project consisting of 2 sensors : force sensor
and photoresistor
*/

int led = 9;
int motor = 3;
int photo = A2;
int force = A0;
int fvalue;
int pvalue; 

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(photo, INPUT);
  pinMode(force, INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  fvalue = analogRead(force);
  Serial.print("Force values : ");
  Serial.print(fvalue);
  Serial.print(" ; ");
  analogWrite(led, fvalue/4);
  
  pvalue = analogRead(photo);
  Serial.print("photoResistor value : ");
  Serial.println(pvalue);
  analogWrite(motor, pvalue/4);
}