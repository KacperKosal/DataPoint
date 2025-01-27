#include "../Headers/Day.hpp"

/**
 * @brief Konstruktor klasy Day.
 *
 * Tworzy obiekt reprezentujący dzień i inicjalizuje cztery kwadranse (poranny, południowy, popołudniowy, wieczorny).
 *
 * @param day Numer dnia (np. 1-31).
 */
Day::Day(const int day) {
    _day = day;

    _quarters[0] = new Quarter(0, 5);   // Poranny (00:00 - 05:45)
    _quarters[1] = new Quarter(6, 11);  // Południowy (06:00 - 11:45)
    _quarters[2] = new Quarter(12, 17); // Popołudniowy (12:00 - 17:45)
    _quarters[3] = new Quarter(18, 23); // Wieczorny (18:00 - 23:45)
}

/**
 * @brief Destruktor klasy Day.
 *
 * Zwalnia pamięć zaalokowaną dla czterech obiektów Quarter.
 */
Day::~Day() {
    for (int i = 0; i < 4; i++) delete _quarters[i];
}

/**
 * @brief Zwraca numer dnia.
 *
 * @return Numer dnia.
 */
int Day::GetDay() const {
    return _day;
}

/**
 * @brief Zwraca tablicę czterech kwadransów.
 *
 * @return Tablica wskaźników do obiektów Quarter.
 */
array<Quarter*, 4> Day::GetQuarters() const {
    return _quarters;
}