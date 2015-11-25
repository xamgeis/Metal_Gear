
#include <NewPing.h>

#define MAX_DISTANCE 200
#define SONAR_NUM 4
#define PING_INTERVAL 33 //milliseconds between pings
int trigPins[] = { 2, 4, 6, 8};
int echoPins[] = { 3, 5, 7, 9};

unsigned long pingTimer[SONAR_NUM];  //WHEN each pings
unsigned int cm[SONAR_NUM]; //stores ping distances
int currentSensor = 0; //which sensor is active
unsigned long sonarCycle; //time of sonar readings

NewPing sonar[SONAR_NUM] = { //sensor object array
  NewPing (trigPins[0], echoPins[0], MAX_DISTANCE),
  NewPing (trigPins[1], echoPins[1], MAX_DISTANCE),
  NewPing (trigPins[2], echoPins[2], MAX_DISTANCE),
  NewPing (trigPins[3], echoPins[3], MAX_DISTANCE)
};


void setup() {
  Serial.begin(115200);
  
  for(int i = 0; i < SONAR_NUM; i++){
    pinMode(trigPins[i],  OUTPUT);
    pinMode(echoPins[i], INPUT);
  }
  
  pingTimer[0] = millis() + 75; //first ping starts in ms
  for( int i = 1; i < SONAR_NUM; i++)
    pingTimer[i] = pingTimer[i-1] + PING_INTERVAL;
}

void loop() {
  for( int i = 0; i < SONAR_NUM; i++){

    if( millis() >= pingTimer[i]){
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;
      
      if( i == 0 && currentSensor == SONAR_NUM - 1){
        oneSensorCycle(); //do Something with results
        
      }
      
      sonar[currentSensor].timer_stop();
      currentSensor = i;
      cm[currentSensor] = 0;
      sonar[currentSensor].ping_timer(echoCheck);
    }
  }//end of for loop
}

//if ping echo, set distance to array
void echoCheck() {
  if( sonar[currentSensor].check_timer())
   cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM; 
}

void oneSensorCycle(){ //do something with the results
  for( int i = 0; i < SONAR_NUM; i++){
     Serial.print("S[");
     Serial.print(i);
     Serial.print("]: ");
     Serial.print(cm[i]);
     Serial.print(" cm\t\t");
 }
}  
