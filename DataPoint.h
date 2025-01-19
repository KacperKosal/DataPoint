#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <string>
#include <ctime>

class DataPoint {
public:
    std::time_t dateTime;
    double autoConsumption;
    double exportPower;
    double importPower;
    double consumption;
    double production;

    DataPoint(const std::string& dateTimeStr, double autoConsumption, double exportPower,
        double importPower, double consumption, double production);

    static std::time_t parseDateTime(const std::string& dateTimeStr);
};

#endif // DATAPOINT_H
