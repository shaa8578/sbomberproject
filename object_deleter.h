#pragma once

#include <memory>
#include <vector>

#include "command.hpp"

namespace cmd {

template <class T>
class ObjectDeleter : public Command {
 public:
  using PtrObj = T*;
  using ObjectVector = std::vector<PtrObj>;

  ObjectDeleter(PtrObj obj, ObjectVector* array)
      : Command(), m_deletingObject(obj), m_objectsArray(array) {}

  bool execute() override {
    PtrObj current_obj(nullptr);
    auto it = m_objectsArray->begin();
    for (; it != m_objectsArray->end(); ++it) {
      current_obj = static_cast<PtrObj>(*it);
      if (current_obj == m_deletingObject) {
        m_objectsArray->erase(it);
        delete current_obj;
        return true;
      }
    }
    return false;
  }

 private:
  /** Указатель на удаляемый объект */
  PtrObj m_deletingObject;
  /** Указатель на масив объектов, в котором нужно удалить искомый объект */
  ObjectVector* m_objectsArray;
};

} /* namespace cmd */
