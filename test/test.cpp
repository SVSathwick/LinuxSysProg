#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    node* head = new node(1);
    head->append(1);

    cout << "nodes in the list: " << endl;
    node* temp = nullptr;
    while(head != nullptr)
    {
        //cout << head->data << endl;        
        temp = head;
        head = head->getNext();
        
        if(temp != nullptr)
        {
            delete temp;
            temp = nullptr;
        }            
    }
}