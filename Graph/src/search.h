#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <map>

#include "graph.h"
#include "ugraph.h"
#include "dgraph.h"

//namespace Search{
struct Path;

class Search
{
    Graph *graph;  // pointer to the graph to be processed
    typedef enum methodID {DFS, BFS} mid; // for clients to choose which search method to use
    typedef enum implStyle {ITR, REC} mstyle; // for clients to choose which implementation style
                                              // (ITR: iteration; REC: recursion) to use
    int *edgeTo; // array of vertices used for tracking the search tree
public:
    Search(UGraph*, int _s); // Initialize the Search algorithm by providing an undirected graph
                             // in graph (adjacency list) representation and a vertex under
                             // consideration named source
    Search(DGraph*, int _s); // Initialize the Search algorithm by providing a directed graph
                             // in graph (adjacency list) representation and a vertex under
                             // consideration named source
    virtual ~Search();

    int  count();        // count how many vertices are connected to the vertex source

    bool hasPathTo(int _v); // determine if there is a path from source to the vertex _v

    Path* pathTo(int _v); // find a path from the source to vertex _v. if there is a path,
                          // then return head (source) of the path (represented as a singly
                          // linked list); otherwise return NULL
    std::string pathToString(Path*); // convert the path to string

private:
    // as the class Search is a set of algorithms, copying algorithm objects does not make any
    // sense, so to disable copying Search objects, both copy constructor and operator are made
    // private.
    Search() {}
    Search(const Search&) {}
    Search& operator=(const Search&) {return *this;}

    std::map<int, bool> marked; // if a vertex _v is connected to source, then marked[v] = true

    void dfs(int, mstyle);
    void dfs_rec(int);
    void dfs_itr(int);

    void bfs(int, mstyle);
    void bfs_rec(int);
    void bfs_itr(int);

    bool directed;
    int  source;   // vertex of the graph currently under consideration

    Path *head; // head of the singly linked list used for representing a path from the source
                // to any given vertex, provided the path exists.
};

//} // namespace Search
#endif // SEARCH_H
