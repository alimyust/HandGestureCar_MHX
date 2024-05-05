
#include "BluetoothSerial.h"

// Left Side
const int in1 = 17;
const int in2 = 4;
// const int enA = 8;

// Right Side
const int in3 = 12;
const int in4 = 14;
// const int enB = 9;

// Speed
int leftSpeed = 0;
int rightSpeed = 0;

String handGesture = "";

BluetoothSerial BT;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // pinMode(enB, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready to pair");
  BT.begin("ali_esp32");

}

void loop() {
  Serial.print(".");
  // stop();
  if(BT.available()){//&& BT.readString() != handGesture
  Serial.print("BT");
    // if(BT.readString().length() <= 13){
      handGesture = BT.readString();
      // if(handGesture.length() > 13){
      //   handGesture = "";
      //   return;
      // }
    // }
  }
  if(handGesture!=""){
    Serial.println(handGesture);
  }
  if(handGesture == "Right:Pointer"){
    // digitalWrite(12, HIGH);
    right();
  }
  if(handGesture == "Left:Pointer"){
    left();
  }
  if(handGesture == "Right:Close"){
    forward();
  }
    if(handGesture == "Left:Close"){
    backward();
  }
    if(handGesture == "Right:Open"){
    stop();
  }
    if(handGesture == "Left:Open"){
    stop();
  }
    delay(50);

  // switch(handGesture){
  //   case "Right:Pointer":
  //   right();
  //   break;
  //   case "Left:Pointer":
  //   left();
  //   break;
  //   case "Right:Close":
  //   forward();
  //   break;
  //   case "Left:Close":
  //   backward();
  //   break;
  //   case "Right:Open":
  //   stop();
  //   break;
  //   case "Left:Open":
  //   stop();
  //   break;
  //   case "Right:Ok":
  //   break;
  //   case "Left:Ok":
  //   break;
    

}

void sideForward(String side){
  if(side=="left"){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // analogWrite(enA, leftSpeed);
  }
  if(side=="right"){
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // analogWrite(enB, rightSpeed);
  }
}

void sideBackward(String side){
  if(side=="left"){ 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // analogWrite(enA, leftSpeed);
  }
  if(side=="right"){
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // analogWrite(enB, rightSpeed);
  }
}

void forward(){
  sideForward("left");
  sideForward("right");
}

void backward(){
  sideBackward("left");
  sideBackward("right");
}

void left(){
  sideBackward("left");
  sideForward("right");
}

void right(){
  sideForward("left");
  sideBackward("right");
}

void stop(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}