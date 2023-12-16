#include "SortCommand.h"
#include "DataPool.h"
#include "InstanceMenu.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

SortCommand::SortCommand(InstanceMenu &p_menu, DataPool &p_pool)
{
  menu = &p_menu;
  pool = &p_pool;
}

void SortCommand::execute()
{
  int ArrayListInstance = menu->run();

  switch (ArrayListInstance)
  {
  case 1:
    pool->intInstance.sort();
    pool->intInstance.list();
    break;
  case 2:
    pool->boolInstance.sort();
    pool->boolInstance.list();
    break;
  case 3:
    pool->charInstance.sort();
    pool->charInstance.list();
    break;
  case 4:
    pool->doubleInstance.sort();
    pool->doubleInstance.list();
    break;
  case 5:
    pool->floatInstance.sort();
    pool->floatInstance.list();
    break;
  default:
    break;
  }
  cout << endl;
  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  auto temp = cin.get();
}
