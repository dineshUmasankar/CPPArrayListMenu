#ifndef ARRAYLIST_COMMAND_H
#define ARRAYLIST_COMMAND_H

class Command {
public:
  virtual ~Command() = default;
  virtual void execute() = 0;
};

#endif // ARRAYLIST_COMMAND_H
