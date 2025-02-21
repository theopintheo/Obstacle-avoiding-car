#include <Servo.h>
#include <NewPing.h>

// Define pins for sensors and motors
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define LEFT_MOTOR_FORWARD 6
#define LEFT_MOTOR_BACKWARD 5
#define RIGHT_MOTOR_FORWARD 10
#define RIGHT_MOTOR_BACKWARD 9
#define MAX_DISTANCE 200

Servo myServo; // create servo object to control servo
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance

void setup() {
  // Initialize motors
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  
  // Initialize servo
  myServo.attach(3); 
  myServo.write(90); // Set servo to center position
  
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  unsigned int distance = sonar.ping_cm();
  if (distance > 0 && distance < 20) {
    // Object detected, stop and determine direction to turn
    stop();
    delay(100);
    myServo.write(0); // Check left
    delay(500);
    unsigned int distanceLeft = sonar.ping_cm();
    
    myServo.write(180); // Check right
    delay(500);
    unsigned int distanceRight = sonar.ping_cm();
    
    myServo.write(90); // Center servo
    delay(500);
    
    if (distanceLeft >= distanceRight) {
      turnRight();
    } else {
      turnLeft();
    }
  } else {
    moveForward();
  }
  delay(100);
}

void moveForward() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void stop() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void turnLeft() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
  delay(500);
  stop();
}

void turnRight() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);
  delay(500);
  stop();
}
