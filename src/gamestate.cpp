#include "gamestate.h"


void StateManager::set_first_state(GameState& first_state) {
    if (current_state == nullptr)
        current_state = &first_state;
}


void StateManager::set_next_state(GameState& next_state) {
    next_state = next_state;
}

void StateManager::change_state() {
    if (next_state != nullptr) {
        current_state->exit();
        next_state->enter();

        current_state = next_state;
        next_state = nullptr;

    }
}

GameState& StateManager::get_current_state() const {
    return *current_state;
}
