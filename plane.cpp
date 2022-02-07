#include "plane.h"

#include "global.h"
#include "my_tools.h"

void Plane::Draw() const {
  using namespace MyTools;
  MyTools::SetColor(CC_Blue);
  GotoXY(x, y);
  Global::console() << "=========>";
  GotoXY(x - 2, y - 1);
  Global::console() << "===";
  GotoXY(x + 3, y - 1);
  Global::console() << "\\\\\\\\";
  GotoXY(x + 3, y + 1);
  Global::console() << "////";
  Global::console().refresh();
}
