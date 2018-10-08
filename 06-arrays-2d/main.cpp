#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>


using namespace std;

int main() {
	int const kCol = 4,
		kRow = 5;
	int arr[kRow][kCol],
		columns_with_zeros = 0,
		max_series_col = 1,
		series_now = 1,
		row_of_max_series = -1;

	//reading .txt
	ifstream fin("file.txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
		return 1;
	}
	for (int i = 0; i < kRow; i++) {
		for (int j = 0; j < kCol; j++) {
			fin >> arr[i][j];
		}
	}
	fin.close();

	//writing array
	cout << "Array: " << endl;
	cout << string(21, '-') << endl;
	for (int i = 0; i < kRow; i++) {
		cout << "|";
		for (int j = 0; j < kCol; j++) {
			cout << setw(3) << arr[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << string(21, '-') << endl << endl;

	//find zeros in columns
	for (int j = 0; j < kCol; j++) {
		for (int i = 0; i < kRow; i++) {
			if (arr[i][j] == 0) {
				columns_with_zeros += 1;
				break;
			}
		}
	}
	cout << "Columns with zeros in array: ";
	cout << columns_with_zeros << endl << endl;

	//find series of identical elements in rows
	for (int i = 0; i < kRow; i++) {
		for (int j = 0; j < kCol - 1; j++) {
			//incrementing series_now if finds identical neighbors
			if (arr[i][j] == arr[i][j + 1]) {
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
	return 0;
}
