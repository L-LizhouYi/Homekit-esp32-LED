#include <Arduino.h>
#include <HomeSpan.h>
#include <DEV_LED.h>


void setup() {
  Serial.begin(115200);

  // homeSpan.comModeLife();
  // homeSpan.setWifiCredentials();
  homeSpan.setLogLevel(1);

  homeSpan.begin();

  homeSpan.enableAutoStartAP();   // 启动热点配置模式
  homeSpan.setPairingCode("20021128");  // 配件链接码


  

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::FirmwareRevision("1.2.0");
      new Characteristic::Identify(true);
      new Characteristic::Manufacturer("Apple");
      new Characteristic::Model("Apple-TGDD_Led-01");
      new Characteristic::SerialNumber("TGDD-1001");


    // new DEV_LED(LED_BUILTIN);
    new DEV_LED(13);




  // new SpanAccessory();                              // Begin by creating a new Accessory using SpanAccessory(), no arguments needed
  
  //   new Service::AccessoryInformation();            // HAP requires every Accessory to implement an AccessoryInformation Service, with the required Identify Characteristic
  //     new Characteristic::Identify();                 // Create the required Identify  

  //   new Service::LightBulb();                       // Create the Light Bulb Service
  //     new Characteristic::On(true);                       // This Service requires the "On" Characterstic to turn the light on and off
  //     (new Characteristic::Brightness(50))->setRange(20,100,5);    

  //   new Service::Fan();
  //     new Characteristic::Active();
  //     (new Characteristic::RotationSpeed(50))->setRange(0,100,25); 



}

void loop() {
  homeSpan.poll();
}