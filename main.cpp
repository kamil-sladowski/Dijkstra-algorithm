#include <iostream>
#include "AdjacencyGraph.cpp"
#include <queue>
#include <map>
#include<algorithm>
#include<iterator>
#include "Heap.cpp"
#include "Neighbor.cpp"

using namespace std;
const int INFINITY = 1000000;
int N;

Neighbor getShortestWay(Heap<Neighbor> &heap){
    Neighbor n = heap.remove();
    return n;
}


int main() {
   cin >>::N;
    AdjacencyGraph adjacency;

    vector<bool> visitedNodes(N, false);
    int *distance = new int[N];
    int *previousVisited = new int[N];
    int currPos = 0;

    adjacency.showMatrix(adjacency.getAdjacencyGraph());
    for(int i = 0; i < N; i++) {
        previousVisited[i] = -1;
        distance[i] = INFINITY;
    }

    visitedNodes[0] = true;
    distance[0] = 0;

    Heap<Neighbor> neighbours_id_dist;
    map<int, vector<int>> adjacencyList;

    auto temp = adjacency.getNeighbours(currPos);

    for(auto ptr = temp.begin(); ptr!=temp.end(); ptr++)
        neighbours_id_dist.push(Neighbor(ptr->first, ptr->second));

    do{
        Neighbor b = getShortestWay( neighbours_id_dist);
        currPos = b.id;
        visitedNodes[currPos] = true;


        map<int, int> neighbours = adjacency.getNeighbours(currPos);
        map<int, int>::const_iterator ptr = neighbours.begin();
        vector<int> nnn;
        for(; ptr!=neighbours.end(); ptr++)
            nnn.push_back(ptr->first);
        adjacencyList.insert(make_pair(currPos, nnn));

        for(auto i : neighbours){
            if (!visitedNodes[i.first])
                if (distance[i.first] > distance[currPos] + i.second) {
                    distance[i.first] = distance[currPos] + i.second;
                    previousVisited[i.first] = currPos;
                }
            neighbours_id_dist.push(Neighbor(i.first, i.second));
        }

    }while(find(visitedNodes.begin(), visitedNodes.end(), false) != visitedNodes.end());//(!visitedNodes.empty()); //!neighbours_id_dist.empty()

    for(auto x : adjacencyList){
        cout <<static_cast<char>('A' + x.first)<<" ->  ";
        for(auto y: x.second)
            cout << static_cast<char>('A' + y)<<"  ";
        cout <<endl;
    }

    return 0;
}




/*
 1 20 17 330 19 190 10
20 1 20 -1 60 75 500
17 20 1 31 15 33 7
330 -1 31 1 -1 2 18
190 60 15 -1 1 880 -1
19 75 33 2 880 1 10
10 500 7 18 -1 10 1
 */