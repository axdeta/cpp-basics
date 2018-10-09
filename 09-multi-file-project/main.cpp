#include "func.h"

int main()
{
	int const kArraySize = 10;
	int array[kArraySize];


	genrateArray(array, kArraySize);
	printArray(array, kArraySize);

	std::cout << "Product even index elements: ";
	std::cout << productEvenIndex(array, kArraySize) << std::endl;
	std::cout << std::endl;

	Zeros zero = findZeros(array, kArraySize);
	std::cout << "Sum between Zeros: ";
	int result_sum = sumBetweenZeros(array, zero);
	if (result_sum != 10)
		std::cout << result_sum << std::endl;
	else
		std::cout << "Error : array has less than two zeros" << std::endl;
	std::cout << std::endl;

	sortArray(array, kArraySize);
	std::cout << "Sorted array:" << std::endl;
	printArray(array, kArraySize);

	return 0;
}