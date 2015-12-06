#ifndef UGRAPH_H
#define UGRAPH_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * First edition was tested on Ubuntu 14.04, Dec. 1. 2015  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <set>
#include <string>
#include <unordered_map>

#include "graph.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * class UGraph is the API for an undirected graph         *
 * it is designed as an abstract data type, any algorithm  *
 * can use it in a way just like using any primitive data  *
 * type.                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
class UGraph:public Graph
{
public:
    UGraph(int); // create a V-vertex graph with no edges
    UGraph(UGraph&); // copy constructor
    UGraph& operator=(UGraph&); // copy operator
    virtual ~UGraph(); // virtual destructor

    void addEdge(int, int); // add edge v-w to this graph
};

#endif // UGRAPH_H
