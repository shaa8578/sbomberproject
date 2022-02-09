#pragma once

#include "base_logger.hpp"
#include "window_console.h"

//------------------------------------------------------------------------------
class Global {
  template <class T>
  struct ObjectDestructor {
    ObjectDestructor() {}
    ~ObjectDestructor() {
      if (m_object) delete m_object;
    }
    void setObject(T* obj) { m_object = obj; }

   private:
    T* m_object = nullptr;
  };

 public:
  ~Global() {}

  static WindowConsole& console();
  static BaseLogger& logger();

 private:
  Global();
  Global(const Global&) = delete;
  Global& operator=(const Global&) = delete;

  static ObjectDestructor<WindowConsole> m_cmdDestructor;
  static WindowConsole* m_console;

  static ObjectDestructor<BaseLogger> m_loggerDestructor;
  static BaseLogger* m_logger;
};
