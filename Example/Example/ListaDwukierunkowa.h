#pragma once
using namespace std;
#include <string>

struct Wezel {
	int dane;
	Wezel* nastepny;
	Wezel* poprzedni;

	Wezel() : dane(NULL), poprzedni(nullptr), nastepny(nullptr) {};
};

class ListaDwukierunkowa
{
private:
	Wezel* poczatek;
	Wezel* koniec;
	int ilosc;
public:
	ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr), ilosc(0) {}
	~ListaDwukierunkowa() {};

	void wyswietl_od_poczatku();
	void wyswietl_od_konca();
	Wezel* dodaj_na_poczatek(int wartosc);
	Wezel* dodaj_na_koniec(int wartosc);
	Wezel* dodaj_na_index(int wartosc, int index);
	void usun_z_poczatku();
	void usun_z_konca();
	void usun_z_indexu(int index);
	string wezel(int index);
	void Widok();
};

