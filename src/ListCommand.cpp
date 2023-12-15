#include "ListCommand.h"
#include "DataPool.h"
#include "InstanceMenu.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;

ListCommand::ListCommand(InstanceMenu &p_menu, DataPool &p_pool) {
  menu = &p_menu;
  pool = &p_pool;
}

void ListCommand::execute() {
  int ArrayListInstance = menu->run();

  switch (ArrayListInstance) {
  case 1:
    pool->intInstance.list();
    break;
  case 2:
    pool->boolInstance.list();
    break;
  case 3:
    pool->charInstance.list();
    break;
  case 4:
    pool->doubleInstance.list();
    break;
  case 5:
    pool->floatInstance.list();
    break;
  case 6:
    return;
  default:
    break;
  }

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  auto temp = cin.get();
}
