#ifndef TREE_H
#define TREE_H

#include "Year.h"
#include <map>


class Tree {
public:
    std::map<int, Year> years;

    void addDataPoint(DataPoint* point);
};


#endif // TREE_H
