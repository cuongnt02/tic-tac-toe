#include <SDL3/SDL_rect.h>
#ifndef SPRITE_H
#define SPRITE_H
class Texture;
typedef struct SDL_FRect Rect;


class Sprite {
    public:
        Sprite();
        Sprite(Texture& texture, Rect rect);
        Sprite(Texture& texture, float x, float y, float width, float height);
        Texture& get_texture();
        Rect& get_rect();
        ~Sprite();
        void free();
    private:
        Texture* m_texture;
        Rect m_rect;
};
#endif
