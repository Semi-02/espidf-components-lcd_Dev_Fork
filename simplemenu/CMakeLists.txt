idf_component_register(SRCS "single_button.cc" "simple_menu_without_hw_scrolling.cc"
                    INCLUDE_DIRS "include"
                    REQUIRES "lcd_common" "driver" "esp_timer" "nvs_flash" "common")
