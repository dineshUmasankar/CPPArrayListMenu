#include "DataPool.h"
#include "ExitCommand.h"
#include "InstanceMenu.h"
#include "ListCommand.h"
#include "Menu.h"

#ifndef ARRAYLIST_CLI_COMMAND_MENU_H
#define ARRAYLIST_CLI_COMMAND_MENU_H

class CLICommandMenu : public Menu {
private:
  InstanceMenu instanceMenu;
  DataPool instanceData;
  ExitCommand exitCmd;
  ListCommand listCmd = ListCommand(instanceMenu, instanceData);

public:
  void displayMenu();
  void run() override;
  void requestInput(int &choice);
  bool validateInput(int &choice);
  void executeCommand(int &choice);
};

#endif // ARRAYLIST_CLI_COMMAND_MENU_H
