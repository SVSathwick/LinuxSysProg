#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> numbers;
    for(int i=0; i<100; i++)
    {
        numbers.push_back(i);
        cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << endl;
    }

    for(const auto& it: numbers)
    {
        cout << it << endl;
    }

    return 0;
}