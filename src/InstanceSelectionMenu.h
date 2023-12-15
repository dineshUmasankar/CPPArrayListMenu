#include "Menu.h"

#ifndef ARRAYLIST_CLI_INSTANCE_SELECTION_MENU_H
#define ARRAYLIST_CLI_INSTANCE_SELECTION_MENU_H

class InstanceSelectionMenu : public Menu {
public:
  void displayMenu();
  void run() override;
  void processInput(int &choice);
  void validateInput(int &choice);
  void executeCommand(int &choice);
};

#endif // ARRAYLIST_CLI_INSTANCE_SELECTION_MENU_H
