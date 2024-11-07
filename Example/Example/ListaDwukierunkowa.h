#pragma once
using namespace std;
#include <string>

/**
 * @brief Struktura reprezentuj¹ca pojedynczy wêze³ listy dwukierunkowej.
 *
 * Ka¿dy wêze³ zawiera dane oraz wskaŸniki na nastêpny i poprzedni element listy.
 */
struct Wezel {
    int dane;              /**< Wartoœæ przechowywana w wêŸle. */
    Wezel* nastepny;       /**< WskaŸnik na nastêpny element listy. */
    Wezel* poprzedni;      /**< WskaŸnik na poprzedni element listy. */

    /**
     * @brief Konstruktor domyœlny inicjalizuj¹cy pola wêz³a.
     */
    Wezel() : dane(NULL), poprzedni(nullptr), nastepny(nullptr) {}
};

/**
 * @brief Klasa reprezentuj¹ca listê dwukierunkow¹.
 *
 * Zapewnia metody do dodawania, usuwania i wyœwietlania elementów listy.
 */
class ListaDwukierunkowa {
private:
    Wezel* poczatek;   /**< WskaŸnik na pierwszy element listy. */
    Wezel* koniec;     /**< WskaŸnik na ostatni element listy. */
    int ilosc;         /**< Liczba elementów w liœcie. */

public:
    /**
     * @brief Konstruktor domyœlny inicjalizuj¹cy pust¹ listê.
     */
    ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr), ilosc(0) {}

    /**
     * @brief Destruktor czyszcz¹cy pamiêæ przy usuwaniu listy.
     */
    ~ListaDwukierunkowa() {}

    /**
     * @brief Wyœwietla elementy listy od pocz¹tku.
     */
    void wyswietl_od_poczatku();

    /**
     * @brief Wyœwietla elementy listy od koñca.
     */
    void wyswietl_od_konca();

    /**
     * @brief Dodaje nowy element na pocz¹tek listy.
     *
     * @param wartosc Wartoœæ do dodania na pocz¹tek listy.
     * @return WskaŸnik do nowo dodanego wêz³a.
     */
    Wezel* dodaj_na_poczatek(int wartosc);

    /**
     * @brief Dodaje nowy element na koniec listy.
     *
     * @param wartosc Wartoœæ do dodania na koniec listy.
     * @return WskaŸnik do nowo dodanego wêz³a.
     */
    Wezel* dodaj_na_koniec(int wartosc);

    /**
     * @brief Dodaje nowy element na podanym indeksie.
     *
     * @param wartosc Wartoœæ do dodania.
     * @param index Indeks, na którym nale¿y dodaæ nowy element.
     * @return WskaŸnik do nowo dodanego wêz³a, lub nullptr jeœli indeks jest nieprawid³owy.
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
     * @param index Indeks elementu do usuniêcia.
     */
    void usun_z_indexu(int index);

    /**
     * @brief Zwraca wartoœæ wêz³a na podanym indeksie jako string.
     *
     * @param index Indeks wêz³a, którego wartoœæ ma zostaæ zwrócona.
     * @return Wartoœæ wêz³a jako string, lub pusty string jeœli indeks jest nieprawid³owy.
     */
    string wezel(int index);

    /**
     * @brief Interfejs konsolowy do zarz¹dzania list¹.
     *
     * Umo¿liwia u¿ytkownikowi wykonywanie operacji na liœcie, takich jak dodawanie, usuwanie, czy wyœwietlanie elementów.
     */
    void Widok();
};
