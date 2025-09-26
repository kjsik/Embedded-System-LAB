#define _LED_R_GPIO_12 12
#define _LED_G_GPIO_13 13
#define _LED_B_GPIO_14 14

int freq = 500;
int ledChannel = 0;
int resolution = 8;

void setup() {

  pinMode(_LED_R_GPIO_12, OUTPUT);
  pinMode(_LED_G_GPIO_13, OUTPUT);
  pinMode(_LED_B_GPIO_14, OUTPUT);
  digitalWrite(_LED_R_GPIO_12, LOW);
  digitalWrite(_LED_G_GPIO_13, LOW);
  digitalWrite(_LED_B_GPIO_14, LOW);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(_LED_R_GPIO_12, ledChannel);
  ledcSetup(ledChannel+1, freq, resolution);
  ledcAttachPin(_LED_G_GPIO_13, ledChannel+1);
  ledcSetup(ledChannel+2, freq, resolution);
  ledcAttachPin(_LED_B_GPIO_14, ledChannel+2);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {

    ledcWrite(ledChannel, dutyCycle);
    ledcWrite(ledChannel+1, dutyCycle);
    ledcWrite(ledChannel+2, dutyCycle);

    delay(7);
  }
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {

    ledcWrite(ledChannel, dutyCycle);
    ledcWrite(ledChannel+1, dutyCycle);
    ledcWrite(ledChannel+2, dutyCycle);

    delay(7);
  }

}
