#include "gamestate.h"
#include "texture.h"
#include "sprite.h"
#ifndef INTROSTATE_H
#define INTROSTATE_H

class Renderer;

class IntroState : public GameState {
    public:
        static IntroState& instance() {
            static IntroState* instance = new IntroState();
            return *instance;
        }

        bool enter();
        bool exit();

        void handle_event(const SDL_Event& event);
        void update();
        void render();
        
    private:
        IntroState() {};

        Texture m_background_texture{};
        Texture m_text_texture{};

        Sprite m_background_sprite;
        

};

#endif
