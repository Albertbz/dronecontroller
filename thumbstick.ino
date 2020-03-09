#include "BMI088.h"

//int buttonUpPin = 8;
//int buttonDownPin = 4;
//int buttonUpState = 0;
//int buttonDownState = 0;

float ax = 0, ay = 0, az = 0;
float gx = 0, gy = 0, gz = 0;
//float height = 0;
int16_t temp = 0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(buttonUpPin, INPUT);
  //pinMode(buttonDownPin, INPUT);
  Wire.begin();
  Serial.begin(250000);
  bmi088.initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  //buttonUpState = digitalRead(buttonUpPin);
  //buttonDownState = digitalRead(buttonDownPin);
  //int x = analogRead(A0);
  //int y = analogRead(A1);
  float x = map(analogRead(A0)+1,253,768,-100,100);
  float y = map(analogRead(A1)+1,253,768,-100,100);
  
  /*if (buttonUpState == HIGH) {
    height = 10;
  }
  else if (buttonDownState == HIGH) {
    height = -10;
  }
  else {
    height = 0;
  }*/
  
  bmi088.getAcceleration(&ax, &ay, &az);
  bmi088.getGyroscope(&gx, &gy, &gz);
  temp = bmi088.getTemperature();

  gz = map(gz,500,-500,-500,500);

  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.print(ax);
  Serial.print(",");
  Serial.print(ay);
  Serial.print(",");
  Serial.print(az);
  Serial.print(",");
  Serial.print(gx);
  Serial.print(",");
  Serial.print(gy);
  Serial.print(",");
  Serial.print(gz);
  Serial.print(",");
  Serial.print(temp);
  /*Serial.print(",");
  Serial.print(height);*/
  Serial.println();
  
  delay(200);
}
