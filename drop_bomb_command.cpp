#include "drop_bomb_command.h"

#include <cmath>
#include <string>

#include "bomb.h"
#include "dynamic_object.h"
#include "global.h"
#include "ground.h"
#include "plane.h"

//------------------------------------------------------------------------------
/** Скорость падения бомбы по умолчанию */
static const double DEFAULT_BOMB_SPEED = 2.0;

/** Составляющая X направления падения бомбы */
static const double DEFAULT_BOMB_DIRECTION_X = 0.3;
/** Составляющая Y направления падения бомбы */
static const double DEFAULT_BOMB_DIRECTION_Y = 1.0;

//------------------------------------------------------------------------------
cmd::DropBombCommand::DropBombCommand(
    const Plane* const& plane, uint16_t* bombCount,
    cmd::DropBombCommand::DynamicObjectArray* bombsArray)
    : Command(),
      m_plane(plane),
      m_bombCount(bombCount),
      m_bombsArray(bombsArray),
      m_craterWidth(SMALL_CRATER_SIZE),
      m_bombSpeed(DEFAULT_BOMB_SPEED) {}

//------------------------------------------------------------------------------
void cmd::DropBombCommand::setBombSpeed(double speed) {
  m_bombSpeed = std::isnormal(speed) ? speed : DEFAULT_BOMB_SPEED;
}

//------------------------------------------------------------------------------
bool cmd::DropBombCommand::execute() {
  if ((m_bombCount) && (*m_bombCount > 0)) {
    Global::logger().writeToLog(std::string(__FUNCTION__) + " was invoked");

    int x = m_plane->GetX() + 4;
    int y = m_plane->GetY() + 2;

    Bomb* bomb(new Bomb);
    bomb->SetDirection(DEFAULT_BOMB_DIRECTION_X, DEFAULT_BOMB_DIRECTION_Y);
    bomb->SetSpeed(m_bombSpeed);
    bomb->SetPos(x, y);
    bomb->SetWidth(m_craterWidth);

    m_bombsArray->push_back(bomb);
    (*m_bombCount)--;
    return true;
  }
  return false;
}
