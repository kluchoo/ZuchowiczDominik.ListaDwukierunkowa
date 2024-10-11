#include <iostream>
using namespace std;

struct Wezel {
	int dane = 0;
	Wezel* nastepny = nullptr;
	Wezel* poprzedni = nullptr;
};

class ListaDwukierunkowa {
private:
	Wezel* poczatek;
	Wezel* koniec;
public:
	ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr) {}

	void wyswietl_od_poczatku() {
		Wezel* wskaznik = poczatek;
		do {
			cout << wskaznik->dane << ", ";
			wskaznik = wskaznik->nastepny;
		} while (wskaznik != nullptr);
	}

	void dodaj_na_poczatek(int wartosc) {
		Wezel* nowyWezel = new Wezel;
		if (!poczatek) {
			poczatek = nowyWezel;
			koniec = nowyWezel;
			nowyWezel->dane = wartosc;
		}
		else
		{
			nowyWezel->nastepny = poczatek;
			poczatek->poprzedni = nowyWezel;
			poczatek = nowyWezel;
			nowyWezel->dane = wartosc;
		}
	}
};

int main()
{
	ListaDwukierunkowa lista;
	lista.dodaj_na_poczatek(1);
	lista.dodaj_na_poczatek(2);
	lista.wyswietl_od_poczatku();
}