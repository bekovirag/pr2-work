#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct jatekos {
	string nev;
	int szul;
	string poszt;
	int meccs, loves, gol;
};

class Labdarugo
{
	int db;
	jatekos* tmb;

public: Labdarugo(string filenev);
	  ~Labdarugo();
	  void kiir();
	  int Osszesloves();
	  jatekos legtobbGol();
	  void fiatalok();
	  jatekos* Egyenlo();
};

int main() {
	string filenev = "jatekosok.txt";
	Labdarugo L(filenev);
	L.kiir();

	cout << endl << "Osszes loves: " << L.Osszesloves() << endl;

	jatekos legtobbetRugott = L.legtobbGol();
	cout << endl << "Aki a legtobb golt rugta: " << legtobbetRugott.nev << endl;
	cout << endl;

	L.fiatalok();

	jatekos* e = L.Egyenlo();
	cout << endl << e[3].nev << endl;

	return 0;
}

Labdarugo::Labdarugo(string filenev)
{
	ifstream be(filenev);
	if (be.fail())
	{
		cout << "Hibas fajl olvasas!" << endl;
		exit(1);
	}

	string sor;
	be >> db;
	tmb = new jatekos[db];

	for (int i = 0; i < db; i++)
	{
		getline(be, tmb[i].nev, ':');
		getline(be, sor, ':');
		tmb[i].szul = stoi(sor);
		getline(be, tmb[i].poszt, ':');

		getline(be, sor, ':');
		tmb[i].meccs = stoi(sor);

		getline(be, sor, ':');
		tmb[i].loves = stoi(sor);

		getline(be, sor);
		tmb[i].gol = stoi(sor);
	}

	be.close();

}

Labdarugo::~Labdarugo()
{
	delete[] tmb;
}

void Labdarugo::kiir()
{
	cout.setf(ios::left); //balra igazítás alapértelmezetten jobbra van
	cout << setw(12) << "Nev" << setw(6) << "Szul." << setw(8) << "Poszt" << setw(6) << "Meccs" << setw(6) << "Loves" << setw(6) << "Gol" << endl;

	for (int i = 0; i < db; i++)
	{
		cout << setw(12) << tmb[i].nev << setw(6) << tmb[i].szul << setw(8) << tmb[i].poszt << setw(6) << tmb[i].meccs << setw(6) << tmb[i].loves << setw(6) << tmb[i].gol << endl;
	}
}

int Labdarugo::Osszesloves() {

	int sum = 0;
	for  (int i = 0;  i < db; i++)
	{
		sum += tmb[i].loves;
	}
	return sum;
}


jatekos Labdarugo::legtobbGol()
{
	int index = 0;
	for (int i = 0; i < db; i++)
	{
		if (tmb[i].gol > tmb[index].gol) {
			index = i;
		}
	}
	return tmb[index];
}

void Labdarugo::fiatalok()
{
	int start = 1995;
	for (int i = 0;  i < db;  i++)
	{
		if (tmb[i].szul >= start)
		{
			cout << "Fiatal: " << tmb[i].nev << ", " << tmb[i].szul << endl;
		}
	}
}

jatekos* Labdarugo::Egyenlo()
{
	int egyenloek = 0;
	jatekos* e = new jatekos[db];
	for (int i = 0; i < db; i++)
	{
		for (int j = 0; j < db; j++)
		{
			if (j != i && tmb[i].gol == tmb[j].gol)
			{
				e[egyenloek] = tmb[i];
				egyenloek++;
			}
		}
	}

	jatekos* e2 = new jatekos[egyenloek];
	for (int i = 0; i < egyenloek; i++)
	{
		e2[i] = e[i];
	}
	return e2;
}



