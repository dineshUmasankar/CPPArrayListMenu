#include "SaveCommand.h"
#include "DataPool.h"
#include "InstanceMenu.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

SaveCommand::SaveCommand(InstanceMenu &p_menu, DataPool &p_pool) {
  menu = &p_menu;
  pool = &p_pool;
}

void SaveCommand::execute() {
  int ArrayListInstance = menu->run();

  // switch (ArrayListInstance)
  // {
  // case 1:
  //   pool->intInstance.save();
  //   break;
  // case 2:
  //   pool->boolInstance.save();
  //   break;
  // case 3:
  //   pool->charInstance.save();
  //   break;
  // case 4:
  //   pool->doubleInstance.save();
  //   break;
  // case 5:
  //   pool->floatInstance.save();
  //   break;
  // default:
  //   break;
  // }
  cout << endl;
  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  auto temp = cin.get();
}
