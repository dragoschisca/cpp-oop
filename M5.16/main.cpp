#include <iostream>

using namespace std;

double radical(double x, double s, double d)
{
	if (d - s <= 0.0001) return d;
	else
	{
		double m = (s + d) / 2;
		if (m *m * m < x) return radical(x, m, d);
		else return radical(x, s, m);
	}
}

int main()
{
	double x;
	cout << "Introduceti x: ";
	cin >> x;

	cout << "Radical de ordinul 3 din x: ";

	if (x > 0)
		if (x < 1) cout << radical(x, 0, 1);
		else cout << radical(x, 0, x);
	else if (x > -1) cout << radical(x, -1, 0);
	else cout << radical(x, x, 0);

	return 0;
}
