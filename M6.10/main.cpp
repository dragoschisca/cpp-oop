#include <fstream>
using namespace std;

int n, a[3][20001], maxx, im, jm;
ifstream fin("m.in");
ofstream fout("m.out");

void citire()
{
	int i, j, m, x;
	fin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			fin >> x;
			if (i == 1) a[i][j] = x;
			else
			{
				if (x == 0) a[2][j] = 0;
				else if (j == 1) a[2][j] = x;
				else
				{
					m = a[1][j - 1];
					if (a[1][j] < m) m = a[1][j];
					if (a[2][j - 1] < m) m = a[2][j - 1];
					a[2][j] = m + 1;
					if (a[2][j] > maxx)
					{
						maxx = a[2][j];
						im = i;
						jm = j;
					}
				}
			}

			a[1][j - 1] = a[2][j - 1];
		}

		a[1][n] = a[2][n];
	}
}

void afisare()
{
	fout <<  maxx << " " << im - maxx + 1 << " " << jm - maxx + 1;
}
int main()
{
	citire();
	afisare();
	fin.close();
	fout.close();
	return 0;
}
