#include "../Headers/EnergyAnalyzer.hpp"

#include <iomanip>
#include <iostream>

/**
 * @brief Konstruktor klasy EnergyAnalyzer.
 * 
 * Wczytuje dane z pliku i tworzy strukturę danych (lata, miesiące, dni, kwadranse, dane).
 * 
 * @param filepath Ścieżka do pliku z danymi.
 */
EnergyAnalyzer::EnergyAnalyzer(const string &filepath) {
    const vector<EnergyData *> *energyData = EnergyData::ReadEnergyData(filepath);

    _commandParser = new CommandParser(*this);

    _years = createYears(energyData);
}

/**
 * @brief Destruktor klasy EnergyAnalyzer.
 *
 * Zwalnia pamięć zaalokowaną dla struktury danych.
 */
EnergyAnalyzer::~EnergyAnalyzer() {
    for (const Year *year: *_years) delete year;

    delete _years;
    delete _commandParser;
}

/**
 * @brief Oblicza sumę autokonsumpcji w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Suma autokonsumpcji w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateAutoConsumptionSumInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetAutoConsumption();
                    }
                }
            }
        }
    }

    return sum;
}

/**
 * @brief Oblicza sumę eksportu energii w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Suma eksportu w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateEksportSumInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetExport();
                    }
                }
            }
        }
    }

    return sum;
}

/**
 * @brief Oblicza sumę importu energii w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Suma importu w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateImportSumInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetImport();
                    }
                }
            }
        }
    }

    return sum;
}

/**
 * @brief Oblicza sumę zużycia energii w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Suma zużycia w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateConsumptionSumInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetConsumption();
                    }
                }
            }
        }
    }

    return sum;
}

/**
 * @brief Oblicza sumę produkcji energii w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Suma produkcji w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateGenerationSumInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetGeneration();
                    }
                }
            }
        }
    }

    return sum;
}

/**
 * @brief Oblicza średnią autokonsumpcji w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Średnia autokonsumpcja w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateAutoConsumptionAvgInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;
    int count = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetAutoConsumption();
                        ++count;
                    }
                }
            }
        }
    }

    return count == 0 ? 0 : sum / count;
}

/**
 * @brief Oblicza średni eksport energii w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Średni eksport w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateEksportAvgInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;
    int count = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetExport();
                        ++count;
                    }
                }
            }
        }
    }

    return count == 0 ? 0 : sum / count;
}

/**
 * @brief Oblicza średni import energii w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Średni import w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateImportAvgInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;
    int count = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetImport();
                        ++count;
                    }
                }
            }
        }
    }

    return count == 0 ? 0 : sum / count;
}

/**
 * @brief Oblicza średnie zużycie energii (pobór) w zadanym przedziale czasowym.
 *
 * Funkcja iteruje przez strukturę danych (lata, miesiące, dni, kwadranse)
 * i sumuje wartości zużycia energii (poboru) dla rekordów, które mieszczą się
 * w zadanym przedziale czasowym. Następnie dzieli sumę przez liczbę rekordów,
 * aby uzyskać średnie zużycie.
 *
 * @param start Wskaźnik do obiektu DateTime określającego początek przedziału czasowego.
 * @param end Wskaźnik do obiektu DateTime określającego koniec przedziału czasowego.
 * @return Średnie zużycie energii w zadanym przedziale czasowym lub 0, jeśli w przedziale
 *         nie znaleziono żadnych rekordów.
 */
long double EnergyAnalyzer::CalculateConsumptionAvgInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;
    int count = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetConsumption();
                        ++count;
                    }
                }
            }
        }
    }

    return count == 0 ? 0 : sum / count;
}

/**
 * @brief Oblicza średnią produkcję energii w zadanym przedziale czasowym.
 *
 * @param start Data i godzina początku przedziału.
 * @param end Data i godzina końca przedziału.
 * @return Średnia produkcja w przedziale [kWh].
 */
long double EnergyAnalyzer::CalculateGenerationAvgInRange(const DateTime *start, const DateTime *end) const {
    long double sum = 0;
    int count = 0;

    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        sum += data->GetGeneration();
                        ++count;
                    }
                }
            }
        }
    }

    return count == 0 ? 0 : sum / count;
}

/**
 * @brief Porównuje sumy autokonsumpcji dla dwóch przedziałów czasowych i wypisuje wynik na standardowe wyjście.
 *
 * @param start_1 Data i godzina początku pierwszego przedziału.
 * @param end_1 Data i godzina końca pierwszego przedziału.
 * @param start_2 Data i godzina początku drugiego przedziału.
 * @param end_2 Data i godzina końca drugiego przedziału.
 */
void EnergyAnalyzer::CompareAutoConsumption(const DateTime *start_1, const DateTime *end_1, const DateTime *start_2, const DateTime *end_2) const {
    const long double sum_1 = CalculateAutoConsumptionSumInRange(start_1, end_1);

    if (const long double sum_2 = CalculateAutoConsumptionSumInRange(start_2, end_2); sum_1 > sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_1->ToString() << " do " << end_1->ToString() << " ma większe zużycie energii o wartości " << sum_1 - sum_2 << " W" << endl;
    else if (sum_1 < sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_2->ToString() << " do " << end_2->ToString() << " ma większe zużycie energii o wartości " << sum_2 - sum_1 << " W" << endl;
    else
        cout << fixed << setprecision(4) << "Okresy mają takie same zużycie energii" << endl;
}

/**
 * @brief Porównuje sumy eksportu energii dla dwóch przedziałów czasowych i wypisuje wynik na standardowe wyjście.
 *
 * @param start_1 Data i godzina początku pierwszego przedziału.
 * @param end_1 Data i godzina końca pierwszego przedziału.
 * @param start_2 Data i godzina początku drugiego przedziału.
 * @param end_2 Data i godzina końca drugiego przedziału.
 */
void EnergyAnalyzer::CompareEksport(const DateTime *start_1, const DateTime *end_1, const DateTime *start_2, const DateTime *end_2) const {
    const long double sum_1 = CalculateEksportSumInRange(start_1, end_1);

    if (const long double sum_2 = CalculateEksportSumInRange(start_2, end_2); sum_1 > sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_1->ToString() << " do " << end_1->ToString() << " ma większe eksportowanie energii o wartości " << sum_1 - sum_2 << " W" << endl;
    else if (sum_1 < sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_2->ToString() << " do " << end_2->ToString() << " ma większe eksportowanie energii o wartości " << sum_2 - sum_1 << " W" << endl;
    else
        cout << fixed << setprecision(4) << "Okresy mają takie same eksportowanie energii" << endl;
}

/**
 * @brief Porównuje sumy importu energii dla dwóch przedziałów czasowych i wypisuje wynik na standardowe wyjście.
 *
 * @param start_1 Data i godzina początku pierwszego przedziału.
 * @param end_1 Data i godzina końca pierwszego przedziału.
 * @param start_2 Data i godzina początku drugiego przedziału.
 * @param end_2 Data i godzina końca drugiego przedziału.
 */
void EnergyAnalyzer::CompareImport(const DateTime *start_1, const DateTime *end_1, const DateTime *start_2, const DateTime *end_2) const {
    const long double sum_1 = CalculateImportSumInRange(start_1, end_1);

    if (const long double sum_2 = CalculateImportSumInRange(start_2, end_2); sum_1 > sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_1->ToString() << " do " << end_1->ToString() << " ma większe importowanie energii o wartości " << sum_1 - sum_2 << " W" << endl;
    else if (sum_1 < sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_2->ToString() << " do " << end_2->ToString() << " ma większe importowanie energii o wartości " << sum_2 - sum_1 << " W" << endl;
    else
        cout << fixed << setprecision(4) << "Okresy mają takie same importowanie energii" << endl;
}

/**
 * @brief Porównuje sumy zużycia energii dla dwóch przedziałów czasowych i wypisuje wynik na standardowe wyjście.
 *
 * @param start_1 Data i godzina początku pierwszego przedziału.
 * @param end_1 Data i godzina końca pierwszego przedziału.
 * @param start_2 Data i godzina początku drugiego przedziału.
 * @param end_2 Data i godzina końca drugiego przedziału.
 */
void EnergyAnalyzer::CompareConsumption(const DateTime *start_1, const DateTime *end_1, const DateTime *start_2, const DateTime *end_2) const {
    const long double sum_1 = CalculateConsumptionSumInRange(start_1, end_1);

    if (const long double sum_2 = CalculateConsumptionSumInRange(start_2, end_2); sum_1 > sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_1->ToString() << " do " << end_1->ToString() << " ma większe zużycie energii o wartości " << sum_1 - sum_2 << " W" << endl;
    else if (sum_1 < sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_2->ToString() << " do " << end_2->ToString() << " ma większe zużycie energii o wartości " << sum_2 - sum_1 << " W" << endl;
    else
        cout << fixed << setprecision(4) << "Okresy mają takie same zużycie energii" << endl;
}

/**
 * @brief Porównuje sumy produkcji energii dla dwóch przedziałów czasowych i wypisuje wynik na standardowe wyjście.
 *
 * @param start_1 Data i godzina początku pierwszego przedziału.
 * @param end_1 Data i godzina końca pierwszego przedziału.
 * @param start_2 Data i godzina początku drugiego przedziału.
 * @param end_2 Data i godzina końca drugiego przedziału.
 */
void EnergyAnalyzer::CompareGeneration(const DateTime *start_1, const DateTime *end_1, const DateTime *start_2, const DateTime *end_2) const {
    const long double sum_1 = CalculateGenerationSumInRange(start_1, end_1);

    if (const long double sum_2 = CalculateGenerationSumInRange(start_2, end_2); sum_1 > sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_1->ToString() << " do " << end_1->ToString() << " ma większe generowanie energii o wartości " << sum_1 - sum_2 << " W" << endl;
    else if (sum_1 < sum_2)
        cout << fixed << setprecision(4) << "Okres od " << start_2->ToString() << " do " << end_2->ToString() << " ma większe generowanie energii o wartości " << sum_2 - sum_1 << " W" << endl;
    else
        cout << fixed << setprecision(4) << "Okresy mają takie same generowanie energii" << endl;
}

/**
 * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość autokonsumpcji mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
 *
 * @param target Szukana wartość autokonsumpcji.
 * @param tolerance Zakres tolerancji wokół szukanej wartości.
 * @param start Data i godzina początku przedziału czasowego.
 * @param end Data i godzina końca przedziału czasowego.
 */
void EnergyAnalyzer::SearchByAutoConsumptionWithTolerance(const long double target, const long double tolerance, const DateTime *start, const DateTime *end) const {
    cout << fixed << setprecision(4) << "Szukam autokonsumpcji w zakresie " << target - tolerance << " - " << target + tolerance
         << " w przedziale czasowym od " << start->ToString() << " do " << end->ToString() << ":" << endl;

    for (const Year *year : *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month : year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day : month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() &&
                    day->GetDay() < start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() &&
                    day->GetDay() > end->GetDay())
                    continue;

                for (const Quarter *quarter : day->GetQuarters()) {
                    for (const auto &data : quarter->GetData()) {
                        // Sprawdź, czy rekord mieści się w przedziale czasowym
                        if (data->GetTime().GetHour() < start->GetHour() ||
                            (data->GetTime().GetHour() == start->GetHour() &&
                             data->GetTime().GetMinute() < start->GetMinute()))
                            continue;
                        if (data->GetTime().GetHour() > end->GetHour() ||
                            (data->GetTime().GetHour() == end->GetHour() &&
                             data->GetTime().GetMinute() > end->GetMinute()))
                            continue;

                        // Sprawdź, czy autokonsumpcja mieści się w zakresie z tolerancją
                        if (data->GetAutoConsumption() >= target - tolerance && data->GetAutoConsumption() <= target + tolerance) {
                            cout << fixed << setprecision(4) << "  - Znaleziono rekord: Data i godzina: "
                            << year->GetYear() << "-" << month->GetMonth() << "-" << day->GetDay() << " " << data->GetTime().GetHour() << ":" << data->GetTime().GetMinute()
                            << ", Autokonsumpcja: " << data->GetAutoConsumption() << endl;
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość eksportu mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
 *
 * @param target Szukana wartość eksportu.
 * @param tolerance Zakres tolerancji wokół szukanej wartości.
 * @param start Data i godzina początku przedziału czasowego.
 * @param end Data i godzina końca przedziału czasowego.
 */
void EnergyAnalyzer::SearchByExportWithTolerance(const long double target, const long double tolerance, const DateTime *start, const DateTime *end) const {
    cout << fixed << setprecision(4) << "Szukam eksportu w zakresie " << target - tolerance << " - " << target + tolerance
         << " w przedziale czasowym od " << start->ToString() << " do " << end->ToString() << ":" << endl;

    for (const Year *year : *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month : year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day : month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() &&
                    day->GetDay() < start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() &&
                    day->GetDay() > end->GetDay())
                    continue;

                for (const Quarter *quarter : day->GetQuarters()) {
                    for (const auto &data : quarter->GetData()) {
                        // Sprawdź, czy rekord mieści się w przedziale czasowym
                        if (data->GetTime().GetHour() < start->GetHour() ||
                            (data->GetTime().GetHour() == start->GetHour() &&
                             data->GetTime().GetMinute() < start->GetMinute()))
                            continue;
                        if (data->GetTime().GetHour() > end->GetHour() ||
                            (data->GetTime().GetHour() == end->GetHour() &&
                             data->GetTime().GetMinute() > end->GetMinute()))
                            continue;

                        // Sprawdź, czy eksport mieści się w zakresie z tolerancją
                        if (data->GetExport() >= target - tolerance && data->GetExport() <= target + tolerance) {
                            cout << fixed << setprecision(4) << "  - Znaleziono rekord: Data i godzina: "
                                << year->GetYear() << "-" << month->GetMonth() << "-" << day->GetDay() << " " << data->GetTime().GetHour() << ":" << data->GetTime().GetMinute()
                                << ", Eksport: " << data->GetExport() << endl;
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość importu mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
 *
 * @param target Szukana wartość importu.
 * @param tolerance Zakres tolerancji wokół szukanej wartości.
 * @param start Data i godzina początku przedziału czasowego.
 * @param end Data i godzina końca przedziału czasowego.
 */
void EnergyAnalyzer::SearchByImportWithTolerance(const long double target, const long double tolerance, const DateTime *start, const DateTime *end) const {
    cout << fixed << setprecision(4) << "Szukam importu w zakresie " << target - tolerance << " - " << target + tolerance
         << " w przedziale czasowym od " << start->ToString() << " do " << end->ToString() << ":" << endl;

    for (const Year *year : *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month : year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day : month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() &&
                    day->GetDay() < start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() &&
                    day->GetDay() > end->GetDay())
                    continue;

                for (const Quarter *quarter : day->GetQuarters()) {
                    for (const auto &data : quarter->GetData()) {
                        // Sprawdź, czy rekord mieści się w przedziale czasowym
                        if (data->GetTime().GetHour() < start->GetHour() ||
                            (data->GetTime().GetHour() == start->GetHour() &&
                             data->GetTime().GetMinute() < start->GetMinute()))
                            continue;
                        if (data->GetTime().GetHour() > end->GetHour() ||
                            (data->GetTime().GetHour() == end->GetHour() &&
                             data->GetTime().GetMinute() > end->GetMinute()))
                            continue;

                        // Sprawdź, czy import mieści się w zakresie z tolerancją
                        if (data->GetImport() >= target - tolerance && data->GetImport() <= target + tolerance) {
                            cout << fixed << setprecision(4) << "  - Znaleziono rekord: Data i godzina: "
                                 << year->GetYear() << "-" << month->GetMonth() << "-" << day->GetDay() << " " << data->GetTime().GetHour() << ":" << data->GetTime().GetMinute()
                                 << ", Import: " << data->GetImport() << endl;
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość zużycia (poboru) mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
 *
 * @param target Szukana wartość zużycia.
 * @param tolerance Zakres tolerancji wokół szukanej wartości.
 * @param start Data i godzina początku przedziału czasowego.
 * @param end Data i godzina końca przedziału czasowego.
 */
void EnergyAnalyzer::SearchByConsumptionWithTolerance(const long double target, const long double tolerance, const DateTime *start, const DateTime *end) const {
    cout << fixed << setprecision(4) << "Szukam zużycia w zakresie " << target - tolerance << " - " << target + tolerance
         << " w przedziale czasowym od " << start->ToString() << " do " << end->ToString() << ":" << endl;

    for (const Year *year : *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month : year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day : month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() &&
                    day->GetDay() < start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() &&
                    day->GetDay() > end->GetDay())
                    continue;

                for (const Quarter *quarter : day->GetQuarters()) {
                    for (const auto &data : quarter->GetData()) {
                        // Sprawdź, czy rekord mieści się w przedziale czasowym
                        if (data->GetTime().GetHour() < start->GetHour() ||
                            (data->GetTime().GetHour() == start->GetHour() &&
                             data->GetTime().GetMinute() < start->GetMinute()))
                            continue;
                        if (data->GetTime().GetHour() > end->GetHour() ||
                            (data->GetTime().GetHour() == end->GetHour() &&
                             data->GetTime().GetMinute() > end->GetMinute()))
                            continue;

                        // Sprawdź, czy zużycie mieści się w zakresie z tolerancją
                        if (data->GetConsumption() >= target - tolerance && data->GetConsumption() <= target + tolerance) {
                            cout << fixed << setprecision(4) << "  - Znaleziono rekord: Data i godzina: "
                                 << year->GetYear() << "-" << month->GetMonth() << "-" << day->GetDay() << " " << data->GetTime().GetHour() << ":" << data->GetTime().GetMinute()
                                 << ", Zużycie: " << data->GetConsumption() << endl;
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Wyszukuje i wypisuje na ekran rekordy, w których wartość produkcji mieści się w zadanym zakresie z tolerancją, w określonym przedziale czasowym.
 *
 * @param target Szukana wartość produkcji.
 * @param tolerance Zakres tolerancji wokół szukanej wartości.
 * @param start Data i godzina początku przedziału czasowego.
 * @param end Data i godzina końca przedziału czasowego.
 */
void EnergyAnalyzer::SearchByGenerationWithTolerance(const long double target, const long double tolerance, const DateTime *start, const DateTime *end) const {
    cout << fixed << setprecision(4) << "Szukam produkcji w zakresie " << target - tolerance << " - " << target + tolerance
         << " w przedziale czasowym od " << start->ToString() << " do " << end->ToString() << ":" << endl;

    for (const Year *year : *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month : year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day : month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() &&
                    day->GetDay() < start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() &&
                    day->GetDay() > end->GetDay())
                    continue;

                for (const Quarter *quarter : day->GetQuarters()) {
                    for (const auto &data : quarter->GetData()) {
                        // Sprawdź, czy rekord mieści się w przedziale czasowym
                        if (data->GetTime().GetHour() < start->GetHour() ||
                            (data->GetTime().GetHour() == start->GetHour() &&
                             data->GetTime().GetMinute() < start->GetMinute()))
                            continue;
                        if (data->GetTime().GetHour() > end->GetHour() ||
                            (data->GetTime().GetHour() == end->GetHour() &&
                             data->GetTime().GetMinute() > end->GetMinute()))
                            continue;

                        // Sprawdź, czy produkcja mieści się w zakresie z tolerancją
                        if (data->GetGeneration() >= target - tolerance && data->GetGeneration() <= target + tolerance) {
                            cout << fixed << setprecision(4) << "  - Znaleziono rekord: Data i godzina: "
                                 << year->GetYear() << "-" << month->GetMonth() << "-" << day->GetDay() << " " << data->GetTime().GetHour() << ":" << data->GetTime().GetMinute()
                                 << ", Produkcja: " << data->GetGeneration() << endl;
                        }
                    }
                }
            }
        }
    }
}

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
void EnergyAnalyzer::PrintAllDataInRange(const DateTime *start, const DateTime *end) const {
    for (const Year *year: *_years) {
        if (year->GetYear() < start->GetYear() || year->GetYear() > end->GetYear()) continue;

        for (const Month *month: year->GetMonths()) {
            if (year->GetYear() == start->GetYear() && month->GetMonth() < start->GetMonth()) continue;
            if (year->GetYear() == end->GetYear() && month->GetMonth() > end->GetMonth()) continue;

            for (const Day *day: month->GetDays()) {
                if (year->GetYear() == start->GetYear() && month->GetMonth() == start->GetMonth() && day->GetDay() <
                    start->GetDay())
                    continue;
                if (year->GetYear() == end->GetYear() && month->GetMonth() == end->GetMonth() && day->GetDay() > end->
                    GetDay())
                    continue;

                for (const Quarter *quoter: day->GetQuarters()) {
                    for (const auto &data: quoter->GetData()) {
                        if (data->GetTime().GetHour() < start->GetHour() || data->GetTime().GetHour() > end->GetHour())
                            continue;
                        if (data->GetTime().GetMinute() < start->GetMinute() || data->GetTime().GetMinute() > end->
                            GetMinute())
                            continue;

                        cout << year->GetYear() << "-" << month->GetMonth() << "-" << day->GetDay() << " ";
                        cout << data->GetTime().GetHour() << ":" << data->GetTime().GetMinute() << "";
                        cout << ", Autokonsumpcja: " << fixed << setprecision(4) << data->GetAutoConsumption() << "";
                        cout << ", Export: " << fixed << setprecision(4) << data->GetExport();
                        cout << ", Import: " << fixed << setprecision(4) << data->GetImport() << "";
                        cout << ", Pobór: " << fixed << setprecision(4) << data->GetConsumption() << "";
                        cout << ", Produkcja: " << fixed << setprecision(4) << data->GetGeneration() << endl;
                    }
                }
            }
        }
    }
}

/**
    * @brief Wykonuje polecenie na danych energetycznych.
    *
    * Ta funkcja przyjmuje polecenie jako ciąg znaków i wykonuje odpowiednią
    * akcję na danych energetycznych. Konkretne polecenia i ich działania są
    * zdefiniowane w implementacji tej funkcji.
    *
    * @param command Polecenie do wykonania.
*/
void EnergyAnalyzer::ExecuteCommand(const string &command) const {
    _commandParser->ParseAndExecute(command);
}


/**
 * @brief Tworzy strukturę danych (lata, miesiące, dni, kwadranse, dane) na podstawie wektora obiektów EnergyData.
 *
 * @param energyData Wektor wskaźników do obiektów EnergyData.
 * @return Wskaźnik do wektora lat.
 */
vector<Year *> *EnergyAnalyzer::createYears(const vector<EnergyData *> *energyData) {
    auto *years = new vector<Year *>;

    for (const EnergyData *data: *energyData) {
        Year *year = nullptr;

        for (Year *y: *years) {
            if (y->GetYear() == data->GetDateTime().GetYear()) {
                year = y;
                break;
            }
        }

        if (year == nullptr) {
            year = new Year(data->GetDateTime().GetYear());
            years->push_back(year);
        }

        Month *month = nullptr;
        for (Month *m: year->GetMonths()) {
            if (m->GetMonth() == data->GetDateTime().GetMonth()) {
                month = m;
                break;
            }
        }

        if (month == nullptr) {
            month = new Month(data->GetDateTime().GetMonth());
            year->GetMonths().push_back(month);
        }

        Day *day = nullptr;
        for (Day *d: month->GetDays()) {
            if (d->GetDay() == data->GetDateTime().GetDay()) {
                day = d;
                break;
            }
        }

        if (day == nullptr) {
            day = new Day(data->GetDateTime().GetDay());
            month->GetDays().push_back(day);
        }

        for (auto quoters = day->GetQuarters(); const auto quoter: quoters) {
            auto *time = new Time(data->GetDateTime().GetHour(), data->GetDateTime().GetMinute());
            auto *newData = new Data(time, data->GetAutoConsumption(), data->GetExport(), data->GetImport(),
                                     data->GetConsumption(), data->GetGeneration());

            if (quoter->AddData(*time, *newData)) break;

            delete newData;
        }
    }

    delete energyData;

    return years;
}