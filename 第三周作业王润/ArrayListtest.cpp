#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include "ArrayList.h"
#pragma comment (lib, "E:\\code\\ArrayListtest\\ArrayListtest\\ArrayList.lib")


using namespace std;
//constructor
//set array size, size and data
template<class T>
ArrayList<T>::ArrayList() {
    arraySize = 10;
    size = 0;
    data = new T[arraySize];
}

//deconstructor
//cleanup objects
template <class T> ArrayList<T> :: ~ArrayList() {
    //    delete arraySize;
    //    delete size;
    delete[]data;
};

//takes in and index and returns the object associated with it
//return NULL or nothing if index is outta range
template <class T> T ArrayList<T> ::get(int index) {
    if (!isValidIndex(index)) return 0;
    return data[index];
}

//returns the index of the given obj
//or -1 if not found
template <class T> int ArrayList<T> ::indexOf(T& d) {
    for (int i = 0; i < size; i++) {
        if (data[i] == *d) return i;
    }
    return -1;
}

//adds the given data to the end of the list
//expands the list if neccisary
template <class T> void ArrayList<T> ::add(T& d) {
    if (needsExpansion()) expandArray();
    data[size++] = d;
}

//adds the given data to the given index
//expands the list if necessary
template <class T> void ArrayList<T> ::add(T& d, int index) {
    if (needsExpansion()) expandArray();
    //accept index at size
    if (!(index >= 0 && index <= size)) return;
    //move all obj's at >= index up 1
    for (int i = size - 1; i >= 0; i--) {
        if (i >= index) {
            data[i + 1] = data[i];
        }
    }
    data[index] = d;
    size++;
}

//removes the element at the given index
template <class T> bool ArrayList<T> ::remove(int index) {
    if (!isValidIndex(index)) return false;
    //shift elements down
    for (int i = index + 1; i < size; i++) {
        data[i - 1] = data[i];
    }
    //remove last element
    data[size--] = nullptr;
    return true;
}

//TRUE if the element exists in the array
//FALSE otherwise.
template <class T> bool ArrayList<T> ::contains(T& d) {
    return indexOf(d) >= 0;
}

//clears out the data that this arraylist holds
template <class T> void ArrayList<T> ::clear() {
    size = 0;
    arraySize = 2;
    delete[]data;
    *data = new T[arraySize];
}

//TRUE if this array list has no elements.
template <class T> bool ArrayList<T> ::isEmpty() {
    return size == 0;
}

//TRUE if this array needs to be expanded.
//needs expansion if it is full.
template<class T> bool ArrayList<T> ::needsExpansion() {
    return size >= arraySize;
}

//expands the array by twice the given size
template<class T> void ArrayList<T> ::expandArray() {
    arraySize+=100;    //arraySize*=2;
    T* newData = new T[arraySize];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[]data;
    data = newData;
}

//check if the index is valid
template<class T>
bool ArrayList<T>::isValidIndex(int index) {
    return index >= 0 && index < size;
}

int main() {

	for (int i = 10; i <= 30; i++) {

		int n = pow(2, i);
		int& r = i;

		clock_t startTime = clock();
		ArrayList<int> vec;
		for (int num = 0; num < n; num++)
			vec.add(r);

		clock_t endTime = clock();

		cout << 2 * n << " operations: \t";
		cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
	system("pause");
	return 0;
}