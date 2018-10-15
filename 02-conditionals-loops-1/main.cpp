#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	const double kEps = 1e-15;

	double a, b, c, x1, x2, dx;
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

	if (dx < kEps) cout << "Error dx";
	else
	{
		cout << string(37, '-') << endl;
		cout << "|        X        |        F        |" << endl;
		cout << string(37, '-') << endl;

		cout << fixed;
		cout.precision(3);

		double f;
		while (x1 <= x2)
		{
			cout << "|" << setw(11) << x1 << setw(7) << "|";

			if ((a < 0) and (abs(c) > kEps))
			{
				f = a * x1 * x1 + b * x1 + c;
			}
			else if ((a > 0) and (abs(c) < kEps))
			{
				if (!(abs(x1 - c) < kEps))
				{
					f = -a / (x1 - c);
				}
				else
				{
					cout << "  division by 0  |" << endl;
					x1 += dx;
					continue;
				}
			}
			else
			{
				f = a * (x1 + c);
			}

			cout << setw(11);
			if ((int(a) & (int(b) | int(c))) != 0)
				cout << f;
			else
				cout << int(f);
			cout << setw(7) << "|" << endl;

			x1 += dx;
		}
		cout << string(37, '-') << endl;
	}
	return 0;
}