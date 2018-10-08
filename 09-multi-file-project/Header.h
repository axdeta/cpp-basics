#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;
//store index values of zero elements
struct zeros {
	int Last = -1;
	int First = -1;
};

//the product of elements with even indices
int productEvenIndex(int array[], int size);

//cout << array
void printArray(int array[], int size);

//sorting array
void sortArray(int array[], int size);

//sum between first and last zeros in array
string sumBetweenZeros(int array[], zeros zero);

//find the first and last zeros
zeros findZeros(int array[], int size);

//generation array
int* generationArray(int array[], int size);
