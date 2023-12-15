#include "InstanceSelectionMenu.h"
#include "AppMessages.h"
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;

void InstanceSelectionMenu::displayMenu() {
  cout << AppMessages::SelectCommandMenu;
}

void InstanceSelectionMenu::processInput(int &choice) {
  cout << AppMessages::SelectInstanceMenu;
  cin >> choice;

  if (cin.fail()) {
    cout << AppMessages::InputErrorMessage;
    choice = 0;
  }
}

void InstanceSelectionMenu::validateInput(int &choice) {
  if (choice > 6) {
    cerr << AppMessages::InputErrorMessage;
    choice = 0;
  }
}

void InstanceSelectionMenu::executeCommand(int &choice) {
  switch (choice) {
  default:
    break;
  }
}

void InstanceSelectionMenu::run() {
  int choice;

  do {
    displayMenu();
    processInput(choice);
    validateInput(choice);
    executeCommand(choice);
  } while (choice != 9);
}
