#include <iostream>
using namespace std;

void pointer_basics();
void references_variables();
void pass_by_reference(int &income);
void pass_by_reference_pointer(int *myNum);
void dynamic_memory_allocation_example();
int** dynamic_memory_allocation_2d_array(int rows, int cols);


int main() {
//	pointer_basics();
//	references_variables();

//	int myIncome = 10000;
//	pass_by_reference(myIncome);
//	cout << myIncome << endl;

//	int myNum = 100;
//	pass_by_reference_pointer(&myNum);
//	cout << myNum << endl;

//	dynamic_memory_allocation_example();

	int **arr = dynamic_memory_allocation_2d_array(5, 50);
	for (int i = 0; i < 5;  i++) {
		for (int j = 0; j < 50; j++) {
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}

	delete [] arr;

	return 0;
}

void pointer_basics() {
	// To get the address of a variable, use the
	// address-of operator (&).
	int x = 56;
	cout << &x << endl;
	cout << "\n";

	// A pointer is a variable which holds the address of another
	// variable.
	int y = 34;
	int *y_ptr = &y;

	cout << "Address of y: " << &y << endl;
	cout << "Value of y_ptr: " << y_ptr << endl;
	cout << "\n";

	// Get the value stored at address referenced by pointer
	// using dereferencing operator (*).
	cout << "Value of y: " << y << endl;
	cout << "Value referenced by y_ptr: " << *y_ptr << endl;
	cout << "\n";

	// The address of y_ptr is accessed as usual using
	// the address-of operator (&).
	cout << "Address of y_ptr: " << &y_ptr << endl;
	cout << "\n";

	// We can store the address of a pointer
	// in another pointer...
	int z = 87;
	int *z_ptr = &z;
	int **z_ptr_pr = &z_ptr;

	cout << "Address of z: " << &z << endl;
	cout << "Value of z_ptr: " << z_ptr << endl;

	cout << "Address of z_ptr: " << &z_ptr << endl;
	cout << "Value stored in z_ptr_ptr: " << z_ptr_pr << endl;

	cout << "Value of z: " << z << endl;
	cout << "Dereferencing z_ptr: " << *z_ptr << endl;
	cout << "Dereferencing z_ptr_ptr: " << *(*z_ptr_pr) << endl;
}

void references_variables() {
	// Pass objects by reference in two ways.
	// One way uses pointers.
	// The other uses references variables.

	// References variables create an alias
	// for the same object.
	int x = 10;
	int &y = x; // y is the reference variable in this example.

	cout << "x value: " << x << endl;
	cout << "y value: " << y << endl;

	x++;
	cout << "x value: " << x << endl;
	cout << "y value: " << y << endl;
}


void pass_by_reference(int &income) {
	float tax = 0.10;
	income = income - (income * tax);
}


void pass_by_reference_pointer(int *myNum) {
	*myNum = *myNum + 1;
}


void dynamic_memory_allocation_example() {
	int n = 50;

	// create dynamic array
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i;
		cout << i << " ";
	}

	// clear dynamic array
	delete [] arr;
}


int** dynamic_memory_allocation_2d_array(int rows, int cols) {
	int **arr = new int*[rows];

	for (int i = 0; i < rows; i++) {

		// allocate memory for each row.
		arr[i] = new int[cols];

		for (int j = 0; j < cols; j++) {
			// intialise each row.
			arr[i][j] = j;
		}
	}

	return arr;
}
