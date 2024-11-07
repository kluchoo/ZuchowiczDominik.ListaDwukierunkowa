#pragma once
using namespace std;
#include <string>

/**
 * @brief Struktura reprezentuj�ca pojedynczy w�ze� listy dwukierunkowej.
 *
 * Ka�dy w�ze� zawiera dane oraz wska�niki na nast�pny i poprzedni element listy.
 */
struct Wezel {
    int dane;              /**< Warto�� przechowywana w w�le. */
    Wezel* nastepny;       /**< Wska�nik na nast�pny element listy. */
    Wezel* poprzedni;      /**< Wska�nik na poprzedni element listy. */

    /**
     * @brief Konstruktor domy�lny inicjalizuj�cy pola w�z�a.
     */
    Wezel() : dane(NULL), poprzedni(nullptr), nastepny(nullptr) {}
};

/**
 * @brief Klasa reprezentuj�ca list� dwukierunkow�.
 *
 * Zapewnia metody do dodawania, usuwania i wy�wietlania element�w listy.
 */
class ListaDwukierunkowa {
private:
    Wezel* poczatek;   /**< Wska�nik na pierwszy element listy. */
    Wezel* koniec;     /**< Wska�nik na ostatni element listy. */
    int ilosc;         /**< Liczba element�w w li�cie. */

public:
    /**
     * @brief Konstruktor domy�lny inicjalizuj�cy pust� list�.
     */
    ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr), ilosc(0) {}

    /**
     * @brief Destruktor czyszcz�cy pami�� przy usuwaniu listy.
     */
    ~ListaDwukierunkowa() {}

    /**
     * @brief Wy�wietla elementy listy od pocz�tku.
     */
    void wyswietl_od_poczatku();

    /**
     * @brief Wy�wietla elementy listy od ko�ca.
     */
    void wyswietl_od_konca();

    /**
     * @brief Dodaje nowy element na pocz�tek listy.
     *
     * @param wartosc Warto�� do dodania na pocz�tek listy.
     * @return Wska�nik do nowo dodanego w�z�a.
     */
    Wezel* dodaj_na_poczatek(int wartosc);

    /**
     * @brief Dodaje nowy element na koniec listy.
     *
     * @param wartosc Warto�� do dodania na koniec listy.
     * @return Wska�nik do nowo dodanego w�z�a.
     */
    Wezel* dodaj_na_koniec(int wartosc);

    /**
     * @brief Dodaje nowy element na podanym indeksie.
     *
     * @param wartosc Warto�� do dodania.
     * @param index Indeks, na kt�rym nale�y doda� nowy element.
     * @return Wska�nik do nowo dodanego w�z�a, lub nullptr je�li indeks jest nieprawid�owy.
     */
    Wezel* dodaj_na_index(int wartosc, int index);

    /**
     * @brief Usuwa pierwszy element z listy.
     */
    void usun_z_poczatku();

    /**
     * @brief Usuwa ostatni element z listy.
     */
    void usun_z_konca();

    /**
     * @brief Usuwa element na podanym indeksie.
     *
     * @param index Indeks elementu do usuni�cia.
     */
    void usun_z_indexu(int index);

    /**
     * @brief Zwraca warto�� w�z�a na podanym indeksie jako string.
     *
     * @param index Indeks w�z�a, kt�rego warto�� ma zosta� zwr�cona.
     * @return Warto�� w�z�a jako string, lub pusty string je�li indeks jest nieprawid�owy.
     */
    string wezel(int index);

    /**
     * @brief Interfejs konsolowy do zarz�dzania list�.
     *
     * Umo�liwia u�ytkownikowi wykonywanie operacji na li�cie, takich jak dodawanie, usuwanie, czy wy�wietlanie element�w.
     */
    void Widok();
};
