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
	int ilosc;
public:
	ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr), ilosc(0) {}

	/**
	
	wyświetlanie listy

	**/

	void wyswietl_od_poczatku() {
		Wezel* wskaznik = poczatek;
		int i = 0;
		do {
			if (wskaznik->nastepny != nullptr) cout << "(index: " << i << "; wartosc: " << wskaznik->dane << "), ";
			else cout << "(index: " << i << "; wartosc: " << wskaznik->dane << ") ";
			wskaznik = wskaznik->nastepny;
			i++;
		} while (wskaznik != nullptr);
	}

	void wyswietl_od_konca() {
		Wezel* wskaznik = koniec;
		int i = ilosc - 1;
		do {
			if (wskaznik->poprzedni != nullptr) cout << "(index: " << i << "; wartosc: " << wskaznik->dane << "), ";
			else cout << "(index: " << i << "; wartosc: " << wskaznik->dane << ") ";
			wskaznik = wskaznik->poprzedni;
			i--;
		} while (wskaznik != nullptr);
	}

	/*
	
	Dodawanie elementów
	
	*/

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
		ilosc++;
	}
	void dodaj_na_koniec(int wartosc) {
		Wezel* nowyWezel = new Wezel;
		if (!koniec) {
			koniec = nowyWezel;
			poczatek = nowyWezel;
			nowyWezel->dane = wartosc;
		}
		else
		{
			nowyWezel->poprzedni = koniec;
			koniec->nastepny = nowyWezel;
			koniec = nowyWezel;
			nowyWezel->dane = wartosc;
		}
		ilosc++;
	}
	void dodaj_na_index(int wartosc, int index) {
		Wezel* nowyWezel = new Wezel;
		Wezel* wskaznik = poczatek;
		for (int i = 0; i < index - 1; i++)
		{
			wskaznik = wskaznik->nastepny;
		}
		nowyWezel->nastepny = wskaznik->nastepny;
		wskaznik->nastepny->poprzedni = nowyWezel;
		wskaznik->nastepny = nowyWezel;
		nowyWezel->poprzedni = wskaznik;
		nowyWezel->dane = wartosc;
		ilosc++;
	}

};

int main()
{
	ListaDwukierunkowa lista;
	lista.dodaj_na_poczatek(1);
	lista.dodaj_na_poczatek(2);
	lista.dodaj_na_poczatek(3);
	lista.dodaj_na_koniec(0);
	
	lista.wyswietl_od_poczatku();
	lista.dodaj_na_index(99, 2);
	cout << "\n==========\n";
	lista.wyswietl_od_poczatku();
	lista.wyswietl_od_konca();
}