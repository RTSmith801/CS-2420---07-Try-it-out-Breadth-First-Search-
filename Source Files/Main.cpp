#include <iostream>
#include "Graph.h"

using std::cout;
using std::endl;

int main() {
    std::cout << "Hello world" << std::endl;
    Graph g1("graphtest32833.txt");
    cout << "0->3:" << g1.shortestCost(0,3) << endl;
    cout << "0->1:" << g1.shortestCost(0,1) << endl;
    cout << "0->2:" << g1.shortestCost(0,2)<< endl;
}