#include <string>
#ifndef TEXTURE_H
#define TEXTURE_H
struct SDL_Texture;
struct SDL_Renderer;


class Texture {
    public:
        Texture();
        ~Texture();

        bool loadFromFile(SDL_Renderer& renderer, std::string path);
        void free();
        void render(int x, int y);
        float get_width();
        float get_height();
        SDL_Texture& get_internal_texture() const;
    private:

        SDL_Texture* m_texture;

        float m_width;
        float m_height;
};
#endif
