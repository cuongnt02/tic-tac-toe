#include "gamestate.h"
#include "texture.h"
#include "sprite.h"
#ifndef INTROSTATE_H
#define INTROSTATE_H

class Renderer;

class MainState : public GameState {
    public:
        static MainState& instance() {
            static MainState* instance = new MainState();
            return *instance;
        }

        bool enter();
        bool exit();

        void handle_event(const SDL_Event& event);
        void update();
        void render();
        
    private:
        MainState() {};

        Texture m_background_texture{};
        Texture m_text_texture{};
        Texture m_symbol_x_texture{};
        Texture m_symbol_o_texture{};
        

        Sprite m_background_sprite;
        Sprite m_symbol_x_sprite;
        Sprite m_symbol_o_sprite;
        

};

#endif
