/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * The main() function in this file is for testing the package functions           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include "unionfind.h"
using namespace std;

int main()
{
    int v_num = 10;
    UnionFind uf(v_num, __EAGER);

    uf._print();

    uf._union(4, 3);
    uf._print();

    uf._union(3, 8);
    uf._print();

    uf._union(6, 5);
    uf._print();

    uf._union(9, 4);
    uf._print();

    uf._union(2, 1);
    uf._print();

    uf._union(8, 9);
    uf._print();

    uf._union(5, 0);
    uf._print();

    uf._union(7, 2);
    uf._print();

    uf._union(6, 1);
    uf._print();

    uf._union(1, 0);
    uf._print();

    uf._union(6, 7);
    uf._print();

    return 0;
}

