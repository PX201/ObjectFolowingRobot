#include <NewPing.h>
#include <IRremote.h>

//right 
#define motor1A 2
#define motor1B 3
//left
#define motor2A  5
#define motor2B  4

#define IR_RECEIVER 7

#define RIGHT_IR 10
#define LEFT_IR 9
#define ULTRASONIC_TRIGER 12
#define ULTRASONIC_ECHO 11

#define MIN_DISTANCE 3
#define MAX_DISTANCE 20


NewPing ultrasonicSensor(ULTRASONIC_TRIGER, ULTRASONIC_ECHO, 100);
boolean isFollowMode = false;

void setup() {
  // Motors Setup
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

  //IR Sensors Setup
  pinMode(RIGHT_IR, INPUT);
  pinMode(LEFT_IR, INPUT);

  // IR Receiver Setup
    IrReceiver.begin(IR_RECEIVER, true);

  // Serial Debugging
  Serial.begin(9600);
}

void loop() {
 
  // Check for IR remote input
  if(IrReceiver.decode()) {
   unsigned long receivedValue = IrReceiver.decodedIRData.decodedRawData;
    Serial.println("Received Value: ");Serial.println(receivedValue);
    IrReceiver.resume(); 

    if(receivedValue == 3125149440){
      isFollowMode = !isFollowMode;
      stop();//Stop the robot when switching modes
    } 
    
    if(!isFollowMode) remoteControlMode(receivedValue); //Switch To Remote Control Mode 
    else followMode(); //Switch TO The Follow Mode
  }
  if(isFollowMode) followMode(); //Switch TO The Follow Mode
 
}



//Folow Mode Logic
void followMode(){
  int distance = ultrasonicSensor.ping_cm(); //distance between the object and the robot
  int rightIRValue = digitalRead(RIGHT_IR); // shows if the right sensor detect the object or not
  int leftIRValue = digitalRead(LEFT_IR); // shows if the right sensor detect the object or not
 
  //Pring the values for debugging 
  Serial.print("Distance: "); Serial.println(distance);
  Serial.print("Right IR: "); Serial.println(rightIRValue);
  Serial.print("Left IR: "); Serial.println(leftIRValue);

  boolean isClose = distance < MIN_DISTANCE ;
  boolean isFar =  distance > MAX_DISTANCE;
  
  // Movement Logic
  if (!isFar && !isClose) {
    if (rightIRValue == HIGH && leftIRValue == HIGH)   move(); //Serial.print("Moving "); 
    else if (rightIRValue == LOW && leftIRValue == HIGH)  turnRight(); //Serial.print("Turn Right ");
    else if (rightIRValue == HIGH && leftIRValue == LOW) turnLeft(); //Serial.print("Turn Left ");
    else stop();
  } else if (isClose) {
    if (rightIRValue == LOW && leftIRValue == LOW) reverse(); //Serial.print("reverse ");
    else if (rightIRValue == LOW && leftIRValue == HIGH) reverseRight(); // Serial.print("reverse right "); 
    else if (rightIRValue == HIGH && leftIRValue == LOW)  reverseLeft(); //Serial.print("reverse back ");
    else stop();
  } else {
    stop();
  }
  delay(100);
}


// Control Mode 
void remoteControlMode(unsigned long receivedValue) {
  switch ( receivedValue) {
    case 3108437760: 
      move();
      break;

    case 3927310080: 
      reverse();
      break;

    case 3141861120: 
      turnLeft();
      break;

    case 3158572800: 
      turnRight();
      break;

    case 3091726080: 
      stop();
      break;
    default:
      Serial.print("Unknown command: ");Serial.println(receivedValue);
      break;
  }
}

void move(){
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);

}
void stop(){
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}
void reverse(){
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);

}

void turnLeft(){
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);

}

void turnRight(){
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  

}
void reverseRight(){
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);

}
void reverseLeft(){
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}
