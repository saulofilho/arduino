//DHT11 Sensor:
#include "DHT.h"
#define DHTPIN 12     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);


//I2C LCD:
#include <Wire.h> // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

// Set the LCD I2C address
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Mohamed Chaara Temp and Humidity Sensor Test");

  dht.begin();
}

void loop() {
    // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  int t = dht.readTemperature();

    // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:

   lcd.print("Temp: ");
   lcd.print(t);
   lcd.print("C");
  
  // set the cursor to (16,1):
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
    
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("C, Humidity: ");
  Serial.print(h);
  Serial.println("%");

}

