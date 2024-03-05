#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int f = 10;
	int *mut;
	int &fi = f;
	mut = &f;

	cout << "f=" << f << ", fi=" << fi << ", *mut=" << *mut << endl;
	fi = 20;
	cout << "f=" << f << ", fi=" << fi << ", *mut=" << *mut << endl;

	cout << &f << " " << &fi << " " << mut << " " <<  &mut << endl;

	// Vektorok
	vector <int> jegyek(3);
	char bet;
	int szam;
	int i;
	for (i = 0; i < 3; i++) //feltöltjük adatokkal
	{
		cout << "Adja meg az " << (i + 1) << ". tanulo jegyet(1-5): ";
		cin >> jegyek[i];
	}

	cout << "Akar meg jegyet felvenni? (y/n)" << endl; //rákérdezünk, hogy akar-e még jegyeket megadni/felvenni
	cin >> bet;
	if (bet == 'y')
	{
		do
		{
			cout << "Jegy (1-5): ";
			cin >> szam;
			jegyek.push_back(szam);
			cout << "Akar meg egyet (y/n)" << endl;
			cin >> bet;
			i++;
		} while (bet == 'y');
	}

	cout << "Jegyek szama: " << jegyek.size() << endl; //kiírjuk hány db jegyünk van

	/* 
	jegyek.pop_back(); //kiveszi az utolsóként megadott osztályzatot
	cout << endl << endl << "Osztalyzatok: " << endl; //osztályzatok kiírása
	for (i = 0; i < jegyek.size(); i++)
	{
		cout << jegyek.at(i) << ", ";
	} 
	*/

	jegyek.insert(jegyek.begin() + 1, 1); //beszúrunk egy egyest az elsõ osztályzat után és a második osztályzat elõtt
	cout << endl << endl << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
		cout << jegyek.at(i) << ", ";
	}

}