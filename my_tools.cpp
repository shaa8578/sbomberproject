#include "my_tools.h"

#include <stdint.h>

#include "global.h"

//------------------------------------------------------------------------------

void MyTools::ClrScr() {
  Global::console().clear();
}

void MyTools::GotoXY(double x, double y) {
  Global::console().move(static_cast<int>(x), static_cast<int>(y));
}

uint16_t MyTools::GetMaxX() {
  return Global::console().maxX();
}

uint16_t MyTools::GetMaxY() {
  return Global::console().maxY();
}

void MyTools::SetColor(ConsoleColor color) {
  Global::console().setColor(
      static_cast<WindowConsole::WindowConsoleColor>(color));
}
