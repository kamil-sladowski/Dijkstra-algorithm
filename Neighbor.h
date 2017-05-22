//
// Created by Kamil on 2017-05-22.
//

#ifndef UNTITLED1_NEIGHBOUR_H
#define UNTITLED1_NEIGHBOUR_H


class Neighbor{
public:
    int id = -1;
    int dist = -1;

    Neighbor(int i, int d);
    Neighbor(pair<int, int> p);
    bool operator <(Neighbor &other) const;
    bool operator >(Neighbor &other) const;

    bool operator <=(Neighbor &other) const;

    bool operator >=(Neighbor &other) const;

    friend std::ostream& operator<< (std::ostream& stream, const Neighbor &other);


};


#endif //UNTITLED1_NEIGBOUR_H
