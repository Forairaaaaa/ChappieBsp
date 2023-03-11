/**
 * @file ChappieLvgl.hpp
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
#include "../EmmaBSP/Display/EmmaDisplay.hpp"
#include "../CTP/ChappieCTP.hpp"
#include "porting/lv_port_disp.h"
#include "demos/lv_demos.h"

class ChappieLvgl {
    private:
        LGFX_EmmaDisplay* _lcd;
        ChappieCTP* _tp;

    public:
        /**
         * @brief Init lvgl 
         * 
         * @param lcd 
         */
        inline void init(LGFX_EmmaDisplay* lcd, ChappieCTP* tp)
        {
            _lcd = lcd;
            _tp = tp;
        
            lv_init();
            lv_port_disp_init(lcd);

            // lv_demo_benchmark();
            lv_demo_stress();


            while (1)
            {
                lv_timer_handler();
                delay(5);
            }


        }

};


