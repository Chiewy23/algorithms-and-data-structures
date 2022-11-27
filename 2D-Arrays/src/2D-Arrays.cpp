#include <iostream>
#include<tuple>

using namespace std;

// The no. of columns must be declared but rows can be skipped.
void print_2d_array(int arr[][100], int rows, int cols) {
    for (int row  = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}


void two_dim_array_basics() {

    //[rows][columns]
    //int arr[100][100];

    char numbers[][10] = {
        "one",
        "two",
        "three",
        "four"
    };

    // Print the entire row.
    // This only works for char arrays.
    cout << numbers[1]; // "two"
}


/*
Spiral Print: Write a function which takes in an n*m 2D array
and prints all array elements in a spiral order. Start from the
top left corner, then go right, and proceed in a spiral pattern.

Input:

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/
void print_spiral(int arr[][4], int n, int m) {

    // We define one iteration as one complete boundary traversal of the array.
    // In the next iteration, we complete the next boundary.
    // For an array with n rows, we would need ~n/2 iterations.
    int startRow = 0;
    int endRow = n - 1;
    int startCol = 0;
    int endCol = m - 1;

    while(startCol <= endCol and startRow <= endCol) {
        // Start Row
        for (int col = startCol; col <= endCol; col++) {
            cout << arr[startRow][col] << " ";
        }

        // End col
        for (int row = startRow + 1; row <= endRow; row++) {
            cout << arr[row][endCol] << " ";
        }

        // End row
        for (int col = endCol - 1; col >= startCol; col--) {
            if (startRow == endRow) {
                break;
            }
            cout << arr[endRow][col] << " ";
        }

        // Start col
        for (int row = endRow - 1; row >= startRow + 1; row--) {
            // Avoid duplicate printing of elements
            if (startCol == endCol) {
                break;
            }
            cout << arr[row][startCol] << " ";
        }

        // Update the variables to point to innder spiral
        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
}


// Sorted array search.
tuple<int, int> staircase_search(int arr[][4], int n, int m, int targetValue) {
    // Start at final element of first row.
    // If element larger than targetValue, decrement column.
    // If element smaller than targetValue, increment row.

    // If column < 0 then break.
    // If row > n then break.

    int row = 0;
    int col = m - 1;
    tuple<int, int> targetValueIndex = make_tuple(-1, -1);

    while(true) {
        int value = arr[row][col];

        if (value == targetValue) {
            cout << "Value found at index (" << row << ", " << col << ")" << endl;
            return tuple(row, col);
        } else if (value > targetValue) {
            col--;
        } else if (value < targetValue) {
            row++;
        }

        if (col < 0 || row > n) {
            break;
        }
    }
    cout << "Value not in array" << endl;
    return targetValueIndex;
}


/**
 * Mango Trees: A farmer has a farm organised as an N x N grid. Each square in the grid
 * either has or does not have a mango tree. He has to divide the farm with his three siblings as
 * follows:
 *  - He will draw one horizontal line and one vertical line to divide the field into four rectangles.
 *  - His friends will choose three of the four smaller fields and he gets the last one.
 *
 * The question is, what is the max number of trees the farmer will get?
 *
 * Let M[x, y] be the number of mango trees in the rectangle between (0, 0) and (x, y).
 * We can calculate M[x, y] as follows:
 *
 *      M[x, y] = 1 + M[x-1, y] + M[x, y-1] - M[x-1, y-1] if tree at (x, y).
 *      M[x, y] = 0 + M[x-1, y] + M[x, y-1] - M[x-1, y-1] if no treet at (x, y).
 *
 * Top right rectangle:
 *
 *      M[N, y] - M[x, y] : Number of mangos in rectangle defined by (x, y) and (N, 0).
 *
 * Bottom left rectangle:
 *
 *      M[x, N] - M[x, y] : Number of mangos in rectangle defined by (0, N) and (x, y)
*/

int main() {
    // auto result = (10 <=> 20) > 0;
    // std::cout << result << std::endl;

//    int arr[][4] = {
//        {1, 2, 3, 4},
//        {14, 15, 16, 5},
//        {13, 20, 17, 6},
//        {12, 19, 18, 7},
//        {11, 10, 9, 8}
//    };
//
//    int arr_two[][4] = {
//        {10, 20, 30, 40},
//        {15, 25, 35, 45},
//        {27, 29, 37, 48},
//        {32, 33, 39, 50}
//    };

    // print_spiral(arr, 5, 4);
    // tuple<int, int> result1 = staircase_search(arr_two, 4, 4, 37);
    // tuple<int, int> result2 = staircase_search(arr_two, 4, 4, 50);
    // tuple<int, int> result3 = staircase_search(arr_two, 4, 4, 10);
    // tuple<int, int> result4 = staircase_search(arr_two, 4, 4, 25);
    // tuple<int, int> result5 = staircase_search(arr_two, 4, 4, 9);
}
