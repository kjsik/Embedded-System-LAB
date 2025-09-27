int freq = 2000; // PWM 주파수 설정(2000Hz)
int channel = 0; // PWM 채널 설정(0~15)
int resolution = 8; // PWM duty cycle resolution(해상도) 설정, 8bit=0~255
int tone[] = {261, 294, 330, 349, 392, 440, 494, 523};

void setup() { 
  ledcSetup(channel,freq,resolution); // PWM 채널, 주파수, 해상도 설정(ledcSetup)
  ledcAttachPin(25,channel); // GPIO핀, 채널 설정
  pinMode(2, OUTPUT); // 부저 전원인가를 위한 GPIO 제어핀 제어
  digitalWrite(2, HIGH); // 부저 전원 ON
}

void loop() {

  ledcWrite(channel, 125);
  for(int i=0; i<sizeof(tone)/sizeof(tone[0]) ; i++){
    freq=tone[i];
    ledcWriteTone(channel, freq);
    delay(400);
  }

  digitalWrite(2, LOW); // 부저 전원 OFF 
}
