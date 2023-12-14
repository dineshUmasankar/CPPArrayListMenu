#include "Command.h"

#ifndef ARRAYLIST_DELETECOMMAND_H
#define ARRAYLIST_DELETECOMMAND_H

class DeleteCommand : public Command {
public:
  void execute() override;
};

#endif // ARRAYLIST_DELETECOMMAND_H
