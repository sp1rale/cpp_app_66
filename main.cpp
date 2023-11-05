#include <iostream>
#include <climits>
using namespace std;


int main()
{
	const int rows = 3;
	const int cols = 5;
	int arr[rows][cols] = { 
		{ 1, 2, 3, 4, 5 },
	    { 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 }
	    };
	int sum = 0;
	int max = INT_MIN;
	int min = INT_MAX;

	for (int i = 0; i < rows; i++)
	{
		
		for (int j = 0; j < cols; j++){
			sum += arr[i][j];

			if (arr[i][j] < min){
				min = arr[i][j];
			}
			if (arr[i][j] > max){
				max = arr[i][j];
			}
		}
	}
	double average = static_cast<double>(sum) / (rows * cols);
	cout << "Sum is " << sum << endl;
	cout << "Average is " << average << endl;
	cout << "Max is " << max << endl;
	cout << "Min is " << min << endl;

	return 0;
}