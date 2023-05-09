 #define BLYNK_USE_DIRECT_CONNECT

// Imports
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
// #include <Servo.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleSerialBLE.h>
#include "./TinyGPS.h"                 // Use local version of this library
#include "./CartDef.h"


int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 13;
int motor2pin2 = 12;

int motor1en = 5;
int motor2en = 9;

bool enabled = true;

SoftwareSerial bluetoothSerial(10, 11);

// Killswitch Hook
BLYNK_WRITE(V1) {
  enabled = !enabled;
  
  //Stop the wheels
  stop();
}

BLYNK_WRITE(V2) {
  GpsParam gps(param);
  
  Serial.println("Received remote GPS: ");
  
  // Print 7 decimal places for Lat
  Serial.print(gps.getLat(), 7); Serial.print(", "); Serial.println(gps.getLon(), 7);

  GeoLoc phoneLoc;
  phoneLoc.lat = gps.getLat();
  phoneLoc.lon = gps.getLon();

  drive();
}

void drive() {
  analogWrite(motor1en,200);
  analogWrite(motor2en,40);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);

  analogWrite(motor1en,40);
  analogWrite(motor2en,200);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(1000);
}

void stop() {
  // now turn off motors
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);  
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor1en, OUTPUT);
  pinMode(motor2en, OUTPUT);

  // Bluetooth
  bluetoothSerial.begin(9600);
  Blynk.begin(bluetoothSerial, auth);

}

void loop() {

  Blynk.run();

  
  

}
