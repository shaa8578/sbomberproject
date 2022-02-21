#pragma once

#include <cstdint>

class GameObject {
 public:
  GameObject() : x(0), y(0), width(0) {}
  virtual ~GameObject() {}

  virtual void Draw() const = 0;

  virtual void SetPos(int nx, int ny) {
    x = nx;
    y = ny;
  }

  virtual int GetY() const { return y; }
  virtual int GetX() const { return x; }

  virtual void SetWidth(uint16_t widthN) { width = widthN; }
  virtual uint16_t GetWidth() const { return width; }

 protected:
  int x, y;
  uint16_t width;
};
