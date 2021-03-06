#pragma once

#include <stdint.h>

#include "game_object.h"

class DynamicObject : public GameObject {
 public:
  DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) {}

  inline void SetSpeed(double sp) { speed = sp; }
  inline void SetDirection(double dx, double dy) {
    xDirction = dx;
    yDirection = dy;
  }

  virtual void Move(uint16_t time) {
    x += static_cast<int>(xDirction * speed * double(time) * 0.001);
    y += static_cast<int>(yDirection * speed * double(time) * 0.001);
  };

 protected:
  double speed;
  double xDirction, yDirection;
};
