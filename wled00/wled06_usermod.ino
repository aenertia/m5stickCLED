/*
 * This file allows you to add own functionality to WLED more easily
 * See: https://github.com/Aircoookie/WLED/wiki/Add-own-functionality
 * EEPROM bytes 2750+ are reserved for your custom use case. (if you extend #define EEPSIZE in wled01_eeprom.h)
 * bytes 2400+ are currently ununsed, but might be used for future wled features
 */

//Use userVar0 and userVar1 (API calls &U0=,&U1=, uint16_t)
//#include <M5StickC.h>
//#include <SPI.h>
//#include <Wire.h>
#include <Seeed_BME280.h>                                                       // required by BME280 library

// #define ASCII_ESC 27
//
// #define MYALTITUDE  150.50
//
// char bufout[10];
//
// BME280<> BMESensor;                                                     // instantiate sensor
 BME280 bme280;
// extern TwoWire i2ctwo;// use SCL2 & SDA2
#define SDA 33
#define SCL 32
//
// TwoWire i2ctwo=TwoWire(0);
int periodUser = 3000;
unsigned long time_now = 0;
void userBeginPreConnection()
{
   M5.begin();
   //start i2c
   //I2cTwo = TwoWire(1); // initialize using the second i2c peripheral
  pinMode(SDA,INPUT_PULLUP);
  pinMode(SCL,INPUT_PULLUP);
   // i2ctwo.begin(SDA2,SCL2,50000);
   // Wire.begin(SDA_PIN, SCL_PIN);
  // //Start OLED
   M5.Lcd.setRotation(0);
   M5.Lcd.fillScreen(BLACK);
   M5.Lcd.setTextColor(WHITE, BLACK);

   // Init gyro
   M5.IMU.Init();
   //Setup Screen
   M5.Lcd.setCursor(0, 2);
   M5.Lcd.printf("ESP32-LED \n");

   //Setup i2c
  // Wire.begin(33,32);                                                      // initialize I2C that connects to sensor
  // BMESensor.begin(); // initalize bme280 sensor
  // //Dim Screen
   M5.Axp.ScreenBreath(8);
   //M5.Axp.SetSleep();

}

void userBegin()
{
  IPAddress ipadr = WiFi.localIP();

  M5.Lcd.setRotation(1);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println((String)ipadr[0] + "." + (String)ipadr[1] + "." + (String)ipadr[2] + "." + (String)ipadr[3]);
  M5.Lcd.setRotation(0);

time_now = millis();
}

void userLoop()
{



int16_t accX = 0;
int16_t accY = 0;
int16_t accZ = 0;

int16_t gyroX = 0;
int16_t gyroY = 0;
int16_t gyroZ = 0;

int16_t accXlast = 0;
int16_t accYlast = 0;
int16_t accZlast = 0;

int16_t gyroXlast = 0;
int16_t gyroYlast = 0;
int16_t gyroZlast = 0;

 while(millis() < time_now + periodUser){
time_now = millis();

  //wakeup grove i2c bme280
  bme280.init();
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.setTextSize(1);

  //write gryo
    //Clear
  //M5.Lcd.fillRect(0, 30, 80, 90, BLACK);
  //M5.Lcd.setCursor(0, 30);
  //colT[0], colT[1], colT[2], colT[3]
  M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
  M5.IMU.getAccelData(&accX,&accY,&accZ);

  M5.Lcd.setTextColor(GREEN);
  //M5.Lcd.printf("\b\b\b\b\b\b\b\b\b\b");
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.printf("G:");
  M5.Lcd.fillRect(20,20,50,10, BLACK);
  M5.Lcd.fillRect(20,20,map(colT[1],0,255,0,50),10, GREEN);
  //M5.Lcd.printf("%d",colT[1]);
  M5.Lcd.printf("\n");
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setCursor(0, 30);
  M5.Lcd.printf("R:");
  M5.Lcd.fillRect(20,30,50,10, BLACK);
  M5.Lcd.fillRect(20,30,map(colT[0],0,255,0,50),10, RED);
  M5.Lcd.printf("\n");
  M5.Lcd.setTextColor(BLUE);
  M5.Lcd.setCursor(0, 40);
  M5.Lcd.printf("B:");
  M5.Lcd.fillRect(20,40,50,10, BLACK);
  M5.Lcd.fillRect(20,40,map(colT[2],0,255,0,50),10, BLUE);
  M5.Lcd.printf("\n");
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(0, 50);
  M5.Lcd.printf("W:");
  M5.Lcd.fillRect(20,50,50,10, BLACK);
  M5.Lcd.fillRect(20,50,map(colT[3],0,255,0,50),10, WHITE);
  M5.Lcd.printf("\n");
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setCursor(0, 60);
  M5.Lcd.printf("Br:");
  M5.Lcd.fillRect(20,60,50,10, BLACK);
  M5.Lcd.fillRect(20,60,map(bri,0,255,0,50),10, YELLOW);
  M5.Lcd.printf("\n");
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(0, 80);
  // M5.Lcd.println("X  Y  Z");
  // M5.Lcd.printf("%.2f %.2f %.2f", map((((float) gyroX) * M5.IMU.gRes),-1000,1000,0,255), map((((float) gyroY) * M5.IMU.gRes),-1000,1000,0,255),map((((float) gyroZ) * M5.IMU.gRes),-1000,1000,0,255));
  M5.Lcd.setTextSize(2);
    float pressure;
  M5.Lcd.fillRect(0,90,80,20, BLACK);
    //get and print temperatures
    M5.Lcd.printf("Temp: %.2f \n", bme280.getTemperature());
    // M5.Lcd.printf(bme280.getTemperature());
    // M5.Lcd.println("C");//The unit for  Celsius because original arduino don't support special symbols
    M5.Lcd.println("");
  M5.Lcd.setTextSize(1);
  M5.Lcd.fillRect(0,130,80,10, BLACK);
    //get and print atmospheric pressure data
    M5.Lcd.printf("Pres %.3d Pa \n", bme280.getPressure());

    // //get and print altitude data
    // M5.Lcd.printf("Altitude: ");
    // M5.Lcd.printf(bme280.calcAltitude(pressure));
    // M5.Lcd.println("m");
  M5.Lcd.setCursor(0, 140);

    //get and print humidity data
    M5.Lcd.printf("Humidity: % \n", bme280.getHumidity());
     M5.Lcd.fillRect(0,150,60,10, BLACK);
      M5.Lcd.fillRect(0,150,map(bme280.getHumidity(),0,100,0,80),10, BLUE);
  // M5.Lcd.setCursor(0, 10);
  // Set up what we want to send. See ir_Daikin.cpp for all the options.
//   ac.on();
//   ac.setFan(1);
//   ac.setMode(kDaikinCool);
//   ac.setTemp(25);
//   ac.setSwingVertical(false);
//   ac.setSwingHorizontal(false);
//
//   // Set the current time to 1:33PM (13:33)
//   // Time works in minutes past midnight
//   ac.setCurrentTime(13 * 60 + 33);
//   // Turn off about 1 hour later at 2:30PM (14:30)
//   ac.enableOffTimer(14 * 60 + 30);
//
//   // Display what we are going to send.
//   //Serial.println(ac.toString());
//
//   // Now send the IR signal.
// #if SEND_DAIKIN
//   ac.send();
// #endif // SEND_DAIKIN
// BMESensor.refresh();                                                  // read current sensor data
// sprintf(bufout,"%c[1;0H",ASCII_ESC);
// Serial.print(bufout);
//
// Serial.print("Temperature: ");
// Serial.print(BMESensor.temperature);                                  // display temperature in Celsius
// Serial.println("C");
//
// Serial.print("Humidity:    ");
// Serial.print(BMESensor.humidity);                                     // display humidity in %
// Serial.println("%");
//
// Serial.print("Pressure:    ");
// Serial.print(BMESensor.pressure  / 100.0F);                           // display pressure in hPa
// Serial.println("hPa");
//
// float relativepressure = BMESensor.seaLevelForAltitude(MYALTITUDE);
// Serial.print("RelPress:    ");
// Serial.print(relativepressure  / 100.0F);                             // display relative pressure in hPa for given altitude
// Serial.println("hPa");
//
// Serial.print("Altitude:    ");
// Serial.print(BMESensor.pressureToAltitude(relativepressure));         // display altitude in m for given pressure
// Serial.println("m");
}
}
