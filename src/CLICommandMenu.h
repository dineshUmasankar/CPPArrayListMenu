#include "AddCommand.h"
#include "DataPool.h"
#include "DeleteCommand.h"
#include "ExitCommand.h"
#include "InstanceMenu.h"
#include "ListCommand.h"
#include "Menu.h"
#include "SearchCommand.h"

#ifndef ARRAYLIST_CLI_COMMAND_MENU_H
#define ARRAYLIST_CLI_COMMAND_MENU_H

class CLICommandMenu : public Menu {
private:
  InstanceMenu instanceMenu;
  DataPool instanceData;
  ExitCommand exitCmd;
  AddCommand addCmd = AddCommand(instanceMenu, instanceData);
  ListCommand listCmd = ListCommand(instanceMenu, instanceData);
  SearchCommand searchCmd = SearchCommand(instanceMenu, instanceData);
  DeleteCommand deleteCmd = DeleteCommand(instanceMenu, instanceData);

public:
  void displayMenu();
  void run() override;
  void requestInput(int &choice);
  bool validateInput(int &choice);
  void executeCommand(int &choice);
};

#endif // ARRAYLIST_CLI_COMMAND_MENU_H
