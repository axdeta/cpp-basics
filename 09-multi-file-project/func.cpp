#include "Header.h"

zeros findZeros(int array[], int size) {
	zeros zero;
	//find zeros
	for (int i = 0; i < size; i++) {
		if (array[i] == 0) {
			zero.First = i;
			break;
		}
	}
	for (int i = size - 1; i > -1; i--) {
		if (array[i] == 0) {
			zero.Last = i;
			break;
		}
	}
	return zero;
}

string sumBetweenZeros(int array[], zeros zero) {
	if (zero.First != zero.Last) {
		int sum = 0;

		for (int i = zero.First + 1; i < zero.Last; i++)
			sum += array[i];
		return to_string(sum);
	}
	else {
		return "Error : array has less than two zeros";
	}
}

void sortArray(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if ((array[j] < 0)&(array[j + 1] >= 0)) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

void printArray(int array[], int size) {
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

int productEvenIndex(int array[], int size) {
	int product = array[0];
	for (int i = 2; i < size; i += 2)
		product *= array[i];
	return product;
}

int* generationArray(int array[], int size) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
		array[i] = int(pow(-1, rand() % 2))*(rand() % 10); //[-9..9]
	return array;
}