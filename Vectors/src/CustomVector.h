#ifndef CUSTOMVECTOR_H_
#define CUSTOMVECTOR_H_

template<typename T>

class CustomVector {

	T *arr;
	int current_size;
	int maximum_size;

public:
	CustomVector(int max_size = 1) {
		current_size = 0;
		maximum_size = max_size;
		arr = new T[maximum_size];
	}

	~CustomVector() {

	}

	void pop_back() {
		arr[current_size] = 0;
		if (current_size > 0) {
			current_size--;
		}
	}

	void push_back(const T val) {
		if (current_size == maximum_size) {
			// create a new array and delete the old one, double the capacity.
			T *old_array = arr;
			maximum_size = 2 * maximum_size;
			arr = new T[maximum_size];

			for (int i = 0; i < current_size; i++) {
				arr[i] = old_array[i];
			}

			delete [] old_array;
		}

		arr[current_size] = val;
		current_size++;
	}

	T front() {
		return arr[0];
	}

	T back() {
		return arr[current_size - 1];
	}

	int size() {
		return current_size;
	}

	int capacity() {
		return maximum_size;
	}
};

#endif /* CUSTOMVECTOR_H_ */
