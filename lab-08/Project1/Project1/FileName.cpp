#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Teglalap {
	public:void init(int a, int b)
	{

	}
	public:int mag, alap;
	public:int ter() {
		return alap * mag;
	}
	public:int ker() {
	return 2*(alap + mag);
	}

};

int main() {
	int old1, old2;
	cout << "Adja meg a teglalap oldalait: " << endl;
	

	Teglalap t1, t2;
	bool inited = false;
	while (!inited) {
		cin >> old1;
		cin >> old2;
		inited = t2.init(old1, old2);
	}
	

	t1.init(5, 10);

	cout << "Az elso teglalap terulete: " <<t1.ter()<< endl;
	cout << "A masodik teglalap terulete: " <<t2.ter()<< endl;
	cout << "Az elso teglalap magassaga: " << t1.getMag() << endl;

	return 0;
}