#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream f("date.in");

int a[100][100], n, io, jo, i1, j1, b[100][3], m;
int minim = 1000, bsol[100][3], bmat[100][100];
int di[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dj[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int inside(int i, int j)
{
	return i >= 1 && j >= 1 && i <= n && j <= n;
}

void afisare()
{
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <=n; j++)
    {
        cout << a[i][j] << " ";
    }cout << endl;
    }
}

void citire()
{
	f >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			f >> a[i][j];
			if (a[i][j] == -1) m++;
		}

    afisare();
    cout << endl << "Introduceti pozitia de start a calului: ";
	cin >> io >> jo;
}

void alege(int k)
{
	if (k < minim)
	{
		minim = k;
		int i, j;
		for (i = 0; i <= minim; i++)
		{
			bsol[i][1] = b[i][1];
			bsol[i][2] = b[i][2];
		}

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				bmat[i][j] = a[i][j];
	}
}

void afis()
{
   cout << "Miscarile pe tabla: " << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << endl;
		for (int j = 1; j <= n; j++)
			cout << bmat[i][j] << " ";
	}
}

void back(int i, int j, int k, int l)
{
	if (l == m) alege(k - 1);
	else
		for (int p = 0; p <= 7; p++)
		{
			int inou, jnou;
			inou = i + di[p];
			jnou = j + dj[p];
			if (inside(inou, jnou) && a[inou][jnou] <= 0)
			{
				b[k][1] = inou;
				b[k][2] = jnou;
				if (a[inou][jnou] == 0)
				{
					a[inou][jnou] = k + 1;
					back(inou, jnou, k + 1, l);
					a[inou][jnou] = 0;
				}
				else
				{
					a[inou][jnou] = k + 1;
					back(inou, jnou, k + 1, l + 1);
					a[inou][jnou] = -1;
				}
			}
		}
}

int main()
{
	citire();
	a[io][jo] = 1;
	b[0][1] = io;
	b[0][2] = jo;
	cout << endl;
	back(io, jo, 1, 0);
	afis();
	return 0;
}
