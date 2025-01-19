#ifndef DAY_H
#define DAY_H

#include "Quarter.h"
#include <ctime>

class Day {
public:
    Quarter quarters[4];

    void addDataPoint(DataPoint* point);
    int getQuarterIndex(const std::time_t& dateTime);
};

#endif // DAY_H
