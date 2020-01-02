#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <stddef.h>
#include <stdint.h>
#include <list>

using namespace std;

class MemoryBlock
{
public:

   // Simple constructor that initializes the resource.
   explicit MemoryBlock(int length)
      : _length(length)
      , _data(new int[length])
   {
      std::cout << "In MemoryBlock(int). length = "
                << _length << "." << std::endl;
   }

   // Destructor.
   ~MemoryBlock()
   {
      std::cout << "In ~MemoryBlock(). length = "
                << _length << ".";

      if (_data != nullptr)
      {
         std::cout << " Deleting resource.";
         // Delete the resource.
         delete[] _data;
      }

      std::cout << std::endl;
   }

   // Copy constructor.
   MemoryBlock(const MemoryBlock& other)
      : _length(other._length)
      , _data(new int[other._length])
   {
      std::cout << "In MemoryBlock(const MemoryBlock&). length = "
                << other._length << ". Copying resource." << std::endl;

      std::copy(other._data, other._data + _length, _data);
   }

   // Copy assignment operator.
   MemoryBlock& operator=(const MemoryBlock& other)
   {
      std::cout << "In operator=(const MemoryBlock&). length = "
                << other._length << ". Copying resource." << std::endl;

      if (this != &other)
      {
         // Free the existing resource.
         delete[] _data;

         _length = other._length;
         _data = new int[_length];
         std::copy(other._data, other._data + _length, _data);
      }
      return *this;
   }

   // Retrieves the length of the data resource.
   int Length() const
   {
      return _length;
   }

   // Move constructor.
   MemoryBlock(MemoryBlock&& other)
      : _length(0)
   	   ,_data(nullptr)
   {
      std::cout << "In MemoryBlock(MemoryBlock&&). length = "
                << other._length << ". Moving resource." << std::endl;

      // Copy the data pointer and its length from the
      // source object.
      _data = other._data;
      _length = other._length;

      // Release the data pointer from the source object so that
      // the destructor does not free the memory multiple times.
      other._data = nullptr;
      other._length = 0;
   }

   // Move assignment operator.
   MemoryBlock& operator=(MemoryBlock&& other)
   {
      std::cout << "In operator=(MemoryBlock&&). length = "
                << other._length << "." << std::endl;

      if (this != &other)
      {
         // Free the existing resource.
         delete[] _data;

         // Copy the data pointer and its length from the
         // source object.
         _data = other._data;
         _length = other._length;

         // Release the data pointer from the source object so that
         // the destructor does not free the memory multiple times.
         other._data = nullptr;
         other._length = 0;
      }
      return *this;
   }

private:
   int _length; // The length of the resource.
   int* _data; // The resource.
};

int main() {

	bool useVector = false;

	if(useVector) //using vector
	{
		vector<MemoryBlock> v;
		v.push_back(MemoryBlock(25));
		//In MemoryBlock(int). length = 25.   								-->Constructor
		//In MemoryBlock(MemoryBlock&&). length = 25. Moving resource.		-->Move Copy Constructor
		//In ~MemoryBlock(). length = 0.									-->Destructor

		v.push_back(MemoryBlock(75));
		//In MemoryBlock(int). length = 75.									-->Constructor
		//In MemoryBlock(MemoryBlock&&). length = 75. Moving resource.		-->Move Copy Constructor
		//In MemoryBlock(const MemoryBlock&). length = 25. Copying resource.-->Copy Constructor why? use list instead?
		//In ~MemoryBlock(). length = 25. Deleting resource.				-->Destructor
		//In ~MemoryBlock(). length = 0.									-->

		// Insert a new element into the second position of the vector.
		v.insert(v.begin() + 1, MemoryBlock(50));
		/*In MemoryBlock(int). length = 50.
		In MemoryBlock(MemoryBlock&&). length = 50. Moving resource.
		In MemoryBlock(const MemoryBlock&). length = 25. Copying resource.
		In MemoryBlock(const MemoryBlock&). length = 75. Copying resource.
		In ~MemoryBlock(). length = 25. Deleting resource.
		In ~MemoryBlock(). length = 75. Deleting resource.
		In ~MemoryBlock(). length = 0.*/
	}
	else
	{
		list<MemoryBlock> l;
		l.push_back(MemoryBlock(25));
		l.push_back(MemoryBlock(75));

		cout << "List -- END" << endl;
	}

}
