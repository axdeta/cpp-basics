#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

//printTableHead 
void printTableHead() {
	cout << string(78, '-') << endl;
	cout << "|         x         |";
	cout << "     f(x) series     |";
	cout << "    f(x) built-in    |";
	cout << " iterations | " << endl;
	cout << string(78, '-') << endl;
}

//Taylor series
void computeSeries(double eps, double &f, int &n, double &x1, const int max_iter) {
	double f_iteration = 1;
	while (abs(f_iteration) > eps) {
		f += f_iteration;
		f_iteration = pow((-1), n) * ((pow(x1, n)) / (tgamma(n + 1)));
		n++;
		if (n > max_iter) {
			break;
		}
	}
}

// output result into table 
void printResult(int n, int max_iter, double f, double x1) {
	cout << "|" << setw(13) << x1;
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



int main() {
	const int max_iter = 100;

	double eps, x1, x2, dx, f;
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

	printTableHead();

	cout << fixed;
	cout.precision(6);

	for (x1; x1 <= x2; x1 += dx) {
		f = 0;
		n = 1;
		computeSeries(eps, f, n, x1, max_iter);
		printResult(n, max_iter, f, x1);
	}
	cout << string(78, '-') << endl;

	return 0;
}