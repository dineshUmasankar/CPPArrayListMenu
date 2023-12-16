#include "Command.h"
#include "DataPool.h"
#include "InstanceMenu.h"

#ifndef ARRAYLIST_SORTCOMMAND_H
#define ARRAYLIST_SORTCOMMAND_H

class SortCommand : public Command {
private:
  InstanceMenu *menu;
  DataPool *pool;

public:
  SortCommand(InstanceMenu &p_menu, DataPool &p_pool);
  void execute() override;
};

#endif // ARRAYLIST_SORTCOMMAND_H
