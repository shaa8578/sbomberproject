#include "bomb_const_iterator.h"

#include <algorithm>

#include "bomb.h"

//------------------------------------------------------------------------------
BombConstIterator BombConstIterator::end(const DynamicObjectArray& objects) {
  return BombConstIterator(objects.end(), objects.end());
}

BombConstIterator BombConstIterator::begin(const DynamicObjectArray& objects) {
  return BombConstIterator(objects.begin(), objects.end());
}

//------------------------------------------------------------------------------
BombConstIterator& BombConstIterator::operator++() {
  nextPosition();
  findBombObjectIterator();
  return *this;
}

BombConstIterator BombConstIterator::operator++(int) {
  BombConstIterator result(*this);
  ++(*this);
  return result;
}

//------------------------------------------------------------------------------
bool BombConstIterator::operator==(const BombConstIterator& rhs) const {
  return this->m_position == rhs.m_position;
}

bool BombConstIterator::operator!=(const BombConstIterator& rhs) const {
  return this->m_position != rhs.m_position;
}

//------------------------------------------------------------------------------
Bomb* BombConstIterator::operator*() const {
  /* Оператор всегда вызывается, на искомом значении,
   * поэтому нет смысла использвоать dynamic_cast */
  return static_cast<Bomb*>(*m_position);
}

//------------------------------------------------------------------------------
BombConstIterator::BombConstIterator(
    BombConstIterator::DynamicObjectArray::const_iterator position,
    BombConstIterator::DynamicObjectArray::const_iterator end)
    : m_position(position), m_end(end) {
  findBombObjectIterator();
}

//------------------------------------------------------------------------------
void BombConstIterator::nextPosition() {
  ++m_position;
}

void BombConstIterator::findBombObjectIterator() {
  m_position =
      std::find_if(m_position, m_end, std::ptr_fun(BombConstIterator::isBomb));
}

bool BombConstIterator::isBomb(DynamicObject* testObject) {
  auto test_bomb = dynamic_cast<Bomb*>(testObject);
  return test_bomb != nullptr;
}
