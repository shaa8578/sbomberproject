#pragma once

#include <atomic>

//------------------------------------------------------------------------------
class Global;

//------------------------------------------------------------------------------
class WindowConsole {
  friend Global;

 public:
  enum WindowConsoleColor {
    WND_COLOR_DEFAULT = 0,
    WND_COLOR_BLACK,
    WND_COLOR_RED,
    WND_COLOR_GREEN,
    WND_COLOR_YELLOW,
    WND_COLOR_BLUE,
    WND_COLOR_MAGENTA,
    WND_COLOR_CYAN,
    WND_COLOR_WHITE
  };

  bool isValid() const { return m_valid; }

  ~WindowConsole();
  void refresh();

  int maxX() const;
  int maxY() const;

  void move(int x, int y);
  void setColor(WindowConsoleColor color);

  int getchar();
  void clear();
  WindowConsole& operator<<(const char* text);
  WindowConsole& operator<<(int number);

 protected:
  void open();
  void initWindow();
  void initColors();

  void close();
  void resetWindow();

 private:
  WindowConsole();
  WindowConsole(const WindowConsole&) = delete;
  WindowConsole& operator=(const WindowConsole&) = delete;

  std::atomic_bool m_valid;
  int m_x;
  int m_y;
  WindowConsoleColor m_currentColor;
};
