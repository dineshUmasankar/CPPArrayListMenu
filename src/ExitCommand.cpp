#include "ExitCommand.h"
#include "AppMessages.h"
#include <iostream>

using std::cout;
using std::endl;

void ExitCommand::execute() {
  cout << AppMessages::ExitMessage << endl;
  exit(0);
}
