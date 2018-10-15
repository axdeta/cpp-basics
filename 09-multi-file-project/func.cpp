#include "func.h"

Zeros findZeros(int array[], int const size) {
	Zeros zero;
	//find Zeros
	for (int i = 0; i < size; i++) {
		if (array[i] == 0) {
			zero.first = i;
			break;
		}
	}
	for (int i = size - 1; i >= 0; i--) {
		if (array[i] == 0) {
			zero.last = i;
			break;
		}
	}
	return zero;
}

int sumBetweenZeros(int array[], Zeros zero) {
	int sum = 0;
	for (int i = zero.first + 1; i < zero.last; i++)
		sum += array[i];
	return sum;
}

void sortArray(int array[], int const size) {
	bool swapped;
	for (int i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if ((array[j] < 0)&&(array[j + 1] >= 0))
			{
				std::swap(array[j], array[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

void printArray(int array[], int const size) {
	cout << std::string(61, '-') << endl;
	cout << "|";

	for (int i = 0; i < size; i++) {
		cout << std::setw(2) << "[" << i << "]" << std::setw(2) << "|";
	}

	cout << "<- Index";
	cout << endl << std::string(61, '-') << endl << "|";

	for (int i = 0; i < size; i++) {
		cout << std::setw(3) << array[i] << std::setw(3) << "|";
	}

	cout << "<- array[i]";
	cout << endl;
	cout << std::string(61, '-') << endl;
	cout << endl;
}

int productEvenIndex(int array[], int const size) {
	int product = array[0];
	for (int i = 2; i < size; i += 2)
		product *= array[i];
	return product;
}

void genrateArray(int array[], int const size) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
		array[i] = int(pow(-1, rand() % 2))*(rand() % 10); //[-9..9]
}