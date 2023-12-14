#include "Command.h"

#ifndef ARRAYLIST_UPDATECOMMAND_H
#define ARRAYLIST_UPDATECOMMAND_H

class UpdateCommand : public Command {
public:
  void execute() override;
};

#endif // ARRAYLIST_UPDATECOMMAND_H
