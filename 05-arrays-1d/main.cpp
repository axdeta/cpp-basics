#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

void PrintProductEvenIndexes(int array[], int size) {
	cout << "Multiplication of elements with even indices: (";
	cout << array[0] << ")";

	int product = array[0];

	for (int i = 2; i < size; i += 2)
	{
		product *= array[i];
		cout << "*(" << array[i] << ")";
	}

	cout << " = " << product << endl << endl;
}

void PrintSumBetweenZeros(int array[],
	int first_zero_index,
	int last_zero_index) {
	int sum_between_zeros = 0;

	cout << "Sum between first and last zeros -> ";
	if ((first_zero_index == -1) |
		((last_zero_index - first_zero_index) < 2)) {
		cout << "Error: the necessary conditions are not met" << endl;
	}
	else {
		cout << "Sum = 0";
		for (int i = first_zero_index; i < last_zero_index; i++) {
			if (array[i] != 0) {
				sum_between_zeros += array[i];
				cout << "+" << "(" << array[i] << ")";
			}
		}
		cout << "+0 = " << sum_between_zeros << endl;
	}
	cout << endl;
}

void PrintArray(int array[], int size) {
	cout << string(61, '-') << endl;
	cout << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(2) << "[" << i << "]" << setw(2) << "|";
	}

	cout << "<- Index";
	cout << endl << string(61, '-') << endl << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(3) << array[i] << setw(3) << "|";
	}

	cout << "<- array[i]";
	cout << endl;
	cout << string(61, '-') << endl;
	cout << endl;
}

void SortArray(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if ((array[j] < 0)&(array[j + 1] >= 0)) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

int main() {
	int const kArraySize = 10;
	int array[kArraySize],
		first_zero_index = -1, // -1 = While item is missing 
		last_zero_index = -1;  // -1 = While item is missing 

	srand((unsigned)time(NULL));

	//generation array
	for (int i = 0; i < kArraySize; i++) {
		array[i] = int(pow(-1, rand() % 2))*(rand() % 10); //[-9..9]
		if ((array[i] == 0) & !(first_zero_index >= 0)) {
			first_zero_index = i;
		}
		if (array[i] == 0) {
			last_zero_index = i;
		}
	}
	cout << "Starting Array :" << endl;
	PrintArray(array, kArraySize);

	PrintProductEvenIndexes(array, kArraySize);

	PrintSumBetweenZeros(array, first_zero_index, last_zero_index);

	cout << "Sorted Array :" << endl;
	SortArray(array, kArraySize);
	PrintArray(array, kArraySize);

	return 0;
}