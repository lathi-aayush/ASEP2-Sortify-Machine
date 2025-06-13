#include <Servo.h>

Servo myServo1;
Servo myServo2;

int servoPin1 = 5;  // First servo pin
int servoPin2 = 6;  // Second servo pin
int adjustVal = 90; // Adjust this for desired speed/power (smaller value = slower)

unsigned long commandTime = 0;  // To store the time when command was given
bool isMoving = false;          // To track if flap is moving or not

void setup() {
  Serial.begin(9600);
  myServo1.attach(servoPin1);  // Attach to pin 5
  myServo2.attach(servoPin2);  // Attach to pin 6

  myServo1.write(90); // Stop position
  myServo2.write(90);

  Serial.println("Dual Opposite Servo Flap Control");
  Serial.println("Enter 1 to open the flap");
  Serial.println("Enter 0 to close the flap");
  Serial.println("Enter 's' to stop");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    if (input == '1') {
      // Open flap: Servo1 clockwise, Servo2 counterclockwise
      myServo1.write(90 + adjustVal);
      myServo2.write(90 - adjustVal);
      Serial.println("Opening flap");
      commandTime = millis();  // Record the time
      isMoving = true;
    }
    else if (input == '0') {
      // Close flap: Servo1 counterclockwise, Servo2 clockwise
      myServo1.write(90 - adjustVal);
      myServo2.write(90 + adjustVal);
      Serial.println("Closing flap");
      commandTime = millis();  // Record the time
      isMoving = true;
    }
    else if (input == 's' || input == 'S') {
      // Stop both
      myServo1.write(90);
      myServo2.write(90);
      Serial.println("Flap stopped manually");
      isMoving = false;
    }
  }

  // Auto-stop after 5 seconds (5000 ms)
  if (isMoving && (millis() - commandTime >= 500)) {
    myServo1.write(90);
    myServo2.write(90);
    Serial.println("Flap stopped automatically after 5 seconds");
    isMoving = false;
  }
}
