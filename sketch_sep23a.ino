#include <Servo.h>
#include <Wire.h>

Servo myservo;
#define ir_car1 5
#define ir_car2 6
#define ir_car3 7
#define ir_car4 8

const int SERVO_PIN = 13; 
Servo servo;
int angle = 0; 
int lastButtonState; 
int currentButtonState; 
int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
int flag1 = 0, flag2 = 0;

void setup() {
 Serial.begin(9600);
 pinMode(ir_car1, INPUT);
 pinMode(ir_car2, INPUT);
 pinMode(ir_car3, INPUT);
 pinMode(ir_car4, INPUT);
 myservo.attach(3);
 myservo.write(90);
 
Read_Sensor();
 Serial.begin(9600); 

 servo.attach(SERVO_PIN); 
 servo.write(angle);
 currentButtonState = digitalRead(BUTTON_PIN); 
 }
 
void loop() {
  
lastButtonState = currentButtonState; 
 currentButtonState = digitalRead(BUTTON_PIN); 
 if(lastButtonState == HIGH && currentButtonState == LOW) 
 {
 Serial.println("The button is pressed");
 if(angle == 0)
 angle = 90;
 else
 if(angle == 90)
 angle = 0;
 
 servo.write(angle);
 }
 
}
void Read_Sensor() {
 S1 = 0, S2 = 0, S3 = 0, S4 = 0;
 if (digitalRead(ir_car1) == 0) {
 S1 = 1;
 }
 if (digitalRead(ir_car2) == 0) {
 S2 = 1;
 }
 if (digitalRead(ir_car3) == 0) {
 S3 = 1;
 }
 if (digitalRead(ir_car4) == 0) {
 S4 = 1;
 }
}



 
