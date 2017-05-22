
#include <utility>
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <map>

#ifndef UNTITLED1_ADJACENCYGRAPH_H
#define UNTITLED1_ADJACENCYGRAPH_H
#define SETWVALUE 6

using namespace std;

class AdjacencyGraph {
    int **adjacencyGraph;

public:
    AdjacencyGraph();

    int **getAdjacencyGraph();

    template<typename T>
    void showMatrix(T **matrix);

    map<int, int> getNeighbours(int); //, vector<bool> visited

    int getWayLength(int, int);

    void getAdjacencyGraphFromFile();
};

template<typename T>
T **createMatrix(T initializer);

#endif //UNTITLED1_ADJENCYGRAPH_H



