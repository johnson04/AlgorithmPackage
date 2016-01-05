#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <string>
#include <map>
#include <unordered_map>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * To make our graph data structure as flexible as possible, we isolate  *
 * the graph representation from all the algorithm implementations.      *
 *                                                                       *
 * Graph is an abstract class, which is used as an framework for both    *
 * directed and undirected graphs.                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Graph
{
    friend class Search;
public:
    Graph(int); // create a v_num-vertex digraph with no edges
    Graph(const Graph&); // copy constructor
    Graph& operator=(Graph&); // copy operator
    virtual ~Graph();

    int  vectexNumber() const; // determine the number of vertices
    int  edgeNumber() const;   // determine the number of edges
    bool inGraph(int) const;   // determine if a provided vertex is in the graph or not

    virtual std::set<int> adjacentTo(int); // return a set of vertices adjacent to v
    virtual std::string toString(); // return a string representation of the graph
    virtual void addVertex(int); // add a vertex into this graph

    virtual void addEdge(int, int) = 0;    // add edge v-w to this graph
    virtual void removeEdge(int, int) = 0; // remove edge v-w from this graph
    virtual void removeVertex(int) = 0;    // remove a vertex v from the graph
                                           // as a result, all edges connecting
                                           // the vertex v are removed too

    int getVNum() const;        // return number of vertices
    int getENum() const;        // return number of edges
    std::unordered_map<int, std::set<int> > getGRep() const; // return adj_list

protected:
    int v_num; // number of vertices
    int e_num; // number of edges

    std::unordered_map<int, std::set<int> > adj_list; // adjacency lists of
                      // the vertices connected to v by an edge exiting from v
    std::map<int, std::string> alias; // as when the graph is created in the constructor,
                                 // the vertices are assigned as consecutive natural
                                 // numbers. In general, vertices may be nominated with
                                 // different symbols. The default symbols are the
                                 // natural numbers assigned to vertices. The client
                                 // may change them into anything they want.
};

#endif // GRAPH_H
