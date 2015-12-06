/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * The main() function in this file is for testing the package functions           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define GRAPH_TYPE 1 // GRAPH_TYPE = 0: undirected graph; GRAPH_TYPE = 1: directed graph

#include <iostream>
#include "dgraph.h"
#include "ugraph.h"
using namespace std;

int main()
{
    int nv = 13, ne = 13;

    cout << "Please input the number of vertices and edges respectively:" << endl;
    cin >> nv >> ne; cin.get();
#if GRAPH_TYPE
    DGraph *graph = new DGraph(nv);

    for (int i = 0; i < ne; i++)
    {
        int v, w;
        cin >> v >> w; cin.get();
        graph->addEdge(v,w);
    }

    cout << graph->toString() << endl;

    cout << "graph->vectexNumber() = " << graph->vectexNumber() << endl;
    cout << "graph->edgeNumber() = " << graph->edgeNumber() << endl;

    cout << "==============================" << endl;
    int v;
    cout << "Input a vertex index:"; cin >> v; cin.get();
    std::set<int> neighbors = graph->adjacentTo(v);
    cout << "The vertices connecting to " << v << " with an edge pointing from it are: ";
    for (auto w = neighbors.begin(); w != neighbors.end(); w++)
        cout << *w << " ";
    cout << endl;

    cout << "-------------------------------" << endl;
    graph->reverse();
    cout << graph->toString() << endl;
    neighbors = graph->adjacentTo(v);
    cout << "The vertices connecting to " << v << " with an edge pointing from it are: ";
    for (auto w = neighbors.begin(); w != neighbors.end(); w++)
        cout << *w << " ";
    cout << endl;
#else
    UGraph graph(nv);

    for (int i = 0; i < ne; i++)
    {
        int v, w;
        cin >> v >> w; cin.get();
        graph.addEdge(v,w);
    }

    cout << graph.toString() << endl;

    cout << "graph.vectexNumber() = " << graph.vectexNumber() << endl;
    cout << "graph.edgeNumber() = " << graph.edgeNumber() << endl;

    cout << "==============================" << endl;
    int v;
    cout << "Input a vertex index:"; cin >> v; cin.get();
    std::set<int> neighbors = graph.adjacentTo(v);
    cout << "The vertices connecting to " << v << " with an edge pointing from it are: ";
    for (auto w = neighbors.begin(); w != neighbors.end(); w++)
        cout << *w << " ";
    cout << endl;
#endif
    return 0;
}

