# Hardware Setup Guide

This guide explains how to set up the hardware for the coil winder project using Arduino MEGA 2560, RAMPS 1.6, DRV8825 drivers, and NEMA 17 motors.

## Components Needed

- Arduino MEGA 2560 R3 Board
- RAMPS 1.6 3D Printer Shield
- 3x DRV8825 Stepper Motor Drivers
- 3x NEMA 17 Stepper Motors
- 12V Power Supply (at least 5A recommended)
- Limit switch for axis homing
- Wires, connectors, and mounting hardware

## RAMPS 1.6 Shield Setup

1. Carefully attach the RAMPS 1.6 shield to the Arduino MEGA 2560 board, ensuring all pins align correctly.
2. Insert the DRV8825 drivers into the X, Y, and Z stepper motor slots on the RAMPS board.
   - **IMPORTANT**: Make sure the orientation is correct - the adjustment potentiometer should be facing away from the power connectors.
   - Double-check all drivers are fully seated in their sockets.

## DRV8825 Driver Setup

1. Set the microstepping jumpers on the RAMPS board according to your desired microstepping setting.
   - Default setting in this project is 32 microsteps (MS1=ON, MS2=ON, MS3=ON).
   - Refer to the DRV8825 datasheet for other microstepping configurations.

2. Adjust the current limiting on each DRV8825:
   - Turn the potentiometer fully counterclockwise to start with minimum current.
   - Power on the board with the motors disconnected.
   - Measure the voltage between the adjustment potentiometer and ground.
   - Calculate the desired voltage: V = 8 * I * R, where I is the desired current limit (typically 1A for NEMA 17) and R is the current sense resistor value (0.1Ω for most DRV8825 boards).
   - Adjust the potentiometer until you measure the calculated voltage.
   - Power off the board before connecting motors.

## Motor Connections

Connect the NEMA 17 stepper motors to the RAMPS board:

1. X-axis motor → X motor output
2. Y-axis motor → Y motor output
3. Z-axis motor → Z motor output

Each motor has 4 wires that form 2 coils. The wiring order is:

- A1, A2: First coil
- B1, B2: Second coil

If you're unsure about the wiring order of your motors, refer to the motor's datasheet or use a multimeter to identify the coils.

## Endstop Setup

At minimum, connect one limit switch to the Y_MIN pin for the Y-axis homing:

1. Connect one side of the switch to the signal pin (S) on the Y_MIN connector.
2. Connect the other side to the ground pin (G) on the same connector.

The endstop should be positioned at the desired "home" position of your Y_AXIS mechanism.

## Power Supply Connection

1. Connect a 12V power supply to the RAMPS 1.6 board:
   - Connect the positive (+) wire to the positive terminal on the RAMPS board.
   - Connect the negative (-) wire to the negative terminal on the RAMPS board.
   - Ensure the power supply can provide at least 5A.

2. **IMPORTANT**: Double-check the polarity before powering on! Incorrect polarity will damage the board.

## Physical Setup

1. Mount the NEMA 17 motors securely to the machine frame.
2. Ensure the X-axis motor is connected to the carriage.
3. Ensure the Y-axis motor is connected to the stator rotation mechanism.
4. Ensure the Z-axis motor is connected to the shuttle containing the wire nozzle.

## Testing

1. Upload the coil-winder.ino sketch to the Arduino MEGA.
2. Open the Serial Monitor at 115200 baud.
3. Send the command 'H' to home all axes.
4. If all motors move as expected, the hardware setup is correct.

## Troubleshooting

- If a motor doesn't move or makes a buzzing sound, check:
  - Motor connections
  - Driver current setting
  - Driver orientation
  - Power supply voltage and current

- If a motor moves in the wrong direction, swap any pair of wires for that motor.

- If the homing doesn't work, check the limit switch connection and orientation.
