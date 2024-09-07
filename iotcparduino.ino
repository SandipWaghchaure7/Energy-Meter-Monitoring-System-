#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define ANALOG_PIN_CURRENT A0
#define ANALOG_PIN_VOLTAGE A1

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  float voltage = getVoltage();
  float current = getCurrent();
  float power = voltage * current;


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(voltage);
  lcd.print("V ");
  lcd.setCursor(0, 1);
  lcd.print("I:");
  lcd.print(current);
  lcd.print("A ");

  
  Serial.print(voltage);
  Serial.print(",");
  Serial.print(current);
  Serial.print(",");
  Serial.println(power);

  delay(2000); 
}


float getCurrent() {
  int sensorValue = analogRead(ANALOG_PIN_CURRENT);
  float voltage = sensorValue * (5.0 / 1023.0); 
  float current = (voltage - 1.5) / 0.185; 
  return current;
}

float getVoltage() {
  int sensorValue = analogRead(ANALOG_PIN_VOLTAGE);
  float voltage = sensorValue * (5.0 / 1023.0) * 5.2; 
  return voltage;
}

