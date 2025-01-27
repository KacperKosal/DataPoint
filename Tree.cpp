#include "Tree.h"



void Tree::addDataPoint(DataPoint* point) {
    std::tm* tm = std::localtime(&point->dateTime);
    int year = tm->tm_year + 1900;
    years[year].addDataPoint(point);
}
