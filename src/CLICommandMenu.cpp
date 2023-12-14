#include "CLICommandMenu.h"
#include "AppMessages.h"
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;

void CLICommandMenu::displayMenu() { cout << AppMessages::SelectCommandMenu; }

void CLICommandMenu::processInput(int &choice) {
  cout << AppMessages::SelectChoiceMessage;
  cin >> choice;

  if (cin.fail()) {
    cout << AppMessages::InputErrorMessage;
    choice = 0;
  }
}

void CLICommandMenu::validateInput(int &choice) {
  if (choice > 9) {
    cerr << AppMessages::InputErrorMessage;
    choice = 0;
  }
}

void CLICommandMenu::executeCommand(int &choice) {
  switch (choice) {
  case 9:
    exitCmd.execute();
    break;
  default:
    break;
  }
}

void CLICommandMenu::run() {
  int choice;

  do {
    displayMenu();
    processInput(choice);
    validateInput(choice);
    executeCommand(choice);
  } while (choice != 9);
}
