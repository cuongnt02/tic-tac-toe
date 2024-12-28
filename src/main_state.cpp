#include "main_state.h"
#include "texture.h"
#include "global.h"
#include "renderer.h"
#include "sprite.h"

#include <SDL3/SDL_log.h>


bool MainState::enter() {
    if (!m_background_texture.loadFromFile(renderer.getRenderer(), "../asset/background.png")) {
        SDL_Log("Error loading texture! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    if (!m_symbol_x_texture.loadFromFile(renderer.getRenderer(), "../asset/x.png")) {
        SDL_Log("Error loading texture! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    if (!m_symbol_o_texture.loadFromFile(renderer.getRenderer(), "../asset/o.png")) {
        SDL_Log("Error loading texture! SDL_Error: %s\n", SDL_GetError());
        return false;
    }


    
    m_background_sprite = Sprite{m_background_texture, 
        Rect{0, 0, m_background_texture.get_width(), // TODO: this should be the default behavior
                    m_background_texture.get_height()}};
    
    m_symbol_x_sprite = Sprite{m_symbol_x_texture,
        Rect{0, 0, m_symbol_x_texture.get_width(),
            m_symbol_x_texture.get_height()}};

    m_symbol_o_sprite = Sprite{m_symbol_o_texture,
        Rect{0, 0, m_symbol_o_texture.get_width(),
            m_symbol_o_texture.get_height()}};

    return true;
}


bool MainState::exit() {
    m_background_texture.free();
    return true;
}


void MainState::handle_event(const SDL_Event& event) {
    // Handle onclick for white button
}


void MainState::update() {
    // Handle updating state
}


void MainState::render() {
    renderer.renderSprite(m_symbol_x_sprite, {30, 230, 140, 140});
    renderer.renderSprite(m_symbol_o_sprite, {0, 0, 200, 200});
    renderer.renderSprite(m_background_sprite, {0, 0, 600, 600});
}
