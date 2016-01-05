#include "unionfind.h"
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::UnionFind
/// \param _n
/// \param _gt
UnionFind::UnionFind(int _n, graph_t _gt = __UG):
    count(_n),
    gtype(_gt)
{
    id.reserve(_n);
    for (int i = 0; i < _n; i++)
        id[i] = i;
}
///////////////////////////////////////////////////////////////////////////////
UnionFind::UnionFind(const DGraph &_dg)
{
    gtype = __DG;
    adj_list = _dg.getGRep();
    count = adj_list.size();
    id.reserve(count);
    for (int i = 0; i < count; i++)
        id[i] = -1; // assume id is not set yet
}
///////////////////////////////////////////////////////////////////////////////
UnionFind::UnionFind(const UGraph &_ug)
{
    gtype = __UG;
    adj_list = _ug.getGRep();
    count = adj_list.size();
    id.reserve(count);
    for (int i = 0; i < count; i++)
        id[i] = -1; // assume id is not set yet
}
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::adj2uf
/// \param adj_list
/// \param id
/* * *
 * adj2uf() : converting adj_list graph representation to UF representation
 *    INPUT : const u_map &adj_list: adjacent list representation for a graph
 *            std::vector<int> &id : UF representation for a graph (assuming empty)
 *   OUTPUT : std::vector<int> &id : the function directly fill the container
 * * */
void UnionFind::adj2uf(const u_map &adj_list, std::vector<int> &id, m_style _ms = __EAGER)
{
    int count = adj_list.size();

    id.clear();
    id.resize(count);
    for (int i = 0; i < count; i++)
        id[i] = -1;

    if (gtype == __DG) // for DGraphs, _ms can be __EAGER (quick-find) only
    {
        bool visited[count];
        for (int i = 0; i < count; i++) visited = false;
        for (u_map::const_iterator vert = adj_list.begin(); vert != adj_list.end(); vert++)
        {
            if (vert->second.empty() && !visited[vert->first]) // vert->first is an end-point
            {
                id[vert->first] = vert->first;  // assuming vert->first is an isolated vertex
                                                // if it does have a parent, it will be corrected later
                visited[vert->first] = true;
            } // if vert->second.empty() && visted[vert->first] then skip
            else // vert->second.empty() == false
            {
                for (auto )
            }
        }
    }
    else // gtype == __UG
    {

    }
}
///////////////////////////////////////////////////////////////////////////////
UnionFind::~UnionFind()
{
}
///////////////////////////////////////////////////////////////////////////////
// put p and q into the same component
void UnionFind::_union(int p, int q, m_style _ms = __EAGER)
{
    if (_connected(p, q, _ms)) return;
    if (_ms == __LAZY)
    {

    }
}
///////////////////////////////////////////////////////////////////////////////
// component identifier for p (0 to N-1)
int UnionFind::_find(int p, m_style _ms = __EAGER) const
{
    if (_ms == __LAZY)
    { // Find component name.
        while (p != id[p]) p = id[p];
    }
    return id[p];
}
///////////////////////////////////////////////////////////////////////////////
// count the number of components, the underlying graph has
int UnionFind::_count() const
{
    return count;
}
///////////////////////////////////////////////////////////////////////////////
// return true if p and q are in the same component
bool UnionFind::_connected(int p, int q, m_style _ms = __EAGER)
{
    if (_ms == __LAZY)
    {
        while (p != id[p]) p = id[p];
        while (q != id[q]) q = id[q];
    }
    return (id[p] == id[q]);
}
///////////////////////////////////////////////////////////////////////////////
