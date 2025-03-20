#include <iostream>
#include <memory.h>
#include "unique_ptr.h"
#include "share.h"

class Test
{
public:
	int _test;

	Test() { std::cout << "\nDefault constructor\t" << _test; }

	explicit Test(int test) : _test(test) { std::cout << "\nParameter constructor\t" << _test; }

	~Test() { std::cout << "\nDestructor"; }
};

int main()
{
	std::unique_ptr<Test> pptr = std::make_unique<Test>(2);
	std::unique_ptr<Test> pptr1 = std::make_unique<Test>(5);
	pptr.swap(pptr1);
	std::cout << "pptr\t" << pptr->_test;
	std::cout << "pptr1\t" << pptr1->_test;
	
	
	//
	//Test* test = new Test(3);
	//pptr.reset(pptr1.get());
	//std::cout << "\ntest\t" << pptr1->_test;
	//std::cout << "\npptr\t" << pptr->_test;
	//if (pptr1.get() == pptr.get()) std::cout << "samesame";
	
	unique_ptr<Test> ptr1(Test(1));
	unique_ptr<Test> ptr2(Test(2));
	ptr1.swap(ptr2);
	std::cout << "ptr1\t" << ptr1->_test;
	std::cout << "ptr2\t" << ptr2->_test;

	return 0;
}