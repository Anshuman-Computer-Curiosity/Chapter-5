#include <iostream>
using namespace std;
int main() {
    int rows = 3, cols = 4;

    // Allocate memory for an array of pointers (rows)
    int* arr[rows];

    // Allocate memory for each row (columns)
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    // Assign values to elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = i * cols + j;
        }
    }

    // Accessing elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory for each row
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }

    return 0;
}