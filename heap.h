#ifndef HEAP_H
#define HEAP_H
#include "data_structures.h"


void printHeap(HEAP *pHeap, ELEMENT **V);
void buildHeap(HEAP *pHeap, ELEMENT **V);
void minHeapify(HEAP *pHeap, ELEMENT **V, int i);
void extractMin(HEAP *pHeap, ELEMENT **V);
void shiftUp(HEAP *pHeap, ELEMENT **V, int i);

#endif //HEAP_H