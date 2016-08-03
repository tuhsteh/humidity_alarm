
/************************************************************
 * Read ambient temperature and humidity using DHT11 sensor, 
 * and display on LCD with I2C backpack.
 * 
 * https://learn.adafruit.com/trinket-temperature-humidity-lcd-display/overview
 *
 ************************************************************/

#include <Adafruit_LiquidCrystal.h>
#include <TinyDHT.h>


//#define DHTTYPE DHT22     // DHT 22  (AM2302)
#define DHTTYPE DHT11     // DHT 11 (RHT01)
#define TEMPTYPE 0        // Use Fahrenheit (0 for celsius)
#define DHTPIN 5          // Sensor connected to DIGITAL #5
DHT dht(DHTPIN, DHTTYPE); // Define Temp Sensor

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  //  lcd.print("hello, world!");

  dht.begin();  // Initialize DHT Teperature Sensor
}

void loop() {
  //  lcd.setCursor(0,1);
  //  lcd.print(millis() / 1000 );

  int8_t h = dht.readHumidity();               // Read humidity
  int16_t t = dht.readTemperature(TEMPTYPE);   // read temperature

  lcd.setCursor(0, 0);
  if ( t == BAD_TEMP || h == BAD_HUM ) { // if error conditions (see TinyDHT.h)
    lcd.print("Bad read on DHT");        //   print error message
  } else {
    lcd.print("Humidity: ");            // write to LCD
    lcd.setCursor(10, 0);
    lcd.print(h);
    lcd.setCursor(12, 0);
    lcd.print(" % ");
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.setCursor(7, 1);
    lcd.print(t);
    lcd.setCursor(10, 1);
    lcd.print("*C");
  }
  delay(8000);
}

