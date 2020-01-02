#define A 10

//if A is not defined don't incldue a.h file. 
//This will avoid duplicate inclusion of a.h from a.h and B.h
// #ifndef A  
#include "a.h"
// #endif

#include "b.h"
//#include <stdlib.h>

int main()
{
    //Comment
    int a = square(15);
    int result = min(5,10);

    int finalResult = -1;
    #ifdef A
    finalResult = sum(10,15);
    #else
    finalResult = multiply(10,15);
    #endif
}