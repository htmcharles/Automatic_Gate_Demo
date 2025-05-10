#include <Servo.h>

// Pin definitions
const int triggerPin = 2;   
const int echoPin = 3;       
const int redLedAnodePin = 4; 
const int redLedCathodePin = 8; 
const int blueLedCathodePin = 7; 
const int blueLedPin = 5;    
const int servoPin = 6;      
const int buzzerPin = 12;    

// Constants
const float thresholdDistance = 10.0;  
const int closedAngle = 0;             
const int openAngle = 90;              
const unsigned long closeDelay = 5000; 

Servo myServo;              
bool isOpen = false;        
unsigned long lastDetectionTime = 0; 

void setup() {
  // Initialize the pins
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedAnodePin, OUTPUT);    
  pinMode(redLedCathodePin, OUTPUT);
  pinMode(blueLedCathodePin,OUTPUT);
  digitalWrite(blueLedCathodePin,LOW);  
  digitalWrite(redLedCathodePin, LOW);
  pinMode(blueLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Attach servo and set initial position
  myServo.attach(servoPin);
  myServo.write(closedAngle);         
  digitalWrite(redLedAnodePin, HIGH); 
  digitalWrite(blueLedPin, LOW);      
  digitalWrite(buzzerPin, LOW);       
}

// Function to measure distance using ultrasonic sensor
float getDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration / 58.0;  
}

unsigned long lastBeepTime = 0;
bool buzzerState = false;

void loop() {
  float distance = getDistance();
  bool objectDetected = (distance < thresholdDistance);
  
  if (objectDetected) {
    if (!isOpen) {
      // Open barrier and update indicators
      myServo.write(openAngle);
      isOpen = true;
      digitalWrite(blueLedPin, HIGH);
      digitalWrite(redLedAnodePin, LOW);  
    }
    lastDetectionTime = millis();  
  } else {
    if (isOpen && (millis() - lastDetectionTime > closeDelay)) {
      // Close barrier after 5 seconds of no detection
      myServo.write(closedAngle);
      isOpen = false;
      digitalWrite(redLedAnodePin, HIGH); 
      digitalWrite(blueLedPin, LOW);
      digitalWrite(buzzerPin, LOW);       
      buzzerState = false;                
    }
  }

  // Beep when gate is open
  if (isOpen) {
    unsigned long currentTime = millis();
    if (currentTime - lastBeepTime >= 500) { 
      buzzerState = !buzzerState;           
      digitalWrite(buzzerPin, buzzerState); 
      lastBeepTime = currentTime;
    }
  }

  delay(50);
}

