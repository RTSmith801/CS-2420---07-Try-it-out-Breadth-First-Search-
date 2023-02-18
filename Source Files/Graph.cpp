/**
 * @file: graph.cpp
 * @assignment_name: 07: Try it out: Breadth First Search
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 02/16/2023
 * @brief: Implement a Graph using an adjacency list representation.
 *
 */


#include "Graph.h"
#include <fstream>
#include <stdexcept>
#include <cstdint>

using std::list;
using std::ifstream;
using std::invalid_argument;

#include "Graph.h"
Graph::Graph(std::string filename) {
    ifstream input;
    input.open(filename);
    if(!input){
        throw invalid_argument("Could not read file");
    }
    input >> numNodes;
    adjList = new list<Pair>[numNodes];
    for(int i = 0; i < numNodes; i++){
        int value;
        int cost;
        input >> value;
        while(value >= 0) {
            input >> cost;
            adjList[i].push_back(Pair(value, cost));
            input >> value;
        }
    }
}

int Graph::shortestCost(int start, int finish){

    int* dist = new int[numNodes];
    list<int> remaining;
    list<int> finished;
    for (int i = 0; i < numNodes; i++) {
        if (i == start) {
            dist[i] = 0;
        }
        else{
            dist[i] = INT_MAX;
        }
        remaining.push_back(i);
    }

    while(!remaining.empty()) {
        int minDist = INT_MAX;
        int minIndex = -1;
        for (list<int>::iterator listIt = remaining.begin(); listIt != remaining.end(); listIt++) {
            if (dist[*listIt] < minDist) {
                minDist = dist[*listIt];
                minIndex = *listIt;
            }
        }

        int cur = minIndex;
        for (list<Pair>::iterator listIt = adjList[cur].begin(); listIt != adjList[cur].end(); listIt++) {
            int next = (*listIt).node;
            int nextWeight = (*listIt).weight;
            if (dist[cur] +  nextWeight < dist[next]) {
                dist[next] = dist[cur] + nextWeight;
            }
        }
        remaining.remove(cur);
        finished.push_back(cur);
    }
    return dist[finish];
}

void Graph::printBFT(std::ostream &out) {
    //out << printParseTreeInOrder(root);
}

//std::string ExpressionTree::printParseTreeInOrder(Node *curr) {
//    //if node exists
//    std::string toReturn = "";
//    if(curr) {
//        //if node->left, recurssive call.
//        if(curr->left){
//            toReturn += printParseTreeInOrder(curr->left);
//        }
//        //add value to string.
//        toReturn += curr->val;
//        //if node->right, recursive call.
//        if(curr->right){
//            toReturn += printParseTreeInOrder(curr->right);
//        }
//        return toReturn;
//    }
//    else{
//        //return nothing when finding an empty node.
//        return "";
//    }
//
//}