# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "main.c"



struct dept;

struct employee
{
    char name[32];
    unsigned int emp_id;
    struct dept* pDept;
};

int main()
{

}

struct dept
{
    int id;
    char name[10];
};
