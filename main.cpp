#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const int rows = 2;
    const int cols = 6;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; 
        }
    }

    cout << "Initial array:" << endl;
    printMatrix(matrix, rows, cols);

    int shifts;
    cout << "Enter the number of shifts: ";
    cin >> shifts;

    char direction;
    cout << "Choose a direction (L - left, R - to the right, U - upp, D - down): ";
    cin >> direction;

    shifts %= (direction == 'L' || direction == 'R') ? cols : rows; 

    if (direction == 'L' || direction == 'l') {
        for (int i = 0; i < rows; i++) {
            for (int s = 0; s < shifts; s++) {
                int temp = matrix[i][0];
                for (int j = 0; j < cols - 1; j++) {
                    matrix[i][j] = matrix[i][j + 1];
                }
                matrix[i][cols - 1] = temp;
            }
        }
    }
    else if (direction == 'R' || direction == 'r') {
        for (int i = 0; i < rows; i++) {
            for (int s = 0; s < shifts; s++) {
                int temp = matrix[i][cols - 1];
                for (int j = cols - 1; j > 0; j--) {
                    matrix[i][j] = matrix[i][j - 1];
                }
                matrix[i][0] = temp;
            }
        }
    }
    else if (direction == 'U' || direction == 'u') {
        for (int i = 0; i < cols; i++) {
            for (int s = 0; s < shifts; s++) {
                int temp = matrix[0][i];
                for (int j = 0; j < rows - 1; j++) {
                    matrix[j][i] = matrix[j + 1][i];
                }
                matrix[rows - 1][i] = temp;
            }
        }
    }
    else if (direction == 'D' || direction == 'd') {
        for (int i = 0; i < cols; i++) {
            for (int s = 0; s < shifts; s++) {
                int temp = matrix[rows - 1][i];
                for (int j = rows - 1; j > 0; j--) {
                    matrix[j][i] = matrix[j - 1][i];
                }
                matrix[0][i] = temp;
            }
        }
    }

    cout << "The array after the landslide:" << endl;
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
