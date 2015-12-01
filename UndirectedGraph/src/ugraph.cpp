#include "ugraph.h"
////////////////////////////////////////////////////////////////////
/* * *
 * create an unordered map whose key is vertex, value is
 * an array of the vertices adjacent to the key
 * * */
UGraph::UGraph(int _v_num):v_num(_v_num)
{
    e_num = 0;
    for (int v = 0; v < v_num; v++)
    {
        adj_list[v] = std::set<int>();
    }
}
////////////////////////////////////////////////////////////////////
/* * *
 * copy constructor
 * * */
UGraph::UGraph(UGraph &_ugraph):
    v_num(_ugraph.v_num),
    e_num(_ugraph.e_num)
{
    for (int v = 0; v < v_num; v++)
    {
        adj_list[v] = _ugraph.adj_list[v];
    }
}
////////////////////////////////////////////////////////////////////
/* * *
 * copy operator
 * * */
UGraph& UGraph::operator=(UGraph &_ugraph)
{
    v_num = _ugraph.v_num;
    e_num = _ugraph.e_num;
    for (int v = 0; v < v_num; v++)
    {
        adj_list[v] = _ugraph.adj_list[v];
    }
    return *this;
}
////////////////////////////////////////////////////////////////////
UGraph::~UGraph()
{
}
////////////////////////////////////////////////////////////////////
/* * *
 * get the number of vertices of the undirected graph
 * * */
int UGraph::vectexNumber() const
{
    return v_num;
}
////////////////////////////////////////////////////////////////////
/* * *
 * get the number of edges of the undirected graph
 * * */
int UGraph::edgeNumber() const
{
    return e_num;
}
////////////////////////////////////////////////////////////////////
/* * *
 * add the edge v-w into the undirected graph
 * * */
void UGraph::addEdge(int v, int w)
{
    if (adj_list[v].find(w) == adj_list[v].end()) e_num ++;
    adj_list[v].insert(w);
    adj_list[w].insert(v); // undirected graph, the two end-points are equivalent
}
////////////////////////////////////////////////////////////////////
/* * *
 * get the set of all vertices adjacent to v
 * * */
std::set<int> UGraph::adjacentTo(int v)
{
    return adj_list[v];
}
////////////////////////////////////////////////////////////////////
/* * *
 * construct string representation of the undirected graph
 * * */
std::string UGraph::toString()
{
    std::string ugraphStr = std::to_string(v_num) + " vertices, "
            + std::to_string(e_num) + " edges\n";
    for (int v = 0; v < v_num; v++)
    {
        ugraphStr += std::to_string(v) + ": ";
        for (auto w = adj_list[v].begin(); w != adj_list[v].end(); w++)
            ugraphStr += std::to_string(*w) + " ";
        ugraphStr += "\n";
    }
    return ugraphStr;
}
////////////////////////////////////////////////////////////////////
