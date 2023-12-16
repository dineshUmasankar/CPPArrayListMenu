#include "SaveCommand.h"
#include "AppMessages.h"
#include "DataPool.h"
#include "InstanceMenu.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

SaveCommand::SaveCommand(InstanceMenu &p_menu, DataPool &p_pool) {
  menu = &p_menu;
  pool = &p_pool;
}

void SaveCommand::execute() {
  int ArrayListInstance = menu->run();

  string filename;
  requestInput(filename);
  if (validateInput(filename)) {
    switch (ArrayListInstance) {
    case 1:
      pool->intInstance.save(filename);
      break;
    case 2:
      pool->boolInstance.save(filename);
      break;
    case 3:
      pool->charInstance.save(filename);
      break;
    case 4:
      pool->doubleInstance.save(filename);
      break;
    case 5:
      pool->floatInstance.save(filename);
      break;
    default:
      break;
    }
  } else {
    cout << AppMessages::OperationCanceledMessage;
  }

  cout << endl;
  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  auto temp = cin.get();
}

void SaveCommand::requestInput(std::string &input) {
  cout << AppMessages::SaveFilenameMessage;
  cin >> input;
}

bool SaveCommand::validateInput(std::string &input) {
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
