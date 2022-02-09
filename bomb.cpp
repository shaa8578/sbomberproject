
#include "bomb.h"

#include "global.h"

void Bomb::Draw() const {
  Global::console().setColor(WindowConsole::WND_COLOR_MAGENTA);
  Global::console().move(x, y);
  Global::console() << "*";
  Global::console().refresh();
}
