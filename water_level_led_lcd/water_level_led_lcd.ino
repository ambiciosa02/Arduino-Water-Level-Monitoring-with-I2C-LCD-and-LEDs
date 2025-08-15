#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address 0x27 is common. Change if needed.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
const int waterSensorPin = A0;
const int led1Pin = 8;
const int led2Pin = 9;

// Water level threshold
const int highLevelThreshold = 600;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
    lcd.init();             // Initialisation de l'écran
  lcd.backlight();  // Turn on LCD backlight
  Serial.begin(9600);
}

void loop() {
  int waterLevel = analogRead(waterSensorPin);
  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water Level:");
  lcd.print(waterLevel);

  if (waterLevel > highLevelThreshold) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: FULL");
  } else {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: LOW ");
  }

  delay(1000);
}
