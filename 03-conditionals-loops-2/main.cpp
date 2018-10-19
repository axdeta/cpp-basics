#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	const int kMaxIters = 1000;

	double xn, xk, dx, eps;
	cout << "Enter xn -> ";
	cin >> xn;
	cout << "Enter xk (xk >= xn) -> ";
	cin >> xk;
	cout << "Enter dx (dx > 0) -> ";
	cin >> dx;
	cout << "Enter eps (eps > 0) -> ";
	cin >> eps;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0) {
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		cout << string(74, '-') << endl;
		cout << "|         x         ";
		cout << "|   exp(-x) (mine)  ";
		cout << "|  exp(-x) (cmath)  ";
		cout << "| iterations |\n";
		cout << string(74, '-') << endl;

		cout << fixed;
		cout.precision(6);

		for (; xn <= xk; xn += dx) {
			int n = 1;
			double nth_term = 1;
			double my_exp = nth_term;
			while (abs(nth_term) > eps) {
				nth_term = pow((-1), n) * ((pow(xn, n)) / (tgamma(n + 1)));
				my_exp += nth_term;
				n++;
				if (n > kMaxIters) break;
			}

			cout << "|" << setw(13) << xn << setw(7) << "|" << setw(14);
			if (n <= kMaxIters)
				cout << my_exp << setw(6) << "|";
			else
				cout << " limit is exceeded |";
			cout << setw(14) << exp(-xn) << setw(6) << "|";
			cout << setw(7) << n << setw(7) << "|\n";

		}
		cout << string(74, '-');
	}

	return 0;
}