#include <SDL3/SDL_events.h>
#ifndef GAMESTATE_H
#define GAMESTATE_H
class GameState {
    public:
        // State transitions
        virtual bool enter() = 0;
        virtual bool exit() = 0;

        // State main loop
        virtual void handle_event(const SDL_Event& event) = 0;
        virtual void update() = 0;
        virtual void render() = 0;

        virtual ~GameState(){};
};


class StateManager {
    public:
        static StateManager& instance() {
            static StateManager* instance = new StateManager();
            return *instance;
        }
        void set_first_state(GameState& first_state);
        void set_next_state(GameState& next_state);
        void change_state();
        GameState& get_current_state() const;
    private:
        StateManager() {};
        GameState* current_state{nullptr};
        GameState* next_state{nullptr};
};
#endif
