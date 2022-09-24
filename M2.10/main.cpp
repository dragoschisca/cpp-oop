#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int t[100], s[100], nr, nrs = 0;

void citire()
{
	f >> nr;

	for (int i = 0; i < nr; i++)
		f >> t[i];
}

void sortare()
{
	int aux;

	for (int i = 0; i < nr; i++)
		for (int j = i + 1; j < nr; j++)
			if (t[i] < t[j])
			{
				aux = t[i];
				t[i] = t[j];
				t[j] = aux;
			}
}

void submultime()
{
	for (int i = 0; i < nr; i++)
		if (t[i] > 0)
		{
			s[i] = t[i];
		}
}

void afisare()
{
	float sum = 0;

	for (int i = 0; i < nrm; i++)
	{
		g << s[i] << " ";
		sum += s[i];
	}

	g << "\n" << sum;
}

int main()
{
	citire();
	sortare();
	submultime();
	afisare();
	return 0;
}
