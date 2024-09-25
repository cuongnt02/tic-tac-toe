#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>

class Window {
    public:
        Window();
        Window(std::string title, int width, int height, SDL_WindowFlags window_flags);
        ~Window();
        bool init();
        SDL_Window& getWindow() const;

    private:
        SDL_Window* m_window;
        int m_width{};
        int m_height{};
        std::string m_title{};
        SDL_WindowFlags m_windowflags{0};

        bool createWindow();
};


#endif
