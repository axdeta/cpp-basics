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
	if (zero.first != zero.last) {
		int sum = 0;

		for (int i = zero.first + 1; i < zero.last; i++)
			sum += array[i];
		return sum;
	}
	else {
		return 10; //because array elements are equal [-9..9]
	}
}

void sortArray(int array[], int const size) {
	int i, j;
	bool swapped;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
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
	std::cout << std::string(61, '-') << std::endl;
	std::cout << "|";

	for (int i = 0; i < size; i++) {
		std::cout << std::setw(2) << "[" << i << "]" << std::setw(2) << "|";
	}

	std::cout << "<- Index";
	std::cout << std::endl << std::string(61, '-') << std::endl << "|";

	for (int i = 0; i < size; i++) {
		std::cout << std::setw(3) << array[i] << std::setw(3) << "|";
	}

	std::cout << "<- array[i]";
	std::cout << std::endl;
	std::cout << std::string(61, '-') << std::endl;
	std::cout << std::endl;
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