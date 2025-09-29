#include <SparkFunBME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

#define ISSI_ADDR_DEFAULT 0x74
#define BME280_ADDR 0x77
Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();
BME280 myBME280;
static const uint8_t PROGMEM

smile_bmp[] = // 이모티콘 배열 선언(생성 사이트 참고)
{ 
  B00000000,
  B01000010,
  B10100101,
  B00000000,
  B01000010,
  B00111100,
  B00000000,
  B00000000
};

int temp_Threshold = 29;
int humn_threshold = 60;

void setup(){
  Serial.begin(115200);
  matrix.begin();
  matrix.clear();
  myBME280.setI2CAddress(BME280_ADDR);
  myBME280.beginI2C();
}

void loop(){
  float temp_c = myBME280.readTempC();
  float humn = myBME280.readFloatHumidity();
  matrix.setRotation(0);
  matrix.clear();

  Serial.print("temp : ");
  Serial.print(temp_c);
  Serial.print(", humn : ");
  Serial.println(humn);

  if (temp_c < temp_Threshold && humn < humn_threshold){
      matrix.drawBitmap(0, 0, smile_bmp, 8, 8, 100); 
      delay(1000);
  }
  delay(2000);
}
