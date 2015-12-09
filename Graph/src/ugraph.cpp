#include "ugraph.h"
////////////////////////////////////////////////////////////////////
/// \brief UGraph::UGraph
/// \param _v_num
/* * *
 * normal constructor: get an non-negative integer, then create
 * an undirected graph by calling the parent constructor.
 * * */
UGraph::UGraph(int _v_num):
    Graph(_v_num)
{
}
////////////////////////////////////////////////////////////////////
/// \brief UGraph::UGraph
/// \param _ugraph
/* * *
 * copy constructor
 * * */
UGraph::UGraph(const UGraph &_ugraph):
    Graph(_ugraph)
{
}
////////////////////////////////////////////////////////////////////
UGraph::~UGraph()
{
}
////////////////////////////////////////////////////////////////////
/// \brief UGraph::addEdge
/// \param v
/// \param w
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
////////////////////////////////////////////////////////////////////
/// \brief UGraph::removeEdge
/// \param _v
/// \param _w
/* * *
 * remove the edge _v-_w from this graph
 * * */
void UGraph::removeEdge(int _v, int _w)
{
    adj_list[_v].erase(_w);
    adj_list[_w].erase(_v);
}
////////////////////////////////////////////////////////////////////
/// \brief UGraph::removeVertex
/// \param _v
/* * *
 * remove the vertex _v from this graph
 * all edges connecting _v with other vertices are removed too.
 * * */
void UGraph::removeVertex(int _v)
{
    adj_list.erase(adj_list.find(_v));
    for (auto w = adj_list.begin(); w != adj_list.end(); w++)
    {
        if ((*w).second.find(_v) != (*w).second.end())
            (*w).second.erase(_v);
    }
}
////////////////////////////////////////////////////////////////////
