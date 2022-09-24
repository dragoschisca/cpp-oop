#include <iostream>
#include <cstring>

using namespace std;

int nr, sol = 0;
char sirul[100], st[50], p[50];

void scrie()
{

		for (int i = 1; i <= nr; i++)
			cout << sirul[st[i] - 1];
		cout << endl;
		sol++;
}

void back(int k)
{
	for (int i = 1; i <= nr; i++)
		if (!p[i])
		{
			st[k] = i;
			p[i] = 1;
			if (k == nr) scrie();
			else back(k + 1);
			p[i] = 0;
		}
}

int main()
{
	cout << "Introduceti sirul: ";
	cin >> sirul;
	nr = strlen(sirul);

	for (int i = 0; i < nr; i++)
		for (int j = i + 1; j < nr; j++)
			if (sirul[i] > sirul[j])
			{
				char aux = sirul[i];
				sirul[i] = sirul[j];
				sirul[j] = aux;
			}

    cout << endl << "Anagramele: " << endl;

	back(1);

	cout << endl << "In total " << sol << " anagrame posibile" << endl;

	return 0;
}
