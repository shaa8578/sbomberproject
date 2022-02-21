
#include "tank.h"

#include <iostream>

#include "global.h"

//------------------------------------------------------------------------------
Tank::Tank() : m_x(0), m_y(0), m_width(0U) {}

//------------------------------------------------------------------------------
bool Tank::isInRange(double x1, double x2) const {
  const double XBeg = m_x + 2.0;
  const double XEnd = m_x + m_width - 1.0;

  if (x1 < XBeg && x2 > XEnd) {
    return true;
  }

  if (x1 > XBeg && x1 < XEnd) {
    return true;
  }

  if (x2 > XBeg && x2 < XEnd) {
    return true;
  }

  return false;
}

//------------------------------------------------------------------------------
void Tank::paint() const {
  Global::console().setColor(WindowConsole::WND_COLOR_RED);
  Global::console().move(m_x, m_y - 3);
  Global::console() << "    #####";
  Global::console().move(m_x - 2, m_y - 2);
  Global::console() << "#######   #";
  Global::console().move(m_x, m_y - 1);
  Global::console() << "    #####";
  Global::console().move(m_x, m_y);
  Global::console() << " ###########";
  Global::console().refresh();
}
