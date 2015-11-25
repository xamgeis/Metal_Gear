
/*
Adafruit Arduino - Lesson 13. DC Motor
*/
#include <NewPing.h>

#define trigPin 5
#define echoPin 6
#define MAX_DISTANCE 200

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);


int turnRadius = 90;
#define leftMotorPin 7
#define rightMotorPin 8
int spd = 255; 
int distance; 

void setup() 
{ 
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  delay(1000);
  
} 
 
 
void loop() 
{ 
  delay(50);
  distance = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(distance);
  Serial.println(" cm");

  
//  if (distance < 30) 
//   {
//   Serial.println("TURNING RIGHT!!!!!");
//   //turnRight(spd);
//   
//  } else
//  {
//    moveFoward(spd);
//  }
//  
}

void moveFoward(int spd){
  analogWrite(rightMotorPin, spd);
  analogWrite(leftMotorPin, spd);
  
  
}

void turnRight(int spd){
  for(int i = 0; i < turnRadius; i++){
    analogWrite(rightMotorPin, 0);
    analogWrite(leftMotorPin, spd);
    delay(10);
  }
}

