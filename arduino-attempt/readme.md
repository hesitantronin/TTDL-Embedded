# TTDL-Embedded

## Summary

This part of the project is supposed to run on the ESP32, it currently measures the value of the sensor, and prints in to SERIAL out. This needs to be expanded with KPN Lora integration, which you should get the keys for from Campus Gouda.

## How to run

To run this, simply:

- connect the sensor to GPIO 35 and GND
- connect the ESP32 to your computer with USB
- open `arduino-attempt.ino` in Arduino IDE
- select the port the ESP32 is connected to, and select the right board to connect it
- run the project

## To add

This is unfinished, and still needs the following improvements:

- connect to KPN Lora, and send the measured values there
- make a system to send those messages at set times, so you can just not send messages at night for example
- does not yet record whether someone is sitting with their back against the chair, which might be useful for medical professionals
