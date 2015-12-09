#include "dgraph.h"
////////////////////////////////////////////////////////////////////
DGraph::DGraph(int _v_num):
    Graph(_v_num)
{
}
////////////////////////////////////////////////////////////////////
DGraph::DGraph(const DGraph &_dgraph):
    Graph(_dgraph)
{
}
////////////////////////////////////////////////////////////////////
/// \brief DGraph::~DGraph
DGraph::~DGraph()
{
}
////////////////////////////////////////////////////////////////////
/// \brief DGraph::addEdge
/// \param v
/// \param w
/* * *
 * add the edge v->w into the directed graph
 * Remember: always start-point first, then end-point
 * * */
void DGraph::addEdge(int v, int w)
{
    if (adj_list[v].find(w) == adj_list[v].end()) e_num ++;
    // increase number of edges by one, only when the adding edge does not exist
    // in the digraph
    adj_list[v].insert(w); // directed graph, the two end-points are not equivalent
}
////////////////////////////////////////////////////////////////////
/// \brief DGraph::removeEdge
/// \param _v
/// \param _w
/* * *
 * remove the edge pointing from _v to _w
 * * */
void DGraph::removeEdge(int _v, int _w)
{
    adj_list[_v].erase(_w);
}
////////////////////////////////////////////////////////////////////
/// \brief DGraph::removeVertex
/// \param _v
/* * *
 * remove the vertex _v and all edges pointing from _v and to _v
 * * */
void DGraph::removeVertex(int _v)
{
    adj_list[_v].clear(); // remove all edges pointing from _v
    adj_list.erase(_v);   // remove the vertex _v
    for (auto w = adj_list.begin(); w != adj_list.end(); w++)
    {
        if ((*w).second.find(_v) != (*w).second.end())
            (*w).second.erase(_v);
    }
}

////////////////////////////////////////////////////////////////////
/// \brief DGraph::reverse
///
/* * *
 * reverse all edge directions. Notice: this changes the digraph itself!
 * * */
void DGraph::reverse()
{
    std::unordered_map<int, std::set<int> > __adj_list;
    for (int v = 0; v < v_num; v++)
    {
        for (auto w = adj_list[v].begin(); w != adj_list[v].end(); w++)
        {
            __adj_list[*w].insert(v);
        }
    }
    adj_list = __adj_list;
}
