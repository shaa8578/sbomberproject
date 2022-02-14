#pragma once

#include <cstdint>

class GameObject {
 public:
  GameObject() : x(0), y(0), width(0) {}
  virtual ~GameObject() {}

  virtual void Draw() const = 0;

  inline void SetPos(int nx, int ny) {
    x = nx;
    y = ny;
  }

  inline int GetY() const { return y; }
  inline int GetX() const { return x; }

  inline void SetWidth(uint16_t widthN) { width = widthN; }
  inline uint16_t GetWidth() const { return width; }

 protected:
  int x, y;
  uint16_t width;
};
