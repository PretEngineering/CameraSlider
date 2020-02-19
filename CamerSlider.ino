#define EN_PIN    7                 // LOW: Driver enabled. HIGH: Driver disabled
#define STEP_PIN  6                // Step on rising edge
#define DIR_PIN 8

const int RIGHT_PIN = 9;
const int LEFT_PIN = 10;

int speed = 75;

int leftButton = 0;
int rightButton = 0;

#include <TMC2208Stepper.h>             // Include library

TMC2208Stepper driver = TMC2208Stepper(&Serial);  // Create driver and use
                          // HardwareSerial0 for communication

void setup() {
  Serial.begin(115200);             // Init used serial port
  while(!Serial);                 // Wait for port to be ready

//   // prepare pins

pinMode(RIGHT_PIN, INPUT);
pinMode(LEFT_PIN, INPUT);



  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

 // setup driver
  driver.pdn_disable(1);              // Use PDN/UART pin for communication
  driver.I_scale_analog(0);           // Adjust current from the registers
  driver.rms_current(500);            // Set driver current 500mA
  driver.toff(0x2);               // Enable driver

  digitalWrite(EN_PIN, LOW);              // Enable driver
}

void loop() {
  leftButton = digitalRead(LEFT_PIN);
  rightButton = digitalRead(RIGHT_PIN);

if (leftButton == 1){
    digitalWrite(DIR_PIN, HIGH); // move left
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(speed);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(speed);
  }


if (rightButton == 1){
    digitalWrite(DIR_PIN, LOW); // move right
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(speed);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(speed);
  }

}
  // Serial.println("testing");
  // Serial.println(leftButton);
  // Serial.println(rightButton);
  // Serial.println();

