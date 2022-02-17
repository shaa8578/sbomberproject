#pragma once

#include <dynamic_object.h>

#include <iterator>
#include <vector>

//------------------------------------------------------------------------------
class Bomb;

//------------------------------------------------------------------------------
class BombConstIterator
    : public std::iterator<std::input_iterator_tag, const DynamicObject*,
                           std::ptrdiff_t, const Bomb**, Bomb*> {
 public:
  using DynamicObjectArray = std::vector<DynamicObject*>;

  static BombConstIterator end(const DynamicObjectArray& objects);
  static BombConstIterator begin(const DynamicObjectArray& objects);

  BombConstIterator& operator++();
  BombConstIterator operator++(int);

  bool operator==(const BombConstIterator& rhs) const;
  bool operator!=(const BombConstIterator& rhs) const;

  Bomb* operator*() const;

 protected:
  BombConstIterator(DynamicObjectArray::const_iterator position,
                    DynamicObjectArray::const_iterator end);

  void nextPosition();
  void findBombObjectIterator();
  static bool isBomb(DynamicObject* testObject);

 private:
  DynamicObjectArray::const_iterator m_position;
  DynamicObjectArray::const_iterator m_end;
};
