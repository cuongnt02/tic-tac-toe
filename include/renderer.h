#ifndef RENDERER_H
#define RENDERER_H


#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <string>

typedef struct SDL_FRect Rect;
class Sprite;

class Renderer {
    public:
        Renderer();
        Renderer(std::string name);
        ~Renderer();
        SDL_Renderer& getRenderer();
        bool init(SDL_Window& window);
        void renderSprite(Sprite& sprite, Rect dst);

    private:
        SDL_Renderer* m_renderer;
        const char* m_name;

        bool createRenderer(SDL_Window* window);
};

#endif
