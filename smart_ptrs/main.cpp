#include <iostream>
#include <memory.h>
#include "unique_ptr.h"
#include "shared_ptr.h"
#include "share.h"

class Test
{
public:
	int _test;

	explicit Test(int test) : _test(test) {}

};

int main()
{
	std::shared_ptr<Test> ptr = std::make_shared<Test>(4);

	std::shared_ptr<Test> ptr1 = std::make_shared<Test>(3);
	std::shared_ptr<Test> ptr2 = std::make_shared<Test>(3);
	ptr = ptr1;
	ptr2 = ptr1;
	std::cout << ptr.;

	////ptr = ptr2;
	//std::cout << ptr1.use_count();
	//ptr = ptr1;
	////std::cout << ptr->_test;
	////std::cout << ptr1->_test;
	//std::cout << ptr1.use_count();


	/*shared_ptr<Test> pptr(Test(2));
	shared_ptr<Test> pptr1(Test(1));
	std::cout << pptr1.use_count();
	pptr = pptr1;
	std::cout << pptr1.use_count();*/
	/*std::cout << "pptr\t" << pptr->_test;
	std::cout << "pptr1\t" << pptr1->_test;*/

	return 0;
}