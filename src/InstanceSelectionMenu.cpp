#include "InstanceSelectionMenu.h"
#include "AppMessages.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;

void InstanceSelectionMenu::displayMenu() {
  cout << AppMessages::SelectInstanceMenu;
}

void InstanceSelectionMenu::processInput(int &choice) {
  cout << AppMessages::SelectChoiceMessage;
  cin >> choice;
}

bool InstanceSelectionMenu::validateInput(int &choice) {
  if (choice > 6) {
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

void InstanceSelectionMenu::run() {
  int choice;

  do {
    displayMenu();
    processInput(choice);
    validateInput(choice);
  } while (choice != 6);
}
