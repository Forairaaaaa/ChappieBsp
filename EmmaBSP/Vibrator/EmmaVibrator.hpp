/**
 * @file EmmaVibrator.hpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "../../EmmaConfig.h"
#if EMMA_MODULE_VIBRATOR
#include <Arduino.h>



class EmmaVibrator {
    private:
        uint8_t __ctrl_pin;
        uint8_t __ledc_channel;
    public:
        EmmaVibrator(uint8_t ctrlPin, uint8_t ledcChannel = 0)
        {
            __ctrl_pin = ctrlPin;
            __ledc_channel = ledcChannel;
            ledcSetup(__ledc_channel, 10000, 8);
            ledcAttachPin(__ctrl_pin, __ledc_channel);
            ledcWrite(__ledc_channel, 0);
        }
        ~EmmaVibrator() { ledcDetachPin(__ctrl_pin); }

        void start(uint8_t intensity = 255) { ledcWrite(__ledc_channel, intensity); }
        void stop() { start(0); }
        /**
         * @brief Buzz for a while (blocking)
         * 
         * @param ms 
         * @param intensity 
         */
        void Buzzzzz(uint32_t ms, uint8_t intensity = 255) { start(intensity); delay(ms); stop(); }
};


#endif
