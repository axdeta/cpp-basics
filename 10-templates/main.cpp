#include <iostream> //Input/Output 
#include <iomanip> //setw()
#include <fstream> //file input
#include <string> //for input string

#define Row 3
#define Col 4

using namespace std;

template <class Type>
void readArr(Type a, string name) {
	ifstream fin(name + ".txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
	}
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			fin >> a[i][j];
		}
	}
	fin.close();
}

template <class Type>
void printArr(Type a) {
	cout << "Array: " << endl;
	for (int i = 0; i < Row; i++) {
		cout << "|";
		for (int j = 0; j < Col; j++) {
			cout << setw(3) << a[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << endl << endl;
}

template <class Type>
int findZeros(Type a) {
	int columns_with_zeros = 0;
	for (int j = 0; j < Col; j++) {
		for (int i = 0; i < Row; i++) {
			if (abs(a[i][j]) < 1e-15) {
				columns_with_zeros += 1;
				break;
			}
		}
	}
	return columns_with_zeros;
}

template <class Type>
int seriesZeros(Type a) {
	int max_series_col = 1,
		series_now = 1,
		row_of_max_series = -1;
	//find series of identical elements in rows
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col - 1; j++) {
			//incrementing series_now if finds identical neighbors
			if (a[i][j] == a[i][j + 1]) {
				series_now += 1;
			}
		}
		//checking for the max series 
		if (series_now > max_series_col) {
			max_series_col = series_now;
			row_of_max_series = i;
		}
		series_now = 1;
	}
	return row_of_max_series;
}

template <class TypeAr>
void start(string name) {
	TypeAr a[Row][Col];
	//reading and print array
	readArr(a, name);
	printArr(a);

	//find columns with zeros in array
	cout << "Columns with zeros in array: ";
	cout << findZeros(a) << endl << endl;
	
	//find row with max series
	int max_series = seriesZeros(a);
	cout << "Row with max series identical neighbors: ";
	if (max_series == -1) {
		cout << "In all no identical neighbors" << endl;
	}
	else {
		cout << max_series;
		cout << "  (numeration starts at 0)" << endl;
	}
}

int main() {
	error:
	cout << "Select the data type (0-integer, 1-double, 2-float): ";
	string select;
	cin >> select;
	if (select == "0") {
		start<int>("int");
	}
	else if (select == "1") {
		start<double>("double");
	}
	else if (select == "2") {
		start<float>("float");
	}
	else {
		cout << "Error input! (Only 0/1/2)" << endl;
		goto error;
	}
	return 0;
}