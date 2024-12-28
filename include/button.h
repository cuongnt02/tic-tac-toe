#ifndef BUTTON_H
#define BUTTON_H

#include "clickable.h"
#include "texture.h"
#include <SDL3/SDL_rect.h>
class Button : public IClickable {
    public:
        Button();
        Button(float x, float y, float width, float height);

        void set_position(float x, float y);
        void render();
        virtual void on_click();
    private:
        float m_button_width{0.0f};
        float m_button_height{0.0f};

        SDL_Point m_point{};
        Texture m_texture{};
};

#endif
