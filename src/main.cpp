#include <SDL3/SDL_init.h>
#define SDL_MAIN_USE_CALLBACKS

#include "window.h"
#include "renderer.h"
#include "texture.h"
#include "sprite.h"
#include "global.h"


#include "intro_state.h"

#include <SDL3/SDL_main.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>
#include <SDL3_image/SDL_image.h>

Window window{"Tic-Tac-Toe", 720, 480, 0};

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_Log("SDL initialization failed! SDL_Error: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    // Init Window 
    if (!window.init()) return SDL_APP_FAILURE;
    if (!renderer.init(window.getWindow())) return SDL_APP_FAILURE;
    int img_flags = IMG_INIT_JPG;
    if ( !(IMG_Init(img_flags) & img_flags)) return SDL_APP_FAILURE;
    state_manager.set_first_state(IntroState::instance());
    state_manager.get_current_state().enter();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    SDL_SetRenderDrawColor(&renderer.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(&renderer.getRenderer());
    state_manager.get_current_state().render();
    state_manager.get_current_state().update();
    state_manager.change_state();
    SDL_RenderPresent(&renderer.getRenderer());
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, const SDL_Event *event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    state_manager.get_current_state().handle_event(*event);
    return SDL_APP_CONTINUE;     
}

void SDL_AppQuit(void *appstate) {
}
