#ifndef MARS_H_
#define MARS_H_

#define CAN_BITRATE 1000000
#define RANGE_FROM 10000
#define RANGE_TO_MIN 0
#define RANGE_TO_MAX 1280

#include <CAN.h>
#include <FlexCAN_T4.h>

class Mars : public CanControl{
    public:
        Mars(CanControl* _can); //setupを行う

        void init();    //bitrateを指定する基板側(mars)で1e6[Hz]に指定
        void setTargetSpeed(int addr, int spd1, int spd2);
        void send();    //データを基板(mars)に送信する
        
    private:
        CanControl* can;
        int16_t speed[16][2]; // -10000~10000
        bool is_motor[16] = {};
};

int map(double num, double from_min, double from_max, double to_min, double to_max);

#endif