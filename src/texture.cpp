#include "texture.h"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_log.h>


Texture::Texture(){
    m_texture = nullptr;    
    m_width = 0;
    m_height = 0;
}


Texture::~Texture(){
    free();
}


// Load the texture from specified file path
bool Texture::loadFromFile(SDL_Renderer& renderer, std::string path){
    free();
    SDL_Texture* texture{ IMG_LoadTexture(&renderer, path.c_str()) };
    if (texture == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Error creating texture: %s\n", SDL_GetError());
    } else {
        m_texture = texture;

        float width{};
        float height{};

        bool success = SDL_GetTextureSize(m_texture, &width, &height);
        if (success) {
            m_width = width;
            m_height = height;
        }
        else {
            SDL_LogWarn(SDL_LOG_CATEGORY_VIDEO, "Warning: Texture data may be bad. SDL_Error: %s\n", SDL_GetError());
        }
    }
    return m_texture != nullptr;
}


// Deallocate the texture
void Texture::free(){
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
        m_width = 0;
        m_height = 0;
    }
}


void Texture::render(int x, int y){

}


float Texture::get_width(){
    return m_width;
}


float Texture::get_height(){
    return m_height;
}


SDL_Texture& Texture::get_internal_texture() const {
    return *m_texture;
}
