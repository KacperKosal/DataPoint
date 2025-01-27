#include "../Headers/CommandParser.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>

CommandParser::CommandParser(EnergyAnalyzer &analyzer) : _analyzer(analyzer) {}

void CommandParser::ParseAndExecute(const string &command) {
    const vector<string> tokens = Tokenize(command);

    if (tokens.empty()) {
        cerr << "Pusta komenda." << endl;
        return;
    }

    if (const string& commandType = tokens[0]; commandType == "SUMA") {
        ExecuteSum(tokens);
    } else if (commandType == "SREDNIA") {
        ExecuteAverage(tokens);
    } else if (commandType == "POROWNAJ") {
        ExecuteCompare(tokens);
    } else if (commandType == "ZNAJDZ") {
        ExecuteSearch(tokens);
    } else if (commandType == "WYPISZ") {
        ExecutePrint(tokens);
    } else if (commandType == "KONIEC") {
        exit(0);
    }
    else {
        cerr << "Nieznana komenda: " << commandType << endl;
    }
}

vector<string> CommandParser::Tokenize(const string &command, const char delimiter) {
    vector<string> tokens;
    stringstream ss(command);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

DateTime *CommandParser::ParseDateTime(const vector<string> &tokens, size_t &index) {
    // Nowy format daty: DD.MM.RRRR GG:MM
    if (index >= tokens.size()) {
        cerr << "Błąd: Brak daty i godziny." << endl;
        return nullptr;
    }
    const vector<string> dateTokens = Tokenize(tokens[index++], '.');
    const vector<string> timeTokens = Tokenize(tokens[index++], ':');

    if (dateTokens.size() != 3 || timeTokens.size() != 2) {
        cerr << "Błąd: Nieprawidłowy format daty i godziny." << endl;
        return nullptr;
    }

    try {
        const int day = stoi(dateTokens[0]);
        const int month = stoi(dateTokens[1]);
        const int year = stoi(dateTokens[2]);
        const int hour = stoi(timeTokens[0]);
        const int minute = stoi(timeTokens[1]);
        // ReSharper disable once CppDFAMemoryLeak
        return new DateTime(day, month, year, hour, minute);
    } catch (const exception &e) {
        cerr << "Błąd: Nieprawidłowy format daty i godziny: " << e.what() << endl;
        return nullptr;
    }
}

void CommandParser::ExecuteSum(const vector<string> &tokens) const {
    if (tokens.size() < 6) {
        cerr << "Błąd: Nieprawidłowa liczba argumentów dla komendy SUMA." << endl;
        return;
    }

    const string& type = tokens[1];
    size_t index = 2;

    if (tokens[index++] != "OD") {
        cerr << "Błąd: Brak słowa kluczowego OD" << endl;
        return;
    }

    const DateTime *start = ParseDateTime(tokens, index);

    if (tokens[index++] != "DO") {
        cerr << "Błąd: Brak słowa kluczowego DO" << endl;
        delete start;
        return;
    }

    const DateTime *end = ParseDateTime(tokens, index);

    if (start == nullptr || end == nullptr) {
        delete start;
        delete end;
        return;
    }

    cout << "Wywołano komendę SUMA dla " << type << " w przedziale od " << start->ToString() << " do " << end->ToString() << endl;

    if (type == "AUTOKONSUMPCJA") {
        cout << fixed << setprecision(4) << "Suma autokonsumpcji: " << _analyzer.CalculateAutoConsumptionSumInRange(start, end) << " W" << endl;
    } else if (type == "EKSPORT") {
        cout << fixed << setprecision(4) << "Suma eksportu: " << _analyzer.CalculateEksportSumInRange(start, end) << " W" << endl;
    } else if (type == "IMPORT") {
        cout << fixed << setprecision(4) << "Suma importu: " << _analyzer.CalculateImportSumInRange(start, end) << " W" << endl;
    } else if (type == "POBOR") {
        cout << fixed << setprecision(4) << "Suma poboru: " << _analyzer.CalculateConsumptionSumInRange(start, end) << " W" << endl;
    } else if (type == "PRODUKCJA") {
        cout << fixed << setprecision(4) << "Suma produkcji: " << _analyzer.CalculateGenerationSumInRange(start, end) << " W" << endl;
    } else {
        cerr << "Błąd: Nieznany typ dla komendy SUMA: " << type << endl;
    }

    delete start;
    delete end;
}

void CommandParser::ExecuteAverage(const vector<string> &tokens) const {
    if (tokens.size() < 6) {
        cerr << "Błąd: Nieprawidłowa liczba argumentów dla komendy SREDNIA." << endl;
        return;
    }

    const string& type = tokens[1];
    size_t index = 2;

    if (tokens[index++] != "OD") {
        cerr << "Błąd: Brak słowa kluczowego OD" << endl;
        return;
    }

    const DateTime *start = ParseDateTime(tokens, index);

    if (tokens[index++] != "DO") {
        cerr << "Błąd: Brak słowa kluczowego DO" << endl;
        delete start;
        return;
    }

    const DateTime *end = ParseDateTime(tokens, index);

    if (start == nullptr || end == nullptr) {
        delete start;
        delete end;
        return;
    }
    cout << "Wywołano komendę SREDNIA dla " << type << " w przedziale od " << start->ToString() << " do " << end->ToString() << endl;

    if (type == "AUTOKONSUMPCJA") {
        cout << fixed << setprecision(4) << "Średnia autokonsumpcja: " << _analyzer.CalculateAutoConsumptionAvgInRange(start, end) << " W" << endl;
    } else if (type == "EKSPORT") {
        cout << fixed << setprecision(4) << "Średnia eksportu: " << _analyzer.CalculateEksportAvgInRange(start, end) << " W" << endl;
    } else if (type == "IMPORT") {
        cout << fixed << setprecision(4) << "Średnia importu: " << _analyzer.CalculateImportAvgInRange(start, end) << " W" << endl;
    } else if (type == "POBOR") {
        cout << fixed << setprecision(4) << "Średnia poboru: " << _analyzer.CalculateConsumptionAvgInRange(start, end) << " W" << endl;
    } else if (type == "PRODUKCJA") {
        cout << fixed << setprecision(4) << "Średnia produkcji: " << _analyzer.CalculateGenerationAvgInRange(start, end) << " W" << endl;
    } else {
        cerr << "Błąd: Nieznany typ dla komendy SREDNIA: " << type << endl;
    }

    delete start;
    delete end;
}

void CommandParser::ExecuteCompare(const vector<string> &tokens) const {
    if (tokens.size() < 11) {
        cerr << "Błąd: Nieprawidłowa liczba argumentów dla komendy POROWNAJ." << endl;
        return;
    }

    const string& type = tokens[1];
    size_t index = 2;

    if (tokens[index++] != "OD") {
        cerr << "Błąd: Brak słowa kluczowego OD" << endl;
        return;
    }

    const DateTime *start1 = ParseDateTime(tokens, index);

    if (tokens[index++] != "DO") {
        cerr << "Błąd: Brak słowa kluczowego DO" << endl;
        delete start1;
        return;
    }

    const DateTime *end1 = ParseDateTime(tokens, index);

    if (tokens[index++] != "Z") {
        cerr << "Błąd: Brak słowa kluczowego Z" << endl;
        delete start1;
        delete end1;
        return;
    }

    if (tokens[index++] != "OD") {
        cerr << "Błąd: Brak słowa kluczowego OD" << endl;
        delete start1;
        delete end1;
        return;
    }

    const DateTime *start2 = ParseDateTime(tokens, index);

    if (tokens[index++] != "DO") {
        cerr << "Błąd: Brak słowa kluczowego DO" << endl;
        delete start1;
        delete end1;
        delete start2;
        return;
    }

    const DateTime *end2 = ParseDateTime(tokens, index);

    if (start1 == nullptr || end1 == nullptr || start2 == nullptr || end2 == nullptr) {
        delete start1;
        delete end1;
        delete start2;
        delete end2;
        return;
    }

    cout << "Wywołano komendę POROWNAJ dla " << type << " w przedziałach od " << start1->ToString() << " do " << end1->ToString() << " oraz od " << start2->ToString() << " do " << end2->ToString() << endl;

    if (type == "AUTOKONSUMPCJA") {
        _analyzer.CompareAutoConsumption(start1, end1, start2, end2);
    } else if (type == "EKSPORT") {
        _analyzer.CompareEksport(start1, end1, start2, end2);
    } else if (type == "IMPORT") {
        _analyzer.CompareImport(start1, end1, start2, end2);
    } else if (type == "POBOR") {
        _analyzer.CompareConsumption(start1, end1, start2, end2);
    } else if (type == "PRODUKCJA") {
        _analyzer.CompareGeneration(start1, end1, start2, end2);
    } else {
        cerr << "Błąd: Nieznany typ dla komendy POROWNAJ: " << type << endl;
    }

    delete start1;
    delete end1;
    delete start2;
    delete end2;
}

void CommandParser::ExecuteSearch(const vector<string> &tokens) const {
    if (tokens.size() < 10) {
        cerr << "Błąd: Nieprawidłowa liczba argumentów dla komendy ZNAJDZ." << endl;
        return;
    }

    const string& type = tokens[1];
    size_t index = 2;

    if (tokens[index++] != "WARTOSC") {
        cerr << "Błąd: Brak słowa kluczowego WARTOSC" << endl;
        return;
    }

    long double target;
    try {
        target = stold(tokens[index++]);
    } catch (const exception &e) {
        cerr << "Błąd: Nieprawidłowy format liczby (wartość): " << e.what() << endl;
        return;
    }

    if (tokens[index++] != "TOLERANCJA") {
        cerr << "Błąd: Brak słowa kluczowego TOLERANCJA" << endl;
        return;
    }

     long double tolerance;
    try {
        tolerance = stold(tokens[index++]);
    } catch (const exception &e) {
        cerr << "Błąd: Nieprawidłowy format liczby (tolerancja): " << e.what() << endl;
        return;
    }

    if (tokens[index++] != "OD") {
        cerr << "Błąd: Brak słowa kluczowego OD" << endl;
        return;
    }

    // ReSharper disable once CppDFAMemoryLeak
    DateTime *start = ParseDateTime(tokens, index);

    if (tokens[index++] != "DO") {
        cerr << "Błąd: Brak słowa kluczowego DO" << endl;
        delete start;
        return;
    }

    // ReSharper disable once CppDFAMemoryLeak
    const DateTime *end = ParseDateTime(tokens, index);

    if (start == nullptr || end == nullptr) {
        delete start;
        delete end;
        return;
    }

    cout << "Wywołano komendę ZNAJDZ dla " << type << " o wartości " << target << " z tolerancją " << tolerance
              << " w przedziale od " << start->ToString() << " do " << end->ToString() << endl;

    if (type == "AUTOKONSUMPCJA")
        _analyzer.SearchByAutoConsumptionWithTolerance(target, tolerance, start, end);
    else if (type == "EXPORT") {
        _analyzer.SearchByExportWithTolerance(target, tolerance, start, end);
    } else if (type == "IMPORT") {
        _analyzer.SearchByImportWithTolerance(target, tolerance, start, end);
    } else if (type == "POBOR") {
        _analyzer.SearchByConsumptionWithTolerance(target, tolerance, start, end);
    } else if (type == "PRODUKCJA") {
        _analyzer.SearchByGenerationWithTolerance(target, tolerance, start, end);
    } else {
        cerr << "Błąd: Nieznany typ dla komendy ZNAJDZ: " << type << endl;
    }

    delete start;
    delete end;
}

void CommandParser::ExecutePrint(const vector<string> &tokens) const {
    if (tokens.size() < 5) {
        cerr << "Błąd: Nieprawidłowa liczba argumentów dla komendy WYPISZ." << endl;
        return;
    }

    size_t index = 1;

    if (tokens[index++] != "OD") {
        cerr << "Błąd: Brak słowa kluczowego OD" << endl;
        return;
    }

    const DateTime *start = ParseDateTime(tokens, index);

    if (tokens[index++] != "DO") {
        cerr << "Błąd: Brak słowa kluczowego DO" << endl;
        delete start;
        return;
    }

    const DateTime *end = ParseDateTime(tokens, index);

    if (start == nullptr || end == nullptr) {
        delete start;
        delete end;
        return;
    }

    cout << "Wywołano komendę WYPISZ w przedziale od " << start->ToString() << " do " << end->ToString() << endl;

    _analyzer.PrintAllDataInRange(start, end);

    delete start;
    delete end;
}
