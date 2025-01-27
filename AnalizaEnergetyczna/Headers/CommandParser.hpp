#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include <string>
#include <vector>

#include "EnergyAnalyzer.hpp"

class EnergyAnalyzer;

/**
 * @brief Klasa odpowiedzialna za parsowanie i wykonywanie komend.
 *
 * Przyjmuje komendy w formie stringów, dzieli je na tokeny, a następnie interpretuje
 * i wywołuje odpowiednie metody klasy `EnergyAnalyzer` do przeprowadzenia obliczeń
 * i operacji na danych.
 */
class CommandParser {
public:
    /**
     * @brief Konstruktor klasy CommandParser.
     *
     * @param analyzer Referencja do obiektu `EnergyAnalyzer`, na którym będą wykonywane operacje.
     */
    explicit CommandParser(EnergyAnalyzer &analyzer);

    /**
     * @brief Destruktor klasy CommandParser.
     *
     * Domyślny destruktor.
     */
    ~CommandParser() = default;

    /**
     * @brief Parsuje i wykonuje komendę.
     *
     * Dzieli komendę na tokeny, a następnie wywołuje odpowiednią metodę `Execute...`
     * na podstawie pierwszego tokenu (typu komendy).
     *
     * @param command Komenda do sparsowania i wykonania.
     */
    void ParseAndExecute(const string &command);

private:
    /**
     * @brief Referencja do obiektu `EnergyAnalyzer`, na którym będą wykonywane operacje.
     */
    EnergyAnalyzer &_analyzer;

    /**
     * @brief Dzieli łańcuch znaków na tokeny na podstawie podanego separatora.
     *
     * @param command Łańcuch znaków do podziału.
     * @param delimiter Separator tokenów (domyślnie spacja).
     * @return Wektor tokenów (stringów).
     */
    [[nodiscard]] static vector<string> Tokenize(const string &command, char delimiter = ' ');

    /**
     * @brief Parsuje datę i godzinę z wektora tokenów.
     *
     * Oczekuje, że data i godzina będą w formacie `DD.MM.RRRR GG:MM`.
     * Parsuje datę i godzinę od podanego indeksu, inkrementując go o 2
     *
     * @param tokens Wektor tokenów, z którego ma być sparsowana data i godzina.
     * @param index Indeks w wektorze `tokens`, od którego należy rozpocząć parsowanie.
     * @return Wskaźnik do obiektu `DateTime` reprezentującego sparsowaną datę i godzinę lub `nullptr`, jeśli parsowanie się nie powiodło.
     */
    static DateTime *ParseDateTime(const vector<string> &tokens, size_t &index);

    /**
     * @brief Wykonuje komendę `SUMA`.
     *
     * Parsuje argumenty komendy i wywołuje odpowiednie metody `EnergyAnalyzer`
     * w celu obliczenia sumy dla zadanego typu danych i przedziału czasowego.
     *
     * @param tokens Wektor tokenów reprezentujących komendę.
     */
    void ExecuteSum(const vector<string> &tokens) const;

    /**
     * @brief Wykonuje komendę `SREDNIA`.
     *
     * Parsuje argumenty komendy i wywołuje odpowiednie metody `EnergyAnalyzer`
     * w celu obliczenia średniej dla zadanego typu danych i przedziału czasowego.
     *
     * @param tokens Wektor tokenów reprezentujących komendę.
     */
    void ExecuteAverage(const vector<string> &tokens) const;

    /**
     * @brief Wykonuje komendę `POROWNAJ`.
     *
     * Parsuje argumenty komendy i wywołuje odpowiednie metody `EnergyAnalyzer`
     * w celu porównania wartości dla zadanego typu danych i dwóch przedziałów czasowych.
     *
     * @param tokens Wektor tokenów reprezentujących komendę.
     */
    void ExecuteCompare(const vector<string> &tokens) const;

    /**
     * @brief Wykonuje komendę `ZNAJDZ`.
     *
     * Parsuje argumenty komendy i wywołuje odpowiednie metody `EnergyAnalyzer`
     * w celu wyszukania rekordów spełniających określone kryteria.
     *
     * @param tokens Wektor tokenów reprezentujących komendę.
     */
    void ExecuteSearch(const vector<string> &tokens) const;

    /**
     * @brief Wykonuje komendę `WYPISZ`.
     *
     * Parsuje argumenty komendy i wywołuje odpowiednie metody `EnergyAnalyzer`
     * w celu wypisania danych dla zadanego przedziału czasowego.
     *
     * @param tokens Wektor tokenów reprezentujących komendę.
     */
    void ExecutePrint(const vector<string> &tokens) const;
};

#endif //COMMANDPARSER_HPP
