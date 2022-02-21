#include "tank_adapter.h"

#include "tank.h"

//------------------------------------------------------------------------------
TankAdapter::TankAdapter() : m_tank(new Tank) {}

//------------------------------------------------------------------------------
TankAdapter::~TankAdapter() = default;

//------------------------------------------------------------------------------
void TankAdapter::Draw() const {
  m_tank->paint();
}

//------------------------------------------------------------------------------
void TankAdapter::SetPos(int nx, int ny) {
  m_tank->setPos(nx, ny);
}

//------------------------------------------------------------------------------
int TankAdapter::GetY() const {
  return m_tank->y();
}

//------------------------------------------------------------------------------
int TankAdapter::GetX() const {
  return m_tank->x();
}

//------------------------------------------------------------------------------
void TankAdapter::SetWidth(uint16_t widthN) {
  m_tank->setWidth(widthN);
}

//------------------------------------------------------------------------------
uint16_t TankAdapter::GetWidth() const {
  return m_tank->width();
}

//------------------------------------------------------------------------------
bool TankAdapter::isInside(double x1, double x2) const {
  return m_tank->isInRange(x1, x2);
}

//------------------------------------------------------------------------------
uint16_t TankAdapter::GetScore() const {
  return m_tank->score();
}
