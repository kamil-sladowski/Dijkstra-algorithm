//
// Created by Kamil on 2017-05-22.
//

#include "Neighbor.h"


    Neighbor::Neighbor(int i, int d){
        id = i;
        dist = d;
    }

    bool Neighbor::operator <(Neighbor &other) const{
        return dist < other.dist;
    }
    bool Neighbor::operator >(Neighbor &other) const{
        return dist > other.dist;
    }

    bool Neighbor::operator <=(Neighbor &other) const{
        return dist <= other.dist;
    }

    bool Neighbor::operator >=(Neighbor &other) const{
        return dist >= other.dist;
    }

     std::ostream& operator<< (std::ostream& stream, const Neighbor &other) {
        return stream << " Dist: " << other.dist<< " to: " << static_cast<char>('A' + other.id);
    }

