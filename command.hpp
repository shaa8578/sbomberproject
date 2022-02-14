#pragma once

namespace cmd {

struct Command {
  virtual ~Command() {}

  virtual bool execute() = 0;
};

} /*namespace cmd */
