#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/52776341-1635-48d8-9be1-ce2e9acb5795 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool lEDStatus;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
int LED1 = 8;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  // initialize specified pin as an output.
  pinMode(LED1, OUTPUT);
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  Serial.println("Hello");
}

void onLEDStatusChange() {
  if (lEDStatus == true) {
      Serial.println("High");
      digitalWrite(LED1, HIGH);  
  } else {
      Serial.println("Low");
      digitalWrite(LED1, LOW);  
  }
  delay(1000);
}

