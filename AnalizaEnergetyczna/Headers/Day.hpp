#ifndef DAY_HPP
#define DAY_HPP

#include <array>

#include "Quarter.hpp"

/**
 * @brief Klasa reprezentująca dzień.
 *
 * Przechowuje informacje o numerze dnia oraz o czterech kwadransach (6-godzinnych okresach) tego dnia.
 */
class Day {
public:
    /**
     * @brief Konstruktor klasy Day.
     *
     * Tworzy obiekt Day z podanym numerem dnia.
     * Inicjalizuje tablicę kwadransów.
     *
     * @param day Numer dnia (1-31).
     */
    explicit Day(int day);

    /**
     * @brief Destruktor klasy Day.
     *
     * Zwalnia pamięć zaalokowaną dla obiektów Quarter.
     */
    ~Day();

    /**
     * @brief Zwraca numer dnia.
     *
     * @return Numer dnia (1-31).
     */
    [[nodiscard]] int GetDay() const;

    /**
     * @brief Zwraca tablicę wskaźników do obiektów Quarter reprezentujących kwadranse dnia.
     *
     * @return Tablica wskaźników do obiektów Quarter.
     */
    [[nodiscard]] array<Quarter*, 4> GetQuarters() const;

private:
    /**
     * @brief Numer dnia (1-31).
     */
    int _day;
    /**
     * @brief Tablica wskaźników do obiektów Quarter reprezentujących kwadranse dnia.
     *
     * Indeksy tablicy odpowiadają kolejnym kwadransom:
     *  - 0: 00:00 - 05:45
     *  - 1: 06:00 - 11:45
     *  - 2: 12:00 - 17:45
     *  - 3: 18:00 - 23:45
     */
    array<Quarter *, 4> _quarters{};
};

#endif
