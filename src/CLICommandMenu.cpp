#include "CLICommandMenu.h"
#include "AppMessages.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;

void CLICommandMenu::displayMenu() { cout << AppMessages::SelectCommandMenu; }

void CLICommandMenu::processInput(int &choice) {
  cout << AppMessages::SelectChoiceMessage;
  cin >> choice;
}

bool CLICommandMenu::validateInput(int &choice) {
  if (choice > 8) {
    cerr << AppMessages::InputErrorMessage;
    return false;
  }

  if (cin.bad()) {
    cerr << AppMessages::InputErrorMessage;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max());
    return false;
  }

  if (cin.fail()) {
    cerr << AppMessages::InputErrorMessage;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  }

  return true;
}

void CLICommandMenu::executeCommand(int &choice) {
  switch (choice) {
  case 2:
    listCmd.execute();
    break;
  case 8:
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
    if (validateInput(choice)) {
      executeCommand(choice);
    };
  } while (choice != 8);
}
