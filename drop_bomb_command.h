#pragma once

#include <cstdint>
#include <vector>

#include "command.hpp"

class Plane;
class DynamicObject;

namespace cmd {

class DropBombCommand : public Command {
 public:
  using DynamicObjectArray = std::vector<DynamicObject*>;

  DropBombCommand(const Plane* const& plane, std::uint16_t* bombCount,
                  DynamicObjectArray* bombsArray);

  inline void setCraterWidth(std::uint16_t width) { m_craterWidth = width; }
  void setBombSpeed(double speed);

  bool execute() override;

 private:
  /** Указатель на самолёт */
  const Plane* m_plane;
  /** Количество доступных бомб */
  std::uint16_t* m_bombCount;
  /** Масив для хранения бомб */
  DynamicObjectArray* m_bombsArray;
  /** Размер кратера */
  std::uint16_t m_craterWidth;
  /** Скорость падения бомбы */
  double m_bombSpeed;
};

} /* namespace cmd */
