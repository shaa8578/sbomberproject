
#include "bomb.h"

#include "global.h"
#include "my_tools.h"

void Bomb::Draw() const {
  using namespace MyTools;
  MyTools::SetColor(CC_Magenta);
  GotoXY(x, y);
  Global::console() << "*";
  Global::console().refresh();
}
