

#include <vector>
#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

template <typename T>
class Heap {
public:
    std::vector<T> elements;
    int n =0;


    Heap();
    void push(T el);
    auto remove();
    void bubbleDown(int k);
    void bubbleUp(int k);
    bool existLeftChild(int k);
    bool existRightChild(int k);
    bool isLeaf(int k);
    void swap(int parentId, int childId);
    int getParent(int k);
    int getLeftChild(int k);
    int getRightChild(int k);

    void show();
};


#endif //HEAP_HEAP_H
