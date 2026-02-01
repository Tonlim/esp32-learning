/*
Goal: set up ESP32 as access point, run a web server on it, have button on web page that turns led on and off
To be used with board "DOIT ESP32 DEVKIT V1"

Inspiration:
- https://randomnerdtutorials.com/esp32-access-point-ap-web-server/
- Examples > WebServer > HelloServer
- Examples > WebServer > WebServer
*/

#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

#include "RootPage.h"

const char* ssid = "Nicks-ESP32";
const char* password = "SambaSamba";

WebServer server(80);

const uint8_t led = 2;
uint8_t ledState = LOW;

const uint8_t motorOne = 21;
const uint8_t motorTwo = 19;
const uint8_t steering = 13;

Servo steeringServo;

void turnLedOn(){
  ledState = HIGH;
  digitalWrite(led, ledState);
}

void turnLedOff(){
  ledState = LOW;
  digitalWrite(led, ledState);
}

void motorForward(){
  digitalWrite(motorOne, HIGH);
  digitalWrite(motorTwo, LOW);
}

void motorReverse(){
  digitalWrite(motorOne, LOW);
  digitalWrite(motorTwo, HIGH);
}

void motorStop(){
  digitalWrite(motorOne, LOW);
  digitalWrite(motorTwo, LOW);
}

void steerLeft(){
  steeringServo.write(0);
}

void steerStraight(){
  steeringServo.write(90);
}

void steerRight(){
  steeringServo.write(180);
}

void toggleLed(){
  Serial.println("led toggle requested");
  if (ledState == LOW){
    ledState = HIGH;
    digitalWrite(led, ledState);
  }
  else{
    ledState = LOW;
    digitalWrite(led, ledState);
  }
  server.send(200, "text/plain", "led toggled");
  Serial.println("led toggle completed");
}

void handleRoot() {
  Serial.println("root page requested");
  server.send(200, "text/html", RootPage);
  Serial.println("root page completed");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115220);
  pinMode(led, OUTPUT);
  digitalWrite(led, ledState);

  pinMode(motorOne, OUTPUT);
  digitalWrite(motorOne, LOW);
  pinMode(motorTwo, OUTPUT);
  digitalWrite(motorTwo, LOW);

  steeringServo.attach(steering);

  Serial.println("Setting AP (Access Point)...");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.on("/turnLedOn", turnLedOn);
  server.on("/turnLedOff", turnLedOff);
  server.on("/toggleLed", toggleLed);
  server.on("/motorForward", motorForward);
  server.on("/motorReverse", motorReverse);
  server.on("/motorStop", motorStop);
  server.on("/steerLeft", steerLeft);
  server.on("/steerStraight", steerStraight);
  server.on("/steerRight", steerRight);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  delay(2);  //allow the cpu to switch to other tasks
}
