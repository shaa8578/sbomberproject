# SBomber

Тестовый проект для реализации примеров паттернов, описанных в книге "Банда четёрых".

## Зависимости

Данный проект зависит от следующих пакетов:

- ncurses-base и ncurses-bin
  ```bash
  sudo apt-get install libncursesw5-dev
  ```

## Реализация паттернов

Паттерны реализованы в рамках отдельных `branch`, кроме `Singleton`.
Который, в рамках рефакторинга единицы трансляции `my_tools.cpp`,
реализован в основной ветке `main`.

### Применение паттерна Singleton

**Задача**: применить паттерн «Одиночка» для логирования событий в проекте
`SBomber` (рефакторинг модуля `my_tools.cpp`).

В единице трансляции `my_tools.cpp` есть вторая группа функций
(помимо функций для работы с экраном) для логирования событий в проекте SBomber.
Рассмотрим их прототипы:

```c++
void OpenLogFile(const std::string& FN);
void CloseLogFile();
void WriteToLog(const std::string& str);
void WriteToLog(const std::string& str, int n);
void WriteToLog(const std::string& str, double d);
```

Видим функции, которые открывают и закрывают файл для ведения лога,
и 3 функции для записи данных в лог-файл.

Необходимо выполнить рефакторинг этих функций и поместить их внутрь «Одиночки» `FileLoggerSingletone`.
