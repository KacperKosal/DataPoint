#include "../Headers/Month.hpp"

/**
 * @brief Konstruktor klasy Month.
 * 
 * Tworzy obiekt reprezentujący miesiąc i inicjalizuje pusty wektor dni.
 * 
 * @param month Numer miesiąca (1-12).
 */
Month::Month(const int month) {
    _month = month;
    _days = new vector<Day*>();
}

/**
 * @brief Destruktor klasy Month.
 * 
 * Zwalnia pamięć zaalokowaną dla obiektów Day przechowywanych w wektorze oraz dla samego wektora.
 */
Month::~Month() {
    for (const Day* day : *_days) delete day;

    delete _days;
}

/**
 * @brief Zwraca numer miesiąca.
 * 
 * @return Numer miesiąca (1-12).
 */
int Month::GetMonth() const {
    return _month;
}

/**
 * @brief Zwraca referencję do wektora dni.
 * 
 * @return Referencja do wektora wskaźników do obiektów Day.
 */
vector<Day*>& Month::GetDays() const {
    return *_days;
}