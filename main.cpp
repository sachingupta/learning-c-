// Comment 
//hash sign (#) are directives read and interpreted by what is known as the preprocesso
#include <iostream>
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
  /*
    int foo [3] = { 10, 20, 30 };
    int foo[] = { 10, 20, 30 };
    int foo[] { 10, 20, 30 };
  */
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
  /*
  & is the address-of operator, and can be read simply as "address of"
* is the dereference operator, and can be read as "value pointed to by"
  */
  /*
  int x;
      int *       p1 = &x;  // non-const pointer to non-const int
const int *       p2 = &x;  // non-const pointer to const int
      int * const p3 = &x;  // const pointer to non-const int
const int * const p4 = &x;  // const pointer to const int 
  
  */
  int myVar = 25;
  int *myVarPtr = &myVar;
  std::cout << "value: " << myVar << " pt: " << myVarPtr << " ptr-value: " << *myVarPtr << std::endl;
}

void pointerArrayExample() {
  /*
  a[5] = 0;       // a [offset of 5] = 0
*(a+5) = 0;     // pointed to by (a+5) = 0  
a could be pointer or array
  */
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
  /*
  void pointers are pointers that point to a value that has no type
  One of its possible uses may be to pass generic parameters to a function
  */
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
  /*
   passing a function as an argument to another function
    Pointers to functions are declared with the same syntax as a regular function declaration, except that the name of the function is enclosed between parentheses () and an asterisk (*) is inserted before the name:
  */
  int m,n;
  int (*minus)(int,int) = subtraction;

  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout <<n;
}

void dynamicMemoryAllocationExample() {
  
  /* int * foo;
  // foo = new int [5];  // if allocation fails, an exception is thrown  
  foo = new (nothrow) int [5];

  if (foo == nullptr) {
    // error assigning memory. Take measures.
  } 
  delete pointer; // releases the memory of a single element allocated using new,
delete[] pointer; //releases the memory allocated for arrays of elements using new and a size in brackets ([])
  */
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

struct movies_t {
  string title;
  int year;
} mine, yours;

void printmovie(movies_t movie) {
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}

void DataStructureExample() {
  string mystr;
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

int main() {
    //sumFun();
    // arrayExample();
    // stringExample();
    // pointerExample();
    //pointerArrayExample();
    // voidPointerExample();
    // pointerToFunctionExample();
    //dynamicMemoryAllocationExample();
    DataStructureExample();
}
