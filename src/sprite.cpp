#include "sprite.h"
#include "texture.h"

Sprite::Sprite() {
    m_texture = nullptr;
    m_rect = {};
}

Sprite::Sprite(Texture& texture, Rect rect) {
    m_texture = &texture;
    m_rect = rect;
}

Sprite::Sprite(Texture& texture, float x, float y, float width, float height) {
    m_texture = &texture;
    m_rect = {x, y, width, height};
}

Sprite::~Sprite() {
    free();
}

void Sprite::free() {
    m_texture = nullptr;
}

Texture& Sprite::get_texture() {
    return *m_texture;
}
Rect& Sprite::get_rect() {
    return m_rect;
}
