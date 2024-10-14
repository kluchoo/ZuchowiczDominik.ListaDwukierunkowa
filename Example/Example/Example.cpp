#include <iostream>
#include <string>
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
		if (!koniec) {}
		else {
			Wezel* wskaznik = poczatek;
			int i = 0;
			do {
				if (wskaznik->nastepny != nullptr) cout << "(index: " << i << "; wartosc: " << wskaznik->dane << "), ";
				else cout << "(index: " << i << "; wartosc: " << wskaznik->dane << ") ";
				wskaznik = wskaznik->nastepny;
				i++;
			} while (wskaznik != nullptr);
		}
	}

	void wyswietl_od_konca() {
		if (!koniec) {}
		else {
			Wezel* wskaznik = koniec;
			int i = ilosc - 1;
			do {
				if (wskaznik->poprzedni != nullptr) cout << "(index: " << i << "; wartosc: " << wskaznik->dane << "), ";
				else cout << "(index: " << i << "; wartosc: " << wskaznik->dane << ") ";
				wskaznik = wskaznik->poprzedni;
				i--;
			} while (wskaznik != nullptr);
		}
	}

	/*
	
	Dodawanie elementów
	
	*/

	Wezel* dodaj_na_poczatek(int wartosc) {
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
		return nowyWezel;
	}
	Wezel* dodaj_na_koniec(int wartosc) {
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
		return nowyWezel;
	}

	/*
	@Brief walidacja dodana!!
	*/
	Wezel* dodaj_na_index(int wartosc, int index) {
		if (index > 0 && index < ilosc) {
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
			return nowyWezel;
		}
		else if (index == 0) dodaj_na_poczatek(wartosc);
		else if (index == ilosc) dodaj_na_koniec(wartosc);
		else cout << "Index poza listą";
	}

	/*
	
	Usuwanie elementów

	*/

	void usun_z_poczatku() {
		if (!poczatek) {
			cout << "brak elementow\n";
		}
		else
		{
			Wezel* chwilowy = poczatek;
			poczatek = poczatek->nastepny;
			poczatek->poprzedni = nullptr;
			delete chwilowy;
		}
		ilosc--;
	}
	void usun_z_konca() {
		if (!koniec) {
			cout << "brak elementow\n";
		}
		else
		{
			Wezel* chwilowy = koniec;
			koniec = koniec->poprzedni;
			koniec->nastepny = nullptr;
			delete chwilowy;
		}
		ilosc--;
	}
	void usun_z_indexu(int index) {
		if (index > 0 && index < ilosc - 1) {
			Wezel* wskaznik = poczatek;
			for (int i = 0; i < index; i++) {
				wskaznik = wskaznik->nastepny;
			}
			Wezel* pomocniczy = wskaznik->poprzedni;
			pomocniczy->nastepny = wskaznik->nastepny;
			wskaznik->nastepny->poprzedni = pomocniczy;
			delete wskaznik;
		}
	}
	void poruszanie_sie_po_liscie() {
		int index = 0;
		int komenda = 0;
		string error = "";
		Wezel* wybrany = new Wezel;
		if (poczatek != nullptr) wybrany = poczatek;
		do {
			
			/*wyswietlanie:*/
			cout << "1 - poprzedni element\n2 - nastepny element\n3 - dodaj na poczatek\n4 - dodaj na koniec\n5 - dodaj na konkretne miejsce\n6 - usun z poczatku\n7 - usun z konca\n8 - usun z konkretnego indexu\n9 - wyswietl liste od poczatku\n10 - wyswietl liste od konca\n0 - wyjdz\n\n\n\n"; \
			if(komenda != 9 && komenda != 10)
			{
				cout << "\n\nwartosc: ";
				if (wybrany->poprzedni != nullptr) { cout << wybrany->poprzedni->dane; }
				if (wybrany != nullptr) { cout << " -> "; if (ilosc == 0) cout << "null"; else cout << wybrany->dane; cout << " <- "; }
				if (wybrany->nastepny != nullptr) { cout << wybrany->nastepny->dane; }
				cout << "\nindex: " << index << "\n\n\n" << error << "\n\n";
			}
			else if(komenda == 9) {
				wyswietl_od_poczatku();
			}
			else if (komenda == 10) {
				wyswietl_od_konca();
			}
			
			/*	*/



			error = "";
			cin >> komenda;
			int a = 0, ind = 0;
			switch (komenda)
			{
			case 1:
				if (wybrany->poprzedni != nullptr) {
					wybrany = wybrany->poprzedni;
					index--;
				}
				break;
			case 2:
				if (wybrany->nastepny != nullptr) {
					wybrany = wybrany->nastepny;
					index++;
				}
				break;
			case 3:
				cout << "Podaj wartosc: ";
				cin >> a;
				if (ilosc == 0) wybrany = dodaj_na_poczatek(a);
				else { dodaj_na_poczatek(a); index++; }
				break;
			case 4:
				cout << "Podaj wartosc: ";
				cin >> a;
				if (ilosc == 0) wybrany = dodaj_na_koniec(a);
				else { dodaj_na_koniec(a); }
				break;
			case 5:
				cout << "Podaj wartosc: ";
				cin >> a;
				cout << "Podaj index: ";
				cin >> ind;
				if (ind >= 0 && ind <= ilosc) {
					wybrany = dodaj_na_index(a, ind);
					index = ind;
				} 
				else error = "Index poza lista";
				
				break;
			case 6:
				if (wybrany == poczatek) { wybrany = poczatek->nastepny; index++; };
				usun_z_poczatku();
				index--;
				break;
			case 7:
				if (wybrany == koniec) { wybrany = koniec->poprzedni; index--; }
				usun_z_konca();
				break;
			case 8:
				if (wybrany == poczatek) { 
					if (wybrany == poczatek) { wybrany = poczatek->nastepny; index++; };
					usun_z_poczatku();
					index--;
				}
				else if (wybrany == koniec) { 
					if (wybrany == koniec) { wybrany = koniec->poprzedni; index--; }
					usun_z_konca();
				}
				else { wybrany = wybrany->poprzedni; usun_z_indexu(index); index--; }
				break;
			}
			system("cls");
		} while (komenda != 0);
	}
};

int main()
{
	ListaDwukierunkowa lista;

	lista.poruszanie_sie_po_liscie();

}