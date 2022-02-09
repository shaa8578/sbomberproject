#pragma once

#include "base_logger.hpp"

class Global;
class ProxyLogger;

//------------------------------------------------------------------------------
class FileLoggerSingletone : public BaseLogger {
  friend Global;
  friend ProxyLogger;

 public:
  virtual ~FileLoggerSingletone();

  void openLogFile(const std::string& fileName) override;
  void closeLogFile() override;

  void writeToLog(const std::string& str) override;
  void writeToLog(const std::string& str, int n) override;
  void writeToLog(const std::string& str, double d) override;

 protected:
  std::ofstream& fileHandle() override;

 private:
  FileLoggerSingletone();

  std::ofstream m_logFile;
};
