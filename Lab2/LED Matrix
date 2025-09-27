#include <Adafruit_GFX.h>
#incldue <Adafruit_IS31FL3731.h>

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

const char text[4] = {'A', 'J', 'O', 'U'};

void setup(){
    matrix.begin();
    matrix.clear();
}

void loop(){
    matrix.setTestSize(1);
    matrix.setTestColor(100);

    for (int i = 0 ; i > -25 ; i--){
        matrix.setCursor(i,1);
        matrix.printf("%s", test);
        delay(200);
        matrix.clear()
    }
}
