#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int nr;
fstream f("date.in");

struct Punct
{
	int x,y;
}t[100];

void afisare(int i)
{
	cout << "x= " << t[i].x << "    " << "y= " << t[i].y << endl;
}

float distanta(Punct a, Punct b)
{
	float d;
	d = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
	return d;
}

int main()
{
	int triunghi = 0;

	f >> nr;

	for (int i = 0; i < nr; i++)
	{
		f >> t[i].x;
		f >> t[i].y;
	}

	cout << "Coordonatele punctelor: " << endl;
	for (int i = 0; i < nr; i++)
		afisare(i);
    cout << endl;
	for (int i = 0; i < nr - 1; i++)
		for (int j = i + 1; j < nr - 1; j++)
			for (int d = j + 1; d < nr; d++)
				if (distanta(t[i], t[j]) + distanta(t[j], t[d]) > distanta(t[d], t[i]) &&
					distanta(t[j], t[d]) + distanta(t[d], t[i]) > distanta(t[i], t[j]) &&
					distanta(t[i], t[j]) + distanta(t[d], t[i]) > distanta(t[j], t[d]))
				{
					triunghi++;
					cout << "Triunghiul " << triunghi << ": " << endl;
					afisare(i);
					afisare(j);
					afisare(d);
					cout << endl;
				}

	cout << "Numarul de triunghiuri posibile: " << triunghi << endl;

	return 0;
}
