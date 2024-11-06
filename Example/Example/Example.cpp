#include <iostream>
#include <string>
using namespace std;

struct Wezel {
	int dane;
	Wezel* nastepny;
	Wezel* poprzedni;

	Wezel() : dane(NULL), poprzedni(nullptr), nastepny(nullptr) {};
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
		if (index > 0 && index < ilosc - 1) {
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
		else if (index == ilosc - 1) dodaj_na_koniec(wartosc);
		else cout << "Index poza listą";
	}

	/*

	Usuwanie elementów

	*/

	void usun_z_poczatku() {
		if (ilosc == 0) {
			cout << "brak elementow\n";
		}
		else
			if (ilosc >= 2)
			{
				Wezel* chwilowy = poczatek;
				poczatek = poczatek->nastepny;
				poczatek->poprzedni = nullptr;
				delete chwilowy;
			}
			else {
				delete poczatek;
				koniec = nullptr;
				poczatek = nullptr;
			}

		ilosc--;
	}
	void usun_z_konca() {
		if (ilosc == 0) {
			cout << "brak elementow\n";
		}
		else if (ilosc > 1)
		{
			Wezel* chwilowy = koniec;
			koniec = koniec->poprzedni;
			koniec->nastepny = nullptr;
			delete chwilowy;
		}
		else if (ilosc == 1) {
			delete koniec;
			poczatek = nullptr;
			koniec = nullptr;
		}
		ilosc--;
	}
	void usun_z_indexu(int index) {
		if (index > 0 && index < ilosc - 1) {
			Wezel* wskaznik = poczatek;
			for (int i = 0; i < index; i++) {
				wskaznik = wskaznik->nastepny;
			}
			wskaznik->poprzedni->nastepny = wskaznik->nastepny;
			wskaznik->nastepny->poprzedni = wskaznik->poprzedni;
			delete wskaznik;
			ilosc--;
		}
		else if (index == 0) usun_z_poczatku();
		else if (index == ilosc - 1) usun_z_konca();
		else cout << "Index poza listą";

	}

	string wezel(int index) {
		if (poczatek == nullptr) return "";
		if (index == -1) return "";
		Wezel* wskaznik = poczatek; 
		for (int i = 0; i < index; i++)
		{
			if (wskaznik->nastepny != nullptr) wskaznik = wskaznik->nastepny;
			else {
				wskaznik = nullptr;
				return "";
			}
		}
		if (wskaznik != nullptr) return to_string(wskaznik->dane);

	}
	void Widok() {

		int wybrany_index = 0, komenda = 0, wartosc = 0, wartosc2 = 0, widok = 0;

		do {

			system("cls");

			cout << "1 - poprzedni element\n2 - nastepny element\n3 - dodaj na poczatek\n4 - dodaj na koniec\n5 - dodaj na konkretne miejsce\n6 - usun z poczatku\n7 - usun z konca\n8 - usun z konkretnego indexu\n9 - wyswietl liste od poczatku\n10 - wyswietl liste od konca\n0 - wyjdz\n\n";

			if (widok == 0) {
				if (wezel(wybrany_index - 1) != "") cout << wezel(wybrany_index - 1); else  cout << "#";
				;			cout << " -> " << wezel(wybrany_index) << " <- ";
				if (wezel(wybrany_index + 1) != "") cout << wezel(wybrany_index + 1); else  cout << "#";

				cout << " \nindex: " << wybrany_index << "\n\nkomenda: ";
			}
			else if (widok == 1) wyswietl_od_poczatku();
			else if (widok == 2) wyswietl_od_konca();
			

			cin >> komenda;


			switch (komenda)
			{
			case 1:
				if(wybrany_index > 0) wybrany_index--;
				break;
			case 2:
				if(wybrany_index < ilosc - 1) wybrany_index++;;
				break;
			case 3:
				cout << "Podaj wartosc: ";
				cin >> wartosc;
				dodaj_na_poczatek(wartosc);
				break;
			case 4:
				cout << "Podaj wartosc: ";
				cin >> wartosc;
				dodaj_na_koniec(wartosc);
				break;
			case 5:
				cout << "Podaj index: ";
				cin >> wartosc2;

				cout << "Podaj wartosc: ";
				cin >> wartosc;

				dodaj_na_index(wartosc, wartosc2);
				break;
			case 6:
				if(ilosc > 0) usun_z_poczatku();
				break;
			case 7:
				if (ilosc > 0) usun_z_konca();
				break;
			case 8:
				cout << "Podaj index: ";
				cin >> wartosc2;

				usun_z_indexu(wartosc2);
				break;
			case 9:
				widok = 1;
				break;
			case 10:
				widok = 2;
				break;
			case 11:
				widok = 0;
				break;
			}

		} while (komenda != 0 && ilosc != 0);
	}
};
	
int main()
{
	ListaDwukierunkowa lista;
	lista.Widok();

}