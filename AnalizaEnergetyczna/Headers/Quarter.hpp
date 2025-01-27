#ifndef QUARTER_HPP
#define QUARTER_HPP

#include <vector>

#include "Time.hpp"
#include "Data.hpp"

using namespace std;

/**
 * @brief Klasa reprezentująca kwadrans (przedział czasowy) w ciągu dnia.
 *
 * Przechowuje informacje o godzinie rozpoczęcia i zakończenia kwadransa oraz dane pomiarowe
 * z tego okresu.
 */
class Quarter {
public:
    /**
     * @brief Konstruktor klasy Quarter.
     *
     * Tworzy obiekt Quarter z podanymi godzinami rozpoczęcia i zakończenia.
     * Inicjalizuje wektor danych.
     *
     * @param startHour Godzina rozpoczęcia kwadransa.
     * @param endHour Godzina zakończenia kwadransa.
     */
    Quarter(int startHour, int endHour);

    /**
     * @brief Destruktor klasy Quarter.
     *
     * Zwalnia pamięć zaalokowaną dla obiektów Time oraz wektora danych.
     */
    ~Quarter();

    /**
     * @brief Dodaje dane pomiarowe do kwadransa, jeśli czas pomiaru mieści się w przedziale czasowym kwadransa.
     *
     * @param time Referencja do stałej টাইম obiektu Time reprezentującego czas pomiaru.
     * @param data Referencja do obiektu Data zawierającego dane pomiarowe.
     * @return `true`, jeśli dane zostały dodane, `false` w przeciwnym razie.
     */
    bool AddData(const Time& time, Data& data) const;

    /**
     * @brief Sortuje dane pomiarowe w kwadransie rosnąco według czasu.
     *
     * Dane są sortowane w miejscu, modyfikując kolejność elementów w wektorze `_data`.
     */
    void SortData() const;

    /**
     * @brief Zwraca referencję do obiektu Time reprezentującego godzinę rozpoczęcia kwadransa.
     *
     * @return Referencja do obiektu Time.
     */
    [[nodiscard]] Time& GetStartTime() const;

    /**
     * @brief Zwraca referencję do obiektu Time reprezentującego godzinę zakończenia kwadransa.
     *
     * @return Referencja do obiektu Time.
     */
    [[nodiscard]] Time& GetEndTime() const;

    /**
     * @brief Zwraca referencję do wektora wskaźników do obiektów Data, zawierającego dane pomiarowe z kwadransa.
     *
     * @return Referencja do wektora wskaźników do obiektów Data.
     */
    [[nodiscard]] vector<Data*>& GetData() const;

private:
    /**
     * @brief Wskaźnik do obiektu Time reprezentującego godzinę rozpoczęcia kwadransa.
     */
    Time* _startTime;
    /**
     * @brief Wskaźnik do obiektu Time reprezentującego godzinę zakończenia kwadransa.
     */
    Time* _endTime;
    /**
     * @brief Wskaźnik do wektora wskaźników do obiektów Data, przechowującego dane pomiarowe z kwadransa.
     */
    vector<Data*>* _data;
};

#endif //QUARTER_HPP
