#include <signal.h>
#include <unistd.h>

#include <atomic>
#include <clocale>
#include <cstring>
#include <iostream>
#include <stdexcept>

#include "global.h"
#include "sbomber.h"

using namespace std;

//------------------------------------------------------------------------------
std::atomic_bool is_terminated(false);

//------------------------------------------------------------------------------
void abortByThrowing();
void onQuitSignalReceived(int signo);
void initOsSignals();

//------------------------------------------------------------------------------

int main(void) {
  setlocale(LC_ALL, "Russian");

  try {
    std::set_terminate(abortByThrowing);
    Global::console().clear();
    initOsSignals();
  } catch (std::exception& ex) {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
  }

  Global::logger().openLogFile("log.txt");

  SBomber game;

  do {
    game.TimeStart();

    game.ProcessKBHit();

    Global::console().clear();

    game.DrawFrame();
    game.MoveObjects();
    game.CheckObjects();

    game.TimeFinish();

  } while ((!is_terminated) && (!game.GetExitFlag()));

  Global::logger().closeLogFile();

  return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
void abortByThrowing() {
  std::cerr << "Аварийное завершение из-за необрабатываемого исключения"
            << std::endl;
  is_terminated = true;
  abort();
}

void onQuitSignalReceived(int signo) {
  std::cout << "Получен код завершения " << signo << std::endl;
  is_terminated = true;
  exit(0);
}

void initOsSignals() {
  if (signal(SIGINT, &onQuitSignalReceived) == SIG_ERR) {
    throw std::domain_error("Ошибка подписки на сигнал SIGINT");
  }
  if (signal(SIGQUIT, &onQuitSignalReceived) == SIG_ERR) {
    throw std::domain_error("Ошибка подписки на сигнал SIGQUIT");
  }
  if (signal(SIGTERM, &onQuitSignalReceived) == SIG_ERR) {
    throw std::domain_error("Ошибка подписки на сигнал SIGTERM");
  }
}
