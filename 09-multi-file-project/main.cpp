#include "Header.h"
#include <iostream>

int main()
{
	int const kArraySize = 10;
	int array[kArraySize];

	generationArray(array, kArraySize);
	printArray(array, kArraySize);

	cout << "Product even index elements: ";
	cout << productEvenIndex(array, kArraySize) << endl;
	cout << endl;

	zeros zero = findZeros(array, kArraySize);
	cout << "Sum between zeros: ";
	cout << sumBetweenZeros(array, zero) << endl;
	cout << endl;

	sortArray(array, kArraySize);
	cout << "Sorted array:" << endl;
	printArray(array, kArraySize);

	return 0;
}