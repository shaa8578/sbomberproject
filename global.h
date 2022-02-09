#pragma once

#include "file_logger_singletone.h"
#include "window_console.h"

//------------------------------------------------------------------------------
class Global {
  struct ConsoleDestructor {
    ConsoleDestructor() {}
    ~ConsoleDestructor();
    void setWindowConsole(WindowConsole* console);

   private:
    WindowConsole* m_console = nullptr;
  };

 public:
  ~Global() {}

  static WindowConsole& console();
  static FileLoggerSingletone& logger();

 private:
  Global();
  Global(const Global&) = delete;
  Global& operator=(const Global&) = delete;

  static ConsoleDestructor m_cmdDestructor;
  static WindowConsole* m_console;
};
