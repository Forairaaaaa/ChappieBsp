/**
 * @file Chappie.h
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "EmmaBSP/Emma.h"
#include "CTP/ChappieCTP.hpp"
#include "RTC/I2C_BM8563.h"


class CHAPPIE : public EMMA {
    private:
        
    public:
        const std::string Logo = R"(
  ___ _  _  __  ____ ____ __ ____ 
 / __) )( \/ _\(  _ (  _ (  |  __)
( (__) __ (    \) __/) __/)( ) _) 
 \___)_)(_|_/\_(__) (__) (__|____)
)";

        /* Touch pad driver */
        CTP Tp;

        /* RTC driver */
        I2C_BM8563 Rtc = I2C_BM8563(I2C_BM8563_DEFAULT_ADDRESS, Wire);


        void init();

        
};


