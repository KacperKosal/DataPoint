#include "Quarter.h"

void Quarter::addDataPoint(DataPoint* point) {
    dataPoints.push_back(point);
}

void Quarter::sortData() 
{
    std::sort(dataPoints.begin(), dataPoints.end(), [](DataPoint* a, DataPoint* b) {
        return a->dateTime < b->dateTime;
        });
}