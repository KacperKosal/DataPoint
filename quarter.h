#ifndef QUARTER_H
#define QUARTER_H

#include "DataPoint.h"
#include <vector>
#include <algorithm>

class Quarter 
{
public:
    std::vector<DataPoint> dataPoints;

    void addDataPoint(DataPoint point);

    void sortData();
};

#endif // QUARTER_H