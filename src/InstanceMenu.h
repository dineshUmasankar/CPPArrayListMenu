#ifndef ARRAYLIST_INSTANCE_MENU_H
#define ARRAYLIST_INSTANCE_MENU_H

class InstanceMenu {
public:
  int run();
  void displayMenu();
  void requestInput(int &choice);
  bool validateInput(int &choice);
};

#endif // ARRAYLIST_INSTANCE_MENU_H
