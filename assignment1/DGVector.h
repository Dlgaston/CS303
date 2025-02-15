#include <cstddef>

#ifndef DGVECTOR_H
#define DGVECTOR_H

using namespace std;

template <typename T>
class DGVector {
    static const size_t INITIAL_CAPACITY = 10;
    int cur_size{};
    int cur_capacity{};
    T* data;

  public:
  // Default constructor
  DGVector() : cur_size(0), cur_capacity(INITIAL_CAPACITY), data(new T[INITIAL_CAPACITY]) {}

  // Constructor with initial size
  explicit DGVector(T size) : cur_size(size) {  // Initialize cur_size
    cur_capacity = (INITIAL_CAPACITY > size) ? INITIAL_CAPACITY : size;
    data = new T[cur_capacity];
  }

  ~DGVector() {
    delete[] data;
  }

  // Reassigns the value at the specified index
  T& operator[](size_t index) {
    validateIndex(index);
    return data[index];
  }

  // Assigns a const variable to the value at specified index.
  const T& operator[](size_t index) const {
    validateIndex(index);
    return data[index];
  }

  // Reserve method allocates a size for the array to keep available for later use.
  void reserve(size_t new_capacity) {
    if (new_capacity > cur_capacity) {
      cur_capacity = (new_capacity > 2 * cur_capacity) ? new_capacity : 2 * cur_capacity;
      T* oldData = data;
      data = new T[cur_capacity];

      for (int i = 0; i < cur_size; i++) {
        data[i] = oldData[i];
      }

      delete[] oldData;
    }
  }

  int getSize() const {
    return cur_size;
  }
// Adds item to the end of an array, increases capacity if needed.
  void push_back(T item) {
    if (cur_size == cur_capacity) {
      reserve(2 * cur_capacity);
    }
    data[cur_size++] = item;
  }

  // Replaces an item in the array, returns the old value first and the new value second.
  std::pair<T, T> replace(T item, size_t index) {
    validateIndex(index);
    if (cur_size == cur_capacity) {
      reserve(2 * cur_capacity);
    }

    T oldItem = data[index];
    data[index] = item;

    return {oldItem, data[index]};
  }
  //Inserts an item into the vector, increments all items to the right.
  void insert(const T& item, size_t index) {
    validateIndex(index);
    if (cur_size == cur_capacity) {
      reserve(2 * cur_capacity);
    }

    for (int i = cur_size; i > index; i--) {
      data[i] = data[i - 1];
    }

    data[index] = item;
    cur_size++;
  }
  //Removes a value based on the index passed in and shifts elements to the left.
  void remove(size_t index) {
    validateIndex(index);
    for (int i = index + 1; i < cur_size; i++) {
      data[i - 1] = data[i];
    }
    cur_size--;
  }

  // Returns -1 if item not found, otherwise returns index.
  int indexOf(T item) {
    if (cur_size == 0) {
      return -1;
    }

    for (int i = 0; i < cur_size; i++) {
      if (data[i] == item) {
        return i;
      }
    }
    return -1;
  }

  // Fix validateIndex to throw exceptions properly
  void validateIndex(int index) {
    if (index >= cur_size || index < 0) {
      throw std::out_of_range("Index is out of range");
    }
  }

  void print() {
    for (int i = 0; i < cur_size; i++) {
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
  }
};

#endif //DGVECTOR_H
