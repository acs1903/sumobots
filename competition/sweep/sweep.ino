#include "Servo.h"

Servo servo;
#define sensor A0

long START_TIME = 0;
long OPP_FOUND = false;
bool SWEEP_CLOCKWISE = true; // above 90

void setup() {
  Serial.begin(9600);
  myservo.attach(6);
}

void loop() {
  if (START_TIME == 0)
  { 
    START_TIME = millis();
    float reading = analogRead(sensor);
    float previous_reading = reading;
    float current_reading = reading;
  }

  if (millis() - START_TIME > 500)
  {
    if (SWEEP_CLOCKWISE)
    {
      SWEEP_CLOCKWISE = false;
      servo.write(90);
      servo.write(85);      
    }
    else
    {
      SWEEP_CLOCKWISE = true;
      servo.write(90);
      servo.write(95);
    }
  }
  else
  {
    if (SWEEP_CLOCKWISE)
    {
      servo.write(95);
    }
    else
    {
      servo.write(85);
    }
  }
  float reading = analogRead(sensor);
  current_reading = reading;
  if (current_reading - previous_reading > 50) {
    // robot found, turn there, move there
  }
}
