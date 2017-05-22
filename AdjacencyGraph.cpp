

#include "AdjacencyGraph.h"
#include <utility>
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <map>

using namespace std;

extern int N;

AdjacencyGraph::AdjacencyGraph(){

    adjacencyGraph = createMatrix(-1);
    getAdjacencyGraphFromFile();
    for (int i = 0; i < N; ++i)
        adjacencyGraph[i][i] = 0;
}

int ** AdjacencyGraph::getAdjacencyGraph(){
    return adjacencyGraph;
}


template<typename T>
T **createMatrix(T initializer) {
    T **matrix = new T *[N];
    for (int i = 0; i < N; ++i)
        matrix[i] = new T[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = initializer;
        }
    }
    return matrix;
}


template <typename T>
void AdjacencyGraph::showMatrix(T ** matrix)
{
    cout << setw(SETWVALUE);
    for(int j = 0; j<N; j++) {
        for(int i = 0; i<N; i++) {
            cout << fixed<< setprecision(4)<< matrix[i][j]<<setw(SETWVALUE);
        }
        cout << endl;
    }
    cout << endl;
}

map<int, int> AdjacencyGraph::getNeighbours(int y){ //, vector<bool> visited
    map<int, int> neighbours;

    for(int i =0; i<N; i++)
        if(adjacencyGraph[y][i] > 0 ) //&& !visited[i]
            neighbours.insert(make_pair(i, adjacencyGraph[y][i]));

    return neighbours;
}

//pair<int, int> AdjacencyGraph::getNextNeighbour(int y, int i){
//
//
//        if(adjacencyGraph[y][i] > 0 )
//            return make_pair(i, adjacencyGraph[y][i]);
//
//
//    return make_pair(-1, -1);
//}

int AdjacencyGraph::getWayLength(int x, int y){
    return adjacencyGraph[y][x];
}


void AdjacencyGraph::getAdjacencyGraphFromFile(){
    int a = 0;
    for(int j = 0; j<N; j++) {
        for(int i = 0; i<N; i++) {
            cin>>a;
            adjacencyGraph[j][i] = a;
        }
        //adjacencyGraph[j][i] = a;
    }
}