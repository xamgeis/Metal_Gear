
#include <NewPing.h>

#define MAX_DISTANCE 100
int trigPins[] = { 2, 4, 6, 8};
int echoPins[] = { 3, 5, 7, 9};

NewPing s1(trigPins[0], echoPins[0], MAX_DISTANCE);
NewPing s2(trigPins[1], echoPins[1], MAX_DISTANCE);
NewPing s3(trigPins[2], echoPins[2], MAX_DISTANCE);
NewPing s4(trigPins[3], echoPins[3], MAX_DISTANCE);

int distance [4];

void setup() {
  
  for(int i = 0; i < sizeof(trigPins)/sizeof(int); i++){
    pinMode(trigPins[i],  OUTPUT);
    pinMode(echoPins[i], INPUT);
  }
  Serial.begin(9600);
  delay(1000);
  
}

void loop() {
 
 delay(50);
 distance[0] = s1.ping_median();
 distance[1] = s2.ping_cm();
  
 for( int i = 0; i < sizeof(distance)/sizeof(int); i++){
  
   Serial.print("Ping: ");
   Serial.print(distance[i]);
   Serial.print(" cm\t");
 }
 Serial.println();
 
}
