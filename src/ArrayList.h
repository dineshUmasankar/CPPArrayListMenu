#include <iostream>
#include <memory>
#include <stdexcept>

#ifndef ARRAYLIST
#define ARRAYLIST

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

template <typename T> class ArrayList {
private:
  unique_ptr<T[]> array;
  int size;
  int capacity;
  const int initialCapacity = 10;

  void resize() {
    capacity *= 2;
    unique_ptr<T[]> newArray = make_unique<T[]>(capacity);
    for (int index = 0; index < size; ++index) {
      newArray[index] = array[index];
    }
    array = std::move(newArray);
  }

public:
  ArrayList() {
    size = 0;
    capacity = 10;
    array = make_unique<T[]>(capacity);
  }

  void add(const T &element) {
    if (size == capacity) {
      resize();
    }

    array[size++] = element;
  }

  int getSize() const { return size; }

  T &operator[](int index) {
    if (index >= size) {
      throw std::out_of_range("Index out of bounds");
    }

    return array[index];
  }

  void list() {
    for (int index = 0; index < size; ++index) {
      cout << array[index] << " ";
    }
  }

  ~ArrayList() {
    // The Destructor of std::unique_ptr will automatically release the memory.
  }
};

#endif // ARRAYLIST