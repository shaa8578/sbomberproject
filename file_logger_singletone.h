#pragma once

#include <fstream>
#include <string>

//------------------------------------------------------------------------------
class Global;

//------------------------------------------------------------------------------
class FileLoggerSingletone {
  friend Global;

 public:
  ~FileLoggerSingletone();

  void openLogFile(const std::string& fileName);
  void closeLogFile();

  void writeToLog(const std::string& str);
  void writeToLog(const std::string& str, int n);
  void writeToLog(const std::string& str, double d);

 private:
  FileLoggerSingletone();
  FileLoggerSingletone(const FileLoggerSingletone&) = delete;
  FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;

  std::ofstream m_logFile;
};
