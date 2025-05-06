#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <iostream>
#include <string>

// Function declarations
void sumFun();
void arrayExample();
void stringExample();
void pointerExample();
void pointerArrayExample();
void voidPointerExample();
void nullPointerExample();
int addition (int a, int b);
int subtraction (int a, int b);
int operation (int x, int y, int (*functocall)(int,int));
void pointerToFunctionExample();
void dynamicMemoryAllocationExample();

// Structure declaration
struct movies_t {
  std::string title;
  int year;
};

// Function declaration for struct
void printmovie(movies_t movie);
void DataStructureExample();

#endif // EXAMPLES_H
