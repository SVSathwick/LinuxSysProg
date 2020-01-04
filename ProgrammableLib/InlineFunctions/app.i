# 1 "app.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "app.c"
# 1 "a.h" 1


inline int sum(int a, int b) { return a+b; }
# 2 "app.c" 2
# 1 "b.h" 1
# 1 "a.h" 1


inline int sum(int a, int b) { return a+b; }
# 2 "b.h" 2



inline int multiply(int a, int b) { return a*b; }
# 3 "app.c" 2

int main()
{

    int a = square(15);
    int result = 5<10?5:10;

    int finalResult = -1;
    finalResult = sum(10,15);
    finalResult = multiply(10,15);
}
