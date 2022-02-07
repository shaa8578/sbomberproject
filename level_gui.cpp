#include "level_gui.h"

#include <cstring>

#include "global.h"
#include "my_tools.h"

void LevelGUI::Draw() const {
  using namespace MyTools;
  MyTools::SetColor(CC_White);

  GotoXY(x, y);
  char* buf = new (std::nothrow) char[width + 1];
  if (buf == nullptr) {
    return;
  }
  memset(buf, '+', width);
  buf[width] = '\0';
  Global::console() << buf;
  GotoXY(x, y + height);
  Global::console() << buf;
  delete[] buf;
  buf = nullptr;

  for (size_t i = size_t(y); i < height + y; i++) {
    GotoXY(x, (double)i);
    Global::console() << "+";
    GotoXY(x + width - 1, (double)i);
    Global::console() << "+";
  }

  GotoXY(3, 1);
  Global::console() << "FramePerSecond: "
                    << static_cast<int>(fps / (passedTime / 1000.0));
  GotoXY(25, 1);
  Global::console() << "PassedTime: " << static_cast<int>(passedTime / 1000.0)
                    << " sec";
  GotoXY(46, 1);
  Global::console() << "BombsNum: " << static_cast<int>(bombsNumber);
  GotoXY(62, 1);
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
