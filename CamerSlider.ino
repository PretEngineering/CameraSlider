#define EN_PIN    7                 // LOW: Driver enabled. HIGH: Driver disabled
#define STEP_PIN  6                // Step on rising edge
#define DIR_PIN 8

#include <TMC2208Stepper.h>             // Include library

TMC2208Stepper driver = TMC2208Stepper(&Serial);  // Create driver and use
                          // HardwareSerial0 for communication

void setup() {
  Serial.begin(115200);             // Init used serial port
  while(!Serial);                 // Wait for port to be ready

  // prepare pins
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

  digitalWrite(DIR_PIN, HIGH); // move in one direction
  for(int x = 0; x < 4000; x++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(400);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(400);
  }

  digitalWrite(DIR_PIN, LOW); // move in other direction
  for(int x = 0; x < 4000; x++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(400);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(400);
  }

  delay(1000);
}
