#define _D0_PIR_GPIO_2 2
#define _D1_PIR_GPIO_15 15

void setup(){
  pinMode(_D0_PIR_GPIO_2, INPUT);
  pinMode(_D1_PIR_GPIO_15, OUTPUT);
}


void loop(){
  int motionState = digitalRead(_D0_PIR_GPIO_2);
  if(motionState == HIGH){
    digitalWrite(_D1_PIR_GPIO_15, HIGH);
    delay(500);
  }
  else{
    digitalWrite(_D1_PIR_GPIO_15, LOW);
    delay(500);
  }
}
