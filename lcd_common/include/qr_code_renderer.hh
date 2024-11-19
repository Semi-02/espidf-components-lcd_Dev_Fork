#pragma once
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bit>
#include "RGB565.hh"
#include "qrcode.h"
#define TAG "QR"
#include <esp_log.h>

namespace lcd_common
{
    // BASELINE: Position der "Baseline" der Buchstaben relativ zur ersten Zeile des Rechtecks
    template <uint16_t SCREEN_WITDH = 240, uint16_t SCREEN_HEIGHT = 240, uint16_t OFFSET_TOP=0, uint OFFSET_BOTTOM=40, uint8_t VERSION = 3>
    class QrCodeRenderer : public IAsyncRenderer
    {
    private:
        QRCode qrcode;
        Point2D topleft; // ist absolute Bildschirmkoordinate obere linke Ecke
        Point2D bottomright_ex; // ist absolute Bildschirmkoordinate obere linke Ecke
        uint8_t scalingFactor{8};
        uint8_t moduleSize{33};
        bool getNextOverallLimitsAlreadySent{false};
        uint8_t *blockBuffer{nullptr};

    public:
        QrCodeRenderer()
        {
            
            this->moduleSize = 4 * VERSION + 17;//4*3+17=29
            int blockSizeIncludingFreeSpace = moduleSize+8;//37; see https://qr1.at/help/article/anleitung-f%C3%BCr-den-druck-von-qr-codes
            this->scalingFactor = std::min(SCREEN_WITDH, (uint16_t)(SCREEN_HEIGHT-OFFSET_BOTTOM-OFFSET_TOP)) / blockSizeIncludingFreeSpace;
            topleft.x=(SCREEN_WITDH-(moduleSize*scalingFactor))/2;
            bottomright_ex.x=topleft.x+moduleSize*scalingFactor;
            topleft.y=OFFSET_TOP+((SCREEN_HEIGHT-OFFSET_TOP-OFFSET_BOTTOM)-(moduleSize*scalingFactor))/2;
            bottomright_ex.y=topleft.y+moduleSize*scalingFactor;
        
            ESP_LOGD(TAG, "QRCode renderer moduleSize=%d, scalingFactor=%d topleft:%d/%d, bottomright:%d/%d", moduleSize, scalingFactor, topleft.x, topleft.y, bottomright_ex.x, bottomright_ex.y);

        }

        bool DisplayText(const char *text)
        {
            AllowRedraw();
            this->blockBuffer = new uint8_t[qrcode_getBufferSize(VERSION)];
            if(!blockBuffer) return false;
            return qrcode_initText(&qrcode, blockBuffer, VERSION, ECC_LOW, text)==0;
        }

        bool HasValidData(){
            return blockBuffer!=nullptr;
        }

        void AllowRedraw(){
            this->getNextOverallLimitsAlreadySent=false;
        }

        bool GetNextOverallLimits(size_t bufferSize, Point2D &start, Point2D &end_excl) override
        {
            if (getNextOverallLimitsAlreadySent)
            {
                return false;
            }
            start.x = 0;
            start.y = OFFSET_TOP;
            end_excl.x = SCREEN_WITDH;
            end_excl.y = SCREEN_HEIGHT-OFFSET_BOTTOM;
            getNextOverallLimitsAlreadySent = true;
            return true;
        }

        void Render(uint16_t startline, uint16_t cnt, uint16_t *buffer) override
        {
            const uint16_t w = Color::WHITE.toST7789_SPI_native();
            const uint16_t b = Color::BLACK.toST7789_SPI_native();
            
            ESP_LOGD(TAG, "Render QR-Code startline=%d, cnt=%d",startline, cnt);
            for (uint16_t l = 0; l < cnt; l++)
            {
                // startline bezieht sich relativ auf die obere linke ecke des rects, das gerade beschrieben wird
                // cnt bezieht sich auf die anzahl an Zeilen, die zu schreiben sind
                // das "l" meint hier die relative Zeile innerhalb des aktuellen buffersegments
                int absoluteLine = OFFSET_TOP+startline+l;
                if(absoluteLine<topleft.y || absoluteLine>=bottomright_ex.y){
                    //Zeile ist oberhalb oder unterhalb des QR-Codes
                    for(int i=0;i<SCREEN_WITDH;i++){
                        *(buffer++)=w;
                    }
                }else{
                    //Zeile ist innerhalb des QR-Codes
                    int y=(OFFSET_TOP+startline+l-topleft.y)/scalingFactor;
                    ESP_LOGD(TAG, "l=%d, absLine=%d, y=%d",l, absoluteLine, y);
                    for(int i=0;i<topleft.x;i++){
                        *(buffer++)=w;
                    }
                    for(int i=0;i<moduleSize*scalingFactor;i++){
                        int x=i/scalingFactor;
                        *(buffer++)=qrcode_getModule(&qrcode, x, y)?b:w;
                    }

                    for(int i=bottomright_ex.x;i<SCREEN_WITDH;i++){
                        *(buffer++)=w;
                    }
                }

            }
        }
    };
}
#undef TAG