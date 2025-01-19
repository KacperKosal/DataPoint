#ifndef MONTH_H
#define MONTH_H

#include "Day.h"
#include <map>

class Month {
public:
    std::map<int, Day> days;

    void addDataPoint(DataPoint* point);
};

#endif // MONTH_H