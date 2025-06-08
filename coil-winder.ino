/**
 * Coil Winder Motor Test
 * 
 * A test for troubleshooting stepper motors with DRV8825 drivers
 * Uses direct pin control for simplicity
 */

#include "drivers/stepper_indirection.h"

// Pin definitions for RAMPS 1.6 / Arduino MEGA 2560
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

// Timing settings
#define STEP_PULSE_LENGTH  5    // microseconds
#define STEP_DELAY         10    // microseconds

void setup() {
  Serial.begin(115200);
  Serial.println("Coil Winder Motor Test");
  Serial.println("----------------------------------------------");
  
  // Configure motor pins
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  
  
  // Disable motors initially (HIGH = disabled)
  digitalWrite(X_ENABLE_PIN, HIGH);
  
  // Print menu
  printMenu();
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    
    // Clear any remaining input
    while (Serial.available() > 0) {
      Serial.read();
    }
    float stepsToMove = 60000.0;
    testSingleMotor(input, stepsToMove);
    delay(1000);
  }
}

void printMenu() {
  Serial.println("\nCoil Winder Motor Test");
  Serial.println("Press X to test X motor");
  Serial.println("Press Y to test Y motor");
  Serial.println("Press Z to test Z motor");
  Serial.println("Press E to test E0 motor");
  Serial.println("Press S to test E1 motor");
}

void testSingleMotor(char motorName, float stepsToMove) {
  Serial.print("\n--- Testing ");
  Serial.print(motorName);
  Serial.println(" motor ---");
  
  // Enable motor (LOW = enabled)
  Serial.print("Enabling ");
  Serial.print(motorName);
  Serial.println(" motor");
  
  int stepPin, dirPin, enablePin;
  
  // Set the appropriate pins based on motor name
  if (motorName == 'X') {
    stepPin = X_STEP_PIN;
    dirPin = X_DIR_PIN;
    enablePin = X_ENABLE_PIN;
  } else if (motorName == 'Y') {
    stepPin = Y_STEP_PIN;
    dirPin = Y_DIR_PIN;
    enablePin = Y_ENABLE_PIN;
  } else if (motorName == 'Z') {
    stepPin = Z_STEP_PIN;
    dirPin = Z_DIR_PIN;
    enablePin = Z_ENABLE_PIN;
  } else if (motorName == 'E') {
    stepPin = E0_STEP_PIN;
    dirPin = E0_DIR_PIN;
    enablePin = E0_ENABLE_PIN;
  } else if (motorName == 'S') {
    stepPin = E1_STEP_PIN;
    dirPin = E1_DIR_PIN;
    enablePin = E1_ENABLE_PIN;
  } else {
    return; // Invalid motor name
  }
  
  // Enable the motor
  digitalWrite(enablePin, LOW);
  delay(500);
  
  // Test forward direction
  Serial.print("Moving ");
  Serial.print(motorName);
  Serial.print(" motor FORWARD (");
  Serial.print(stepsToMove);
  Serial.println(" steps)");
  
  // Set direction for forward movement
  digitalWrite(dirPin, HIGH);
  
  // Move the motor forward
  for (int i = 0; i < stepsToMove; i++) {
    // Send step pulse
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(STEP_PULSE_LENGTH);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(STEP_DELAY);
  }
  
  delay(1000);
  
  // Test reverse direction
  Serial.print("Moving ");
  Serial.print(motorName);
  Serial.print(" motor REVERSE (");
  Serial.print(stepsToMove);
  Serial.println(" steps)");
  
  // Set direction for reverse movement
  digitalWrite(dirPin, LOW);
  
  // Move the motor in reverse
  for (int i = 0; i < stepsToMove; i++) {
    // Send step pulse
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(STEP_PULSE_LENGTH);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(STEP_DELAY);
  }
  
  // Disable motor when done
  Serial.print("Disabling ");
  Serial.print(motorName);
  Serial.println(" motor");
  
  // Disable the motor
  digitalWrite(enablePin, HIGH);
} 
