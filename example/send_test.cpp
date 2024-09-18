#include <Arduino.h>
#include <FlexCAN_T4.h>
#include "CAN.h"
#include <Mars.h>
#include <Metro.h>

CanControl DriveCan(2);
Mars mars = Mars(&DriveCan);
Metro countup = Metro(2000);
bool flag = 0;

void setup() {
  Serial.begin(9600);
  mars.init();
}

void loop(){
  mars.setTargetSpeed(0 ,5000, -7000);
  mars.send();
  // CAN_message_t msg;
  // msg.id = 0x300;
  // msg.len = 8;
  // for(int i=0; i<8; i++){
  //   msg.buf[i] = 0;
  // }
  // msg.buf[0] = 0xff;
  // msg.buf[1] = 0;
  // msg.buf[2] = 0xff;
  // msg.buf[3] = 0;
  // DriveCan.CANMsgWrite(msg);
}