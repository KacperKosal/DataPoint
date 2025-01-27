#ifndef DATE_TIME_HPP
#define DATE_TIME_HPP

#include <string>

using namespace std;

/**
 * @brief Klasa reprezentująca datę i godzinę.
 *
 * Przechowuje informacje o dniu, miesiącu, roku, godzinie i minucie.
 */
class DateTime {
public:
    /**
     * @brief Konstruktor klasy DateTime.
     *
     * Tworzy obiekt DateTime z podanymi wartościami.
     *
     * @param day Dzień (1-31).
     * @param month Miesiąc (1-12).
     * @param year Rok.
     * @param hour Godzina (0-23).
     * @param minute Minuta (0-59).
     */
    DateTime(int day, int month, int year, int hour, int minute);

    /**
     * @brief Zwraca dzień.
     *
     * @return Dzień (1-31).
     */
    [[nodiscard]] int GetDay() const;

    /**
     * @brief Zwraca miesiąc.
     *
     * @return Miesiąc (1-12).
     */
    [[nodiscard]] int GetMonth() const;

    /**
     * @brief Zwraca rok.
     *
     * @return Rok.
     */
    [[nodiscard]] int GetYear() const;

    /**
     * @brief Zwraca godzinę.
     *
     * @return Godzina (0-23).
     */
    [[nodiscard]] int GetHour() const;

    /**
     * @brief Zwraca minutę.
     *
     * @return Minuta (0-59).
     */
    [[nodiscard]] int GetMinute() const;

    /**
     * @brief Zwraca tekstową reprezentację daty i godziny w formacie RRRR-MM-DD GG:MM.
     *
     * @return Tekstowa reprezentacja daty i godziny.
     */
    [[nodiscard]] string ToString() const;

private:
    /**
     * @brief Dzień (1-31).
     */
    int _day;
    /**
     * @brief Miesiąc (1-12).
     */
    int _month;
    /**
     * @brief Rok.
     */
    int _year;
    /**
     * @brief Godzina (0-23).
     */
    int _hour;
    /**
     * @brief Minuta (0-59).
     */
    int _minute;
};

#endif //DATE_TIME_HPP
