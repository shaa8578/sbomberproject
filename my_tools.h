#pragma once

#include <stdint.h>

#include <string>

namespace MyTools {

// Палитра цветов от 0 до 15
enum ConsoleColor {
  CC_Empty = 0,
  CC_Black,
  CC_Red,
  CC_Green,
  CC_Yellow,
  CC_Blue,
  CC_Magenta,
  CC_Cyan,
  CC_White
};

//------------------------------------------------------------------------------

void ClrScr();

void GotoXY(double x, double y);

uint16_t GetMaxX();

uint16_t GetMaxY();

void SetColor(ConsoleColor color);

//------------------------------------------------------------------------------

void OpenLogFile(const std::string& FN);

void CloseLogFile();

void WriteToLog(const std::string& str);

void WriteToLog(const std::string& str, int n);

void WriteToLog(const std::string& str, double d);

//------------------------------------------------------------------------------

}
