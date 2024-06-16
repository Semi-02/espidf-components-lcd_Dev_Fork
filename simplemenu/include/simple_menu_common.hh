#pragma once

#include <cstdint>
#include <cstdio>
#include <vector>
#include <lcd_interfaces.hh>

#include <esp_log.h>
#include <symbols.hh>
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"

#include <esp_log.h>

namespace menu
{
     inline size_t modulo(const int i, const int n)
    {
        return (i % n + n) % n;
    }
    
    enum class MenuItemResult
    {
        NO_ACTION,
        REDRAW_SECOND_LINE,
        OPEN_NEW_FULLSCREEN,
        CLOSE_MYSELF,
        REDRAW,
    };
    enum class OnOpenFullscreenResult
    {
        OK,
        NOT_OK,                           // for PlaceholderItem
        NOT_OK_AND_CLOSE_PREVIOUS_WINDOW, // for ReturnItem
    };

    class iValueManager{
        public:
        virtual const char *GetName() const=0;
        virtual esp_err_t SaveToNvs(nvs_handle_t& nvs_handle){
            return ESP_OK;
        }
        virtual esp_err_t OpenFromNvs(nvs_handle_t& nvs_handle){
            return ESP_OK;
        }
    };

    class iMenuManagement{
         public:
        virtual void Down()=0;
        virtual void Up()=0;
        virtual void Select()=0;
        virtual void GoBack()=0;
    };

    template <class T>
    class MenuItemChanged
    {
    public:
        virtual void ValueChanged(const iValueManager *item, T newValue) = 0;
    };
    
    template <class T>
    class MenuItemChangedWithHandle
    {
    public:
        virtual void ValueChanged(const iValueManager *item, void* referenceOrHandle, T newValue) = 0;
    };
}