#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <filesystem>

#include "../Headers/EnergyData.hpp"

/**
 * @brief Konstruktor klasy EnergyData.
 *
 * @param dateTime Wskaźnik do obiektu DateTime reprezentującego datę i czas pomiaru.
 * @param autoConsumption Autokonsumpcja energii [kWh].
 * @param exportW Eksport energii [kWh].
 * @param import Import energii [kWh].
 * @param consumption Całkowite zużycie energii [kWh].
 * @param generation Produkcja energii [kWh].
 */
EnergyData::EnergyData(DateTime *dateTime, const double autoConsumption, const double exportW,
                       const double import, const double consumption, const double generation): _dateTime(dateTime),
    _autoConsumption(autoConsumption), _export(exportW), _import(import), _consumption(consumption),
    _generation(generation) {
}

/**
 * @brief Destruktor klasy EnergyData.
 *
 * Zwalnia pamięć zajmowaną przez obiekt DateTime.
 */
EnergyData::~EnergyData() {
    delete _dateTime;
}

/**
 * @brief Zwraca referencję do obiektu DateTime.
 *
 * @return Referencja do obiektu DateTime.
 */
DateTime &EnergyData::GetDateTime() const {
    return *_dateTime;
}

/**
 * @brief Zwraca wartość autokonsumpcji.
 *
 * @return Autokonsumpcja [kWh].
 */
double EnergyData::GetAutoConsumption() const {
    return _autoConsumption;
}

/**
 * @brief Zwraca wartość eksportu energii.
 *
 * @return Eksport energii [kWh].
 */
double EnergyData::GetExport() const {
    return _export;
}

/**
 * @brief Zwraca wartość importu energii.
 *
 * @return Import energii [kWh].
 */
double EnergyData::GetImport() const {
    return _import;
}

/**
 * @brief Zwraca wartość całkowitego zużycia energii.
 *
 * @return Całkowite zużycie energii [kWh].
 */
double EnergyData::GetConsumption() const {
    return _consumption;
}

/**
 * @brief Zwraca wartość produkcji energii.
 *
 * @return Produkcja energii [kWh].
 */
double EnergyData::GetGeneration() const {
    return _generation;
}

/**
 * @brief Wczytuje dane o zużyciu energii z pliku CSV.
 *
 * @param filepath Ścieżka do pliku CSV.
 * @return Wskaźnik do wektora obiektów EnergyData.
 * @throws runtime_error Jeśli nie udało się otworzyć pliku.
 */
vector<EnergyData *> *EnergyData::ReadEnergyData(const string &filepath) {
    auto *energyData = new vector<EnergyData *>();

    ifstream inputFile(filepath);

    string line;

    getline(inputFile, line); // Pomiń pierwszy wiersz (nagłówek)

    if (inputFile.is_open()) {
        auto timeStr = GetCurrentDateTimeFormatted();

        auto logFile = CreateFileInExecutionDir("log_" + timeStr + ".txt");
        auto errorFile = CreateFileInExecutionDir("log_error_" + timeStr + ".txt");

        while (getline(inputFile, line)) {
            stringstream ss(line);

            string dateTime, autoConsumption, exportW, import, consumption, generation;

            // Pobierz poszczególne wartości z linii, rozdzielone przecinkami.
            getline(ss, dateTime, ',');
            getline(ss, autoConsumption, ',');
            getline(ss, exportW, ',');
            getline(ss, import, ',');
            getline(ss, consumption, ',');
            getline(ss, generation, ',');

            stringstream dateTimeSS(dateTime);

            string day, month, year, hour, minute;

            // Rozdziel datę i godzinę na poszczególne składowe.
            getline(dateTimeSS, day, '.');
            getline(dateTimeSS, month, '.');
            getline(dateTimeSS, year, ' ');
            getline(dateTimeSS, hour, ':');
            getline(dateTimeSS, minute, ':');

            // Zamień kropki na przecinki w wartościach numerycznych.
            ranges::replace(autoConsumption, '.', ',');
            ranges::replace(exportW, '.', ',');
            ranges::replace(import, '.', ',');
            ranges::replace(consumption, '.', ',');
            ranges::replace(generation, '.', ',');

            // Usuń cudzysłowy z poszczególnych wartości.
            erase(dateTime, '\"');
            erase(autoConsumption, '\"');
            erase(exportW, '\"');
            erase(import, '\"');
            erase(consumption, '\"');
            erase(generation, '\"');

            erase(day, '\"');
            erase(month, '\"');
            erase(year, '\"');
            erase(hour, '\"');
            erase(minute, '\"');

            try {
                // Utwórz obiekt DateTime.
                auto *dateTimeObj = new DateTime(stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute));

                // Utwórz obiekt EnergyData i dodaj go do wektora.
                // ReSharper disable once CppDFAMemoryLeak - Uzasadnienie: Pamięć jest zwalniana w destruktorze klasy, która zarządza wektorem
                auto *ed = new EnergyData(dateTimeObj, stod(autoConsumption), stod(exportW), stod(import),
                                          stod(consumption), stod(generation));

                energyData->push_back(ed);

                logFile << "Parsed line: " << line << endl;
            } catch (exception &e) {
                logFile << "Error while parsing line: " << line << endl;
                errorFile << e.what() << ": " << line << endl;
            }

            logFile.flush();
            errorFile.flush();
        }

        inputFile.close();
        logFile.close();
        errorFile.close();

        return energyData;
    }

    throw runtime_error("Could not open file");
}

string EnergyData::GetCurrentDateTimeFormatted() {
    // Pobierz aktualny czas
    const auto now = chrono::system_clock::now();
    // Konwertuj na czas lokalny
    const time_t currentTime = chrono::system_clock::to_time_t(now);
    tm localTime{};
    localtime_s(&localTime, &currentTime);

    // Sformatuj czas do stringa w formacie YYYY-MM-DD_HH-MM-SS
    stringstream ss;
    ss << put_time(&localTime, "%Y-%m-%d_%H-%M-%S");
    return ss.str();
}

ofstream EnergyData::CreateFileInExecutionDir(const string &filename) {
    try {
        // Pobierz ścieżkę do katalogu wykonywalnego
        filesystem::path executionPath = filesystem::current_path(); // Uniwersalne w C++17+
        filesystem::path filePath = executionPath / filename;

        // Utwórz i otwórz plik
        ofstream file(filePath);
        if (!file.is_open()) {
            throw ios_base::failure("Failed to create or open the file: " + filePath.string());
        }

        return file;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        throw; // Ponownie wyrzuć wyjątek, aby kod wywołujący mógł go obsłużyć
    }
}
