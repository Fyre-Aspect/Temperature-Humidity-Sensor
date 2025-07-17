


#include <DHT.h>;
//I2C LCD:
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <IRremote.hpp>

LiquidCrystal_I2C lcd(0x27,16,2); 
  
//Constants
#define DHTPIN 7     //what pin we're connected to
#define DHTTYPE DHT11   //DHT 11
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
const int IR_RECEIVE_PIN = 8;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;

//Variables
//int chk;
int h;  //Stores humidity value
int t; //Stores temperature value

void setup()
{
    Serial.begin(9600);
    Serial.println("Temperature and Humidity Sensor Test");
    dht.begin();
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);
    lcd.init();         
    lcd.noBacklight();
}

void loop()
{
    
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %, Temp: ");
    Serial.print(t);
    Serial.println(" ° Celsius");
        



    
  delay(500);
  h = dht.readHumidity();
  t = dht.readTemperature();
   if (IrReceiver.decode()) {

    if (IrReceiver.decodedIRData.protocol != UNKNOWN) {
      IrReceiver.printIRResultShort(&Serial);
      Serial.println();
      if (IrReceiver.decodedIRData.command == 0xC) toggleLED(ledPin1);
      if (IrReceiver.decodedIRData.command == 0x18) toggleLED(ledPin2);
      if (IrReceiver.decodedIRData.command == 0x5E) toggleLED(ledPin3);
      if (IrReceiver.decodedIRData.command == 0x45) {
    toggleLED(ledPin1);
    toggleLED(ledPin2);
    toggleLED(ledPin3);
    lcd.init(); 
    lcd.backlight(); 
    lcd.setCursor(0, 0);
    lcd.println("Temp&Humidity   ");
    
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(t);
    lcd.print("C");

    lcd.setCursor(6, 1);
    lcd.println("|||| ");
     
    lcd.setCursor(11, 1);
    lcd.print("H:");
    lcd.print(h);
    lcd.print("%");
    
  delay(1000);
      
      }
      if (IrReceiver.decodedIRData.command == 0x47){
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        lcd.noBacklight();
      }
      
    }
    IrReceiver.resume(); 
  }
}
void toggleLED(int ledPin) {
  digitalWrite(ledPin, !digitalRead(2));
  delay(500);
}
