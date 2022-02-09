#include "ground.h"

#include <cstring>

#include "global.h"

//------------------------------------------------------------------------------

void Crater::Draw() const {
  // Рисование воронки в 9 символов шириной
  if (width == SMALL_CRATER_SIZE) {
    Global::console().move(x - 4, y + 1);
    Global::console() << "==     ==";
    Global::console().move(x - 2, y + 2);
    Global::console() << "=====";
    Global::console().refresh();
  }
}

bool Crater::isInside(double xn) const {
  const double size_2 = width / 2.0;
  if (int(xn) > int(x - size_2) && xn <= int(x + size_2)) {
    return true;
  }

  return false;
}

//------------------------------------------------------------------------------

void Ground::Draw() const {
  Global::console().setColor(WindowConsole::WND_COLOR_GREEN);

  const size_t bufSize = width + 1;
  char* buf = new (std::nothrow) char[bufSize];
  if (buf == nullptr) {
    return;
  }

  if (vecCrates.size() == 0) {
    Global::console().move(x, y);
    memset(buf, '=', bufSize);
    buf[bufSize - 1] = '\0';
    Global::console() << buf;
  } else {
    const size_t X = size_t(x);
    char c;
    for (size_t i = X; i < width + X; i++) {
      c = (isInsideAnyCrater((double)i)) ? ' ' : '=';
      buf[i - X] = c;
    }

    Global::console().move(x, y);
    buf[bufSize - 1] = '\0';
    Global::console() << buf;

    for (size_t i = 0; i < vecCrates.size(); i++) {
      vecCrates[i].Draw();
    }
  }
  Global::console().refresh();

  delete[] buf;
}

bool Ground::isInsideAnyCrater(double x) const {
  bool isInside = false;
  for (size_t i = 0; i < vecCrates.size(); i++) {
    if (vecCrates[i].isInside(x)) {
      isInside = true;
      break;
    }
  }

  return isInside;
}

void Ground::AddCrater(double xn) {
  Crater cr;
  cr.SetPos(int(xn), y);
  cr.SetWidth(SMALL_CRATER_SIZE);
  vecCrates.push_back(cr);
}
