#include <Servo.h>
int inches = 0;
int cm = 50;
// Declaramos la variable para controlar el servo
Servo servo1;
Servo servo2;

long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);  // Clear the trigger
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // Sets the pin on HIGH state for 10 micro seconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  // Reads the pin, and returns the sound wave travel time in microseconds
  return pulseIn(pin, HIGH);
}
void setup()
{
  pinMode(4, INPUT);
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(2);
 
   
}
void loop()
{
// measure the ping time in cm
    cm = 0.01723 * readUltrasonicDistance(4);
//product size 30cm
if (cm <= 20) {
   servo2.write(0);
   servo1.write(90);
  }
//product size 20cm
 if (cm <= 30&& cm >20) {
   servo1.write(0);
   servo2.write(90);
   }
//product size 10cm 
  if (cm <= 40 && cm >30) {
    servo1.write(0);
    servo2.write(0);
    }
   delay(100);
 }
