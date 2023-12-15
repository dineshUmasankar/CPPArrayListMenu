#include "AppMessages.h"
#include "Command.h"
#include "DataPool.h"
#include "InstanceMenu.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;

#ifndef ARRAYLIST_DELETE_COMMAND_H
#define ARRAYLIST_DELETE_COMMAND_H

class DeleteCommand : public Command {
private:
  InstanceMenu *menu;
  DataPool *pool;

public:
  DeleteCommand(InstanceMenu &p_menu, DataPool &p_pool) {
    menu = &p_menu;
    pool = &p_pool;
  }

  void execute() override {
    int ArrayListInstance = menu->run();
    int delIndex;
    requestInput(delIndex);
    try {
      if (validateInput(delIndex)) {
        switch (ArrayListInstance) {
        case 1:
          pool->intInstance.removeAt(delIndex);
          break;
        case 2:
          pool->boolInstance.removeAt(delIndex);
          break;
        case 3:
          pool->charInstance.removeAt(delIndex);
          break;
        case 4:
          pool->doubleInstance.removeAt(delIndex);
          break;
        case 5:
          pool->floatInstance.removeAt(delIndex);
          break;
        default:
          break;
        }
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
    } catch (std::out_of_range) {
      cout << AppMessages::OperationCanceledMessage;
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
    cout << AppMessages::DeleteDataMessage;
    cin >> data;
  }
};

#endif // ARRAYLIST_DELETE_COMMAND_H
