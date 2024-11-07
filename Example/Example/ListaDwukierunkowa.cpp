#include "ListaDwukierunkowa.h"
#include <iostream>
#include <string>


/**
* @brief Wy�wietla elementy listy od pocz�tku.
*
* Wypisuje ka�dy element listy zaczynaj�c od pierwszego elementu.
*/

	void ListaDwukierunkowa::wyswietl_od_poczatku() {
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

	/**
 * @brief Wy�wietla elementy listy od ko�ca.
 *
 * Wypisuje ka�dy element listy zaczynaj�c od ostatniego elementu.
 */

	void ListaDwukierunkowa::wyswietl_od_konca() {
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

	/**
 * @brief Dodaje nowy element na pocz�tek listy.
 *
 * @param wartosc Warto�� do dodania na pocz�tek listy.
 * @return Wska�nik do nowo dodanego w�z�a.
 */

	Wezel* ListaDwukierunkowa::dodaj_na_poczatek(int wartosc) {
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

	/**
 * @brief Dodaje nowy element na koniec listy.
 *
 * @param wartosc Warto�� do dodania na koniec listy.
 * @return Wska�nik do nowo dodanego w�z�a.
 */

	Wezel* ListaDwukierunkowa::dodaj_na_koniec(int wartosc) {
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


	/**
	 * @brief Dodaje nowy element na podanym indeksie.
	 *
	 * @param wartosc Warto�� do dodania.
	 * @param index Indeks, na kt�rym nale�y doda� nowy element.
	 * @return Wska�nik do nowo dodanego w�z�a, lub nullptr je�li indeks jest nieprawid�owy.
	 */

	Wezel* ListaDwukierunkowa::dodaj_na_index(int wartosc, int index) {
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
		else cout << "Index poza list�";
	}

	/**
	 * @brief Usuwa pierwszy element z listy.
	 */

	void ListaDwukierunkowa::usun_z_poczatku() {
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
	/**
 * @brief Usuwa ostatni element z listy.
 */
	void ListaDwukierunkowa::usun_z_konca() {
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

	/**
 * @brief Usuwa element na podanym indeksie.
 *
 * @param index Indeks elementu do usuni�cia.
 */

	void ListaDwukierunkowa::usun_z_indexu(int index) {
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
		else cout << "Index poza list�";

	}

	/**
 * @brief Zwraca warto�� w�z�a na podanym indeksie jako string.
 *
 * @param index Indeks w�z�a, kt�rego warto�� ma zosta� zwr�cona.
 * @return Warto�� w�z�a jako string, lub pusty string je�li indeks jest nieprawid�owy.
 */

	string ListaDwukierunkowa::wezel(int index) {
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

	/**
 * @brief Interfejs konsolowy do zarz�dzania list�.
 *
 * Umo�liwia u�ytkownikowi wykonywanie operacji na li�cie, takich jak dodawanie, usuwanie, czy wy�wietlanie element�w.
 */

	void ListaDwukierunkowa::Widok() {

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
				if (wybrany_index > 0) wybrany_index--;
				break;
			case 2:
				if (wybrany_index < ilosc - 1) wybrany_index++;;
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
				if (wybrany_index + 1 == ilosc) wybrany_index--;
				if (ilosc > 0) usun_z_poczatku();
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
