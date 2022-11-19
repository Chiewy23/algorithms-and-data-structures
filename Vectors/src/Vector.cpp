/*
 * Vector.cpp
 *
 *  Created on: 19 Nov 2022
 *      Author: chris
 */

#include "Vector.h"

int *arr;
int current_size;
int maximum_size;

Vector::Vector() {
	// TODO Auto-generated constructor stub
	current_size = 0;
	maximum_size = 1;
	arr = new int[maximum_size];
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

// get

// pop_back
void pop_back() {
	arr[current_size] = 0;
	if (current_size > 0) {
		current_size--;
	}
}

// push_back
void push_back(int val) {
	if (current_size == maximum_size) {
		// create a new array and delete the old one, double the capacity.
		int *old_array = arr;
		maximum_size = 2 * maximum_size;
		arr = new int[maximum_size];

		for (int i = 0; i < current_size; i++) {
			arr[i] = old_array[i];
		}

		delete [] old_array;
	}

	arr[current_size] = val;
	current_size++;
}

// front()

// back()

// size()

// capacity()

