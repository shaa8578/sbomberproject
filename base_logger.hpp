#pragma once

#include <fstream>
#include <string>

//------------------------------------------------------------------------------
class BaseLogger {
 public:
  virtual ~BaseLogger() {}

  virtual void openLogFile(const std::string& /*fileName*/) = 0;
  virtual void closeLogFile() = 0;

  virtual void writeToLog(const std::string& /*str*/) = 0;
  virtual void writeToLog(const std::string& /*str*/, int /*n*/) = 0;
  virtual void writeToLog(const std::string& /*str*/, double /*d*/) = 0;

 protected:
  BaseLogger() {}
  virtual std::ofstream& fileHandle() = 0;

 private:
  BaseLogger(const BaseLogger&) = delete;
  BaseLogger& operator=(const BaseLogger&) = delete;
};
