#include "intro_state.h"
#include "texture.h"
#include "global.h"
#include "renderer.h"
#include "sprite.h"
#include <SDL3/SDL_log.h>


bool IntroState::enter() {
    if (!m_background_texture.loadFromFile(renderer.getRenderer(), "../asset/test.jpg")) {
        SDL_Log("Error loading texture! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    Rect rect{0, 0, m_background_texture.get_width(), m_background_texture.get_height()};
    Sprite background_sprite{m_background_texture, rect};
    m_background_sprite = Sprite{m_background_texture, rect};
    return true;
}


bool IntroState::exit() {
    m_background_texture.free();
    return true;
}


void IntroState::handle_event(const SDL_Event& event) {

}


void IntroState::update() {

}


void IntroState::render() {
    renderer.renderSprite(m_background_sprite);
}
