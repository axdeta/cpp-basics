#include <iostream>
#include <string>
#include <algorithm> //min()
#include <iomanip>
#define kStudents 10
#define kMarks 5

using namespace std;

struct Student {
	string full_name, group_number;
	string marks[kMarks];
};

void addStudents(Student *a) {
	for (int i = 0; i < kStudents; i++) {
		cout << i + 1 << ". Input the surname and initials (e.g., Ivanov I.I.): ";
		getline(cin, a[i].full_name);
		cout << "Input the Group number of the student(e.g., IZ-228): ";
		getline(cin, a[i].group_number);
		cout << "Input his marks (5 marks [2..5]):" << endl;
		for (int j = 0; j < kMarks; j++) {
			cout << string(25, ' ') << "Mark " << j + 1 << " = ";
			cin >> a[i].marks[j];
		}
		cin.ignore();
		cout << endl;
	}
	cout << endl;
}

void sortStudents(Student *a) {
	for (int i = 0; i < kStudents; i++) {
		for (int j = 0; j < kStudents - i - 1; j++) {
			if (a[j].full_name.compare(a[j + 1].full_name) > 0) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void printStudents(Student *a) {
	for (int i = 0; i < kStudents; i++) {
		cout << i + 1 << ". " << a[i].full_name << endl;
	}
	cout << endl;
}

void printDebt(Student *a) {
	cout << "Students with academic debt: " << endl;
	for (int i = 0; i < kStudents; i++) {
		for (int j = 0; j < kMarks; j++) {
			if (a[i].marks[j] == "2") {
				cout << "|" << setw(4) << a[i].full_name;
				cout << setw(4) << "|" << endl;
				break;
			}
		}
	}
}

int main() {
	Student stud_list[kStudents];
	addStudents(stud_list);
	sortStudents(stud_list);
	printStudents(stud_list);
	printDebt(stud_list);
	return 0;
}