#include "level_gui.h"

#include <cstring>

#include "global.h"

void LevelGUI::Draw() const {
  Global::console().setColor(WindowConsole::WND_COLOR_WHITE);

  Global::console().move(x, y);
  char* buf = new (std::nothrow) char[width + 1];
  if (buf == nullptr) {
    return;
  }
  memset(buf, '+', width);
  buf[width] = '\0';
  Global::console() << buf;
  Global::console().move(x, y + height);
  Global::console() << buf;
  delete[] buf;
  buf = nullptr;

  for (size_t i = size_t(y); i < static_cast<size_t>(height + y); i++) {
    Global::console().move(x, static_cast<int>(i));
    Global::console() << "+";
    Global::console().move(x + width - 1, static_cast<int>(i));
    Global::console() << "+";
  }

  Global::console().move(3, 1);
  Global::console() << "FramePerSecond: "
                    << static_cast<int>(fps / (passedTime / 1000.0));
  Global::console().move(25, 1);
  Global::console() << "PassedTime: " << static_cast<int>(passedTime / 1000.0)
                    << " sec";
  Global::console().move(46, 1);
  Global::console() << "BombsNum: " << static_cast<int>(bombsNumber);
  Global::console().move(62, 1);
  Global::console() << "Score: " << static_cast<int>(score);
  Global::console().refresh();
}

void LevelGUI::SetParam(uint64_t passedTimeNew, uint64_t fpsNew,
                        uint16_t bombsNumberNew, int16_t scoreNew) {
  passedTime = passedTimeNew;
  fps = fpsNew;
  bombsNumber = bombsNumberNew;
  score = scoreNew;
}
