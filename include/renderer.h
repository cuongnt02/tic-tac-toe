#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL_render.h>
#include <string>

class Sprite;

class Renderer {
    public:
        Renderer();
        Renderer(std::string name);
        ~Renderer();
        SDL_Renderer& getRenderer() const;
        bool init(SDL_Window& window);
        void renderSprite(Sprite& sprite);

    private:
        SDL_Renderer* m_renderer;
        const char* m_name;

        bool createRenderer(SDL_Window* window);
};

#endif
