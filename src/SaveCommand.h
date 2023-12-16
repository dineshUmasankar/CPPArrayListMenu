#include "Command.h"
#include "DataPool.h"
#include "InstanceMenu.h"

#ifndef ARRAYLIST_SAVECOMMAND_H
#define ARRAYLIST_SAVECOMMAND_H

class SaveCommand : public Command {
private:
  InstanceMenu *menu;
  DataPool *pool;

public:
  SaveCommand(InstanceMenu &p_menu, DataPool &p_pool);
  void execute() override;
  void requestInput(std::string &input);
  bool validateInput(std::string &input);
};

#endif // ARRAYLIST_SAVECOMMAND_H
