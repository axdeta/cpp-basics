#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;


int main() {
	double a, b, c, x1, x2, dx, f;
	const double EPS = 1e-15;
	cout << fixed;
	cout << "Enter a -> ";
	cin >> a;
	cout << "Enter b -> ";
	cin >> b;
	cout << "Enter c -> ";
	cin >> c;
	cout << "Enter x1 -> ";
	cin >> x1;
	cout << "Enter x2 -> ";
	cin >> x2;
	cout << "Enter dx -> ";
	cin >> dx;
	if (dx < EPS) { cout << "Error dx"; }
	else
	{
		cout << string(25, '-') << endl;
		cout << "|     X     |     F     |" << endl;
		cout << string(25, '-') << endl;
		cout.precision(3);
		while (x1 <= x2) {
			if ((a < 0) and (abs(c) > EPS))
			{
				f = a * x1*x1 + b * x1 + c;
			}
			else if ((a > 0) and (abs(c) < EPS) and ((abs(x1 - c)) >= EPS))
			{
				f = -a / (x1 - c);
			}
			else
			{
				f = a * (x1 + c);
			}

			if (abs(int(a) & (int(b) | int(c))) > EPS) {
				cout << "|" << setw(6) << x1 << setw(6) << "|";
				cout << setw(6) << f << setw(6) << "|" << endl;
			}
			else {
				cout << "|" << setw(6) << x1 << setw(6) << "|";
				cout << setw(6) << int(f) << setw(6) << "|" << endl;
			}
			x1 += dx;
		}
		cout << string(25, '-') << endl;
	}
	return 0;
}