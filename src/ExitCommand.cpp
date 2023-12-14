#include "ExitCommand.h"
#include <iostream>

using std::cout;
using std::endl;

void ExitCommand::execute()
{
  cout << "Exiting Program..." << endl;
  exit(0);
}
