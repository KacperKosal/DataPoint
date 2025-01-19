#include "Day.h"

void Day::addDataPoint(DataPoint* point) {
    int quarterIndex = getQuarterIndex(point->dateTime);
    quarters[quarterIndex].addDataPoint(point);
}

int Day::getQuarterIndex(const std::time_t& dateTime) {
    std::tm* tm = std::localtime(&dateTime);
    int hour = tm->tm_hour;

    if (hour < 6) return 0;
    if (hour < 12) return 1;
    if (hour < 18) return 2;
    return 3;
}