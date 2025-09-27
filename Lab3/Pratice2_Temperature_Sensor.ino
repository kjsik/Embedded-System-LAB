#include <SparkFunBME280.h>
#define BME280_ADDR 0x77
BME280 myBME280;

void setup(){
  Serial.begin(115200);
  myBME280.setI2CAddress(BME280_ADDR);
  myBME280.beginI2C();
}

void loop(){
  Serial.println("#BME280 Sensor Data#");
  //섭씨 온도
  Serial.print("Temperature(C): ");
  Serial.print(myBME280.readTempC(), 2);
  Serial.println("degrees C");
  //상대습도
  Serial.print("Humidity: ");
  Serial.print(myBME280.readFloatHumidity(), 2);
  Serial.println(" %");
  //기압
  Serial.print("Pressure: ");
  Serial.print(myBME280.readFloatPressure(), 2);
  Serial.println(" Pa");
  //고도
  Serial.print("Altitude: ");
  Serial.print(myBME280.readFloatAltitudeMeters(), 2);
  Serial.println(" m");
  
  Serial.println();
  delay(2000);
}
