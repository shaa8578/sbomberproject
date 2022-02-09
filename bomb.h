#pragma once

#include "dynamic_object.h"

class Bomb : public DynamicObject {
 public:
  static const uint16_t BombCost = 10;  // стоимость бомбы в очках

  void Draw() const override;

 private:
};
