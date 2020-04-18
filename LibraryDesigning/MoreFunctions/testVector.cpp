//============================================================================
// Name        : HelloWorld2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class Person
{
	int m_id;
	string m_name;
public:
	Person(const Person& rhs) { cout << "copy constructing " << rhs.m_name <<endl; }
	Person(int id, string name): m_id(id), m_name(name){ cout << "Constructing " << this->m_name << endl;}
	~Person() { cout << "Destructing " << this->m_name << endl;}
	void printDetails()
	{
		cout << this->m_id << " " << this->m_name << endl;
	}
};

int main() {

	/*Person* pPerson = new person(1, "sathwick");
	Person* pPerson2 = new person(2, "Sunitha");

	std::list<Person*> people;
	people.push_back(pPerson);
	people.push_back(pPerson2);

	for(auto it: people)
	{
		it->printDetails();
	}*/

	Person sathwick(1, "Sathwick");
	Person sunitha(2, "Sunitha");

	std::vector<Person> people;
	people.push_back(sathwick);
	people.push_back(sunitha);

	for(auto it:people)
	{
		it.printDetails();
	}
	return 0;
}
