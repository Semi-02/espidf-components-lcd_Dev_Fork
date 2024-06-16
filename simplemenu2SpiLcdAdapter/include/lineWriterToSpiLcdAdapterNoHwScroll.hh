#pragma once
#include <cstdlib>
#include <cstdint>
#include <lcd_interfaces.hh>
#include <FullTextLineRenderer.hh>
#include <spilcd16.hh>
#define TAG "LCDA"
#include <esp_log.h>

using namespace spilcd16;
namespace display
{
    template <uint8_t LINE_HEIGHT_PIXELS, uint8_t LINE_WIDTH_PIXELS, uint8_t PADDING_LEFT, uint8_t PADDING_RIGHT>
class LineWriterToSpiLcdAdapterNoHwScroll : public iFullLineWriterWithoutHardwareScrolling
{
private:
    IRendererHost *host;
    FilledRectRenderer* frr;
    FullTextlineRenderer<LINE_HEIGHT_PIXELS, LINE_WIDTH_PIXELS, PADDING_LEFT, PADDING_RIGHT>* ftlr;
public:
    LineWriterToSpiLcdAdapterNoHwScroll(IRendererHost *host,const lcd_common::FontDesc* const font) : host(host) {
        ftlr= new FullTextlineRenderer<LINE_HEIGHT_PIXELS, LINE_WIDTH_PIXELS, PADDING_LEFT, PADDING_RIGHT>(font);
    }
    
    size_t printfl(int line, bool invert, const char *format, ...) override
    {
        va_list args_list;
        va_start(args_list, format);
        line=(line+GetShownLines())%GetShownLines();
        size_t ret = ftlr->printfl(line, invert?Color::BLACK:Color::YELLOW, invert?Color::YELLOW:Color::BLACK, format, args_list);
        va_end(args_list);
        host->Draw(ftlr, true);
        return ret; 
    }

    void clearLines(int startLineIncl, int endLineExc) override{
        for(int l=startLineIncl;l<endLineExc;l++){
            printfl(l, false, " ");
        }
    }
    
    uint8_t GetShownLines() override
    {
        return 5;
    }
};
}
#undef TAG