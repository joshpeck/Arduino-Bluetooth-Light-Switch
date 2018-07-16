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

INSTRUCTIONS
1. Upload 'BluetoothLightSwitch.ino' onto the Arduino Uno
2. Make sure that you measure your light switch and make any changes to the 3D printing files so that everything fits
3. Print all 3 3D printing components: servo arm, servo holder, and arduino holder
4. Screw on the aruduino holder and servo holder printed components onto the light switch panel
5. Screw the SG90 servo onto the servo holder
6. Place the plastic arm that fits into the servo arm which came with the SG90 servo
7. Place the combination of printed arm and plastic arm onto the servo so that it encloses the light switch
8. Screw on the Arduino onto the Arduino holder
9. Wire the pins according to the provided diagram
10. Attach a power supply to the Arduino

ADDITIONAL NOTES
- There is a file called 'BluetoothAT.ino' which I found useful in programming the bluetooth module if you need to.
- This only works with traditional 'toggle' light switches.
- Due to the nature of the bluetooth module I used, a voltage divider was needed (cutting 5V to 3.3V). This uses additional energy on standby than just the Arduino Uno alone.

KNOWN ISSUES
- Sometimes the servo does not seem to be strong enough. A fix I came across is just re-uploading the BluetoothLightSwitch.ino file.
- When reuploading a file, make sure to have the RX and TX pins disconnected so that the files are successfully uploaded without error.

[<3 AlexeyY]
