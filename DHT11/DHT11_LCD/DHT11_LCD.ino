//This code is to use with DHT11 Temperature/humidity sensor with LCD i2c screen
//We measure the values of the temperature and humidity then print them on the screen every second
//Refer to Surtrtech channel on youtube or blogger for more information or how to use the LCD i2c

#include <dht.h> //DHT and LCD libraries
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

dht DHT; //Declaring the DHT as a dht type to use it later

#define DHT11_PIN 7 //Declaring where the DHT signal pin is wired

void setup(){
  Serial.begin(9600);
              lcd.begin (16,2);
            lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
            lcd.setBacklight(HIGH);
            lcd.home ();
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  int chk = DHT.read11(DHT11_PIN); //Reading data from the module
  lcd.print("Temp: ");
  lcd.print(DHT.temperature); //Showing temperature value (before that you can do some math to get the temperature in Farnheit)
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.println(DHT.humidity); //Showing humidity percentage
  lcd.print(" %");
  delay(1000); //Refreshing every 1s
}
