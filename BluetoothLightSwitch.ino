#include <Servo.h>

Servo servo;

//Variables
int defCenter = 42;
int defUp = 13;
int defDown = 84;

int center = defCenter;
int up = defUp;
int down = defDown;

String data = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //BAUD rate

  pinMode(13, OUTPUT);

  servo.attach(13);
  servo.write(center);
  servo.detach();

  resetVars();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);

  if (Serial.available() > 0) {
    char ch = Serial.read();
    data += ch;
    //String printData = "Current command line is: " + data;
    //Serial.println(printData + ";");
    if (ch == ',') {
      if (data == "on,") {
        Serial.println("");
        Serial.println("Turning on");
        servo.attach(13);
        servo.write(up);
        delay (1500);
        servo.write(center);
        delay (500);
        digitalWrite(13, LOW);
        servo.detach();
      }
      else if (data == "off,") {
        Serial.println("");
        Serial.println("Turning off");
        servo.attach(13);
        servo.write(down);
        delay (1500);
        servo.write(center);
        delay (500);
        digitalWrite(13, LOW);
        servo.detach();
      }
      else if (data == "vars,") {
        printVars();
      }
      else if (data == "reset,") {
        Serial.println("");
        Serial.println("Reset variables");
        resetVars();
      }
      else if (data == "commands,") {
        printCommands();
      }
      else if (data.length() >= 7 && data.substring(0, 6).equals("center")) {
        String num = data.substring(7, data.length() - 1);
        int angle = num.toInt();
        center = angle;
        Serial.println("");
        Serial.println("Set center to " + num);
      }
      else if (data.length() >= 4 && data.substring(0, 2).equals("up")) {
        String num = data.substring(3, data.length() - 1);
        int angle = num.toInt();
        up = angle;
        Serial.println("");
        Serial.println("Set up to " + num);
      }
      else if (data.length() >= 6 && data.substring(0, 4).equals("down")) {
        String num = data.substring(5, data.length() - 1);
        int angle = num.toInt();
        down = angle;
        Serial.println("");
        Serial.println("Set down to " + num);
      }
      else {
        printHelp();
      }
      data = "";
    }
    //Serial.println(data); // Print input
  }
  delay(50);
}

void resetVars() {
  center = defCenter;
  up = defUp;
  down = defDown;
}

void printHelp() {
  Serial.println("");
  Serial.println("Enter \'vars\' to see current variable values");
  Serial.println("Enter \'commands\' to see commands");
  Serial.println("Enter \'help\' to see this page again");
}

void printVars() {
  Serial.println("");
  Serial.println("Default center angle: 42");
  Serial.println("Default up angle: 13");
  Serial.println("Default down angle: 84");
  Serial.println("Current center angle: " + String(center));
  Serial.println("Current up angle: " + String(up));
  Serial.println("Current down angle: " + String(down));
}

void printCommands() {
  Serial.println("");
  Serial.println("To change angle, enter: \'variable\'");
  Serial.println("such as \'center\', \'up\', or \'down\'");
  Serial.println("and the new angle");
  Serial.println("Enter \'reset\' to set variables to default");
}
