#include <algorithm>
#include <iomanip>
#include <iostream>

#include "Headers/EnergyAnalyzer.hpp"

using namespace std;

int main() {
    locale::global(locale("pl_PL.UTF-8"));
    wcin.imbue(locale());
    wcout.imbue(locale());
    wcerr.imbue(locale());

    const auto* energyAnalyzer = new EnergyAnalyzer("../Chart Export.csv");

    delete energyAnalyzer;

    return 0;
}