#include "AppMessages.h"
#include "Command.h"
#include "DataPool.h"
#include "InstanceMenu.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;

#ifndef ARRAYLIST_UPDATECOMMAND_H
#define ARRAYLIST_UPDATECOMMAND_H

class UpdateCommand : public Command {
private:
  InstanceMenu *menu;
  DataPool *pool;

public:
  UpdateCommand(InstanceMenu &p_menu, DataPool &p_pool) {
    menu = &p_menu;
    pool = &p_pool;
  }

  void execute() override {
    int ArrayListInstance = menu->run();

    int updateIndex;
    requestInput(updateIndex);
    try {
      if (validateInput(updateIndex)) {
        // Get data
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
    cout << AppMessages::UpdateDataMessage;
    cin >> data;
  }
};

#endif // ARRAYLIST_UPDATECOMMAND_H
