#include "Year.h"


void Year::addDataPoint(DataPoint* point) {
    std::tm* tm = std::localtime(&point->dateTime);
    int month = tm->tm_mon + 1;
    months[month].addDataPoint(point);
}