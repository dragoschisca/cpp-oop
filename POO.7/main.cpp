#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Pacient
{
	public:
		string nume, prenume, boala, medicament, tip, domeniu;
	int zile_tratament, anul, ret_luna;
	double pret_medicament;

	public:
    void citire();
	void afisare();
	void afisare(int);
	void varstnici();
	void tineri();
	void inserare();
	void anumita_boala();
	void acelasi_tratament();
	void retete_luna();
	void tratament();
	void tip_med();
	void domen();
	double varsta()
	{
		return 2022 - anul;
	}
}t[100];

fstream f("date.in");

int nr;

void Pacient::citire()
{
	f >> nr;

	for (int i = 0; i < nr; i++)
	{
		f >> t[i].nume;
		f >> t[i].prenume;
		f >> t[i].anul;
		f >> t[i].boala;
		f >> t[i].medicament;
		f >> t[i].tip;
		f >> t[i].ret_luna;
		f >> t[i].pret_medicament;
		f >> t[i].zile_tratament;
		f >> t[i].domeniu;
	}
}

void antet()
{
	cout << "Nr: ";
	cout << setw(10) << "Nume: ";
	cout << setw(12) << "Prenume: ";
	cout << setw(11) << "Anul: ";
	cout << setw(13) << "Varsta: ";
	cout << setw(14) << "Boala: ";
	cout << setw(15) << "Medicament: ";
	cout << setw(13) << "Tip: ";
	cout << setw(13) << "Retete/lun: ";
	cout << setw(10) << "Pret: ";
	cout << setw(10) << "Zile: ";
	cout << setw(12) << "Domeniu: " << endl;
}

void Pacient::afisare()
{
	antet();

	for (int i = 0; i < nr; i++)
	{
		cout << i + 1 << setw(10);
		cout << setw(12) << t[i].nume;
		cout << setw(10) << t[i].prenume;
		cout << setw(12) << t[i].anul;
		cout << setw(13) << t[i].varsta();
		cout << setw(14) << t[i].boala;
		cout << setw(15) << t[i].medicament;
		cout << setw(13) << t[i].tip;
		cout << setw(13) << t[i].ret_luna;
		cout << setw(10) << t[i].pret_medicament;
		cout << setw(10) << t[i].zile_tratament;
		cout << setw(12) << t[i].domeniu << endl;
	}
}

void Pacient::afisare(int i)
{
        cout << i + 1 << setw(10);
		cout << setw(12) << t[i].nume;
		cout << setw(10) << t[i].prenume;
		cout << setw(12) << t[i].anul;
		cout << setw(13) << t[i].varsta();
		cout << setw(14) << t[i].boala;
		cout << setw(15) << t[i].medicament;
		cout << setw(13) << t[i].tip;
		cout << setw(13) << t[i].ret_luna;
		cout << setw(10) << t[i].pret_medicament;
		cout << setw(10) << t[i].zile_tratament;
		cout << setw(12) << t[i].domeniu << endl;
}

void Pacient::inserare()
{
	cout << "=====Inserare=====" << endl;
	cout << "Introduceti numele: ";
	cin >> t[nr].nume;
	cout << "Introduceti prenumele: ";
	cin >> t[nr].prenume;
	cout << "Introduceti anul nasterii: ";
	cin >> t[nr].anul;
	cout << "Introduceti boala: ";
	cin >> t[nr].boala;
	cout << "Introduceti medicamentul prescris: ";
	cin >> t[nr].medicament;
	cout << "Introduceti tipul medicamentului: ";
	cin >> t[nr].tip;
	cout << "Introduceti nr de retete pe luna: ";
	cin >> t[nr].ret_luna;
	cout << "Introduceti pretul: ";
	cin >> t[nr].pret_medicament;
	cout << "Introduceti zilele tratamentului: ";
	cin >> t[nr].zile_tratament;
	cout << "Introduceti domeniul pacientului: ";
	cin >> t[nr].domeniu;

	nr++;
}

void Pacient::varstnici()
{
	int v = 0;
	antet();
	for (int i = 0; i < nr; i++)
		if (t[i].varsta() >= 60)
		{
			v++;
			afisare(i);
		}

	cout << endl << "Medicul are " << v << " pacienti varstnici!" << endl;
}

void Pacient::tineri()
{
	int tin = 0;
	antet();
	for (int i = 0; i < nr; i++)
		if (t[i].varsta() <= 30)
		{
			tin++;
			afisare(i);
		}

	cout << endl << "Medicul are " << tin << " pacienti tineri!" << endl;
}

void Pacient::anumita_boala()
{
	string search;
	int numar = 0;

	cout << "Introduceti boala cautata: ";
	cin >> search;
    antet();
	for (int i = 0; i < nr; i++)
		if (t[i].boala == search)
		{
			numar++;
			afisare(i);
		}

	cout << endl << numar << " pacienti sufera de boala: " << search << endl << endl;
}

void Pacient::acelasi_tratament()
{
	int numar = 1;

    	    antet(); cout << endl;
	for (int i = 0; i < nr; i++)
	{
		for (int j = i + 1; j < nr; j++)
			if (t[i].medicament == t[j].medicament)
			{
				afisare(i);
				afisare(j);
				numar++;
			}

		if (numar != 1)
			cout << endl << numar << " pacienti cu tratamentul " << t[i].medicament << endl << endl;
		numar = 1;
	}
}

void Pacient::retete_luna()
{
	int numar, s = 0;

	cout << "Introduceti numarul de retete minim necesar: ";
	cin >> numar;
    antet();
	for (int i = 0; i < nr; i++)
		if (t[i].ret_luna > numar)
		{
			s++;
			t[i].afisare(i);
		}

	cout << endl << s << " pacienti au numarul de retete pe luna mai mult de " << numar << endl;
}

void Pacient::tip_med()
{
	string td[100];
	int nr_tip, numar = 0;

	nr_tip = nr;

	for (int i = 0; i < nr; i++)
		td[i] = t[i].tip;

	for (int i = 0; i < nr_tip; i++)
		for (int j = i + 1; j < nr_tip; j++)
			if (td[i] == td[j])
			{
				for (int k = j; k < nr_tip; k++)
					td[k] = td[k + 1];

				nr_tip--;
				j--;
			}
    antet();
	for (int i = 0; i < nr_tip; i++)
	{
		for (int j = 0; j < nr; j++)
			if (td[i] == t[j].tip)
			{
				numar++;
				afisare(j);
			}

		cout << endl << numar << " pacienti cu tratament de tip " << td[i] << endl << endl;
		numar = 0;
	}
}

void Pacient::domen()
{
	string d[100];
	int nr_domen, numar = 0;

	nr_domen = nr;

	for (int i = 0; i < nr; i++)
		d[i] = t[i].domeniu;

	for (int i = 0; i < nr_domen; i++)
		for (int j = i + 1; j < nr_domen; j++)
			if (d[i] == d[j])
			{
				for (int k = j; k < nr_domen; k++)
					d[k] = d[k + 1];

				nr_domen--;
				j--;
			}

	for (int i = 0; i < nr_domen; i++)
	{
		cout << "\t\t\t\tDomeniu: " << d[i] << endl << endl;
		antet();
		for (int j = 0; j < nr; j++)
			if (d[i] == t[j].domeniu)
			{
				numar++;
				afisare(j);
			}

		cout << endl << numar << " pacienti din domeniul " << d[i] << endl << endl;
		numar = 0;
	}
}

int main()
{
	Pacient p;
	int alegere;

	do {
		cout << endl;
		cout << " __________________________MENIU____________________________ " << endl;
		cout << "|...........................................................|" << endl;
		cout << "|A) Introducerea unui pacient nou--------------------------1|" << endl;
		cout << "|B) Afisarea tuturor pacientilor---------------------------2|" << endl;
		cout << "|C) Clasarea pacientilor in varstnici/tineri---------------3|" << endl;
		cout << "|D) Nr. de pacienti cu o anumita boala---------------------4|" << endl;
		cout << "|E) Nr. de pacienti cu acelasi tratament-------------------5|" << endl;
		cout << "|F) Nr. de retete/luna mai mare ca un numar----------------6|" << endl;
		cout << "|G) Nr. de medicamente prescrise de un anumit tip dat------7|" << endl;
		cout << "|H) Pacienti in dependenta de domeniul de activitate-------8|" << endl;
		cout << "|() Iesire-------------------------------------------------0|" << endl;
		cout << "|...........................................................|" << endl;
		cout << "|___________________________________________________________|" << endl;
		cout << endl;

		alegere = getch();
		p.citire();
		system("cls");

		switch (alegere)
		{
			case '1': p.inserare(); break;
			case '2': p.afisare(); getch(); break;
			case '3':
				cout << " ________________ " << endl;
				cout << "|Varstnici------1|" << endl;
				cout << "|Tineri---------2|" << endl;
				cout << "|________________|" << endl;
				alegere = getch();
				system("cls");

				switch (alegere)
				{
					case '1': p.varstnici(); break;
					case '2': p.tineri(); break;
				}

				break;

			case '4': p.anumita_boala(); break;
			case '5': p.acelasi_tratament(); break;
			case '6': p.retete_luna(); break;
			case '7': p.tip_med(); break;
			case '8': p.domen(); break;
		}
	} while (alegere != '0');

	return 0;
}
