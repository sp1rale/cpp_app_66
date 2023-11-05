#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int rows = 5;
    const int cols1 = 10;
    const int cols2 = 5;

    int array1[rows][cols1];
    int array2[rows][cols2];

    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols1; j++) {
            array1[i][j] = rand() % 51; 
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols2; j++) {
            array2[i][j] = array1[i][2 * j] + array1[i][2 * j + 1];
        }
    }

    cout << "The first array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }

    
    cout << "The second array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << array2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
