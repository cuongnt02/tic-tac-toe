#include "renderer.h"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_log.h>
#include "sprite.h"
#include "texture.h"


Renderer::Renderer() {
    m_renderer = nullptr;
    m_name = nullptr;
}

Renderer::Renderer(std::string name) {
    m_renderer = nullptr;
    m_name = name.c_str();
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
}


SDL_Renderer& Renderer::getRenderer() const {
    return *m_renderer;
}
        
bool Renderer::init(SDL_Window& window) {
    bool success = createRenderer(&window);
    if (!success) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Failed to initialize renderer!");
        return false;
    }
    else {
        SDL_LogDebug(SDL_LOG_CATEGORY_VIDEO, "Renderer created successfully!");
        return true;
    }
}

bool Renderer::createRenderer(SDL_Window* window) {
    m_renderer = SDL_CreateRenderer(window, m_name);
    if (m_renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Failed to create renderer! SDL_Error: %s", SDL_GetError());
        return false;
    }
    return true;
}

void Renderer::renderSprite(Sprite& sprite) {
    SDL_RenderTexture(m_renderer, &sprite.get_texture().get_internal_texture(), NULL, NULL);
}
