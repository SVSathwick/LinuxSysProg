#include "LinkedList.h"

using namespace std;

node::node(int data):iData(data),iNext(nullptr)
{
    //cout << "Creating node [" << data << "]" << endl;
}

node::~node()
{
    //cout << "Destroying node [" << data << "]" << endl;
}

void node::append(int data)
{
    this->iNext = new node(data);
}