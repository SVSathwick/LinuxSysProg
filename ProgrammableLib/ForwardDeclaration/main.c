//#include <stdio.h>

/*forward declaration*/
struct  dept;

struct  employee
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