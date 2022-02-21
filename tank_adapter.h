#pragma once

#include <memory>

#include "destroyable_ground_object.h"

//------------------------------------------------------------------------------
class Tank;

//------------------------------------------------------------------------------
class TankAdapter : public DestroyableGroundObject {
  using PtrTank = std::unique_ptr<Tank>;

 public:
  TankAdapter();
  ~TankAdapter();

  void Draw() const override;

  void SetPos(int nx, int ny) override;
  int GetY() const override;
  int GetX() const override;

  void SetWidth(uint16_t widthN) override;
  uint16_t GetWidth() const override;

  bool isInside(double x1, double x2) const override;
  inline uint16_t GetScore() const override;

 private:
  PtrTank m_tank;
};
