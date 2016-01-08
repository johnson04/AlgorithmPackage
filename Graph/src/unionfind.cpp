#include "unionfind.h"
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::UnionFind
/// \param _n
/// \param _gt
/* * *
 * UnionFind(int, m_style) : initialize an UF representation of a set of _n
 *                           elements. Before any equivalence relation is
 *                           established between any two elements, every element
 *                           itself form an equivalence class.
 * * */
UnionFind::UnionFind(int _n, m_style _m):
    count(_n),
    _ms(_m)
{
    id.reserve(_n);
    compo_size.reserve(_n);
    for (int i = 0; i < _n; i++)
    {
        id.push_back(i); // every element forms an equivalence class, therefore it is
                    // the representative of its equivalence class
        compo_size[i] = 1; // as every element forms a component (i.e. equivalence
                    // class), the size of every component is clearly one!
    }
}
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::UnionFind
/// \param _dg
/* * *
 * UnionFind(const DGraph&, m_style) : construct UF representation from adjacent
 *                                     list representation of a directed graph
 * * */
UnionFind::UnionFind(const DGraph &_dg, m_style _m):
    _ms(_m)
{
    gtype = __DG;
    adj_list = _dg.getGRep();
    count = adj_list.size();
    id.reserve(count);
    for (int i = 0; i < count; i++)
        id[i] = -1; // assume id is not set yet
}
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::UnionFind
/// \param _ug
/* * *
 * UnionFind(const UGraph&) : construct UF representation from adjacent list
 *                            representation of an undirected graph
 * * */
UnionFind::UnionFind(const UGraph &_ug, m_style _m):
    _ms(_m)
{
    gtype = __UG;
    adj_list = _ug.getGRep();
    count = adj_list.size();
    id.reserve(count);
    for (int i = 0; i < count; i++)
        id[i] = -1; // assume id is not set yet
}
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::~UnionFind
/* * *
 * UF Destructor
 * * */
UnionFind::~UnionFind()
{
}
///////////////////////////////////////////////////////////////////////////////
void UnionFind::_print() const
{
    std::cout << "The UF data structure has: " << std::endl;
    std::cout << "  " << id.size() << " elements;" << std::endl;
    std::cout << "  " << count << " components (equivalence classes);" << std::endl;
    for (size_t i = 0; i < id.size(); i ++)
        std::cout << std::setw(5) << i;
    std::cout << std::endl;
    for (size_t i = 0; i < id.size(); i++)
        std::cout << "_____";
    std::cout << std::endl;
    for (size_t i = 0; i < id.size(); i++)
        std::cout << std::setw(5) << id[i];
    std::cout << std::endl << std::endl;
}
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::adj2uf
/// \param adj_list
/// \param id
/* * *
 * adj2uf() : converting adj_list graph representation to UF representation
 *    INPUT : const u_set_map &adj_list: adjacent list representation for a graph
 *            std::vector<int> &id : UF representation for a graph (assuming empty)
 *   OUTPUT : std::vector<int> &id : the function directly fill the container
 * * */
void UnionFind::adj2uf(const u_set_map &adj_list, std::vector<int> &id)
{
    // TODO:
}
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::__union
/// \param p
/// \param q
/* * *
 * put p and q into the same component [component containing p joins component
 * containing q].
 * * */
void UnionFind::_union(int p, int q)
{
    int pid = _find(p);
    int qid = _find(q);
    if (pid == qid) return;         // p and q are already in the same component
    if (_ms == __LAZY)              // quick union approach
        id[pid] = qid;
    else if (_ms == __W_LAZY)       // weighted quick union approach
    {
        int psize = compo_size[pid];
        int qsize = compo_size[qid];
        if (psize < qsize) id[pid] = qid;
        else id[qid] = pid;
        compo_size[pid] = pid + qid;
        compo_size[qid] = pid + qid;
    }
    else                            // quick find approach
    {
        for (int i = 0; i < id.size(); i++)
            if (id[i] == pid) id[i] = qid;
    }
    count --;
}
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::_find
/// \param p
/// \return
/* * *
 * component identifier for p (0 to N-1)
 * for quick union approach (_ms == __LAZY), need to tace back to the "root"
 * of its id labels; for quick find approach (_ms == __EAGER), directly return
 * its id label.
 * * */
int UnionFind::_find(int p) const
{
    if (_ms == __LAZY || _ms == __W_LAZY) // quick union approach (weighted or not)
    { // Find component name.
        while (p != id[p]) p = id[p];
    }
    return id[p];
}
///////////////////////////////////////////////////////////////////////////////
/// \brief UnionFind::_count
/// \return
/* * *
 * count the number of components, the underlying graph has;
 * directly return the value of count.
 * * */
int UnionFind::_count() const
{
    return count;
}
///////////////////////////////////////////////////////////////////////////////
bool UnionFind::_connected(int p, int q)
{
    int pid = _find(p);
    int qid = _find(q);
    return (pid == qid);
}
///////////////////////////////////////////////////////////////////////////////



