#include "WiFiConnect.h" 

#include <WiFiClient.h>                      
#ifdef ARDUINO_ARCH_ESP8266  
#include <ESP8266HTTPClient.h>
#else  
#include <HTTPClient.h>
#endif

WiFiConnect wc;
WiFiClient client;
HTTPClient http;
const int buttonPin1 = 4;  
const int buttonPin2 = 5;  
const int buttonPin3 = 2 ;  
//const int buttonPin4 = 2;  
//const int buttonPin5 = 1;  
//const int buttonPin6 = 0;  

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
//int buttonState4 = 0;
//int buttonState5 = 0;
//int buttonState6 = 0;
 
void configModeCallback(WiFiConnect *mWiFiConnect) {
  Serial.println("Entering Access Point");
}


void startWiFi(boolean showParams = false) {
 
  wc.setDebug(true);
  wc.setAPCallback(configModeCallback);

  //wc.resetSettings(); //helper to remove the stored wifi connection, comment out after first upload and re upload

    /*
       AP_NONE = Continue executing code
       AP_LOOP = Trap in a continuous loop - Device is useless
       AP_RESET = Restart the chip
       AP_WAIT  = Trap in a continuous loop with captive portal until we have a working WiFi connection
    */
    if (!wc.autoConnect()) { // try to connect to wifi
      wc.setAPName("SmartButton");
      wc.startConfigurationPortal(AP_WAIT);//if not connected show the configuration portal
    }
}


void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(100);
  }
  Serial.println("....");
pinMode(buttonPin1, INPUT_PULLUP);
pinMode(buttonPin2, INPUT_PULLUP);
pinMode(buttonPin3, INPUT_PULLUP);
//pinMode(buttonPin4, INPUT_PULLUP);
//pinMode(buttonPin5, INPUT_PULLUP);
//pinMode(buttonPin6, INPUT_PULLUP);
  delay (5000);
  startWiFi();

}

void loop() {
    delay(100);


buttonState1 = digitalRead(buttonPin1);
buttonState2 = digitalRead(buttonPin2);
buttonState3 = digitalRead(buttonPin3);
//buttonState4 = digitalRead(buttonPin4);
//buttonState5 = digitalRead(buttonPin5);
//buttonState6 = digitalRead(buttonPin6);
Serial.println("================== Button State ========================");
Serial.println(buttonState1);
Serial.println(buttonState2);
Serial.println(buttonState3);
//Serial.println(buttonState4);
//Serial.println(buttonState5);
//Serial.println(buttonState6);
Serial.println("================== Button State ========================");
  
    if (WiFi.status() == WL_CONNECTED) {



  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
 // if (buttonState == HIGH) {
    // turn LED on
  //   Serial.println("button pushed");
 // } else {
    // turn LED off
 //  Serial.println("button no pushed");
//  }
    }else{

       wc.setAPName("IntralogicSmartButton");
      if (!wc.autoConnect()) wc.startConfigurationPortal(AP_WAIT);
      
    }
  
  delay (500);
}
