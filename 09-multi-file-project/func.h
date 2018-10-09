#include <iostream> //Input/Output 
#include <cstdlib> //rand()
#include <ctime> // rand()
#include <iomanip> //std::setw()
#include <string> //string()

using std::cout;
using std::endl;

//store index values of zero elements
struct Zeros {
	int last = -1;
	int first = -1;
};

//the product of elements with even indices
int productEvenIndex(int array[], int const size);

//cout << array
void printArray(int array[], int const size);

//sorting array
void sortArray(int array[], int const size);

//sum between first and last Zeros in array
int sumBetweenZeros(int array[], Zeros zero);

//find the first and last Zeros
Zeros findZeros(int array[], int const size);

//generation array
void genrateArray(int array[], int const size);