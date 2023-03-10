/**
 * @file ChappieIMU.hpp
 * @author Forairaaaaa
 * @brief Reference: https://github.com/ElectronicCats/mpu6050/blob/master/examples/MPU6050_DMP6/MPU6050_DMP6.ino
 * @version 0.1
 * @date 2023-03-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <Arduino.h>
#include <Wire.h>
#include "../Utility/MPU6050/MPU6050_6Axis_MotionApps20.h"
#include "../Utility/MPU6050/MPU6050.h"


class ChappieIMU : public MPU6050 {
    private:
        TwoWire* _wire;

    public:
        ChappieIMU() {}
        ~ChappieIMU() {}

        inline void init()
        {
            initialize();
            printf(testConnection() ? "[IMU] connection successful\n" : "[IMU] connection failed\n");

            if (dmpInitialize()) {

            }
        }



};

