/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * The main() function in this file is for testing the package functions           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include "ugraph.h"
using namespace std;

int main()
{
    int nv = 13, ne = 13;

    cout << "Please input the number of vertices and edges respectively:" << endl;
    cin >> nv >> ne; cin.get();

    UGraph ug(nv);
    for (int i = 0; i < ne; i++)
    {
        int v, w;
        cin >> v >> w; cin.get();
        ug.addEdge(v,w);
    }

    cout << ug.toString() << endl;

    cout << "ug.vectexNumber() = " << ug.vectexNumber() << endl;
    cout << "ug.edgeNumber() = " << ug.edgeNumber() << endl;

    int v;
    cout << "Input a vertex index:"; cin >> v; cin.get();
    std::set<int> neighbors = ug.adjacentTo(v);
    cout << "The vertices adjacent to " << v << " are: ";
    for (auto w = neighbors.begin(); w != neighbors.end(); w++)
        cout << *w << " ";
    cout << endl;

    return 0;
}

