#include <AFMotor.h>

// Create motor objects
AF_DCMotor motor1(3); // Front left motor
AF_DCMotor motor2(1); // Front right motor
AF_DCMotor motor3(4); // Rear left motor
AF_DCMotor motor4(2); // Rear right motor

// Connect two IR sensors to the following pins
const int irSensor1Pin = 19; // Connect IR sensor 1 to pin 19
const int irSensor2Pin = 20; // Connect IR sensor 2 to pin 20

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("AFMotor - 4 Motors - IR Sensor Test!");

  // Set up IR sensor pins
  pinMode(irSensor1Pin, INPUT);
  pinMode(irSensor2Pin, INPUT);

}

void loop() {
  motor1.setSpeed(150);  // Adjust the speed as needed
  motor1.run(FORWARD);
  // // // Read the state of IR sensors
  // int irSensor1State = digitalRead(irSensor1Pin);
  // int irSensor2State = digitalRead(irSensor2Pin);

  // // Check if both IR sensors detect an obstacle
  // if (irSensor1State == HIGH || irSensor2State == HIGH) {
  //   // Turn right at 90 degrees
  //   turnRight();
  // } else {
  //   // If no obstacle, move forward
  //   moveForward();
  // }
}

void moveForward() {
  // Motor control logic to move forward
  motor1.setSpeed(150);  // Adjust the speed as needed
  motor1.run(FORWARD);

  motor2.setSpeed(150);
  motor2.run(FORWARD);

  motor3.setSpeed(150);
  motor3.run(FORWARD);

  motor4.setSpeed(150);
  motor4.run(FORWARD);
}

void turnRight() {
  // Motor control logic to turn right
  motor1.setSpeed(150);  // Adjust the speed as needed
  motor1.run(BACKWARD);

  motor2.setSpeed(150);
  motor2.run(FORWARD);

  motor3.setSpeed(150);
  motor3.run(BACKWARD);

  motor4.setSpeed(150);
  motor4.run(FORWARD);

  // Delay to turn for 90 degrees
  delay(1000); // Adjust the delay based on your robot's speed and wheelbase

  // Stop all motors after turning
  stopMotors();
}

void stopMotors() {
  // Stop all motors
  motor1.setSpeed(0);
  motor1.run(RELEASE);

  motor2.setSpeed(0);
  motor2.run(RELEASE);

  motor3.setSpeed(0);
  motor3.run(RELEASE);

  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
