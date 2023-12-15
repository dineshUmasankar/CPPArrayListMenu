#include "ExitCommand.h"
#include "ListCommand.h"
#include "Menu.h"

#ifndef ARRAYLIST_CLI_COMMAND_MENU_H
#define ARRAYLIST_CLI_COMMAND_MENU_H

class CLICommandMenu : public Menu {
private:
  ExitCommand exitCmd;
  ListCommand listCmd;

public:
  void displayMenu();
  void run() override;
  void requestInput(int &choice);
  bool validateInput(int &choice);
  void executeCommand(int &choice);
};

#endif // ARRAYLIST_CLI_COMMAND_MENU_H
