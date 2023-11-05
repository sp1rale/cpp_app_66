#include <iostream>
using namespace std;

int main() {
	int size;
	cout << "Enter number: ";
	cin >> size;
	const int rows = 1;
	const int cols = 10;

	int arr[rows][cols];

	for (int j = 0; j < cols; j++) {
		arr[0][j] = size;
		size *= 2;
		}

	for (int j = 0; j < cols; j++) {
		cout << arr[0][j] << " ";

	}

	cout << endl;

		return 0;

}
