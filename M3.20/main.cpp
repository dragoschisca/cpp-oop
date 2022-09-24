#include <iostream>
#include <cstring>
#include <tuple>
using namespace std;

int n, m, len, io, jo;
char t[20][20];
char cuv[20];

void citire()
{
	cout << "Introduceti cuvantul prefixul caruia va fi cautat: ";
	cin >> cuv;
	len = strlen(cuv);
	cout << "Introdueti n(linii): ";
	cin >> n;
	cout << "Introduceti m(coloane): ";
	cin >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "t[" << i << "][" << j << "]= ";
			cin >> t[i][j];
		}
}

void afisare(int i, int j)
{
	cout << t[i][j] << " ";
}

void afis()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}

tuple<int, int> first()	//tiple permite returnarea a 2 variabile odata
{
	for (int k = 0; k < len; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (t[i][j] == cuv[k])
					return {i, j};
}

tuple<int, int> aproape(int i, int j, int k)
{
	if ((i - 1 >= 0) && (t[i - 1][j] == cuv[k])) return {i - 1, j};
	else if ((i + 1 < n) && (t[i + 1][j] == cuv[k])) return {i + 1, j};
	else if ((j - 1 >= 0) && (t[i][j - 1] == cuv[k])) return {i, j - 1};
	else if ((j + 1 < m) && (t[i][j + 1] == cuv[k])) return {i, j + 1};
}

bool valid(int i, int j, int k)
{
	if ((i - 1 >= 0) && (t[i - 1][j] == cuv[k])) return true;
	else if ((i + 1 < n) && (t[i + 1][j] == cuv[k])) return true;
	else if ((j - 1 >= 0) && (t[i][j - 1] == cuv[k])) return true;
	else if ((j + 1 < m) && (t[i][j + 1] == cuv[k])) return true;
	else
		return false;
}

void back(int k)
{
	int i, j, x, y;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if ((t[i][j] == cuv[k]) && (valid(io, jo, k)))
			{
				auto[x, y] = aproape(io, jo, k);
				io = x;
				jo = y;
				afisare(i, j);
				back(k + 1);
			}
}

int main()
{
	citire();
	cout << endl;
	afis();

	auto[io, jo] = first();
	cout << endl << "Prefixul de lungime maxima: " << endl;
	afisare(io, jo);
	back(1);
	return 0;
}
