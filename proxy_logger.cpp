#include "proxy_logger.h"

#include "file_logger_singletone.h"

//------------------------------------------------------------------------------
ProxyLogger::~ProxyLogger() = default;

//------------------------------------------------------------------------------
void ProxyLogger::openLogFile(const std::string& fileName) {
  m_wrapper->openLogFile(fileName);
}

//------------------------------------------------------------------------------
void ProxyLogger::closeLogFile() {
  m_wrapper->closeLogFile();
}

//------------------------------------------------------------------------------
void ProxyLogger::writeToLog(const std::string& str) {
  addEventNo();
  m_wrapper->writeToLog(str);
}

//------------------------------------------------------------------------------
void ProxyLogger::writeToLog(const std::string& str, int n) {
  addEventNo();
  m_wrapper->writeToLog(str, n);
}

//------------------------------------------------------------------------------
void ProxyLogger::writeToLog(const std::string& str, double d) {
  addEventNo();
  m_wrapper->writeToLog(str, d);
}

//------------------------------------------------------------------------------
std::ofstream& ProxyLogger::fileHandle() {
  return m_wrapper->fileHandle();
}

void ProxyLogger::addEventNo() {
  m_wrapper->fileHandle() << "[Event " << std::to_string(++m_eventNo) << "] ";
}

//------------------------------------------------------------------------------
ProxyLogger::ProxyLogger()
    : BaseLogger(), m_eventNo(0UL), m_wrapper(new FileLoggerSingletone) {}
