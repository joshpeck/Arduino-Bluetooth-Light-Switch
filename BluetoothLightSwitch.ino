#include <Servo.h>

Servo servo;

#define COMMAND_SIZE 21 // Size of command buffer
#define PRINT_SIZE 101 // Size of command buffer

//Variables
int defCenter = 42;
int defUp = 13;
int defDown = 84;

int center = defCenter;
int up = defUp;
int down = defDown;

char buf1[COMMAND_SIZE];  // Allow up to 21 character commands
char buf2[PRINT_SIZE];    // Allow up to 101 character print statements
int chars;                // Keep track of how many characters we have used before a ','

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //BAUD rate
  
  chars = 0;
  memset(buf1, 0, COMMAND_SIZE);
  memset(buf2, 0, PRINT_SIZE);

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
    if(chars == 0)
      Serial.println("");
    char c = Serial.read();
    buf1[chars] = c;
    chars++;
    //memset(buf2, 0, PRINT_SIZE);
    //sprintf(buf2, "Current command line is: \"%s\" with latest char \"%c\"", buf1, c);
    //Serial.println(buf2);
    if (c == ',') {
      if (!strncmp(buf1,"on",2)) {
        Serial.println("Turning on");
        servo.attach(13);
        servo.write(up);
        delay (1500);
        servo.write(center);
        delay (500);
        digitalWrite(13, LOW);
        servo.detach();
      }
      else if (!strncmp(buf1,"off",3)) {
        Serial.println("Turning off");
        servo.attach(13);
        servo.write(down);
        delay (1500);
        servo.write(center);
        delay (500);
        digitalWrite(13, LOW);
        servo.detach();
      }
      else if (!strncmp(buf1,"vars",4)) {
        printVars();
      }
      else if (!strncmp(buf1,"reset",5)) {
        Serial.println("Reset variables");
        resetVars();
      }
      else if (!strncmp(buf1,"commands",8)) {
        printCommands();
      }
      else if (strlen(buf1) >= 8 && !strncmp(buf1,"center",6)) {
        int angle = atoi(buf1+7);
        center = angle;
        memset(buf2, 0, PRINT_SIZE);
        sprintf(buf2, "Set \"center\" to %d", angle);
        Serial.println(buf2);
      }
      else if (strlen(buf1) >= 4 && !strncmp(buf1,"up",2)) {
        int angle = atoi(buf1+3);
        up = angle;
        memset(buf2, 0, PRINT_SIZE);
        sprintf(buf2, "Set \"up\" to %d", angle);
        Serial.println(buf2);
      }
      else if (strlen(buf1) >= 6 && !strncmp(buf1,"down",4)) {
        int angle = atoi(buf1+5);
        down = angle;
        memset(buf2, 0, PRINT_SIZE);
        sprintf(buf2, "Set \"down\" to %d", angle);
        Serial.println(buf2);
      }
      else {
        printHelp();
      }
      chars = 0;
      memset(buf1, 0, COMMAND_SIZE);
    }
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
  Serial.println("Current center angle: " + String(center) + "");
  Serial.println("Current up angle: " + String(up) + "");
  Serial.println("Current down angle: " + String(down) + "");
}

void printCommands() {
  Serial.println("");
  Serial.println("To change angle, enter: \'variable\'");
  Serial.println("such as \'center\', \'up\', or \'down\'");
  Serial.println("and the new angle");
  Serial.println("Enter \'reset\' to set variables to default");
}
