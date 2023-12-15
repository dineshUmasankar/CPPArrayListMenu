#include "AppMessages.h"
#include "Command.h"
#include "DataPool.h"
#include "InstanceMenu.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;

#ifndef ARRAYLIST_ADDCOMMAND_H
#define ARRAYLIST_ADDCOMMAND_H

class AddCommand : public Command {
private:
  InstanceMenu *menu;
  DataPool *pool;

public:
  AddCommand(InstanceMenu &p_menu, DataPool &p_pool) {
    menu = &p_menu;
    pool = &p_pool;
  }

  void execute() override {
    int ArrayListInstance = menu->run();

    switch (ArrayListInstance) {
    case 1:
      int intData;
      requestInput(intData);
      if (validateInput(intData)) {
        pool->intInstance.add(intData);
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    case 2:
      bool boolData;
      requestInput(boolData);
      if (validateInput(boolData)) {
        pool->boolInstance.add(boolData);
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    case 3:
      char charData;
      requestInput(charData);
      if (validateInput(charData)) {
        pool->charInstance.add(charData);
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    case 4:
      double doubleData;
      requestInput(doubleData);
      if (validateInput(doubleData)) {
        pool->doubleInstance.add(doubleData);
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    case 5:
      float floatData;
      requestInput(floatData);
      if (validateInput(floatData)) {
        pool->floatInstance.add(floatData);
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    default:
      break;
    }
  }

  template <typename T> bool validateInput(T &data) {
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

  template <typename T> void requestInput(T &data) {
    cout << AppMessages::AddDataMessage;
    cin >> data;
  }
};

#endif // ARRAYLIST_ADDCOMMAND_H
