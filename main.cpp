#include <iostream>
#include "AdjacencyGraph.cpp"
#include <queue>
#include <map>
#include<algorithm>
#include<iterator>

using namespace std;
const int INFINITY = 1000000;
int N;

pair<int, int> getShortestWay(map<int, int> &neighbours_id_dist){
    auto greatherThan = [](pair<int, int> i, pair<int, int> j){return i.first > j.first;};

    make_heap(neighbours_id_dist.begin(),neighbours_id_dist.end(), greatherThan); //greater<int>
    sort_heap(neighbours_id_dist.begin(), neighbours_id_dist.end(), greatherThan);
    auto a = make_pair(0, neighbours_id_dist[0]);
    pop_heap(neighbours_id_dist.begin(),neighbours_id_dist.end()); neighbours_id_dist.erase(a.first);
    return a;
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

    map<int, int> neighbours_id_dist; //ID, dist
    map<int, vector<int>> adjacencyList;

    neighbours_id_dist = adjacency.getNeighbours(currPos);

    do{
        pair<int, int> b = getShortestWay( neighbours_id_dist);
        currPos = b.second;
        visitedNodes[currPos] = true;


        map<int, int> neighbours = adjacency.getNeighbours(currPos);
        map<int, int>::const_iterator ptr = neighbours.begin();
        vector<int> nnn;
        for(; ptr!=neighbours.end(); ptr++)
            nnn.push_back(ptr->second);
        adjacencyList.insert(make_pair(currPos, nnn));
        for(auto i : neighbours){
            if (!visitedNodes[i.second])
                if (distance[i.second] > distance[currPos] + i.first) {
                    distance[i.second] = distance[currPos] + i.first;
                    previousVisited[i.second] = currPos;
                }
            neighbours_id_dist.insert(i.first, i.second);
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