#include <iostream>
#include <string>
#include <cstring>
#include <thread>

using namespace std;

class Contact {

public:
   char* iName;
   int iAge;

public:
   Contact( const char* name, int age ) {
	   iName = new char[strlen( name ) + 1];
	   strcpy( iName, name );
	   iAge = age;

	   cout << "Constructing " << iName << endl;
   }

   Contact( const Contact& rhs ) {

      iName = new char[strlen( rhs.iName ) + 1];
      strcpy( iName, rhs.iName );
      iAge = rhs.iAge;

      cout << "Copy constructing " << iName << endl;
   }

   Contact& operator=( const Contact& rhs ) {

      char* tempName = new char[strlen( rhs.iName ) + 1];
      delete[] iName;
      iName = tempName;
      strcpy( iName, rhs.iName );
      iAge = rhs.iAge;

      cout << "Assignment of " << iName << endl;

      return *this;
   }

   Contact(Contact&& other)
   {
	   iAge = other.iAge;
	   iName = other.iName;

	   other.iAge = -1;
	   other.iName = nullptr;

	   cout << "Move copy constructor for " << iName << endl;
   }

   Contact& operator=(Contact&& other)
   {
	   if(this && this != &other)
	   {
		   delete[] iName;

		   iAge = other.iAge;
		   iName = other.iName;
	   }

	   cout << "Move assignment of " << iName << endl;

	   return *this;
   }

   void print()
   {
	   cout << "Name: " << iName << ", Age: " << iAge << endl;
   }

   ~Contact() {
	   cout << "Deleting " << iName << endl;
      delete[] iName;
   }
};



int main() {
	{
		Contact tom("tom", 35);
		tom.print();

		Contact bobby(tom);
		bobby.print();

		Contact dan("Dan", 31);
		dan.print();

		Contact bill("Bill", 30);
		bill.print();

		bill = dan;
		bill.print();

		auto steve = bill;
		steve.print();

		std::unique_ptr<Contact> anshuman(new Contact("Anshuman", 2));
		anshuman->print();

		auto aayu = make_unique<Contact>("Aayu", 2);
		aayu->print();

		aayu = std::move(anshuman);
		aayu->print();

		std::unique_ptr<Contact> naidu(new Contact("Naidu", 67));
		naidu->print();

		unique_ptr<Contact> naidu2(std::move(naidu));
		naidu2->print();

	}

	cout << "END" << endl;
}
