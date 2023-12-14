#include "Command.h"

#ifndef ARRAYLIST_SAVECOMMAND_H
#define ARRAYLIST_SAVECOMMAND_H

class SaveCommand : public Command {
public:
  void execute() override;
};

#endif // ARRAYLIST_SAVECOMMAND_H
