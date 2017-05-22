
#include "Heap.h"
#include <iterator>
#include <algorithm>
#include <cstdarg>

#define Print(x) cout << x<< "  ";


template <typename T>
Heap<T>::Heap(){
    n = 0;
}
template <typename T>
void Heap<T>::push(T el){
    elements.push_back(el);
    n++;
    bubbleUp(n-1);
}
template <typename T>
auto Heap<T>::remove(){
    auto temp = elements[0];
    elements[0] = elements.back();
    elements.erase(elements.end() - 1);
    n--;
    bubbleDown(0);

    return temp;
}

template <typename T>
void Heap<T>::bubbleDown(int k){
    int leftChildId = getLeftChild(k);
    int rightChildId = getRightChild(k);

    if(existLeftChild(k) && existRightChild(k)){
        if(elements[leftChildId] >= elements[rightChildId]){
            swap(k, rightChildId);
            bubbleDown(rightChildId);
        }
        else{
            swap(k, leftChildId);
            bubbleDown(leftChildId);
        }
    }
    else
        return;
}

template <typename T>
void Heap<T>::bubbleUp(int k){
    int parentPos = getParent(k);
    if(k > 0 && elements[parentPos] > elements[k]){
        swap(parentPos, k);
        bubbleUp(parentPos);
    }
    else
        return;
}

template <typename T>
bool Heap<T>::existLeftChild(int k){
    return 2*k+1<n-1;
}
template <typename T>
bool Heap<T>::existRightChild(int k){
    return 2*k+2<n-1;
}

template <typename T>
bool Heap<T>::isLeaf(int k){
    return 2*k+2>n-1;
}

template <typename T>
void Heap<T>::show() {
    using namespace std;
    cout <<"\n" "\n";
    for_each(elements.begin(), elements.end(), [](auto& a){ Print(a); });
    cout <<"\n" "\n";
    int m = 2;

    cout << elements[0]<< "\n";
    for (int i = 1; i < n; i++)
        if (i <= m) {
            Print(elements[i]);
        } else {
            m = 2*m +2;
            cout << "\n";
            Print(elements[i]);
        }
}

template <typename T>
int Heap<T>::getParent(int k){
    return (k-1)/2;
}
template <typename T>
int Heap<T>::getLeftChild(int k){
    return 2*k+1;
}
template <typename T>
int Heap<T>::getRightChild(int k){
    return 2*k+2;
}
template <typename T>
void Heap<T>::swap(int parentId, int childId){
    std::swap(elements[parentId], elements[childId]);
}

