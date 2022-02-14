#include "bomb_decorator.h"

#include "bomb.h"
#include "global.h"

//------------------------------------------------------------------------------
/** Коэффициент ускорения падения бомбы */
static const double BOMB_SPEED_COEF = 1.5;

//------------------------------------------------------------------------------
BombDecorator::BombDecorator(BombDecorator::PtrBomb baseBomb)
    : DynamicObject(), m_bomb(baseBomb) {}

//------------------------------------------------------------------------------
BombDecorator::~BombDecorator() = default;

//------------------------------------------------------------------------------
void BombDecorator::Move(uint16_t time) {
  DynamicObject::Move(time * BOMB_SPEED_COEF);
  y *= BOMB_SPEED_COEF;
}

//------------------------------------------------------------------------------
void BombDecorator::Draw() const {
  m_bomb->SetWidth(width);
  m_bomb->SetPos(x, y);
  m_bomb->Draw();
  DrawNewGraphic();
}

//------------------------------------------------------------------------------
void BombDecorator::DrawNewGraphic() const {
  Global::console().move(x - 1, y - 1);
  Global::console() << "\\ /";
  Global::console().refresh();
}
