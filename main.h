#ifndef MAIN_H
#define MAIN_H
#include "data_structures.h"
#include <string>

void UnknownInstructions();
bool read(const char *inputFile, ELEMENT **&V, HEAP *&pHeap);
void Write(const char *outputFile, ELEMENT **V, int n);
int main(int argc, char *argv[]);
#endif //MAIN_H