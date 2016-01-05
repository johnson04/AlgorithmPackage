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

#include <vector>
#include <set>
#include <unordered_map>

#include "graph.h"
#include "dgraph.h"
#include "ugraph.h"

class UnionFind
{
    typedef enum graph_type {__DG, __UG} graph_t;   // for clients to choose the type of the
                                // underlying graph to deal with.
                                // __DG: directed graph; __UG: undirected graph
    typedef enum method_style {__EAGER, __LAZY, __W_EAGER, __W_LAZY} m_style; // for clients
                                // to choose the styles of the Union-Find algorithm.
                                // __EAGER: eager approach (quick-find)
                                // __LAZY : lazy approach (quick-union)
                                // __W_EAGER: weighted eager approach (weighted quick-find)
                                // __W_LAZY : weighted lazy approach (weighted quick-union)
    typedef std::unordered_map<int, std::set<int> > u_map; // container for the adjacent list
                                // representation from the Graph class and its two descendants
public:
    UnionFind(int, graph_t);    // Initialize the UnionFind algorithm by providing
                                // the number of vertices the underlying graph has, and the
                                // default graph type is __UG (undirected graph)
    UnionFind(const UGraph&);   // Initialize the UnionFind algorithm by providing an
                                // undirected graph in graph (adjacency list) representation
    UnionFind(const DGraph&);   // Initialize the Search algorithm by providing a directed
                                // graph in graph (adjacency list) representation
    virtual ~UnionFind();

    void _union(int p, int q, m_style _ms = __EAGER);  // put p and q into the same component
    int  _find(int p, m_style _ms = __EAGER) const;    // component identifier for p (0 to N-1)
    int  _count() const;        // count the number of components, the underlying graph has
    bool _connected(int p, int q, m_style _ms = __EAGER);  // return true if p and q are in the
                                // same component

private:
    // as the class UnionFind is a set of algorithms, copying algorithm objects does not make any
    // sense, so to disable copying UnionFind objects, both copy constructor and operator are made
    // private.
    UnionFind() {}
    UnionFind(const UnionFind&) {}
    UnionFind& operator=(const UnionFind&) {return *this;}

    void adj2uf(const u_map &adj_list, std::vector<int> &id, m_style _ms = __EAGER); // convert
                                // adjacent list representation to UF representation.
                                // NOTICE: there is no uf2adj() function!! as in adj2uf(), path
                                // information is lost!!

    std::vector<int> id;        // access to component id (site indexed)
    int              count;     // number of components
    graph_t          gtype;     // type of the underlying graph
    u_map            adj_list;  // the adjacent list representation for the underlying graph
};

#endif // UNIONFIND_H
