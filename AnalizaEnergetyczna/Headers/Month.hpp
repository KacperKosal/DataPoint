
#ifndef MONTH_HPP
#define MONTH_HPP

#include <vector>

#include "Day.hpp"

using namespace std;

/**
 * @brief Klasa reprezentująca miesiąc.
 *
 * Przechowuje informacje o numerze miesiąca oraz o dniach wchodzących w skład tego miesiąca.
 */
class Month {
public:
    /**
     * @brief Konstruktor klasy Month.
     *
     * Tworzy obiekt Month z podanym numerem miesiąca.
     * Inicjalizuje wektor dni.
     *
     * @param month Numer miesiąca (1-12).
     */
    explicit Month(int month);

    /**
     * @brief Destruktor klasy Month.
     *
     * Zwalnia pamięć zaalokowaną dla obiektów Day.
     */
    ~Month();

    /**
     * @brief Zwraca numer miesiąca.
     *
     * @return Numer miesiąca (1-12).
     */
    [[nodiscard]] int GetMonth() const;

    /**
     * @brief Zwraca referencję do wektora wskaźników do obiektów Day reprezentujących dni miesiąca.
     *
     * @return Referencja do wektora wskaźników do obiektów Day.
     */
    [[nodiscard]] vector<Day*>& GetDays() const;

private:
    /**
     * @brief Numer miesiąca (1-12).
     */
    int _month;
    /**
     * @brief Wskaźnik do wektora wskaźników do obiektów Day reprezentujących dni miesiąca.
     */
    vector<Day*>* _days;
};

#endif //MONTH_HPP
