#pragma once

#include <memory>

#include "dynamic_object.h"

class Bomb;

class BombDecorator : public DynamicObject {
 public:
  using PtrBomb = std::shared_ptr<Bomb>;

  BombDecorator(PtrBomb baseBomb = std::make_shared<Bomb>());
  ~BombDecorator();

  void Move(uint16_t time) override;
  void Draw() const override;

 protected:
  void DrawNewGraphic() const;

 private:
  PtrBomb m_bomb;
};
