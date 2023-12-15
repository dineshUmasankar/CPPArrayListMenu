#include "ArrayList.h"

#ifndef ARRAYLIST_DATAPOOL_H
#define ARRAYLIST_DATAPOOL_H

class DataPool {
public:
  ArrayList<int> intInstance;
  ArrayList<double> doubleInstance;
  ArrayList<char> charInstance;
  ArrayList<float> floatInstance;
  ArrayList<bool> boolInstance;
};

#endif // ARRAYLIST_DATAPOOL_H
