#include "Mars.h"
#include <Arduino.h>

Mars::Mars(CanControl* _canN){
    can = _canN;
}

void Mars::init(){
	can->init(CAN_BITRATE);
}

void Mars::setTargetSpeed(int addr, int spd1, int spd2){
    is_motor[addr] = true;
    speed[addr][0] = spd1;
    speed[addr][1] = spd2;
}

void Mars::send(){
    for(int i=0; i<16; i++){
        if(is_motor[i] == false)    continue;
        CAN_message_t msg;
        msg.id = 0x300 + i;
        msg.len = 8;
        for(int i=0; i<8; i++){
            msg.buf[i] = 0;
        }
        msg.buf[0] = speed[i][0] & 0xff;
        msg.buf[1] = (speed[i][0] & 0xff00) >> 8;
        msg.buf[2] = speed[i][1] & 0xff;
        msg.buf[3] = (speed[i][1] & 0xff00) >> 8;
        can->CANMsgWrite(msg);
    }
}