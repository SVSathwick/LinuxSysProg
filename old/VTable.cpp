#include <iostream>
#include <thread>
#include <memory>

using namespace std;


class base
{
public:
	virtual void func1()
	{
		cout << "Base::func1" << endl;
	}
	void func2()
	{
		cout << "Base::func2" << endl;
	}
	virtual ~base()
	{
		cout << "Base::Destructor" << endl;
	}
};

class derived:public base
{
public:
	void func1()
	{
		cout << "Derived::func1" << endl;
	}
	virtual ~derived()
	{
		cout << "Derived::Destructor" << endl;
	}
};

int main() {

	base* pBase = new base();
	pBase->func1();
	pBase->func2();
	delete pBase;

	derived* pDerived = new derived();
	pDerived->func1();
	pDerived->func2();
	delete pDerived;

	unique_ptr<base> spBase = make_unique<base>();
	spBase->func1();

	unique_ptr<derived> spDerived(new derived());
	spDerived->func2();

	unique_ptr<string> pSentence(new string("Hello my name is Venkata Sathwick Sivvala"));
	cout << "Content: " << pSentence->c_str() <<
			", Length: " << pSentence->size() <<
			", Pointer: " << pSentence.get() << endl;
}
