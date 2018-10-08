#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include <float.h>

#define N 3

using namespace std;

template <class Type>
void readArr(Type *a, string name) {
	ifstream fin(name + ".txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fin >> a[i][j];
		}
	}
	fin.close();
}

template <class Type>
void printArr(Type a) {
	cout << "Array: " << endl;
	for (int i = 0; i < N; i++) {
		cout << "|";
		for (int j = 0; j < N; j++) {
			cout << setw(3) << a[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << endl << endl;
}

template <class Type>
void findZeros(Type a) {
	int columns_with_zeros = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (abs(a[i][j]) < DBL_EPSILON) {
				columns_with_zeros += 1;
				break;
			}
		}
	}
	cout << "Columns with zeros in aay: ";
	cout << columns_with_zeros << endl << endl;
}

template <class Type>
void seriesZeros(Type a) {
	int max_series_col = 1,
		series_now = 1,
		row_of_max_series = -1;
	//find series of identical elements in rows
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			//incrementing series_now if finds identical neighbors
			if (a[i][j] == a[i][j + 1]) {
				series_now += 1;
			}
		}
		//check for find max of series 
		if (series_now > max_series_col) {
			max_series_col = series_now;
			row_of_max_series = i;
		}
		series_now = 1;
	}
	cout << "Row with max series identical neighbors: ";
	if (row_of_max_series == -1) {
		cout << "In all no identical neighbors" << endl;
	}
	else {
		cout << row_of_max_series;
		cout << "  (numbering starts at 0)" << endl;
	}
}

template <class TypeAr>
void start(string name) {
	TypeAr a[N][N];
	readArr(a, name);
	printArr(a);
	findZeros(a);
	seriesZeros(a);
}

int main() {
	cout << "Select the data type (0 -integer, 1- double, 2 -float): ";
	int select;
	cin >> select;
	if (select == 0) {
		start<int>("int");
	}
	else if (select == 1) {
		start<double>("double");
	}
	else if (select == 2) {
		start<float>("float");
	}
	else {
		cout << "Error input! (Only 0/1/2)" << endl;
	}
	return 0;
}