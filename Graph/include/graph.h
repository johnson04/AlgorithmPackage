#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <string>
#include <unordered_map>

/* * *
 * Graph is an abstract class, which is used as an interface for all
 * graph related data structures and algorithms
 * * */
class Graph
{
public:
    Graph(int); // create a v_num-vertex digraph with no edges
    Graph(const Graph&); // copy constructor
    Graph& operator=(Graph&); // copy operator
    virtual ~Graph();

    virtual int vectexNumber() const; // return the number of vertices
    virtual int edgeNumber() const; // return the number of edges
    virtual std::set<int> adjacentTo(int); // return a set of vertices adjacent to v
    virtual std::string toString(); // return a string representation of the graph

    virtual void addEdge(int, int) = 0; // add edge v-w to this graph

protected:
    int v_num; // number of vertices
    int e_num; // number of edges
    std::unordered_map<int, std::set<int> > adj_list; // adjacency lists of
                      // the vertices connected to v by an edge exiting from v
};

#endif // GRAPH_H
