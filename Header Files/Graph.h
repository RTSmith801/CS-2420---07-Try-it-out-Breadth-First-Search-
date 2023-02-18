/**
 * @file: graph.h
 * @assignment_name: 07 Learning Activity: Dijkstra's Algorithm
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 02/13/2023
 * @brief: This will demonstrate the implementation of a Dijkstra's Algorithm using and Adjacency List graph representation
 *
 */

#ifndef INC_07_LEARNING_ACTIVITY_DIJKSTRAS_ALGORITHM_GRAPH_H
#define INC_07_LEARNING_ACTIVITY_DIJKSTRAS_ALGORITHM_GRAPH_H

#include <list>
#include <string>

struct Pair {

    Pair(int n, int w){
        node = n;
        weight = w;
    }

    int node;
    int weight;
};

class Graph {

public:
    //Constructor
    Graph(std::string file);
    int shortestCost(int start, int finish);
    void printBFT(std::ostream& out); // outputs the graph using a breadth-first traversal


private:
    std::list<Pair>* adjList;
    int numNodes;

};




#endif //INC_07_LEARNING_ACTIVITY_DIJKSTRAS_ALGORITHM_GRAPH_H
