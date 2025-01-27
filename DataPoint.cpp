#include "DataPoint.h"
#include <sstream>
#include <iomanip>

DataPoint::DataPoint(const std::string& dateTimeStr, double autoConsumption, double exportPower,
    double importPower, double consumption, double production)
    : autoConsumption(autoConsumption), exportPower(exportPower),
    importPower(importPower), consumption(consumption), production(production) 
{
    dateTime = parseDateTime(dateTimeStr);
}

std::time_t DataPoint::parseDateTime(const std::string& dateTimeStr) {

    std::tm tm = {};
    std::istringstream ss(dateTimeStr);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return std::mktime(&tm);
}
