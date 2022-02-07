#include "my_tools.h"

#include <stdint.h>
#include <time.h>

#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "global.h"

using namespace std;

ofstream logOut;

//------------------------------------------------------------------------------
namespace {

string GetCurDateTime() {
  auto cur = std::chrono::system_clock::now();
  time_t time = std::chrono::system_clock::to_time_t(cur);
  char buf[64] = {0};
  ctime_r(&time, buf);
  buf[strlen(buf) - 1] = '\0';
  return string(buf);
}

} /* namespace */

//------------------------------------------------------------------------------

void MyTools::ClrScr() {
  Global::console().clear();
}

void MyTools::GotoXY(double x, double y) {
  Global::console().move(static_cast<int>(x), static_cast<int>(y));
}

uint16_t MyTools::GetMaxX() {
  return Global::console().maxX();
}

uint16_t MyTools::GetMaxY() {
  return Global::console().maxY();
}

void MyTools::SetColor(ConsoleColor color) {
  Global::console().setColor(
      static_cast<WindowConsole::WindowConsoleColor>(color));
}

//------------------------------------------------------------------------------

void MyTools::OpenLogFile(const string& FN) {
  logOut.open(FN, ios_base::out);
}

void MyTools::CloseLogFile() {
  if (logOut.is_open()) {
    logOut.close();
  }
}

void MyTools::WriteToLog(const string& str) {
  if (logOut.is_open()) {
    logOut << GetCurDateTime() << " - " << str << endl;
  }
}

void MyTools::WriteToLog(const string& str, int n) {
  if (logOut.is_open()) {
    logOut << GetCurDateTime() << " - " << str << n << endl;
  }
}

void MyTools::WriteToLog(const string& str, double d) {
  if (logOut.is_open()) {
    logOut << GetCurDateTime() << " - " << str << d << endl;
  }
}
