#ifndef UGRAPH_H
#define UGRAPH_H

/* * * * * * * * * * * * * * * * * * * *
 * Tested on Ubuntu 14.04, Dec. 1. 2015
 * * * * * * * * * * * * * * * * * * * */

#include <set>
#include <string>
#include <unordered_map>

class UGraph // API for an undirected graph
{
public:
    UGraph(int); // create a V-vertex graph with no edges
    UGraph(UGraph&); // copy constructor
    UGraph& operator=(UGraph&); // copy operator
    virtual ~UGraph(); // virtual destructor

    int vectexNumber() const; // return the number of vertices
    int edgeNumber() const; // return the number of edges
    void addEdge(int, int); // add edge v-w to this graph
    std::set<int> adjacentTo(int); // return a set of vertices adjacent to v
    std::string toString(); // return a string representation of the graph

private:
    int v_num; // number of vertices
    int e_num; // number of edges
    std::unordered_map<int, std::set<int> > adj_list; // adjacency lists
};

#endif // UGRAPH_H
