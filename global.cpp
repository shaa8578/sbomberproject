#include "global.h"

//------------------------------------------------------------------------------
Global::ConsoleDestructor Global::m_cmdDestructor;
WindowConsole* Global::m_console = nullptr;

//------------------------------------------------------------------------------
Global::ConsoleDestructor::~ConsoleDestructor() {
  if (m_console) delete m_console;
}

void Global::ConsoleDestructor::setWindowConsole(WindowConsole* console) {
  m_console = console;
}

//------------------------------------------------------------------------------
WindowConsole& Global::console() {
  if (m_console == nullptr) {
    m_console = new WindowConsole();
    m_console->open();
    m_cmdDestructor.setWindowConsole(m_console);
  }
  return *m_console;
}

//------------------------------------------------------------------------------
FileLoggerSingletone& Global::logger() {
  static FileLoggerSingletone logger_instance;
  return logger_instance;
}
