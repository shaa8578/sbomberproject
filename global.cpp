#include "global.h"

#include "proxy_logger.h"

//------------------------------------------------------------------------------
Global::ObjectDestructor<WindowConsole> Global::m_cmdDestructor;
WindowConsole* Global::m_console = nullptr;

Global::ObjectDestructor<BaseLogger> Global::m_loggerDestructor;
BaseLogger* Global::m_logger = nullptr;

//------------------------------------------------------------------------------
WindowConsole& Global::console() {
  if (m_console == nullptr) {
    m_console = new WindowConsole();
    m_console->open();
    m_cmdDestructor.setObject(m_console);
  }
  return *m_console;
}

//------------------------------------------------------------------------------
BaseLogger& Global::logger() {
  if (m_logger == nullptr) {
    m_logger = new ProxyLogger();
    m_loggerDestructor.setObject(m_logger);
  }
  return *m_logger;
}
