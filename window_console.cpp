#include "window_console.h"

#include <curses.h>

#include <iostream>
#include <stdexcept>

//------------------------------------------------------------------------------
WindowConsole::~WindowConsole() {
  close();
}

//------------------------------------------------------------------------------
void WindowConsole::refresh() {
  if (m_valid) {
    ::refresh();
  }
}

//------------------------------------------------------------------------------
int WindowConsole::maxX() const {
  return COLS;
}

//------------------------------------------------------------------------------
int WindowConsole::maxY() const {
  return LINES;
}

//------------------------------------------------------------------------------
void WindowConsole::move(int x, int y) {
  m_x = x;
  m_y = y;
}

//------------------------------------------------------------------------------
void WindowConsole::setColor(WindowConsole::WindowConsoleColor color) {
  m_currentColor = color;
}

//------------------------------------------------------------------------------
int WindowConsole::getchar() {
  return getch();
}

//------------------------------------------------------------------------------
void WindowConsole::clear() {
  if (m_valid) {
    ::clear();
    ::refresh();
  }
}

//------------------------------------------------------------------------------
WindowConsole& WindowConsole::operator<<(const char* text) {
  if (m_valid) {
    attron(COLOR_PAIR(m_currentColor));
    mvprintw(m_y, m_x, text);
    attroff(COLOR_PAIR(m_currentColor));
  }
  return *this;
}

//------------------------------------------------------------------------------
WindowConsole& WindowConsole::operator<<(int number) {
  return operator<<(std::to_string(number).c_str());
}

//------------------------------------------------------------------------------
void WindowConsole::open() {
  initWindow();
  initColors();
}

//------------------------------------------------------------------------------
void WindowConsole::initWindow() {
  if (!initscr()) throw std::domain_error("Ошибка инициализации консоли");

  cbreak();
  noecho();
  nonl();
  halfdelay(5);
  meta(stdscr, TRUE);
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  curs_set(0);

  clear();
  m_valid = true;
}

//------------------------------------------------------------------------------
void WindowConsole::initColors() {
  if (has_colors() == false) {
    throw std::domain_error("Your terminal does not support color");
  }
  start_color();
  init_pair(WND_COLOR_DEFAULT, WND_COLOR_WHITE, 0);
  init_pair(WND_COLOR_BLACK, WND_COLOR_BLACK, 0);
  init_pair(WND_COLOR_RED, WND_COLOR_RED, 0);
  init_pair(WND_COLOR_GREEN, WND_COLOR_GREEN, 0);
  init_pair(WND_COLOR_YELLOW, WND_COLOR_YELLOW, 0);
  init_pair(WND_COLOR_BLUE, WND_COLOR_BLUE, 0);
  init_pair(WND_COLOR_MAGENTA, WND_COLOR_MAGENTA, 0);
  init_pair(WND_COLOR_CYAN, WND_COLOR_CYAN, 0);
  init_pair(WND_COLOR_WHITE, WND_COLOR_WHITE, 0);
}

//------------------------------------------------------------------------------
void WindowConsole::close() {
  if (m_valid) {
    m_valid = false;
    resetWindow();
  }
}

//------------------------------------------------------------------------------
void WindowConsole::resetWindow() {
  bkgdset(COLOR_PAIR(0));
  ::clear();
  ::refresh();
  ::endwin();
}

//------------------------------------------------------------------------------
WindowConsole::WindowConsole()
    : m_valid(false), m_x(0), m_y(0), m_currentColor(WND_COLOR_DEFAULT) {}
