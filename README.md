# Coil X_AXIS

A BLDC coil winding machine built with Arduino.

## Overview

This project provides the software for a coil winding machine controlled by Arduino. It uses stepper motors to precisely wind wire around a bobbin or core to create coils for electric motors, transformers, inductors, or other electromagnetic components.

## Hardware Components

- ZYLtech MEGA 2560 R3 Board
- RAMPS 1.6 3D Printer Shield
- DRV8825 motor drivers
- NEMA 17 stepper motors
- Limit switches for homing
- 12V-24V power supply

## Features

- Multi-axis control (X_AXIS, Y_AXIS, Z-axis)
- Layer-by-layer winding with configurable parameters
- Automatic wire distribution
- Tension control
- Real-time progress monitoring
- Serial interface for commands and configuration
- Optional LCD display support

## Project Structure

- `coil_X_AXIS.ino`: Main Arduino sketch
- `config.h`: Configuration parameters and pin definitions
- `motor_control.h/cpp`: Stepper motor control functions
- `winding.h/cpp`: Winding process logic
- `ui.h/cpp`: User interface functions
- `HARDWARE_SETUP.md`: Detailed hardware setup instructions
- `LIBRARY_INSTALLATION.md`: Library installation guide

## Getting Started

1. Follow the instructions in `HARDWARE_SETUP.md` to assemble the hardware.
2. Install the required libraries as per `LIBRARY_INSTALLATION.md`.
3. Adjust parameters in `config.h` according to your specific setup.
4. Upload the `coil_X_AXIS.ino` sketch to your Arduino MEGA.
5. Open the Serial Monitor at 115200 baud to interact with the system.

## Commands

The following commands can be sent via serial:
- `S`: Start winding
- `P`: Pause winding
- `R`: Resume winding
- `H`: Home all axes
- `C`: Configure winding parameters
- `?`: Report status

## Configuration

The default configuration can be modified in `config.h` or via the serial interface:
- Number of layers
- Turns per layer
- Wire diameter
- Microstepping settings
- Motor speeds and accelerations
- Mechanical parameters

## Customization

The code is designed to be modular and easily customizable. To adapt it to your specific hardware:

1. Modify pin assignments in `config.h`
2. Adjust the motor control functions in `motor_control.cpp`
3. Implement or modify the winding algorithm in `winding.cpp`
4. Extend the UI functions in `ui.cpp` if using additional display or input devices

## Contributing

Contributions to improve the project are welcome. Please feel free to submit pull requests or open issues to suggest improvements or report bugs.

## License

This project is licensed under the terms of the included LICENSE file.
