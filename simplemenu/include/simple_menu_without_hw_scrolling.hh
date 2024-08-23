#pragma once
#include <esp_log.h>
#define TAG "MENU"

#include <simple_menu_common.hh>
using namespace display;



namespace SimpleMenu
{
    class MenuItem:public iValueManager
    {
    protected:
        const char *const name;

    public:
        MenuItem(const char *const name) : name(name) {}
        virtual void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int line, bool invert) = 0;
        virtual void RenderFullScreen(iFullLineWriterWithoutHardwareScrolling *lw, bool initial, uint8_t shownLines){};
        virtual OnOpenFullscreenResult OnOpenFullscreen() { return OnOpenFullscreenResult::OK; } // This is the normal case
        virtual void OnCloseFullscreen() { return; }                                             // This is the normal case
        virtual MenuItemResult Up() { return MenuItemResult::CLOSE_MYSELF; }
        virtual MenuItemResult Down() { return MenuItemResult::CLOSE_MYSELF; }
        virtual MenuItemResult Select(MenuItem **toOpen) { return MenuItemResult::CLOSE_MYSELF; }
        virtual MenuItemResult Back() { return MenuItemResult::CLOSE_MYSELF; }
        const char *GetName() const override { return name; }
    };

    class ConfirmationItem : public MenuItem
    {
    private:
        void* referenceOrHandle;
        MenuItemChangedWithHandle<bool> *cb;
        static bool confirmationTmp;

    public:
        ConfirmationItem(const char *const name, void* referenceOrHandle, MenuItemChangedWithHandle<bool> *cb = nullptr) : MenuItem(name), referenceOrHandle(referenceOrHandle), cb(cb) {}
        
        void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int line, bool invert) override
        {
            lw->printfl(line, invert, "%s" G_LABEL_ALT, name);
        }

        MenuItemResult Select(MenuItem **toOpen) override {
            (void)toOpen;
             if (cb)
                cb->ValueChanged(this, this->referenceOrHandle, confirmationTmp);
            return MenuItemResult::CLOSE_MYSELF;
        }

        void RenderFullScreen(iFullLineWriterWithoutHardwareScrolling *lw, bool initial, uint8_t shownLines) override
        {
            if (initial)
            {
                lw->printfl(0, false, "Are you sure?");
                lw->clearLines(2, shownLines);
                confirmationTmp=false;
            }
            lw->printfl(1, true, ">[%s]", confirmationTmp?"Yes":"No");
            
        }
        MenuItemResult Up() override
        {
            confirmationTmp=!confirmationTmp;
            return MenuItemResult::REDRAW;
        }
        MenuItemResult Down() override
        {
            confirmationTmp=!confirmationTmp;
            return MenuItemResult::REDRAW;
        }
    };

    

    class IntegerItem : public MenuItem
    {
    private:
        int32_t *value;
        int32_t value_min;
        int32_t value_max;
        MenuItemChanged<int32_t> *cb;
        static int32_t valueTmp;

    public:
        IntegerItem(const char *const name, int32_t *value, int32_t value_min, int32_t value_max, MenuItemChanged<int32_t> *cb = nullptr) : MenuItem(name), value(value), value_min(value_min), value_max(value_max), cb(cb) {}
        void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int line, bool invert) override
        {
            lw->printfl(line, invert, "%s\t\t%d", name, *value);
        }

        esp_err_t SaveToNvs(nvs_handle_t& nvs_handle) override{
            return nvs_set_i32(nvs_handle, name, *value);
        }

        esp_err_t OpenFromNvs(nvs_handle_t& nvs_handle) override{
            return nvs_get_i32(nvs_handle, name, value);
        }

        MenuItemResult Select(MenuItem **toOpen) override {
            *value=valueTmp;
             if (cb)
                cb->ValueChanged(this, *value);
            return MenuItemResult::CLOSE_MYSELF;
        }

        void RenderFullScreen(iFullLineWriterWithoutHardwareScrolling *lw, bool initial, uint8_t shownLines) override
        {
            if (initial)
            {
                valueTmp=*value;
                lw->printfl(0, false, "Edit Value of %s", this->name);
                lw->clearLines(2, shownLines);
                
            }
            lw->printfl(1, true, "%d [%d]", valueTmp, *value);
        }
        MenuItemResult Up() override
        {
            valueTmp++;
            if (valueTmp > value_max)
                valueTmp = value_min;
           
            return MenuItemResult::REDRAW;
        }
        MenuItemResult Down() override
        {
            valueTmp--;
            if (valueTmp < value_min)
                valueTmp = value_max;
            return MenuItemResult::REDRAW;
        }
    };

    class BoolItem : public MenuItem
    {
    private:
        bool *value;
        MenuItemChanged<bool> *cb;
        static bool valueTmp;

    public:
        BoolItem(const char *const name, bool *value, MenuItemChanged<bool> *cb = nullptr) : MenuItem(name), value(value), cb(cb) {}
        
        esp_err_t SaveToNvs(nvs_handle_t& nvs_handle) override{
            return nvs_set_i32(nvs_handle, name, *value?1:0);
        }

        esp_err_t OpenFromNvs(nvs_handle_t& nvs_handle) override{
            int32_t foo=0;
            auto ret = nvs_get_i32(nvs_handle, name, &foo);
            *value=foo==1?true:false;
            return ret;
        }
        
        void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int line, bool invert) override
        {
            if (*value)
            {
                lw->printfl(line, invert, "%s\t\t" G_CHECKBOX_ON, name);
            }
            else
            {
                lw->printfl(line, invert, "%s\t\t" G_CHECKBOX, name);
            }
        }

        MenuItemResult Select(MenuItem **toOpen) override {
            *value=valueTmp;
             if (cb)
                cb->ValueChanged(this, *value);
            return MenuItemResult::CLOSE_MYSELF;
        }

        void RenderFullScreen(iFullLineWriterWithoutHardwareScrolling *lw, bool initial, uint8_t shownLines) override
        {
            if (initial)
            {
                valueTmp=*value;
                lw->printfl(0, false, "Edit Value of %s", this->name);
                lw->clearLines(2, shownLines);
                
            
            }
            lw->printfl(1, true, "%s (%s)", valueTmp?G_CHECKBOX_ON:G_CHECKBOX, valueTmp==*value?"orig":"changed");
            
        }

        MenuItemResult Up() override
        {
            valueTmp = !valueTmp;
            return MenuItemResult::REDRAW;
        }
        MenuItemResult Down() override
        {
            valueTmp = !valueTmp;
            return MenuItemResult::REDRAW;
        }
    };

    template <uint16_t UNITS_PER_INTEGER = 10>
    class FixedPointItem : public MenuItem
    {
    private:
        int32_t value_min, value_max;
        float *value;
        static int valueTmp;
        MenuItemChanged<float> *cb;

    public:
        FixedPointItem(const char *const name, float *value, float value_min, float value_max, MenuItemChanged<float> *cb = nullptr) : MenuItem(name),
                                                                                                                            
                                                                                                                                       value_min(value_min * UNITS_PER_INTEGER),
                                                                                                                                       value_max(value_max * UNITS_PER_INTEGER),
                                                                                                                                       value(value),
                                                                                                                                       cb(cb)
        {
        }


        esp_err_t SaveToNvs(nvs_handle_t& nvs_handle) override{
            return nvs_set_i32(nvs_handle, name, (*value)*(float)UNITS_PER_INTEGER);
        }

        esp_err_t OpenFromNvs(nvs_handle_t& nvs_handle) override{
            int32_t foo=0;
            auto ret = nvs_get_i32(nvs_handle, name, &foo);
            *value=foo/(float)UNITS_PER_INTEGER;
            return ret;
        }

        void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int line, bool invert) override
        {
            lw->printfl(line, invert, "%s\t\t%.2f", name, *value);
        }

        void RenderFullScreen(iFullLineWriterWithoutHardwareScrolling *lw, bool initial, uint8_t shownLines) override
        {
            if (initial)
            {
                valueTmp=(*value)*(float)UNITS_PER_INTEGER;
                lw->printfl(0, false, "Edit Value of %s", this->name);
                lw->clearLines(2, shownLines);
            }
            lw->printfl(1, true, "%.2f [%.2f]", valueTmp/(float)UNITS_PER_INTEGER, *value);
        }

        MenuItemResult Select(MenuItem **toOpen) override {
            *value=valueTmp/(float)UNITS_PER_INTEGER;
             if (cb)
                cb->ValueChanged(this, *value);
            return MenuItemResult::CLOSE_MYSELF;
        }

        MenuItemResult Up() override
        {
            valueTmp++;
            if (valueTmp > value_max)
                valueTmp = value_min;
            return MenuItemResult::REDRAW;
        }
        
        MenuItemResult Down() override
        {
            valueTmp--;
            if (valueTmp < value_min)
                valueTmp = value_max;
            return MenuItemResult::REDRAW;
        }
    };

    template <uint16_t UNITS_PER_INTEGER>
    int FixedPointItem<UNITS_PER_INTEGER>::valueTmp;
    
    class ReturnItem : public MenuItem
    {
    public:
        ReturnItem() : MenuItem(G_ARROW_UP G_ARROW_UP G_ARROW_UP G_ARROW_UP) {}
        void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int line, bool invert) override
        {
            lw->printfl(line, invert, "%s", name);
        }

        OnOpenFullscreenResult OnOpenFullscreen() override { return OnOpenFullscreenResult::NOT_OK_AND_CLOSE_PREVIOUS_WINDOW; }
    };

    class PlaceholderItem : public MenuItem
    {
    public:
        PlaceholderItem(const char *const name) : MenuItem(name) {}
        void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int line, bool invert) override
        {
            lw->printfl(line, invert, "%s", name);
        }
        OnOpenFullscreenResult OnOpenFullscreen() override { return OnOpenFullscreenResult::NOT_OK; }
    };

    class FolderItem : public MenuItem
    {
    private:
        const std::vector<MenuItem *> *const content;
        size_t selected_menu{0}; // index in the content vector

    public:
        FolderItem(const char *const name, const std::vector<MenuItem *> *const content) : MenuItem(name), content(content) {}
        
        esp_err_t SaveToNvs(nvs_handle_t& nvs_handle) override{
            for (int i=0;i<content->size();i++) {
                content->at(i)->SaveToNvs(nvs_handle);
            }
            return ESP_OK;
        }

        esp_err_t OpenFromNvs(nvs_handle_t& nvs_handle) override{
            for (int i=0;i<content->size();i++) {
                content->at(i)->OpenFromNvs(nvs_handle);
            }
            return ESP_OK;
        }
        
        void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int line, bool invert) override
        {
            lw->printfl(line, invert, "%s\t\t" G_CHEVRON_RIGHT, name);
        }

        MenuItem *GetContent(int uncorrected_index)
        {
            return content->at(modulo(uncorrected_index, content->size()));
        }

        void RenderFullScreen(iFullLineWriterWithoutHardwareScrolling *lw, bool initial, uint8_t shownLines) override
        {
            
            ESP_LOGI(TAG, "Menu Full update selected_menu=%u, shownLines=%d", selected_menu, shownLines);
            int menu_idx = selected_menu - 1;
            for (int textline = 0; textline < shownLines; textline++)
            {
                int corr_menu_idx = modulo(menu_idx, content->size());
                MenuItem *itm = content->at(corr_menu_idx);
                itm->RenderCompact(lw, textline, menu_idx == selected_menu);
                menu_idx++;
            }
            
        }

        MenuItemResult Up() override
        {
            selected_menu--;
            return MenuItemResult::REDRAW;
        }
        MenuItemResult Down() override
        {
            selected_menu++;
            return MenuItemResult::REDRAW;
        }

        MenuItemResult Select(MenuItem **itemToOpen) override
        {
            *itemToOpen = content->at(selected_menu);
            return MenuItemResult::OPEN_NEW_FULLSCREEN;
        }
    };

    class OptionItem : public MenuItem
    {
    private:
        std::vector<const char *> *options;
        size_t selectedOption{0}; // index in the content vector
        static uint32_t selectedOptionTmp;
        MenuItemChanged<uint32_t> *cb;

    public:
        OptionItem(const char *name, std::vector<const char *> *options, MenuItemChanged<uint32_t> *cb = nullptr) : MenuItem(name), options(options), cb(cb) {}
        
        esp_err_t SaveToNvs(nvs_handle_t& nvs_handle) override{
            return nvs_set_u32(nvs_handle, name, selectedOption);
        }

        esp_err_t OpenFromNvs(nvs_handle_t& nvs_handle) override{
            return nvs_get_u32(nvs_handle, name, (uint32_t*)&selectedOption);
        }

        void RenderCompact(iFullLineWriterWithoutHardwareScrolling *lw, int page, bool invert) override
        {
            lw->printfl(page, invert, "%s\t\t%s", name, GetSelectedOptionName());
        }

        const char *GetSelectedOptionName(int offset = 0)
        {
            auto name = options->at(modulo(selectedOptionTmp + offset, options->size()));
            return name;
        }

        const char *GetSelectedOptionSymbol(int offsetWrtSelectedOptionTmp = 0)
        {
            return modulo(selectedOptionTmp+offsetWrtSelectedOptionTmp, options->size())==selectedOption?G_ARROW_LEFT_BOX:" ";
        }

        size_t GetSelectedOptionIndex()
        {
            return selectedOption;
        }

        void RenderFullScreen(iFullLineWriterWithoutHardwareScrolling *lw, bool initial, uint8_t shownLines) override
        {
            if(initial){
                selectedOptionTmp=selectedOption;
            }
            ESP_LOGI(TAG, "Full update, selectedOptionTmp=%lu", selectedOptionTmp);
            for (int ramline = 0; ramline < shownLines; ramline++)
            {
                lw->printfl(ramline, ramline==1, "%s %s", GetSelectedOptionName(-1+ramline), GetSelectedOptionSymbol(- 1+ramline));
            }
        
        }

         MenuItemResult Select(MenuItem **toOpen) override {
            selectedOption=selectedOptionTmp;
             if (cb)
                cb->ValueChanged(this, selectedOption);
            return MenuItemResult::CLOSE_MYSELF;
        }

        MenuItemResult Up() override
        {
            selectedOptionTmp--;
            return MenuItemResult::REDRAW;
        }
        MenuItemResult Down() override
        {
            selectedOptionTmp++;
            return MenuItemResult::REDRAW;
        }
    };

    // Management enthält ein Vector mit dem Pfad der Bearbeitung
    // MenuFolder enthält andere MenuFolder und auch MenuItems
    // Wird ein MenuItem selektiert, wird es dem Pfad hinzugefügt und es darf sich FullScreen zeigen
    // Normales Item wechselt es in eine Bearbeitungssicht Show. es bekommt dann alle Nutzerbefehle Up, Down, Select, Back

    class MenuManagement:public iMenuManagement
    {
    private:
        FolderItem *root;
        iFullLineWriterWithoutHardwareScrolling *lw;
        std::vector<MenuItem *> path;
        uint8_t shownLines;//lines visible on screen (ex: ST7789 with line height 24 on a 240x240 display: 10)

    public:
        MenuManagement(FolderItem *root, iFullLineWriterWithoutHardwareScrolling *lw) : root(root), lw(lw), shownLines(lw->GetShownLines()) {}

        void Init()
        {
            root->RenderFullScreen(lw, true, shownLines);
            path.push_back(this->root);
        }

        void SaveToNvs(const char *partition_label, const char* namespace_name){
            esp_err_t err = nvs_flash_init_partition(partition_label);
            if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
                // NVS partition was truncated and needs to be erased
                // Retry nvs_flash_init
                ESP_ERROR_CHECK(nvs_flash_erase_partition(partition_label));
                err = nvs_flash_init_partition(partition_label);
            }
            ESP_ERROR_CHECK( err );
            ESP_LOGI(TAG, "Opening Non-Volatile Storage (NVS) handle... ");
            nvs_handle_t nvs_handle;
            err = nvs_open_from_partition(partition_label, namespace_name, NVS_READWRITE, &nvs_handle);
            this->root->SaveToNvs(nvs_handle);
            nvs_commit(nvs_handle);
        }

        void OpenFromNvs(const char *partition_label, const char* namespace_name){
            esp_err_t err = nvs_flash_init_partition(partition_label);
            if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
                // NVS partition was truncated and needs to be erased
                // Retry nvs_flash_init
                ESP_ERROR_CHECK(nvs_flash_erase_partition(partition_label));
                err = nvs_flash_init_partition(partition_label);
            }
            ESP_ERROR_CHECK( err );
            ESP_LOGI(TAG, "Opening Non-Volatile Storage (NVS) handle... ");
            nvs_handle_t nvs_handle;
            err = nvs_open_from_partition(partition_label, namespace_name, NVS_READONLY, &nvs_handle);
            this->root->OpenFromNvs(nvs_handle);
            nvs_commit(nvs_handle);
        }


        void Down() override
        {
            MenuItem *mi = path.back();
            switch (mi->Down())
            {
            case MenuItemResult::REDRAW:
                mi->RenderFullScreen(lw, false, shownLines);
                break;
            case MenuItemResult::NO_ACTION:
                break;
            default:
                break;
            }
        }

        void Up() override
        {
            MenuItem *mi = path.back();
            switch (mi->Up())
            {
            case MenuItemResult::REDRAW:
                mi->RenderFullScreen(lw, false, shownLines);
                break;
            case MenuItemResult::NO_ACTION:
                break;
            default:
                break;
            }
        }

        void GoBack() override
        {
            MenuItem *mi = path.back();
            mi->OnCloseFullscreen();
            path.pop_back();
            path.back()->OnOpenFullscreen();
            path.back()->RenderFullScreen(lw, true, shownLines);
        }
        
        void Select()
        {
            MenuItem *toOpen{nullptr};
            MenuItem *mi = path.back();
            switch (mi->Select(&toOpen))
            {
            case MenuItemResult::NO_ACTION:
                break;
            case MenuItemResult::REDRAW:
                mi->RenderFullScreen(lw, false, shownLines);
                break;
            case MenuItemResult::CLOSE_MYSELF:
                GoBack();
                break;
            case MenuItemResult::OPEN_NEW_FULLSCREEN:
            {
                assert(toOpen);
                switch (toOpen->OnOpenFullscreen())
                {
                case OnOpenFullscreenResult::OK:
                    mi->OnCloseFullscreen();
                    toOpen->RenderFullScreen(lw, true, shownLines);
                    path.push_back(toOpen);
                    break;
                case OnOpenFullscreenResult::NOT_OK_AND_CLOSE_PREVIOUS_WINDOW:
                    GoBack();
                    break;
                case OnOpenFullscreenResult::NOT_OK:
                    break;
                default:
                    break;
                }
                break;
            }
            default:
                break;
            }
        }
    };
}
#undef TAG