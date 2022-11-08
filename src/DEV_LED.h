#include "extras/PwmPin.h"

struct DEV_LED:Service::LightBulb{
  int lampPin;
  boolean ledFlag;

  SpanCharacteristic *lampPower;

  DEV_LED(int lampPin):Service::LightBulb() {
    lampPower=new Characteristic::On();
    this->lampPin=lampPin;
    pinMode(lampPin,OUTPUT);
  };

  boolean update() {
    digitalWrite(lampPin,lampPower->getNewVal());
    Serial.println("update");
    return(true);
  };

  void loop() {
    int touchnValue = touchRead(15);
    Serial.println(touchnValue);
    Serial.println(ledFlag);

    if (touchnValue == 0 && ledFlag ) {       // 检测按键按下
        lampPower->setVal(!lampPower->getNewVal());
        digitalWrite(this->lampPin,lampPower->getNewVal());

        ledFlag = false;
    };

    if (touchnValue != 0 && !ledFlag) {
      ledFlag = true;
    };

  };

   void button(int pin, int pressType) override {}
};
