#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	const int max_iter = 100;

	double eps, x1, x2, dx, f, f_iteration;
	int n;

	//enter
	cout << "Enter x1 -> ";
	cin >> x1;
	cout << "Enter x2 -> ";
	cin >> x2;
	cout << "Enter dx -> ";
	cin >> dx;
	cout << "Enter eps -> ";
	cin >> eps;

	//head
	cout << string(78, '-') << endl;
	cout << "|         x         |";
	cout << "     f(x) series     |";
	cout << "    f(x) built-in    |";
	cout << " iterations | " << endl;
	cout << string(78, '-') << endl;

	cout << fixed;
	cout.precision(6);

	for (x1; x1 <= x2; x1 += dx) {
		f = 0;
		n = 1;
		f_iteration = 1;
		cout << "|" << setw(13) << x1;

		while (abs(f_iteration) > eps) {
			f += f_iteration;
			f_iteration = pow((-1), n) * ((pow(x1, n)) / (tgamma(n + 1)));
			n++;
			if (n > max_iter) {
				break;
			}
		}

		cout << setw(7) << "|" << setw(15);
		if (n < max_iter) {
			cout << f << setw(7) << "|";
		}
		else {
			cout << "    too small eps  " << setw(3) << "|";
		}
		cout << setw(15) << exp(-x1) << setw(7) << "|";
		cout << setw(7) << n << setw(6) << "|" << endl;

	}
	cout << string(78, '-') << endl;

	return 0;
}