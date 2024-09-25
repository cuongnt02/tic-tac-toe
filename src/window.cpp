#include "window.h"

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_log.h>

Window::Window() {
    m_width = 640;
    m_height = 480;
    m_window = nullptr;
    m_title = "Untitled";
}



Window::Window(std::string title, int width, int height, SDL_WindowFlags window_flags) {
    m_title = title;
    m_width = width;
    m_height = height;
    m_windowflags = window_flags;
}

Window::~Window() {
    SDL_DestroyWindow(m_window);
}

bool Window::init() {
    bool success = createWindow();
    if (!success) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Error initilizing window");
        return false;
    }
    else {
        SDL_LogDebug(SDL_LOG_CATEGORY_RENDER, "Window created successfully");
        return true;
    }
}


SDL_Window& Window::getWindow() const {
    return *m_window;
}


bool Window::createWindow() {
    m_window = SDL_CreateWindow(m_title.c_str(), m_width, m_height, m_windowflags);
    if (m_window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER,"Could not create window! SDL_Error: %s", SDL_GetError());
        return false;
    }
    return true;
}
