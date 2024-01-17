#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);  // Initializing LCD with pin connections

#define sensor A0  // Defining the analog input pin for the temperature sensor

byte degree[8] = {  // Creating a custom character for the degree symbol
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  lcd.begin(16,2);  // Initializing the LCD with 16 columns and 2 rows
  lcd.createChar(1, degree);  // Loading the custom degree symbol to LCD
  lcd.setCursor(0,0);
  lcd.print(" Digital ");  // Displaying "Digital" on the first line of LCD
  lcd.setCursor(0,1);
  lcd.print(" Thermometer ");  // Displaying "Thermometer" on the second line of LCD
  delay(2000);  // Delay for 2000 milliseconds (2 seconds)
  lcd.clear();  // Clearing the LCD screen
}

void loop() {
  /*---------Temperature-------*/
  float reading = analogRead(sensor);  // Reading analog value from the temperature sensor
  float temperature = reading * (5.0 / 1023.0) * 100;  // Converting analog value to temperature in Celsius
  delay(10);  // Delay for 10 milliseconds
  
  /*------Display Result------*/
  lcd.clear();  // Clearing the LCD screen
  lcd.setCursor(2,0);
  lcd.print("Temperature");  // Displaying "Temperature" on the first line of LCD
  lcd.setCursor(4,1);
  lcd.print(temperature);  // Displaying the temperature value on the second line of LCD
  lcd.write(1);  // Displaying the custom degree symbol
  lcd.print("C");  // Displaying "C" for Celsius
  delay(1000);  // Delay for 1000 milliseconds (1 second)
}

