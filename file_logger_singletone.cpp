#include "file_logger_singletone.h"

#include <time.h>

#include <chrono>
#include <cstring>

//------------------------------------------------------------------------------
namespace {

std::string currentDateTime() {
  auto cur = std::chrono::system_clock::now();
  time_t time = std::chrono::system_clock::to_time_t(cur);
  char buf[64] = {0};
  ctime_r(&time, buf);
  buf[strlen(buf) - 1] = '\0';
  return std::string(buf);
}

} /* namespace */

//------------------------------------------------------------------------------
FileLoggerSingletone::~FileLoggerSingletone() {
  closeLogFile();
}

//------------------------------------------------------------------------------
void FileLoggerSingletone::openLogFile(const std::string& fileName) {
  m_logFile.open(fileName, std::ios_base::out);
}

//------------------------------------------------------------------------------
void FileLoggerSingletone::closeLogFile() {
  if (m_logFile.is_open()) {
    m_logFile.flush();
    m_logFile.close();
  }
}

//------------------------------------------------------------------------------
void FileLoggerSingletone::writeToLog(const std::string& str) {
  if (m_logFile.is_open()) {
    m_logFile << currentDateTime() << " - " << str << std::endl;
  }
}

//------------------------------------------------------------------------------
void FileLoggerSingletone::writeToLog(const std::string& str, int n) {
  if (m_logFile.is_open()) {
    m_logFile << currentDateTime() << " - " << str << n << std::endl;
  }
}

//------------------------------------------------------------------------------
void FileLoggerSingletone::writeToLog(const std::string& str, double d) {
  if (m_logFile.is_open()) {
    m_logFile << currentDateTime() << " - " << str << d << std::endl;
  }
}

//------------------------------------------------------------------------------
FileLoggerSingletone::FileLoggerSingletone() : m_logFile() {}
