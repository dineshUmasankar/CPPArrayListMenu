#include "CLICommandMenu.h"
#include "AppMessages.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;

void CLICommandMenu::displayMenu() { cout << AppMessages::SelectCommandMenu; }

void CLICommandMenu::requestInput(int &choice) {
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
  case 1:
    addCmd.execute();
    break;
  case 2:
    listCmd.execute();
    break;
  case 3:
    searchCmd.execute();
    break;
  case 4:
    deleteCmd.execute();
    break;
  case 5:
    cout << "Not Implemented." << endl;
    break;
  case 6:
    saveCmd.execute();
    break;
  case 7:
    cout << "Not Implemented." << endl;
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
    requestInput(choice);
    if (validateInput(choice)) {
      executeCommand(choice);
    };
  } while (choice != 8);
}
