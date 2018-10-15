#include "func.h"

int main()
{
	int const kArraySize = 10;
	int array[kArraySize];


	genrateArray(array, kArraySize);
	printArray(array, kArraySize);

	cout << "Product even index elements: ";
	cout << productEvenIndex(array, kArraySize) << endl;
	cout << endl;

	Zeros zero = findZeros(array, kArraySize);
	cout << "Sum between Zeros: ";
	if (zero.first != zero.last) {
		int result_sum = sumBetweenZeros(array, zero);
		cout << result_sum << endl;
	}
	else
		cout << "Error: array has less than two zeros" << endl;
	cout << endl;

	sortArray(array, kArraySize);
	cout << "Sorted array:" << endl;
	printArray(array, kArraySize);

	return 0;
}