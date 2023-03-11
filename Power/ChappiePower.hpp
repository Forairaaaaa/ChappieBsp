/**
 * @file ChappiePower.hpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-03-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <Arduino.h>

#define CHAPPIE_PWR_CTRL    GPIO_NUM_9
#define CHAPPIE_BATM_ADC    GPIO_NUM_8
#define CHAPPIE_BATM_EN     GPIO_NUM_18

class ChappiePower {
    private:
        inline void _enableBatMeasure() { gpio_set_level(CHAPPIE_BATM_EN, 1); }
        inline void _disableBatMeasure() { gpio_set_level(CHAPPIE_BATM_EN, 0); }

    public:
        ChappiePower() {}
        ~ChappiePower() {}

        inline void init()
        {
            gpio_reset_pin(CHAPPIE_BATM_ADC);
            gpio_reset_pin(CHAPPIE_BATM_EN);

            gpio_set_direction(CHAPPIE_BATM_EN, GPIO_MODE_OUTPUT);
            _disableBatMeasure();
            
        }

        inline void powerOff()
        {
            gpio_reset_pin(CHAPPIE_PWR_CTRL);
            gpio_set_direction(CHAPPIE_PWR_CTRL, GPIO_MODE_OUTPUT_OD);
            /* Double click */
            gpio_set_level(CHAPPIE_PWR_CTRL, 0);
            delay(100);
            gpio_set_level(CHAPPIE_PWR_CTRL, 1);
            delay(100);
            gpio_set_level(CHAPPIE_PWR_CTRL, 0);
            delay(100);
            gpio_set_level(CHAPPIE_PWR_CTRL, 1);
            delay(1000);
        }

        // inline double getBatVoltage()
        // {

        // }

        // inline uint8_t getBatLevel()
        // {

        // }

};

