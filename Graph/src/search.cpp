#include "search.h"
////////////////////////////////////////////////////////////////////
/// \brief The Path struct
///
struct Path
{
    int val;
    Path *next;

    Path(int _v):val(_v)
    {
        next = NULL;
    }
};
////////////////////////////////////////////////////////////////////
/// \brief Search::Search
/// \param _dg
/// \param _s
/* * *
 * constructor for directed graph
 * * */
Search::Search(DGraph *_dg, int _s):
    graph(_dg), source(_s)
{
    head = new Path(source);
    directed = true;
    edgeTo = new int[graph->v_num];
    dfs(source, REC);
}
////////////////////////////////////////////////////////////////////
/// \brief Search::Search
/// \param _ug
/// \param _s
/* * *
 * constructor for undirected graph
 * * */
Search::Search(UGraph *_ug, int _s):
    graph(_ug), source(_s)
{
    head = new Path(source);
    directed = false;
    edgeTo = new int[graph->v_num];
    dfs(source, REC);
}
////////////////////////////////////////////////////////////////////
/// \brief Search::~Search
/* * *
 * destructor
 * * */
Search::~Search()
{
    Path *node;
    while (head->next)
    {
        node = head->next;
        delete head;
        head = node;
    }
    delete head;
    if (edgeTo != NULL) delete edgeTo;

    // Notice: graph is a pointer to data structure from outside
    //         should not delete it here!!
}
////////////////////////////////////////////////////////////////////
/// \brief Search::pathTo
/// \param _v
/// \return
/* * *
 * retrieve the path from source to _v by "back tracing" the array
 * edgeTo, if the path exists; otherwise simply return a NULL pointer
 * * */
Path* Search::pathTo(int _v)
{
    if (!hasPathTo(_v)) return NULL;

    if (head != NULL) delete head;
    Path *node;
    int v = _v;
    head = new Path(v);
    while (v != source)
    {
        node = head;
        v = edgeTo[v];
        head = new Path(v);
        head->next = node;
    }
    return head;
}
////////////////////////////////////////////////////////////////////
/// \brief Search::hasPathTo
/// \param _v
/// \return
/* * *
 * check if vertex _v is connected to the source
 * * */
bool Search::hasPathTo(int _v)
{
    return marked[_v];
}

////////////////////////////////////////////////////////////////////
/// \brief Search::pathToString
/// \param head
/// \return
/* * *
 * convert the path from source to _v into string (for output)
 * * */
std::string Search::pathToString(Path *head)
{
    std::string pathStr = std::to_string(head->val);
    while(head->next != NULL)
    {
        head = head->next;
        pathStr += "->" + std::to_string(head->val);
    }
    return pathStr;
}
////////////////////////////////////////////////////////////////////
void Search::dfs(int _v, mstyle mst = REC)
{
    if (mst==REC) dfs_rec(_v);
    else          dfs_itr(_v);
}
////////////////////////////////////////////////////////////////////
void Search::dfs_itr(int _v)
//TODO:
{
}
////////////////////////////////////////////////////////////////////
void Search::dfs_rec(int _v)
{
    marked[_v] = true;
    for (auto w = graph->adj_list[_v].begin();
         w != graph->adj_list[_v].end(); w++)
    {
        if (!marked[*w])
        {
            edgeTo[*w] = _v;
            dfs_rec(*w);
        }
    }
}
////////////////////////////////////////////////////////////////////
void Search::bfs(int _v, mstyle mst=ITR)
{
    if (mst==ITR) bfs_itr(_v);
    else          bfs_rec(_v);
}
////////////////////////////////////////////////////////////////////
void Search::bfs_itr(int _v)
// TODO:
{
}
////////////////////////////////////////////////////////////////////
void Search::bfs_rec(int _v)
// TODO:
{
}
////////////////////////////////////////////////////////////////////
