#include "ugraph.h"
////////////////////////////////////////////////////////////////////
UGraph::UGraph(int _v_num):
    Graph(_v_num)
{
}
////////////////////////////////////////////////////////////////////
/* * *
 * copy constructor
 * * */
UGraph::UGraph(UGraph &_ugraph):
    Graph(_ugraph)
{
}
////////////////////////////////////////////////////////////////////
UGraph::~UGraph()
{
}
////////////////////////////////////////////////////////////////////
/* * *
 * add the edge v-w into the undirected graph
 * * */
void UGraph::addEdge(int v, int w)
{
    if (adj_list[v].find(w) == adj_list[v].end()) e_num ++;
    // increase number of edges by one, only when the adding edge does not exist
    // in the graph
    adj_list[v].insert(w);
    adj_list[w].insert(v); // undirected graph, the two end-points are equivalent
}
