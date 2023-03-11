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
#include "porting/lv_port_disp.h"
#include "porting/lv_port_indev.h"
#include "porting/lv_port_fs.h"
#include "demos/lv_demos.h"

class ChappieLvgl {
    private:
        TaskHandle_t _task_handler;
        SemaphoreHandle_t _semaphore_mutex;

        /**
         * @brief Task to handle lvgl timer
         * 
         * @param param 
         */
        static void task_lv_timer_handler(void* param)
        {
            ChappieLvgl* lvgl = (ChappieLvgl*)param;
            while (1)
            {
                lvgl->startUpdate();
                lv_timer_handler();
                lvgl->stopUpdate();
                delay(5);
            }
            vTaskDelete(NULL);
        }

    public:
        /**
         * @brief Init lvgl and create a task to handle lv timer
         * 
         * @param lcd 
         * @param tp 
         */
        inline void init(LGFX_EmmaDisplay* lcd, ChappieCTP* tp)
        {
            lv_init();
            lv_port_disp_init(lcd);
            lv_port_indev_init(tp);
            lv_fs_fatfs_init();

            /* Create a task to handle lvgl timer */
            _semaphore_mutex = xSemaphoreCreateMutex();
            xTaskCreate(task_lv_timer_handler, "lvgl", 4096, this, 10, &_task_handler);
        }

        /**
         * @brief Call this before calling lvgl api
         * 
         * @param xTicksToWait 
         */
        inline void startUpdate(TickType_t xTicksToWait = portMAX_DELAY) { xSemaphoreTake(_semaphore_mutex, xTicksToWait); }

        /**
         * @brief Call this after calling lvgl api
         * 
         */
        inline void stopUpdate() { xSemaphoreGive(_semaphore_mutex); }

};


