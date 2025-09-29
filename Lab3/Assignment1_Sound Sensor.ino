#define MIC 36
#define _LED_R_GPIO_12 12
#define _LED_B_GPIO_14 14

int led_state = 0;
int MIC_threshold = 1500;

void setup(){
  Serial.begin(115200);
  pinMode(_LED_R_GPIO_12, OUTPUT);
  pinMode(_LED_B_GPIO_14, OUTPUT);
}

void loop(){
  int sound = analogRead(MIC);
  Serial.println(sound);

  if(sound > MIC_threshold){
    if(led_state == 0){
      led_state = 1;
      digitalWrite(_LED_R_GPIO_12, HIGH);
      digitalWrite(_LED_B_GPIO_14, LOW);
      delay(100);
    }
    else{
      led_state = 0;
      digitalWrite(_LED_R_GPIO_12, LOW);
      digitalWrite(_LED_B_GPIO_14, HIGH);
      delay(100);
    }
  delay(2);
  }
}
