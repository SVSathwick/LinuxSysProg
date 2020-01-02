#define DLL_PUBLIC __attribute__ ((visibility ("default")))

//extern "C" DLL_PUBLIC Node(int a);
class  node
{
private:
    int iData;
    node* iNext;
public:
    DLL_PUBLIC node(int data);
    DLL_PUBLIC ~ node();
    DLL_PUBLIC void append(int data);

    DLL_PUBLIC int getData() { return iData; }
    DLL_PUBLIC node* getNext() { return iNext; }
};