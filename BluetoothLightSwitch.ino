#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);

  servo.attach(13);
  servo.write(42);
  servo.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);

  if(Serial.available()>0){
    char data = Serial.read();
    switch(data){
      case '0': servo.attach(13);servo.write(74);delay (1500);servo.write(42);delay (500);digitalWrite(13, LOW);servo.detach();break;
      case '1': servo.attach(13);servo.write(13);delay (1500);servo.write(42);delay (500);digitalWrite(13, LOW);servo.detach();break;
      default: break;
    }
    Serial.println(data);
  }
  delay(50);
}
