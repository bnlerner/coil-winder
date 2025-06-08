#! /bin/bash

# This script is used to test the RAMPS pins on the Zyltech HC board

# Set the serial port
SERIAL_PORT=/dev/ttyACM0

# Set the baud rate
BAUD_RATE=115200

# arduino-cli compile --fqbn arduino:avr:mega Marlin/Marlin.ino
# arduino-cli upload -p $SERIAL_PORT --fqbn arduino:avr:mega Marlin/Marlin.ino

arduino-cli compile --fqbn arduino:avr:mega ZYLtechHC/ZYLtechHC.ino
arduino-cli upload -p $SERIAL_PORT --fqbn arduino:avr:mega ZYLtechHC/ZYLtechHC.ino

# Set the test steps
# arduino-cli compile --fqbn arduino:avr:mega $1
# arduino-cli upload -p $SERIAL_PORT --fqbn arduino:avr:mega $1
arduino-cli monitor -p $SERIAL_PORT -c baudrate=$BAUD_RATE
