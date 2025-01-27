#ifndef ENERGYDATA_HPP
#define ENERGYDATA_HPP

using namespace std;

#include <vector>
#include <string>

#include "DateTime.hpp"

/**
 * @brief Klasa reprezentująca pojedynczy rekord danych z pomiarów energii wczytany z pliku CSV.
 *
 * Przechowuje informacje o dacie i godzinie pomiaru oraz wartościach autokonsumpcji, eksportu,
 * importu, zużycia i produkcji energii.
 */
class EnergyData {
public:
    /**
     * @brief Konstruktor klasy EnergyData.
     *
     * Tworzy obiekt EnergyData z podanymi wartościami.
     *
     * @param dateTime Wskaźnik do obiektu DateTime reprezentującego datę i godzinę pomiaru.
     * @param autoConsumption Wartość autokonsumpcji energii (w watach [W]).
     * @param exportW Wartość eksportu energii (w watach [W]).
     * @param import Wartość importu energii (w watach [W]).
     * @param consumption Wartość zużycia energii (poboru) (w watach [W]).
     * @param generation Wartość produkcji energii (w watach [W]).
     */
    EnergyData(DateTime* dateTime, double autoConsumption, double exportW, double import, double consumption, double generation);

    /**
     * @brief Destruktor klasy EnergyData.
     *
     * Zwalnia pamięć zaalokowaną dla obiektu DateTime.
     */
    ~EnergyData();

    /**
     * @brief Zwraca referencję do obiektu DateTime reprezentującego datę i godzinę pomiaru.
     *
     * @return Referencja do obiektu DateTime.
     */
    [[nodiscard]] DateTime& GetDateTime() const;

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
     * @return Wartość zużycia energii (poboru) (w watach [W]).
     */
    [[nodiscard]] double GetConsumption() const;

    /**
     * @brief Zwraca wartość produkcji energii.
     *
     * @return Wartość produkcji energii (w watach [W]).
     */
    [[nodiscard]] double GetGeneration() const;

    /**
     * @brief Wczytuje dane z pliku CSV i zwraca wektor wskaźników do obiektów EnergyData.
     *
     * Pomija pierwszą linię pliku (nagłówek).
     *
     * @param filepath Ścieżka do pliku CSV.
     * @return Wektor wskaźników do obiektów EnergyData.
     * @throws runtime_error Jeśli nie można otworzyć pliku lub jeśli wystąpi błąd podczas parsowania danych.
     */
    static vector<EnergyData*>* ReadEnergyData(const string &filepath);

private:
    /**
     * @brief Wskaźnik do obiektu DateTime reprezentującego datę i godzinę pomiaru.
     */
    DateTime* _dateTime;
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

    /**
     * @brief Pobiera aktualną datę i godzinę i formatuje ją do stringa.
     *
     * @return String w formacie "YYYY-MM-DD_HH-MM-SS".
     */
    static string GetCurrentDateTimeFormatted();

    /**
     * @brief Tworzy lub otwiera plik w bieżącym katalogu roboczym programu.
     *
     * Funkcja pobiera ścieżkę do bieżącego katalogu roboczego, a następnie tworzy lub otwiera
     * plik o podanej nazwie w tym katalogu.
     *
     * @param filename Nazwa pliku do utworzenia lub otwarcia.
     * @return Obiekt `ofstream` reprezentujący otwarty plik. W przypadku błędu,
     *         właściwość `failbit` obiektu `ofstream` będzie ustawiona.
     */
    static ofstream CreateFileInExecutionDir(const string& filename);
};

#endif //ENERGYDATA_HPP
