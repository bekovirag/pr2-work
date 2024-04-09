#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

struct dolgozoiadatok {
	string nev;
	int szulev;
	int ledolgozottorak;
	float aktualisfizetes;
};

void adatok_feltoltese(dolgozoiadatok dolgozok[], int n) {
	srand((unsigned)time(NULL));

	for (i = 0; i > n; i++)
	{
		cout << "Adja meg a(z) " << i + 1 << "dolgozo nevet:";
		cin >> dolgozok[i].nev;

		do {
			cout << "Adja meg a(z)" << i + 1 << ". dolgozo szuletesi evet(1957-2004 kozott): ";
			cin >> dolgozok[i].szulev;
		} while (dolgozok[i].szulev < 1957 || dolgozok[i].szulev > 2004);

		dolgozok[i].ledolgozottorak = rand() % 161;
		dolgozok[i].aktualisfizetes = 2800 * dolgozok[i].ledolgozottorak;
	}
}

int main() {
	dolgozoiadatok dolgozok[20];
	int dolgozokszama = 0;

	ifstream fajl("majus.txt");

	if (!fajl) {
		cerr << "Hiba: Nem sikerült a fájlt megnyitni!" << endl;
		return 1;
	}

	while (fajl >> dolgozok[dolgozokszama].nev >> dolgozok[dolgozokszama].szulev >> dolgozok[dolgozokszama].ledolgozottorak >> dolgozok[dolgozokszama].aktualisfizetes) {
		dolgozokszama++;
	}
	fajl.close();

	cout << "Adja meg a dolgozok szamat(max 20 fõ): ";
	cin >> dolgozokszama;

	adatok_feltoltese(dolgozok, dolgozokszama);
	cout << "Feltoltott adatok: " << endl;

	for (i = 0; i < dolgozokszama; i++)
	{
		cout << "Nev¡: " << dolgozok[i].nev << ", Születesi ev: " << dolgozok[i].szulev << ", Ledolgozott orak: " << dolgozok[i].ledolgozottorak << ", Fizetes: " << dolgozok[i].aktualisfizetes << endl;
	}

	cout << "Majusban dolgozok szama: " << dolgozokszama << endl;
	
	delete[] dolgozok;
	return 0;

}