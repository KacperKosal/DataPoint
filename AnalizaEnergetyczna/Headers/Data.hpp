#ifndef DATA_HPP
#define DATA_HPP

#include "Time.hpp"

/**
 * @brief Klasa reprezentująca pojedynczy rekord danych z pomiarów energii.
 *
 * Przechowuje informacje o czasie pomiaru oraz wartościach zużycia, produkcji,
 * eksportu i importu energii.
 */
class Data {
public:
    /**
     * @brief Konstruktor klasy Data.
     *
     * Tworzy obiekt Data z podanymi wartościami.
     *
     * @param time Wskaźnik do obiektu Time reprezentującego czas pomiaru.
     * @param autoConsumption Wartość autokonsumpcji energii (w watach [W]).
     * @param exportW Wartość eksportu energii (w watach [W]).
     * @param importW Wartość importu energii (w watach [W]).
     * @param consumption Wartość zużycia energii (poboru) (w watach [W]).
     * @param generation Wartość produkcji energii (w watach [W]).
     */
    Data(Time* time, double autoConsumption, double exportW, double importW, double consumption, double generation);

    /**
     * @brief Destruktor klasy Data.
     *
     * Zwalnia pamięć zaalokowaną dla obiektu Time.
     */
    ~Data();

    /**
     * @brief Zwraca referencję do obiektu Time reprezentującego czas pomiaru.
     *
     * @return Referencja do obiektu Time.
     */
    [[nodiscard]] Time& GetTime() const;

    /**
     * @brief Zwraca wartość autokonsumpcji energii.
     *
     * @return Wartość autokonsumpcji energii (w watach [W]).
     */
    [[nodiscard]] double GetAutoConsumption() const;

    /**
     * @brief Zwraca wartość eksportu energii.
     *
     * @return Wartość eksportu energii (w watach [W]).
     */
    [[nodiscard]] double GetExport() const;

    /**
     * @brief Zwraca wartość importu energii.
     *
     * @return Wartość importu energii (w watach [W]).
     */
    [[nodiscard]] double GetImport() const;

    /**
     * @brief Zwraca wartość zużycia energii (poboru).
     *
     * @return Wartość zużycia energii (w watach [W]).
     */
    [[nodiscard]] double GetConsumption() const;

    /**
     * @brief Zwraca wartość produkcji energii.
     *
     * @return Wartość produkcji energii (w watach [W]).
     */
    [[nodiscard]] double GetGeneration() const;

private:
    /**
     * @brief Wskaźnik do obiektu Time reprezentującego czas pomiaru.
     */
    Time* _time;
    /**
     * @brief Wartość autokonsumpcji energii (w watach [W]).
     */
    double _autoConsumption;
    /**
     * @brief Wartość eksportu energii (w watach [W]).
     */
    double _export;
    /**
     * @brief Wartość importu energii (w watach [W]).
     */
    double _import;
    /**
     * @brief Wartość zużycia energii (poboru) (w watach [W]).
     */
    double _consumption;
    /**
     * @brief Wartość produkcji energii (w watach [W]).
     */
    double _generation;
};

#endif //DATA_HPP
