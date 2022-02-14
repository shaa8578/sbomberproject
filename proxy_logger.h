#include <fstream>
#include <memory>
#include <string>

#include "base_logger.hpp"

//------------------------------------------------------------------------------
class Global;
class FileLoggerSingletone;

//------------------------------------------------------------------------------
class ProxyLogger : public BaseLogger {
  friend Global;

 public:
  virtual ~ProxyLogger();

  void openLogFile(const std::string& fileName) override;
  void closeLogFile() override;

  void writeToLog(const std::string& str) override;
  void writeToLog(const std::string& str, int n) override;
  void writeToLog(const std::string& str, double d) override;

 protected:
  virtual std::ofstream& fileHandle() override;
  void addEventNo();

 private:
  ProxyLogger();

  size_t m_eventNo;
  std::unique_ptr<FileLoggerSingletone> m_wrapper;
};
