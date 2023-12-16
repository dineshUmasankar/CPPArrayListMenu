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
        switch (ArrayListInstance) {
        case 1:
          int intData;
          requestData(intData);
          if (validateInput(intData)) {
            pool->intInstance.updateAt(updateIndex, intData);
          } else {
            cout << AppMessages::InputErrorMessage;
          }
          break;
        case 2:
          bool boolData;
          requestData(boolData);
          if (validateInput(boolData)) {
            pool->boolInstance.updateAt(updateIndex, boolData);
          } else {
            cout << AppMessages::InputErrorMessage;
          }
          break;
        case 3:
          char charData;
          requestData(charData);
          if (validateInput(charData)) {
            pool->charInstance.updateAt(updateIndex, charData);
          } else {
            cout << AppMessages::InputErrorMessage;
          }
          break;
        case 4:
          double doubleData;
          requestData(doubleData);
          if (validateInput(doubleData)) {
            pool->doubleInstance.updateAt(updateIndex, doubleData);
          } else {
            cout << AppMessages::InputErrorMessage;
          }
          break;
        case 5:
          float floatData;
          requestData(floatData);
          if (validateInput(floatData)) {
            pool->floatInstance.updateAt(updateIndex, floatData);
          } else {
            cout << AppMessages::InputErrorMessage;
          }
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
    cout << AppMessages::UpdateDataMessage;
    cin >> data;
  }

  template <typename T> void requestData(T &data) {
    cout << AppMessages::AddDataMessage;
    cin >> data;
  }
};

#endif // ARRAYLIST_UPDATECOMMAND_H
