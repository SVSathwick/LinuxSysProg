#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "Hello" << endl;

    vector<string> names;
    names.push_back("Sathwick");
    names.push_back("Sunitha");
    names.push_back("Anshuman");

    for(const auto& it: names)
        cout << it << endl;
}