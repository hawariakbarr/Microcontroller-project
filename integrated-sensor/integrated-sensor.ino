//initialized lcd library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <SD.h>
#include <SPI.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


//File svData;

//initialized rain gauge sensor
int rainPin = 2; 
int inputRead = 0;
float counter = 0;
int currentState = 0;
int previousState = 0;

//initialized ultrasonic sensor
#define trigpin1 11
#define echopin1 12

//initialized dht sensor
#include <DHT.h>
#define DHTPIN 10
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//declaration variabel
double duration1, waterlevel1;
double duration2, waterlevel2;
float temp, humadity;
float levelOfWater1;
float levelOfWater2;
int hum;

//setup program
void setup() {
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print("Pemantau Curah Hujan");
  lcd.setCursor(3, 1);
  lcd.print("dan Ketinggian");
  lcd.setCursor(3, 2);
  lcd.print("Permukaan Air");
  lcd.setCursor(5, 3);
  lcd.print("-by akbar-");
  delay(4000);
  lcd.clear();
  Serial.begin(115200);
  dht.begin();
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
}
void loop() {
  ultrasonic1();
  waterlevel1 = levelOfWater1;
  dht_config();
  hum = humidity;
  rain_gauge();
  
  //  ultrasonic2(); 
  //  waterlevel2 = levelOfWater2;

  float transmit[4] = {humidity, temp, waterlevel1};
  Serial.write((uint8_t*)transmit, 4 * sizeof(float));

  lcd_print();
  
  Serial.print("Ketinggian air:");
  Serial.print(tinggiair1);
  Serial.println(" centimeter");
  Serial.print("Kelembapan:");
  Serial.print(kelembapan);
  Serial.print(" %");
  Serial.print(" ");
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" C");
}
