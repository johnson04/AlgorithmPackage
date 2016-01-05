#ifndef DGRAPH_H
#define DGRAPH_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * First edition was tested on Ubuntu 14.04, Dec. 5. 2015  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <set>
#include <string>
#include <unordered_map>

#include "graph.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * class DGraph is the API for an undirected graph         *
 * it is designed as an abstract data type, any algorithm  *
 * can use it in a way just like using any primitive data  *
 * type.                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class DGraph:public Graph
{
    friend class Search;
public:
    DGraph(int); // create a v_num-vertex digraph with no edges
    DGraph(const DGraph&); // copy constructor
    DGraph& operator=(DGraph&); // copy operator
    virtual ~DGraph(); // virtual destructor

    void addEdge(int, int);    // add edge v->w to this graph
    void removeEdge(int, int); // remove edge v->w from this graph
    void removeVertex(int);    // remove vertex _v from this graph

    void reverse(); // reverse of this digraph: all edges reverse their directions
};

#endif // DGRAPH_H
