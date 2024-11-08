#pragma once
using namespace std;
#include <string>

/**
 * @brief Struktura reprezentujaca pojedynczy wezel listy dwukierunkowej.
 *
 * Kazdy wezel zawiera dane oraz wskazniki na nastepny i poprzedni element listy.
 */
struct Wezel {
    int dane;              /**< Wartosc przechowywana w wezle. */
    Wezel* nastepny;       /**< Wskaznik na nastepny element listy. */
    Wezel* poprzedni;      /**< Wskaznik na poprzedni element listy. */

    /**
     * @brief Konstruktor domyslny inicjalizujacy pola wezla.
     */
    Wezel() : dane(NULL), poprzedni(nullptr), nastepny(nullptr) {}
};

/**
 * @brief Klasa reprezentujaca liste dwukierunkowa.
 *
 * Zapewnia metody do dodawania, usuwania i wyswietlania elementow listy.
 */
class ListaDwukierunkowa {
private:
    Wezel* poczatek;   /**< Wskaznik na pierwszy element listy. */
    Wezel* koniec;     /**< Wskaznik na ostatni element listy. */
    int ilosc;         /**< Liczba elementow w liscie. */

public:
    /**
     * @brief Konstruktor domyslny inicjalizujacy pusta liste.
     */
    ListaDwukierunkowa();

    /**
     * @brief Destruktor czyszczacy pamiec przy usuwaniu listy.
     */
    ~ListaDwukierunkowa();

    /**
     * @brief Wyswietla elementy listy od poczatku.
     */
    void wyswietl_od_poczatku();

    /**
     * @brief Wyswietla elementy listy od konca.
     */
    void wyswietl_od_konca();

    /**
     * @brief Dodaje nowy element na poczatek listy.
     *
     * @param wartosc Wartosc do dodania na poczatek listy.
     * @return Wskaznik do nowo dodanego wezla.
     */
    Wezel* dodaj_na_poczatek(int wartosc);

    /**
     * @brief Dodaje nowy element na koniec listy.
     *
     * @param wartosc Wartosc do dodania na koniec listy.
     * @return Wskaznik do nowo dodanego wezla.
     */
    Wezel* dodaj_na_koniec(int wartosc);

    /**
     * @brief Dodaje nowy element na podanym indeksie.
     *
     * @param wartosc Wartosc do dodania.
     * @param index Indeks, na ktorym nalezy dodac nowy element.
     * @return Wskaznik do nowo dodanego wezla, lub nullptr jesli indeks jest nieprawidlowy.
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
     * @param index Indeks elementu do usuniecia.
     */
    void usun_z_indexu(int index);

    /**
     * @brief Zwraca wartosc wezla na podanym indeksie jako string.
     *
     * @param index Indeks wezla, ktorego wartosc ma zostac zwrocona.
     * @return Wartosc wezla jako string, lub pusty string jesli indeks jest nieprawidlowy.
     */
    string wezel(int index);

    /**
     * @brief Interfejs konsolowy do zarzadzania lista.
     *
     * Umozliwia uzytkownikowi wykonywanie operacji na liscie, takich jak dodawanie, usuwanie, czy wyswietlanie elementow.
     */
    void Widok();

    void WyczyscListe();
};

//commit do usuniêcia
