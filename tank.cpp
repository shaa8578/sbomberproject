
#include "tank.h"

#include <iostream>

#include "global.h"
#include "my_tools.h"

using namespace std;

bool Tank::isInside(double x1, double x2) const {
  const double XBeg = x + 2;
  const double XEnd = x + width - 1;

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

void Tank::Draw() const {
  using namespace MyTools;
  MyTools::SetColor(CC_Red);
  GotoXY(x, y - 3);
  Global::console() << "    #####";
  GotoXY(x - 2, y - 2);
  Global::console() << "#######   #";
  GotoXY(x, y - 1);
  Global::console() << "    #####";
  GotoXY(x, y);
  Global::console() << " ###########";
  Global::console().refresh();
}
