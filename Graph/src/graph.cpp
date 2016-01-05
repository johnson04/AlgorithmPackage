#include "graph.h"
////////////////////////////////////////////////////////////////////
/// \brief Graph::Graph
/// \param _v_num
/* * *
 * create an unordered map whose key is vertex, value is
 * an set of the vertices adjacent to the key
 * * */
Graph::Graph(int _v_num): v_num(_v_num)
{
    e_num = 0;
    for (int v = 0; v < v_num; v++)
    {
        adj_list[v] = std::set<int>();
        alias[v]    = std::to_string(v);
    }
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::Graph
/// \param _dgraph
/* * *
 * copy constructor
 * * */
Graph::Graph(const Graph &_graph):
    v_num(_graph.v_num),
    e_num(_graph.e_num)
{
    if (e_num > 0) adj_list.clear();
    adj_list = _graph.adj_list;
    alias    = _graph.alias;
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::operator =
/// \param _graph
/// \return
/* * *
 * copy operator
 * * */
Graph& Graph::operator=(Graph &_graph)
{
    if (e_num > 0) adj_list.clear();
    adj_list = _graph.adj_list;
    alias    = _graph.alias;
    v_num    = _graph.v_num;
    e_num    = _graph.e_num;
    return *this;
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::~Graph
Graph::~Graph()
{
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::vectexNumber
/// \return
/* * *
 * get the number of vertices of the graph
 * * */
int Graph::vectexNumber() const
{
    return v_num;
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::edgeNumber
/// \return
/* * *
 * get the number of edges of the graph
 * * */
int Graph::edgeNumber() const
{
    return e_num;
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::inGraph
/// \param _v
/// \return
/* * *
 * determine if the given vertex _v is in the graph or not
 * * */
bool Graph::inGraph(int _v) const
{
    return (adj_list.find(_v) != adj_list.end());
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::adjacentTo
/// \param v
/// \return
/* * *
 * get the set of all vertices adjacent to or exiting from v
 * * */
std::set<int> Graph::adjacentTo(int v)
{
    return adj_list[v];
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::addVertex
/// \param _v
/* * *
 * check if the vertex _v is in the graph, if it is not in the graph
 * then add it into the graph, otherwise nothing is done
 * * */
void Graph::addVertex(int _v)
{
    if (adj_list.find(_v) == adj_list.end())
        adj_list[_v] = std::set<int>();
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::toString
/// \return
/* * *
 * construct string representation of the graph
 * * */
std::string Graph::toString()
{
    std::string graphStr = std::to_string(v_num) + " vertices, "
            + std::to_string(e_num) + " edges\n";
    for (int v = 0; v < v_num; v++)
    {
        graphStr += std::to_string(v) + ": ";
        for (auto w = adj_list[v].begin(); w != adj_list[v].end(); w++)
            graphStr += std::to_string(*w) + " ";
        graphStr += "\n";
    }
    return graphStr;
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::getVNum
/// \return v_num
int Graph::getVNum() const
{
    return v_num;
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::getENum
/// \return e_num
int Graph::getENum() const
{
    return e_num;
}
////////////////////////////////////////////////////////////////////
/// \brief Graph::getGRep
/// \return adj_list
std::unordered_map<int, std::set<int> > Graph::getGRep() const
{
    return adj_list;
}
////////////////////////////////////////////////////////////////////
