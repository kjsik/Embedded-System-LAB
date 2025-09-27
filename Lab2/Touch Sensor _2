#define _TOUCH_LEFT_27 27 // LEFT TOUCH 장치 Pin번호 매크로 지정(GPIO27)
#define _TOUCH_RIGHT_4 4 // RIGHT TOUCH 장치 Pin번호 매크로 지정(GPIO4)
#define _LED_R_GPIO_12 12 
#define _LED_B_GPIO_14 14

#define BUZ_GPIO 2
#define BUZ_DAC 25

int freq = 500;     // PWM 주파수 설정 500Hz
int channel = 0; // PWM 채널 설정(0~15)
int resolution = 8; // PWM duty Cycle resolution(해상도) 설정
int dutyCycle = 50;
int left = 20;
int right = 20;
char status= 'n';

void setup() {
  Serial.begin(115200);
  pinMode(_LED_R_GPIO_12, OUTPUT);
  pinMode(_LED_B_GPIO_14, OUTPUT);
  pinMode(BUZ_GPIO, OUTPUT);
  pinMode(BUZ_DAC, OUTPUT);

  digitalWrite(BUZ_GPIO, HIGH);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(BUZ_DAC, channel);

}
void loop() {
  digitalWrite(_LED_R_GPIO_12, LOW);
  digitalWrite(_LED_B_GPIO_14, LOW);

  left = touchRead(_TOUCH_LEFT_27);
  right = touchRead(_TOUCH_RIGHT_4);

  Serial.print("Left touch = ");
  Serial.print(left);
  Serial.print("   ");
  Serial.print("Right Touch = ");
  Serial.print(right);

  if(left <= 10 && right <=15)
    status = 'a';
  else if(left <= 10)
    status = 'l';
  else if(right <= 15)
    status = 'r';
  else
    status = 'n';

  switch(status){
    case 'l':
      Serial.println("Red_LED_ON");
      digitalWrite(_LED_R_GPIO_12, HIGH);
      ledcWrite(channel, dutyCycle);
      break;
    case 'r':
      Serial.println("Blue_LED_ON");
      digitalWrite(_LED_B_GPIO_14, HIGH);
      ledcWrite(channel, dutyCycle);
      break;
    default:
      ledcWrite(channel, 0);
  }

  delay(500);
}
