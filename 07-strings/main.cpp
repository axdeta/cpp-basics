#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string s, file_name;

	cout << "Write  file name (default name 'a') -> ";
	cin >> file_name;
	file_name += ".txt";
	ifstream fin(file_name);

	if (!fin.is_open()) {
		cout << "can't open file!" << endl;
		return 1;
	}

	cout << "Strings containing two-digit numbers:" << endl;
	while (getline(fin, s, '\n')) {
		for (unsigned int i = 1; i < s.length(); i++) {
			if (((s[i] <= '9') && (s[i] >= '1'))&
				((s[i + 1] <= '9') && (s[i + 1] >= '1'))) {
				cout << s << endl;
				break;
			}
		}

	}

	fin.close();
	return 0;
}