#include "search.h"
#include <iostream>
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
//    DFS(source, __REC);
//    DFS(source, __ITR);
//    BFS(source, __ITR);
    BFS(source, __REC);
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
//    DFS(source, __REC);
//    DFS(source, __ITR);
//    BFS(source, __ITR);
    BFS(source, __REC);
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
/// \brief Search::DFS
/// \param _v
/// \param mst
/* * *
 * DFS: interface to implementations of Depth First Search
 *      depending on the input mst (implementation style),
 *      DFS can be implemented with either recursion (mst = __REC)
 *      or iteration (mst = __ITR).
 * * */
void Search::DFS(int _v, mstyle mst = __REC)
{
    if (mst==__REC)       dfsRec(_v);
    else /*mst == __ITR*/ dfsItr(_v);
}
////////////////////////////////////////////////////////////////////
/// \brief Search::dfsItr
/// \param _v
/* * *
 * Depth First Search for paths from vertex _v to all vertices
 * connected to it, and save the path information in the array:
 * edgeTo[] and this member function implements DFS with iterations.
 * * */
void Search::dfsItr(int _v)
{
    std::stack<int> dfs_stack;
    dfs_stack.push(_v);
    while (!dfs_stack.empty())
    {
        int v = dfs_stack.top();
        dfs_stack.pop();
        if (!marked[v])
        {
            marked[v] = true;
            edgeTo[v] = _v; _v = v;
            for (auto w = graph->adj_list[_v].begin();
                 w != graph->adj_list[_v].end(); w++)
                dfs_stack.push(*w);
        }
    }
}
////////////////////////////////////////////////////////////////////
/// \brief Search::dfsRec
/// \param _v
/* * *
 * Depth First Search for paths from vertex _v to all vertices
 * connected to it, and save the path information in the array:
 * edgeTo[] and this member function implements DFS with recursions.
 * * */
void Search::dfsRec(int _v)
{
    marked[_v] = true;
    for (auto w = graph->adj_list[_v].begin();
         w != graph->adj_list[_v].end(); w++)
    {
        if (!marked[*w])
        {
            edgeTo[*w] = _v;
            dfsRec(*w);
        }
    }
}
////////////////////////////////////////////////////////////////////
/// \brief Search::BFS
/// \param _v
/// \param mst
/* * *
 * BFS: interface to implementations of Bredth First Search
 *      depending on the input mst (implementation style),
 *      BFS can be implemented with either recursion (mst = __REC)
 *      or iteration (mst = __ITR).
 * * */
void Search::BFS(int _v, mstyle mst=__ITR)
{
    if (mst == __ITR)     bfsItr(_v);
    else /* mst==__ITR */ bfsRec(_v);
}
////////////////////////////////////////////////////////////////////
/// \brief Search::bfsItr
/// \param _v
/* * *
 * Bredth First Search for paths from vertex _v to all vertices
 * connected to it, and save the path information in the array:
 * edgeTo[] and this member function implements BFS with iterations.
 * * */
void Search::bfsItr(int _v)
{
    std::queue<int> bfs_queue;
    bfs_queue.push(_v);
    marked[_v] = true;
    while (!bfs_queue.empty())
    {
        int v = bfs_queue.front();
        bfs_queue.pop();
        for (auto w = graph->adj_list[v].begin();
             w != graph->adj_list[v].end(); w++)
        {
            if (!marked[*w])
            {
                bfs_queue.push(*w);
                edgeTo[*w] = v;
                marked[*w] = true;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////
/// \brief Search::bfsRec
/// \param _v
/* * *
 * Bredth First Search for paths from vertex _v to all vertices
 * connected to it, and save the path information in the array:
 * edgeTo[] and this member function implements BFS with recursions.
 * * */
void Search::bfsRec(int _v)
{
    std::stack<int> level;

    for (auto w = graph->adj_list[_v].begin();
         w != graph->adj_list[_v].end(); w++)
    {
        if (!marked[*w])
        {
            marked[*w] = true;
            edgeTo[*w] = _v;
            level.push(*w);
        }
    }
    int v;
    while (!level.empty())
    {
        v = level.top();
        level.pop();
        bfsRec(v);
    }
}
////////////////////////////////////////////////////////////////////
