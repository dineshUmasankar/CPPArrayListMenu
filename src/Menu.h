#ifndef ARRAYLIST_MENU_H
#define ARRAYLIST_MENU_H

class Menu {
public:
  virtual ~Menu() = default;
  virtual void run() = 0;
};

#endif // ARRAYLIST_MENU_H
