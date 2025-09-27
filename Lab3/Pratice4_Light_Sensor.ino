#define _A0_LIGHT_ADC_36 36;

void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.print("Light Sensor Value = ");
  Serial.println(analogWrite(_A0_LIGHT_ADC_38));
  delay(100);
}
