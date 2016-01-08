/**************************************************************************************************
 * UnionFind class is an implementation of the Union-Find algorithms. Although UF algorithms can  *
 * be used to deal with graphs, its data structure is more general than graphs. UF data structure *
 * can be viewed as equivalence classes (here class is a mathematical concept). Two vertices in a *
 * graph which are disconnected can be in the same equivalence class (a.k.a component), while two *
 * directly connected vertices in a graph can be in disjoint equivalence classes. Whether or not  *
 * any two vertices are in the same component depends on the definition of the equivalence        *
 * relation.                                                                                      *
 *                                                                                                *
 * Notice: as what is described above, the component structure of a graph depends on definition   *
 *         of equivalence relation, not necessarily the connectedness between two vertices.       *
 *         However, in the UnionFind class here, we assume the equivalence relation for graphs    *
 *         (directed and undirected) is defined as path-connectedness relation. In other words,   *
 *         any two vertices v and w are in the same components, if and only if there is a path    *
 *         from v to w or from w to v.                                                            *
 **************************************************************************************************/

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_map>

#include "graph.h"
#include "dgraph.h"
#include "ugraph.h"

typedef enum graph_type {__DG, __UG} graph_t;   // for clients to choose the type of the
                            // underlying graph to deal with.
                            // __DG: directed graph; __UG: undirected graph
typedef enum method_style {__EAGER, __LAZY, __W_LAZY} m_style; // for clients
                            // to choose the styles of the Union-Find algorithm.
                            // __EAGER: eager approach (quick-find)
                            // __LAZY : lazy approach (quick-union)
                            // __W_LAZY : weighted lazy approach (weighted quick-union)
typedef std::unordered_map<int, std::set<int> > u_set_map; // container for the adjacent list
                            // representation from the Graph class and its two descendants
typedef std::unordered_map<int, int> u_int_map; // container for size of components

class UnionFind
{
public:
    UnionFind(int, m_style);    // Initialize the UnionFind algorithm by providing
                                // the number of vertices the underlying graph has
    UnionFind(const UGraph&, m_style); // Initialize the UnionFind algorithm by providing an
                                // undirected graph in graph (adjacency list) representation
    UnionFind(const DGraph&, m_style); // Initialize the Search algorithm by providing a directed
                                // graph in graph (adjacency list) representation
    virtual ~UnionFind();

    void _union(int p, int q);  // join the two components containing elements p and q
                                // respectively
    int  _find(int p) const;    // find representative element of the component containing
                                // element p

    int  _count() const;        // count the number of components, the underlying graph has
    bool _connected(int p, int q);  // return true if p and q are in the
                                // same component

    void _print() const;        // print out components one by one

private:
    // as the class UnionFind is a set of algorithms, copying algorithm objects does not make any
    // sense, so to disable copying UnionFind objects, both copy constructor and operator are made
    // private.
    UnionFind() {}
    UnionFind(const UnionFind&) {}
    UnionFind& operator=(const UnionFind&) {return *this;}

    void adj2uf(const u_set_map &adj_list, std::vector<int> &id); // convert adjacent list
                                // representation to UF representation.
                                // NOTICE: there is no uf2adj() function!! as in adj2uf(), path
                                // information is lost!!

    m_style          _ms;       // method style: lazy, eager, weighted-lazy approaches
                                // the value of this variable should not be changed, as soon as
                                // it is determined when initializing in constructor
    std::vector<int> id;        // access to component id (site indexed)
    int              count;     // number of components
    u_int_map        compo_size;// size of component, the size of this vector is the
                                // value of the variable count
    graph_t          gtype;     // type of the underlying graph
    u_set_map        adj_list;  // the adjacent list representation for the underlying graph
};

#endif // UNIONFIND_H
