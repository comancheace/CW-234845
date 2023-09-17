#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

//sensor pins
#define trig_pin A0 //analog input 1
#define echo_pin A1 //analog input 2

#define maximum_distance 250
boolean goesForward = false;
int distance = 150;
int pos = 0;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo myservo; //our servo name
Servo myservo2; //our servo name
Servo myservo3; //our servo name
Servo myservo4; //our servo name
Servo myservo5; //our servo name
Servo myservo6; //our servo name
Servo myservo7; //our servo name
Servo myservo8; //our servo name
Servo myservo9; //our servo name


void setup(){

  Serial.begin(9600);

  myservo.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);
  myservo6.attach(7);
  myservo7.attach(8);
  myservo8.attach(9);
  myservo9.attach(10);
  
  myservo.write(115);
  myservo3.write(200);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  
  isObstacle = digitalRead(isObstaclePin);

  Serial.println(isObstacle);

  delay(200);
  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(300);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      delay(300);
      moveStop();
      delay(300);
    }
  }
  else{
    moveForward();
    delay(300);
  }
    distance = readPing();
}

int lookRight(){  
  myservo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  delay(100);
  return distance;
}

int lookLeft(){
  myservo.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  delay(100);
  return distance;
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
    Serial.println("Stop");
    delay(1000);
    
    

}

void moveForward(){

  if(!goesForward){

    Serial.println("Forward");
    
    delay(100);

    goesForward=true;
    distance = readPing();
    //Serial.println(isObstacle);
    while (   distance > 20){
      
      for (pos = 0; pos <= 35; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
   
      myservo4.write(pos);
      myservo5.write(pos);
      myservo6.write(-(pos*2));          // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 35; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo4.write(pos);
      myservo5.write(pos);
      myservo6.write(-(pos*2));           // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
      }
      
      for (pos = 90; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
   
      myservo7.write(pos);
      myservo8.write(pos);
      myservo9.write(-(pos*2));         // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 120; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo7.write(pos);
      myservo8.write(pos);
      myservo9.write(-(pos*2));           // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
      }
    }
  }
}



void moveBackward(){

  Serial.println("Back");
  delay(100);

  goesForward=false;

  

      for (pos = 35; pos <= 0; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
   
      myservo4.write(pos);
      myservo5.write(pos);
      myservo6.write(-(pos*2));          // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 0; pos >= 35; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo4.write(pos);
      myservo5.write(pos);
      myservo6.write(-(pos*2));           // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
      }
      
      for (pos = 120; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
   
      myservo7.write(pos);
      myservo8.write(pos);
      myservo9.write(-(pos*2));         // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 90; pos >= 120; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo7.write(pos);
      myservo8.write(pos);
      myservo9.write(-(pos*2));           // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
      }
    
  
}

void turnRight(){

  Serial.println("Right");
  delay(100);

  
  myservo3.write(45);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15 ms for the servo to reach the position
  myservo3.write(25);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15 ms for the servo to reach the position
     
  
}

void turnLeft(){

  Serial.println("Left");
  delay(100);

  myservo2.write(180);              // tell servo to go to position in variable 'pos'
  delay(15);
  myservo2.write(200);
  200                // waits 15 ms for the servo to reach the position

}