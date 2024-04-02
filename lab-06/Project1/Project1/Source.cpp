#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

inline double atvalt(double fok)
{
	return fok * 3.14159 / 180;
}

int main(int ArgDb, char* ArgTmb[])
{
	/*cout << "Argumentumok szama: " << ArgDb << endl;

	cout << ArgTmb[1]; */

	char nev[80] = "";
	if (ArgDb == 2)
	{
		strcpy_s(nev, ArgTmb[1]);
	}
	else
	{
		cout << "Adja meg az allomany nevet: ";
		cin >> nev;
	}

	cout << "Az allomany neve: " << nev << endl;

	ifstream stream;

	stream.open(nev);
	if (stream)
	{
		int db = 0;
		int szam;
		while (!stream.eof())
		{
			stream >> szam;
			cout << "szam: " << szam << endl;
			db++;
		}
		cout << "Ennyi szam van a listaban: " << db << endl;

		stream.clear();
		stream.seekg(0, ios::beg);
		int* p = new int[db];
		if (p)
		{
			register int i;
			for (i = 0; i < db; i++)
			{
				stream >> p[i];
			}
			stream.close();

			cout << endl << "A beolvasott szamok: " << endl;

			double s = 0.0;
			for (i = 0; i < db; i++)
			{
				cout << setw(8) << p[i];
				s += p[i];
			}
			cout << endl << endl;
			for (i = 0; i < db; i++)
			{
				cout << setw(12) << atvalt(p[i]);
			}
		}
		else
		{
			cerr << "A tarfoglalas sikertelen!" << endl;
			system("pause");
			exit(3);
		}
	}
	else
	{
		cerr << "Fajl megnyitasi hiba!" << endl;
		stream.close();
		system("pause");
		exit(2);
	}

	system("pause");
	return 0;
}