#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a;
	cout << "Enter alpha -> ";
	cin >> a;

	double z1 = (sin(2 * a) + sin(5 * a) - sin(3 * a)) /
		(cos(a) + 1 - 2 * pow(sin(2 * a), 2));
	double z2 = 2 * sin(a);
	cout << "\nz1= " << z1 << "\nz2= " << z2 << endl;

	return 0;
}