#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
template <class T> class ArrayList {

public:
    // Constructor to initialize the list.
    ArrayList();

    // Destructor to clean up the list.
    ~ArrayList();

    // Finds a specifies element of the array list based on the index. Returns null if nothing.
    T get(int index);

    //Finds the index of the given element.
    int indexOf(T& d);

    // Inserts an element at the end of the list.
    void add(T& d);

    // Inserts an element at a specified position in the array list.
    void add(T& d, int position);

    // Deletes the element at the given index.
    //TRUE if successful
    bool remove(int index);

    //TRUE if this array contains the given data
    bool contains(T& d);

    // Empties/clears out the array list structure.
    void clear();

    // Tests to see if the array list structure is empty.
    bool isEmpty();

    // Returns the size of the array.
    inline int listSize() { return size; }

private:

    int arraySize;// Size of the array.
    int size; // Number of elements in the array.
    T* data = nullptr;// Pointer to the array.

    // Checks if the array is full of elements.
    bool needsExpansion();

    //makes space in the array by doubling the arraySize
    void expandArray();

    //returns TRUE if the given index is in range (0 -> size)
    bool isValidIndex(int index);
};