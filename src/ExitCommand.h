#include "Command.h"

#ifndef ARRAYLIST_EXITCOMMAND_H
#define ARRAYLIST_EXITCOMMAND_H

class ExitCommand : public Command {
public:
  void execute() override;
};

#endif // ARRAYLIST_EXITCOMMAND_H
