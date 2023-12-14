#include "Command.h"
#include "ExitCommand.h"
#include <iostream>

int main() {
  ExitCommand exitcmd;
  exitcmd.execute();
  return 0;
}
