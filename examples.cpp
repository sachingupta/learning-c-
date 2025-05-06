#include "examples.h" // Include the header file
#include <iostream>
#include <string>
#include <new> // For std::nothrow

using namespace std;

void sumFun() {
  int a, b, sum;
    std::cin >> a;
    std::cin >> b;
    sum = a + b;
    std::cout << sum << std::endl;
}

void arrayExample() {
  int foo [5] = {2, 4, 16, 64, 128};
  for (int i = 0; i < 5; i++) {
    std::cout << foo[i] << std::endl;
  }
}

void stringExample() {
  char myword1[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
  char myword2[] = "Hello";
  std::cout << myword1 << std::endl;
   std::cout << myword2 << std::endl;
}

void pointerExample() {
  int myVar = 25;
  int *myVarPtr = &myVar;
  std::cout << "value: " << myVar << " pt: " << myVarPtr << " ptr-value: " << *myVarPtr << std::endl;
}

void pointerArrayExample() {
  int a[5];
  int * p;
  p = a;  *p = 10;
  p++;  *p = 20;
  p = &a[2];  *p = 30;
  p = a + 3;  *p = 40;
  p = a;  *(p+4) = 50;
  for (int n=0; n<5; n++)
    cout << a[n] << ", ";

  cout << endl;

  for (int n=0; n<5; n++)
    cout << *(a+n) << ", ";

  cout << endl;

  p = a;

    for (int n=0; n<5; n++)
    cout << p[n] << ", ";

  cout << endl;

  for (int n=0; n<5; n++)
    cout << *(p+n) << ", ";

  cout << endl;
}

 void increase (void* data, int psize) {
  if (psize == sizeof(char)) {
    char* pchar;
    pchar = (char*)data;
    ++(*pchar);
  }
  else if(psize == sizeof(int)) {
    int* pint;
    pint = (int*)data;
    ++(*pint);
  }
 }

void voidPointerExample() {
  char a = 'x';
  int b = 16;
  increase(&a, sizeof(a));
  increase(&b, sizeof(b));
  cout << a << ", " << b << endl;
}

void nullPointerExample() {
  int * p = 0;
int * q = nullptr;
}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

void pointerToFunctionExample() {
  int m,n;
  int (*minus)(int,int) = subtraction;

  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout <<n;
}

void dynamicMemoryAllocationExample() {
  int i,n;
  int * p;
  cout << "How many numbers would you like to type? ";
  cin >> n;
  p= new (nothrow) int[n];
  if (p == nullptr)
    cout << "Error: memory could not be allocated";
  else
  {
    for (i=0; i<n; i++)
    {
      cout << "Enter number: ";
      cin >> p[i];
    }
    cout << "You have entered: ";
    for (i=0; i<n; i++)
      cout << p[i] << ", ";
    delete[] p;
  }
}

void printmovie(movies_t movie) {
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}

void DataStructureExample() {
  string mystr;
  movies_t mine, yours;
  mine.title = "Shaktiman";
  mine.year = 1990;

  yours.title = "Shree Krishna";
  yours.year = 2000;

  cout << "My favorite movie is:\n ";
  printmovie (mine);
  cout << "And yours is:\n ";
  printmovie (yours);

  movies_t * pmovie;
  pmovie = &mine;
   cout << "And mines using pointer is:\n ";
  cout << pmovie->title;
  cout << " (" << pmovie->year << ")\n";
}
