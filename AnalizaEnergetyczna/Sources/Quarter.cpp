#include "../Headers/Quarter.hpp"

#include <algorithm>

/**
 * @brief Konstruktor klasy Quarter.
 *
 * Tworzy obiekt reprezentujący kwadrans (przedział czasowy) i inicjalizuje wektor danych.
 *
 * @param startHour Godzina rozpoczęcia kwadransa (0-23).
 * @param endHour Godzina zakończenia kwadransa (0-23).
 */
Quarter::Quarter(const int startHour, const int endHour) {
    _startTime = new Time(startHour, 0);
    _endTime = new Time(endHour, 45);
    _data = new vector<Data*>();
}

/**
 * @brief Destruktor klasy Quarter.
 *
 * Zwalnia pamięć zaalokowaną dla obiektów Time oraz dla obiektów Data przechowywanych w wektorze.
 */
Quarter::~Quarter() {
    delete _startTime;
    delete _endTime;

    for (const Data* data : *_data) delete data;

    delete _data;
}

/**
 * @brief Dodaje dane do kwadransa, jeśli czas danych mieści się w przedziale czasowym kwadransa.
 *
 * @param time Czas danych do dodania.
 * @param data Referencja do obiektu Data do dodania.
 * @return true, jeśli dane zostały dodane, false w przeciwnym razie.
 */
bool Quarter::AddData(const Time& time, Data& data) const {
    const auto startTime = GetStartTime();

    if (const auto endTime = GetEndTime(); time > endTime || time < startTime) return false;

    _data->push_back(&data);

    return true;
}

/**
 * @brief Sortuje dane w kwadransie rosnąco po czasie.
 */
void Quarter::SortData() const {
    ranges::sort(*_data, [](const Data* a, const Data* b) {
        return a->GetTime() < b->GetTime();
    });
}

/**
 * @brief Zwraca referencję do obiektu Time reprezentującego czas rozpoczęcia kwadransa.
 *
 * @return Referencja do obiektu Time.
 */
Time& Quarter::GetStartTime() const {
    return *_startTime;
}

/**
 * @brief Zwraca referencję do obiektu Time reprezentującego czas zakończenia kwadransa.
 *
 * @return Referencja do obiektu Time.
 */
Time& Quarter::GetEndTime() const {
    return *_endTime;
}

/**
 * @brief Zwraca referencję do wektora przechowującego wskaźniki do obiektów Data.
 *
 * @return Referencja do wektora wskaźników do obiektów Data.
 */
vector<Data*>& Quarter::GetData() const {
    return *_data;
}