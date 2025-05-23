#pragma once
#include <cstdint>
#include <driver/gpio.h>
#include <esp_timer.h>
#include <time.h>
#include <sys/time.h>
#include "simple_menu_common.hh"

namespace button{
    enum class ButtonPressResult
    {
        NO_CHANGE,
        PRESSED,
        RELEASED_SHORT,
        PRESSED_LONG,
        RELEASED_LONG,
    };
    ButtonPressResult Button(gpio_num_t gpio);
    ButtonPressResult ButtonLoop(SimpleMenu::iMenuManagement* m, gpio_num_t gpio);
}