#include <iostream>
#include <vector>

#include "CustomVector.h"

using namespace std;

void vector_basics();
void two_dimensional_vector();

/*
 * Vectors are sequence containers representing arrays which can
 * change in size.
 *
 * Just like arrays, vectors use contiguous storage locations for
 * their elements, which means their elements can also be accessed directly
 * in O(1) time.
 *
 * Unlike arrays, their size can change dynamically, with their storage
 * being handled automatically by the container.
 */
int main() {
	//vector_basics();
	//two_dimensional_vector();
	CustomVector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	return 0;
}

void vector_basics() {
	vector<int> arr = {1, 2, 3};

	// No. of elements.
	cout << arr.size() << endl;

	// Capacity of the vector.
	cout << arr.capacity() << endl;
	arr.push_back(5);
	cout << arr.capacity() << endl;

	// Remove last element.
	arr.pop_back();

	// Fill constructor example.
	// 10 elements of value 7.
	vector<int> arr2(10, 7);
}

void two_dimensional_vector() {
	// Note that each row can have a different number of elements.
	vector<vector<int>> arr = { {1, 2, 3}, {4, 5, 6}, {11, 12, 34, 56} };

	for (vector<int> vec : arr) {
		for (int val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
}
