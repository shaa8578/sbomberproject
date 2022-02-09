#include "plane.h"

#include "global.h"

void Plane::Draw() const {
  Global::console().setColor(WindowConsole::WND_COLOR_BLUE);
  Global::console().move(x, y);
  Global::console() << "=========>";
  Global::console().move(x - 2, y - 1);
  Global::console() << "===";
  Global::console().move(x + 3, y - 1);
  Global::console() << "\\\\\\\\";
  Global::console().move(x + 3, y + 1);
  Global::console() << "////";
  Global::console().refresh();
}
