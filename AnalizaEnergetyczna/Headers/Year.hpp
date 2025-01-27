#ifndef YEAR_HPP
#define YEAR_HPP

#include <vector>

#include "../Headers/Month.hpp"

using namespace std;

/**
 * @brief Klasa reprezentująca rok.
 *
 * Przechowuje informacje o numerze roku oraz o miesiącach wchodzących w skład tego roku.
 */
class Year {
public:
    /**
     * @brief Konstruktor klasy Year.
     *
     * Tworzy obiekt Year z podanym numerem roku.
     * Inicjalizuje wektor miesięcy.
     *
     * @param year Numer roku.
     */
    explicit Year(int year);

    /**
     * @brief Destruktor klasy Year.
     *
     * Zwalnia pamięć zaalokowaną dla obiektów Month.
     */
    ~Year();

    /**
     * @brief Zwraca numer roku.
     *
     * @return Numer roku.
     */
    [[nodiscard]] int GetYear() const;

    /**
     * @brief Zwraca referencję do wektora wskaźników do obiektów Month reprezentujących miesiące roku.
     *
     * @return Referencja do wektora wskaźników do obiektów Month.
     */
    [[nodiscard]] vector<Month*>& GetMonths() const;

private:
    /**
     * @brief Numer roku.
     */
    int _year;
    /**
     * @brief Wskaźnik do wektora wskaźników do obiektów Month reprezentujących miesiące roku.
     */
    vector<Month*>* _months;
};

#endif //YEAR_HPP
