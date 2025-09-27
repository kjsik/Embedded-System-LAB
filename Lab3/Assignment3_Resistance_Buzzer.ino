#define _A0_RES_ADC_36 36
#define BUZ_GPIO 2
#define BUZ_DAC 25

int freq = 500;
int channel = 0;
int resolution = 8;
int dutyCycle = 100;


void setup(){
  Serial.begin(115200);
  pinMode(BUZ_GPIO, OUTPUT);
  pinMode(BUZ_DAC, OUTPUT);

  digitalWrite(BUZ_GPIO, HIGH);
  
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(BUZ_DAC, channel);
}

void loop(){
  ledcWrite(channel, dutyCycle);
  int resistor = analogRead(_A0_RES_ADC_36);

  Serial.println(resistor);

  ledcWriteTone(channel, resistor);
  delay(50);
}
