#include "../Headers/Data.hpp"

/**
 * @brief Konstruktor klasy Data.
 *
 * Tworzy obiekt klasy Data przechowujący informacje o zużyciu i produkcji energii w danym czasie.
 *
 * @param time Wskaźnik do obiektu Time reprezentującego czas pomiaru.
 * @param autoConsumption Wartość autokonsumpcji energii [kWh].
 * @param exportW Wartość eksportu energii [kWh].
 * @param importW Wartość importu energii [kWh].
 * @param consumption Wartość całkowitego zużycia energii [kWh].
 * @param generation Wartość produkcji energii [kWh].
 */
Data::Data(Time* time,const double autoConsumption, const double exportW, const double importW, const double consumption, const double generation) {
    _time = time;
    _autoConsumption = autoConsumption;
    _export = exportW;
    _import = importW;
    _consumption = consumption;
    _generation = generation;
}

/**
 * @brief Destruktor klasy Data.
 *
 * Zwalnia pamięć zaalokowaną dla obiektu Time.
 */
Data::~Data() {
    delete _time;
}

/**
 * @brief Zwraca referencję do obiektu Time.
 *
 * @return Referencja do obiektu Time reprezentującego czas pomiaru.
 */
Time& Data::GetTime() const {
    return *_time;
}

/**
 * @brief Zwraca wartość autokonsumpcji energii.
 *
 * @return Wartość autokonsumpcji energii [kWh].
 */
double Data::GetAutoConsumption() const {
    return _autoConsumption;
}

/**
 * @brief Zwraca wartość eksportu energii.
 *
 * @return Wartość eksportu energii [kWh].
 */
double Data::GetExport() const {
    return _export;
}

/**
 * @brief Zwraca wartość importu energii.
 *
 * @return Wartość importu energii [kWh].
 */
double Data::GetImport() const {
    return _import;
}

/**
 * @brief Zwraca wartość całkowitego zużycia energii.
 *
 * @return Wartość całkowitego zużycia energii [kWh].
 */
double Data::GetConsumption() const {
    return _consumption;
}

/**
 * @brief Zwraca wartość produkcji energii.
 *
 * @return Wartość produkcji energii [kWh].
 */
double Data::GetGeneration() const {
    return _generation;
}