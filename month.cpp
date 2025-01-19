#include "Month.h"

void Month::addDataPoint(DataPoint* point) {
    std::tm* tm = std::localtime(&point->dateTime);
    int day = tm->tm_mday;
    days[day].addDataPoint(point);
}