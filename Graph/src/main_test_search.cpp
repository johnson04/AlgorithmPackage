/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * The main() function in this file is for testing the package functions           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define GRAPH_TYPE 1 // GRAPH_TYPE = 0: undirected graph; GRAPH_TYPE = 1: directed graph

#include <iostream>
#include "dgraph.h"
#include "ugraph.h"
#include "search.h"
using namespace std;

int main()
{
    int v = -1, w = -1;

#if GRAPH_TYPE
    DGraph dgraph(7);
    dgraph.addEdge(0,2);
    dgraph.addEdge(0,1);
    dgraph.addEdge(0,5);
    dgraph.addEdge(2,1);
    dgraph.addEdge(2,3);
    dgraph.addEdge(3,4);
    dgraph.addEdge(3,5);
    cout << "digraph:\n" << dgraph.toString() << endl;

    while (v < 0 || v > dgraph.vectexNumber())
    {
        cout << "Please input a vertex id you want to check: "; cin >> v; cin.get();
    }
    Search search(&dgraph, v);
    while (!dgraph.inGraph(w))
    {
        cout << "input a vertex in the graph: "; cin >> w; cin.get();
    }
    if (search.hasPathTo(w))
    {
        cout << "There is a path from " << v << " to " << w << "." << endl;
        cout << search.pathToString(search.pathTo(w)) << endl;
    }
    else
    {
        cout << "There is no path from " << v << " to " << w << "." << endl;
    }
#else
    UGraph ugraph(7);
    ugraph.addEdge(0,2);
    ugraph.addEdge(0,1);
    ugraph.addEdge(0,5);
    ugraph.addEdge(2,1);
    ugraph.addEdge(2,3);
    ugraph.addEdge(3,4);
    ugraph.addEdge(3,5);
    cout << "undirected graph:\n" << ugraph.toString() << endl;

    while (v < 0 || v > ugraph.vectexNumber())
    {
        cout << "Please input a vertex id you want to check: "; cin >> v; cin.get();
    }
    Search search(&ugraph, v);
    while (!ugraph.inGraph(w))
    {
        cout << "input a vertex in the graph: "; cin >> w; cin.get();
    }
    if (search.hasPathTo(w))
    {
        cout << "There is a path from " << v << " to " << w << "." << endl;
        cout << search.pathToString(search.pathTo(w)) << endl;
    }
    else
    {
        cout << "There is no path from " << v << " to " << w << "." << endl;
    }
#endif
    return 0;
}

