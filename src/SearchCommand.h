#include "AppMessages.h"
#include "Command.h"
#include "DataPool.h"
#include "InstanceMenu.h"
#include <iostream>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;

#ifndef ARRAYLIST_SEARCHCOMMAND_H
#define ARRAYLIST_SEARCHCOMMAND_H

class SearchCommand : public Command {
private:
  InstanceMenu *menu;
  DataPool *pool;

public:
  SearchCommand(InstanceMenu &p_menu, DataPool &p_pool) {
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
        int index = pool->intInstance.indexOf(intData);
        cout << "Index: " << index << endl;
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    case 2:
      bool boolData;
      requestInput(boolData);
      if (validateInput(boolData)) {
        int index = pool->boolInstance.indexOf(boolData);
        cout << "Index : " << index << endl;
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    case 3:
      char charData;
      requestInput(charData);
      if (validateInput(charData)) {
        int index = pool->charInstance.indexOf(charData);
        cout << "Index : " << index << endl;
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    case 4:
      double doubleData;
      requestInput(doubleData);
      if (validateInput(doubleData)) {
        int index = pool->doubleInstance.indexOf(doubleData);
        cout << "Index : " << index << endl;
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    case 5:
      float floatData;
      requestInput(floatData);
      if (validateInput(floatData)) {
        int index = pool->floatInstance.indexOf(floatData);
        cout << "Index : " << index << endl;
      } else {
        cout << AppMessages::OperationCanceledMessage;
      }
      break;
    default:
      break;
    }
    cout << endl;
    cout << "Press Enter to Continue";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    auto temp = cin.get();
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
    cout << AppMessages::SearchDataMessage;
    cin >> data;
  }
};

#endif // ARRAYLIST_SEARCHCOMMAND_H
