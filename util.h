#ifndef UTIL_H
#define UTIL_H
#include "data_structures.h"

void printArray(ELEMENT **V, int size);
void insertIndex(ELEMENT **V, int index, HEAP *pHeap);
void Stop();

void decreaseKey(ELEMENT **V, int index, double newKey, HEAP *pHeap);

void UnknownInstructions();
#endif //UTIL_H