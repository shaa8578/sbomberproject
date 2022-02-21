#pragma once

#include <stdint.h>

//------------------------------------------------------------------------------
class Tank {
 public:
  Tank();

  bool isInRange(double x1, double x2) const;
  void paint() const;

  inline uint16_t score() const { return m_score; }

  inline void setPos(int nx, int ny) {
    m_x = nx;
    m_y = ny;
  }

  inline int y() const { return m_y; }
  inline int x() const { return m_x; }

  inline void setWidth(uint16_t widthN) { m_width = widthN; }
  inline uint16_t width() const { return m_width; }

 private:
  int m_x;
  int m_y;
  uint16_t m_width;
  const uint16_t m_score = 30;
};
