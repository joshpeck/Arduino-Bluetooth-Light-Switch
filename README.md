# Arduino-Bluetooth-Light-Switch
In this repository are files schematics and instructions on how to make your own bluetooth light switch.

REQUIRED PARTS
1. Arduino Uno w/ power supply of some sort
2. Breadboard
3. 9 Compatable pins (Male to Male)
4. SG90 servo
5. HC-05 Bluetooth Module
6. Access to a a 3D printer
7. Access to a computer
8. A device with bluetooth (what you will use to turn on and off the lights, ex. a smartphone)
9. A 500 ohm and 1000 ohm resistor

INSTRUCTIONS
1. Upload 'BluetoothLightSwitch.ino' onto the Arduino Uno
2. Make sure that you measure your light switch and make any changes to the 3D printing files so that everything fits
3. Print all 3 3D printing components: servo arm, servo holder, and arduino holder
4. Screw on the aruduino holder and servo holder printed components onto the light switch panel
5. Screw the SG90 servo onto the servo holder
6. Place the plastic arm that fits into the servo arm which came with the SG90 servo
7. Place the combination of printed arm and plastic arm onto the servo so that it encloses the light switch
8. Screw on the Arduino onto the Arduino holder
9. Wire the pins according to the provided diagram (WorkingWiring.png)
10. Attach a power supply to the Arduino
11. Connect to the Bluetooth Module on your bluetooth device and send the string "on," or "off," to turn on and off your lights

BLUETOOTH MODULE PROGRAMMING
1. Disconnect the module from the arduino
2. Upload an empty file to the arduino
3. Switch the RX and TX pins so that the module is wired according to ATModeWiring.png
4. Reconnect the bluetooth module
5. Power the arduino via USB on a computer with Arduino Sketch installed while holding down the module button
6. After 2 seconds, you'll notice the blue light on the module blinking every 2 seconds, this means the module is in programming mode
7. Open the serial monitor in Arduino Sketch and set the bottom right boxes to 'Both NL & CR' and '9600 baud'
8. Type the command 'AT' twice, and if an 'OK' appears, then you can type your programming commands

ADDITIONAL NOTES
- When uploading a .ino file to the arduino, make sure the servo and bluetooth module are disconnected
- This project only works with traditional 'toggle' light switches.
- Due to the nature of the bluetooth module I used, a voltage divider was needed (cutting 5V to 3.3V). This uses additional energy on standby than just the Arduino Uno alone.

[<3 AlexeyY]
