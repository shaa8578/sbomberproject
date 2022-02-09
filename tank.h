#pragma once

#include <stdint.h>

#include "destroyable_ground_object.h"

class Tank : public DestroyableGroundObject {
 public:
  bool isInside(double x1, double x2) const override;

  inline uint16_t GetScore() const override { return score; }

  void Draw() const override;

 private:
  const uint16_t score = 30;
};
