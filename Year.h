#ifndef YEAR_H
#define YEAR_H

#include "Month.h"
#include <map>

class Year {
public:
    std::map<int, Month> months;

    void addDataPoint(DataPoint* point);
};

#endif // YEAR_H
