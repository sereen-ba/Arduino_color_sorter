
#include <Servo.h>


#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 3
#define SERVO360MICRO_PIN_SIG  2


Servo servo;
int frequency = 0;
int Red;
int Green;
int Blue;

String Colour ="colored";


void setup() {
 
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);      // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
 
  servo.attach(2);               // Attaching Servo Motor on Pin 2
  delay(2000);
  
  servo.write(0);                // Rotating Servo to 75 degrees. On testing, it came out that the plate is in center position at 75 degrees
  delay(2000);
  Serial.begin(9600);             // Initiating Serial Communication for Debugging purpose
}


void loop() {
  

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);      // Reading the output frequency
  Red = frequency;
 
  Serial.print("Red= ");                    //printing name
  Serial.print(frequency);                  //printing RED color frequency
  Serial.print("  ");
  delay(50);
  
  digitalWrite(S2, HIGH);                   // Setting Green filtered photodiodes to be read
  digitalWrite(S3, HIGH);
 
  frequency = pulseIn(sensorOut, LOW);      // Reading the output frequency
  Green = frequency;
                                                     
  Serial.print("Green= ");                  //printing name
  Serial.print(frequency);                  //printing RED color frequency
  Serial.print("  ");
  delay(50);
  
  digitalWrite(S2, LOW);                    // Setting Blue filtered photodiodes to be read
  digitalWrite(S3, HIGH);
  
  frequency = pulseIn(sensorOut, LOW);      // Reading the output frequency
  Blue = frequency;
  
  Serial.print("Blue= ");                   //printing name
  Serial.print(frequency);                  //printing RED color frequency
  Serial.print("  ");
  delay(50);


if((Red-Green>30||Green-Red>30) && (Green-Blue>30||Blue-Green>30) && (Red-Blue>30||Blue-Red>30))    // If the Difference between any two colours is greater than 30, that means it is coloured
  {   
      delay(200);
      if((Red-Green>30||Green-Red>30) && (Green-Blue>30||Blue-Green>30) && (Red-Blue>30||Blue-Red>30))
        {
 
            Colour= "colored";
            servo.write(90);
            delay(2000);
            servo.write(0);
       
  }}
else if(Red>=80||Green>=80||Blue>=80)
{
  delay(200);
  if(Red>=80||Green>=80||Blue>=80)
    {
        Colour= "white";
        servo.write(180);
        delay(2000);
        servo.write(0);
    }
}
else
{
  Colour="black";
  servo.write(270);
  delay(2000);
  servo.write(0);
  
}
Serial.println(Colour);
delay(1000);
}





    
    
