#include "InstanceMenu.h"
#include "AppMessages.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;

void InstanceMenu::displayMenu() { cout << AppMessages::SelectInstanceMenu; }

void InstanceMenu::requestInput(int &choice) {
  cout << AppMessages::SelectChoiceMessage;
  cin >> choice;
}

bool InstanceMenu::validateInput(int &choice) {
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

int InstanceMenu::run() {
  int choice;

  do {
    displayMenu();
    requestInput(choice);
    if (validateInput(choice)) {
      break;
    }
  } while (choice != 6);

  return choice;
}
