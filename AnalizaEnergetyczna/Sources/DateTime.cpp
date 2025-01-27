#include "../Headers/DateTime.hpp"

/**
 * @brief Konstruktor klasy DateTime.
 *
 * @param day Dzień.
 * @param month Miesiąc.
 * @param year Rok.
 * @param hour Godzina.
 * @param minute Minuta.
 */
DateTime::DateTime(const int day, const int month, const int year, const int hour, const int minute) : _day(day),
    _month(month), _year(year), _hour(hour), _minute(minute) { }

/**
 * @brief Zwraca dzień.
 *
 * @return Dzień.
 */
int DateTime::GetDay() const {
    return _day;
}

/**
 * @brief Zwraca miesiąc.
 *
 * @return Miesiąc.
 */
int DateTime::GetMonth() const {
    return _month;
}

/**
 * @brief Zwraca rok.
 *
 * @return Rok.
 */
int DateTime::GetYear() const {
    return _year;
}

/**
 * @brief Zwraca godzinę.
 *
 * @return Godzina.
 */
int DateTime::GetHour() const {
    return _hour;
}

/**
 * @brief Zwraca minutę.
 *
 * @return Minuta.
 */
int DateTime::GetMinute() const {
    return _minute;
}

/**
 * @brief Zwraca datę i godzinę w formacie string.
 *
 * @return Data i godzina jako string w formacie "DD.MM.YYYY HH:MM".
 */
string DateTime::ToString() const {
    char buffer[20]; // Bufor na sformatowany string (DD.MM.YYYY HH:MM + null terminator)
    // Używamy snprintf do bezpiecznego formatowania daty i godziny do bufora.
    // %02d - liczba całkowita z wiodącym zerem, jeśli jest mniejsza niż 10 (dla dni, miesięcy, godzin i minut).
    // %04d - liczba całkowita z wiodącymi zerami, jeśli jest mniejsza niż 1000 (dla roku).
    snprintf(buffer, sizeof(buffer), "%02d.%02d.%04d %02d:%02d", _day, _month, _year, _hour, _minute);
    return string(buffer); // Zwracamy string utworzony z bufora.
}