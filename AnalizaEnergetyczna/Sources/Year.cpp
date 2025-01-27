#include "../Headers/Year.hpp"

/**
 * @brief Konstruktor klasy Year.
 * 
 * Tworzy obiekt reprezentujący rok i inicjalizuje pusty wektor miesięcy.
 * 
 * @param year Numer roku.
 */
Year::Year(const int year) {
    _year = year;
    _months = new vector<Month*>();
}

/**
 * @brief Destruktor klasy Year.
 * 
 * Zwalnia pamięć zaalokowaną dla obiektów Month przechowywanych w wektorze oraz dla samego wektora.
 */
Year::~Year() {
    for (const Month* month : *_months) delete month;

    delete _months;
}

/**
 * @brief Zwraca numer roku.
 * 
 * @return Numer roku.
 */
int Year::GetYear() const {
    return _year;
}

/**
 * @brief Zwraca referencję do wektora miesięcy.
 * 
 * @return Referencja do wektora wskaźników do obiektów Month.
 */
vector<Month*>& Year::GetMonths() const {
    return *_months;
}