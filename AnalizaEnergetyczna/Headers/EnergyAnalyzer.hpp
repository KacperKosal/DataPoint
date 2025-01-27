#ifndef ENERGYANALYZER_HPP
#define ENERGYANALYZER_HPP

#include <vector>
#include <string>

#include "Year.hpp"
#include "EnergyData.hpp"
#include "CommandParser.hpp"

class CommandParser;

using namespace std;

/**
 * @brief Klasa do analizy danych dotyczących zużycia i produkcji energii.
 *
 * Umożliwia wczytanie danych z pliku CSV, a następnie wykonywanie różnych obliczeń
 * i analiz na tych danych, takich jak obliczanie sumy, średniej, porównywanie
 * wartości w różnych przedziałach czasowych oraz wypisywanie danych w zadanym zakresie.
 */
class EnergyAnalyzer {
public:
    /**
     * @brief Konstruktor klasy EnergyAnalyzer.
     *
     * Wczytuje dane z pliku CSV o podanej ścieżce i tworzy strukturę danych
     * do ich przechowywania (lata, miesiące, dni, kwadranse, dane).
     *
     * @param filepath Ścieżka do pliku CSV z danymi.
     *
     * @throws std::runtime_error Jeśli nie można otworzyć pliku.
     */
    explicit EnergyAnalyzer(const string& filepath);

    /**
     * @brief Destruktor klasy EnergyAnalyzer.
     *
     * Zwalnia pamięć zaalokowaną dla struktury danych.
     */
    ~EnergyAnalyzer();

    /**
     * @brief Oblicza sumę autokonsumpcji w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Suma autokonsumpcji w przedziale [W].
     */
    long double CalculateAutoConsumptionSumInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza sumę eksportu energii w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Suma eksportu w przedziale [W].
     */
    long double CalculateEksportSumInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza sumę importu energii w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Suma importu w przedziale [W].
     */
    long double CalculateImportSumInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza sumę zużycia energii (poboru) w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Suma zużycia (poboru) w przedziale [W].
     */
    long double CalculateConsumptionSumInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza sumę produkcji energii w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Suma produkcji w przedziale [W].
     */
    long double CalculateGenerationSumInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza średnią autokonsumpcji w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Średnia autokonsumpcja w przedziale [W].
     */
    long double CalculateAutoConsumptionAvgInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza średni eksport energii w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Średni eksport w przedziale [W].
     */
    long double CalculateEksportAvgInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza średni import energii w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Średni import w przedziale [W].
     */
    long double CalculateImportAvgInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza średnie zużycie energii (pobór) w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Średnie zużycie (pobór) w przedziale [W].
     */
    long double CalculateConsumptionAvgInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Oblicza średnią produkcję energii w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     * @return Średnia produkcja w przedziale [W].
     */
    long double CalculateGenerationAvgInRange(const DateTime* start, const DateTime* end) const;

    /**
     * @brief Porównuje autokonsumpcję w dwóch zadanych przedziałach czasowych.
     *
     * Wypisuje na standardowe wyjście informację o tym, w którym przedziale
     * autokonsumpcja była większa i o ile.
     *
     * @param start_1 Wskaźnik do obiektu DateTime określającego początek pierwszego przedziału czasowego.
     * @param end_1 Wskaźnik do obiektu DateTime określającego koniec pierwszego przedziału czasowego.
     * @param start_2 Wskaźnik do obiektu DateTime określającego początek drugiego przedziału czasowego.
     * @param end_2 Wskaźnik do obiektu DateTime określającego koniec drugiego przedziału czasowego.
     */
    void CompareAutoConsumption(const DateTime* start_1, const DateTime* end_1, const DateTime* start_2, const DateTime* end_2) const;

    /**
     * @brief Porównuje eksport energii w dwóch zadanych przedziałach czasowych.
     *
     * Wypisuje na standardowe wyjście informację o tym, w którym przedziale
     * eksport był większy i o ile.
     *
     * @param start_1 Wskaźnik do obiektu DateTime określającego początek pierwszego przedziału czasowego.
     * @param end_1 Wskaźnik do obiektu DateTime określającego koniec pierwszego przedziału czasowego.
     * @param start_2 Wskaźnik do obiektu DateTime określającego początek drugiego przedziału czasowego.
     * @param end_2 Wskaźnik do obiektu DateTime określającego koniec drugiego przedziału czasowego.
     */
    void CompareEksport(const DateTime* start_1, const DateTime* end_1, const DateTime* start_2, const DateTime* end_2) const;

    /**
     * @brief Porównuje import energii w dwóch zadanych przedziałach czasowych.
     *
     * Wypisuje na standardowe wyjście informację o tym, w którym przedziale
     * import był większy i o ile.
     *
     * @param start_1 Wskaźnik do obiektu DateTime określającego początek pierwszego przedziału czasowego.
     * @param end_1 Wskaźnik do obiektu DateTime określającego koniec pierwszego przedziału czasowego.
     * @param start_2 Wskaźnik do obiektu DateTime określającego początek drugiego przedziału czasowego.
     * @param end_2 Wskaźnik do obiektu DateTime określającego koniec drugiego przedziału czasowego.
     */
    void CompareImport(const DateTime* start_1, const DateTime* end_1, const DateTime* start_2, const DateTime* end_2) const;

    /**
     * @brief Porównuje zużycie energii (pobór) w dwóch zadanych przedziałach czasowych.
     *
     * Wypisuje na standardowe wyjście informację o tym, w którym przedziale
     * zużycie (pobór) było większe i o ile.
     *
     * @param start_1 Wskaźnik do obiektu DateTime określającego początek pierwszego przedziału czasowego.
     * @param end_1 Wskaźnik do obiektu DateTime określającego koniec pierwszego przedziału czasowego.
     * @param start_2 Wskaźnik do obiektu DateTime określającego początek drugiego przedziału czasowego.
     * @param end_2 Wskaźnik do obiektu DateTime określającego koniec drugiego przedziału czasowego.
     */
    void CompareConsumption(const DateTime* start_1, const DateTime* end_1, const DateTime* start_2, const DateTime* end_2) const;

    /**
     * @brief Porównuje produkcję energii w dwóch zadanych przedziałach czasowych.
     *
     * Wypisuje na standardowe wyjście informację o tym, w którym przedziale
     * produkcja była większa i o ile.
     *
     * @param start_1 Wskaźnik do obiektu DateTime określającego początek pierwszego przedziału czasowego.
     * @param end_1 Wskaźnik do obiektu DateTime określającego koniec pierwszego przedziału czasowego.
     * @param start_2 Wskaźnik do obiektu DateTime określającego początek drugiego przedziału czasowego.
     * @param end_2 Wskaźnik do obiektu DateTime określającego koniec drugiego przedziału czasowego.
     */
    void CompareGeneration(const DateTime* start_1, const DateTime* end_1, const DateTime* start_2, const DateTime* end_2) const;

    /**
     * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość autokonsumpcji mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
     *
     * @param target Szukana wartość autokonsumpcji.
     * @param tolerance Zakres tolerancji wokół szukanej wartości.
     * @param start Data i godzina początku przedziału czasowego.
     * @param end Data i godzina końca przedziału czasowego.
     */
    void SearchByAutoConsumptionWithTolerance(long double target, long double tolerance, const DateTime *start, const DateTime *end) const;

    /**
     * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość eksportu mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
     *
     * @param target Szukana wartość eksportu.
     * @param tolerance Zakres tolerancji wokół szukanej wartości.
     * @param start Data i godzina początku przedziału czasowego.
     * @param end Data i godzina końca przedziału czasowego.
     */
    void SearchByExportWithTolerance(long double target, long double tolerance, const DateTime *start, const DateTime *end) const;

    /**
     * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość importu mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
     *
     * @param target Szukana wartość importu.
     * @param tolerance Zakres tolerancji wokół szukanej wartości.
     * @param start Data i godzina początku przedziału czasowego.
     * @param end Data i godzina końca przedziału czasowego.
     */
    void SearchByImportWithTolerance(long double target, long double tolerance, const DateTime *start, const DateTime *end) const;

    /**
     * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość zużycia (poboru) mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
     *
     * @param target Szukana wartość zużycia.
     * @param tolerance Zakres tolerancji wokół szukanej wartości.
     * @param start Data i godzina początku przedziału czasowego.
     * @param end Data i godzina końca przedziału czasowego.
     */
    void SearchByConsumptionWithTolerance(long double target, long double tolerance, const DateTime *start, const DateTime *end) const;

    /**
     * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość produkcji mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
     *
     * @param target Szukana wartość produkcji.
     * @param tolerance Zakres tolerancji wokół szukanej wartości.
     * @param start Data i godzina początku przedziału czasowego.
     * @param end Data i godzina końca przedziału czasowego.
     */
    void SearchByGenerationWithTolerance(long double target, long double tolerance, const DateTime *start, const DateTime *end) const;

    /**
     * @brief Wykonuje polecenie na danych energetycznych.
     *
     * Ta funkcja przyjmuje polecenie jako ciąg znaków i wykonuje odpowiednią
     * akcję na danych energetycznych. Konkretne polecenia i ich działania są
     * zdefiniowane w implementacji tej funkcji.
     *
     * @param command Polecenie do wykonania.
     */
    void ExecuteCommand(const string& command) const;

    /**
     * @brief Wypisuje wszystkie dane z zadanego przedziału czasowego.
     *
     * Funkcja iteruje przez strukturę danych (lata, miesiące, dni, kwadranse)
     * i wypisuje na standardowe wyjście wszystkie rekordy danych, które mieszczą się
     * w zadanym przedziale czasowym.
     *
     * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
     * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
     */
    void PrintAllDataInRange(const DateTime* start, const DateTime* end) const;

private:
    /**
     * @brief Wskaźnik do wektora przechowującego lata.
     *
     * Struktura danych przechowuje wskaźniki do obiektów Year, które z kolei
     * przechowują miesiące, dni, kwadranse i dane.
     */
    vector<Year*>* _years;

    /**
     * @brief Wskaźnik do obiektu CommandParser.
     *
     * Obiekt CommandParser jest używany do parsowania i wykonywania poleceń
     * na danych energetycznych.
     */
    CommandParser* _commandParser;

    /**
     * @brief Tworzy strukturę danych (lata, miesiące, dni, kwadranse, dane) na podstawie wektora obiektów EnergyData.
     *
     * @param energyData Wektor wskaźników do obiektów EnergyData.
     * @return Wskaźnik do wektora lat.
     */
    static vector<Year*>* createYears(const std::vector<EnergyData*>* energyData);
};

#endif //ENERGYANALYZER_HPP
