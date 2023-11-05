#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	int size;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Enter number: ";
	cin >> size;

	const int rows = 1;
	const int cols = 10;

	int arr[rows][cols];

	SetConsoleTextAttribute(hConsole, 11);

	for (int j = 0; j < cols; j++) {
		arr[0][j] = size + (j + 1);
	}

	for (int j = 0; j < cols; j++) {
		cout << arr[0][j] << " ";
	}
	cout << endl;

	SetConsoleTextAttribute(hConsole, 7);

	return 0;
}