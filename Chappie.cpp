/**
 * @file Chappie.cpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Chappie.h"



void CHAPPIE::init()
{
    Lcd.init();
    Lcd.setFont(&fonts::efontCN_12);

    /* Print Logo in a cool way */
    for (char c : Logo) {
        Lcd.printf("%c", c);
        delay(2);
    }

    delay(50);
    Lcd.printf(" ChappieBSP %s :)\n Author: Forairaaaaa\n", EMMA_BSP_VERISON);
    delay(50);
    Lcd.printf(" Project: %s\n", EMMA_PROJECT_NAME);
    delay(50);
    Lcd.printf("%s", Cowsay("Meow~").c_str());
    delay(50);



}
