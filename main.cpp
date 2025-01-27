#include "Tree.h"
#include "DataPoint.h"
#include <fstream>
#include <sstream>
#include <iostream>

int main() {
    std::ifstream file("data.csv");
    std::string line;
    Tree dataTree;

    // Pomiñ nag³ówek
    std::getline(file, line);


    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string dateTime, autoConsumption, exportPower, importPower, consumption, production;

        std::getline(ss, dateTime, ',');
        std::getline(ss, autoConsumption, ',');
        std::getline(ss, exportPower, ',');
        std::getline(ss, importPower, ',');
        std::getline(ss, consumption, ',');
        std::getline(ss, production, ',');

        DataPoint* point = new DataPoint(dateTime, std::stod(autoConsumption), std::stod(exportPower),
            std::stod(importPower), std::stod(consumption), std::stod(production));
        dataTree.addDataPoint(point);
    }

    file.close();
    return 0;
}