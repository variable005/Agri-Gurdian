#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <RTClib.h>

// Pin Definitions based on your diagram.json
#define I2C_SDA 8
#define I2C_SCL 9
#define DHT_PIN 4
#define DS18B20_PIN 5
#define MQ2_PIN 1
#define LDR_PIN 2

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DHT dht(DHT_PIN, DHT22);
OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);
RTC_DS1307 rtc;

void setup() {
  Serial.begin(115200);
  
  // S2 specific I2C init
  Wire.begin(I2C_SDA, I2C_SCL); 

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(20, 20);
  display.println("AGRITECH EDGE");
  display.display();

  dht.begin();
  sensors.begin();
  if (!rtc.begin()) {
    Serial.println("RTC fail");
  }
  
  delay(2000);
}

void loop() {
  // 1. Collect Stats
  DateTime now = rtc.now();
  float hum = dht.readHumidity();
  float airTemp = dht.readTemperature();
  sensors.requestTemperatures();
  float soilTemp = sensors.getTempCByIndex(0);
  int gasVal = analogRead(MQ2_PIN);
  int lightVal = analogRead(LDR_PIN);

  // 2. Display Stats Dashboard
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(now.timestamp(DateTime::TIMESTAMP_TIME));
  display.drawLine(0, 10, 128, 10, WHITE);

  display.setCursor(0, 15);
  display.printf("AIR: %.1fC | H:%.0f%%", airTemp, hum);
  display.setCursor(0, 30);
  display.printf("SOIL: %.1fC", soilTemp);
  display.setCursor(0, 45);
  display.printf("LDR: %d | GAS: %d", lightVal, gasVal);
  
  display.drawLine(0, 56, 128, 56, WHITE);
  display.setCursor(15, 57);
  display.print("LOCAL AI ACTIVE");
  display.display();

  // 3. JSON for Local AI Response
  Serial.printf("{\"ts\":\"%s\",\"at\":%.1f,\"h\":%.1f,\"st\":%.1f,\"l\":%d,\"g\":%d}\n", 
                now.timestamp().c_str(), airTemp, hum, soilTemp, lightVal, gasVal);

  delay(3000); 
}
