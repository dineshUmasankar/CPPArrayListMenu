#include "Command.h"
#include "DataPool.h"
#include "InstanceMenu.h"

#ifndef ARRAYLIST_LISTCOMMAND_H
#define ARRAYLIST_LISTCOMMAND_H

class ListCommand : public Command {
private:
  InstanceMenu *menu;
  DataPool *pool;

public:
  ListCommand(InstanceMenu &p_menu, DataPool &p_pool);
  void execute() override;
};

#endif // ARRAYLIST_LISTCOMMAND_H
