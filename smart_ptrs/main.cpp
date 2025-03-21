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
	std::unique_ptr<Test> pptrr = std::make_unique<Test>();
	std::shared_ptr<Test> ptr = std::make_shared<Test>(4);
	ptr.reset()

	//std::shared_ptr<Test> ptr1 = std::make_shared<Test>(3);
	//std::shared_ptr<Test> ptr2 = std::make_shared<Test>(3);
	

	int* arr = new int[3] {1, 2, 3};
	int array[3] = {1, 2, 3};
	shared_ptr<int*> pptr1(new int[4] {1,2,3,4});

	/*
	std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
	shared_ptr<Test> pptr2(pptr1);
	std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
	std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
	shared_ptr<Test> pptr3(Test(5));
	std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
	std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
	std::cout << "pptr3 value:\t" << pptr3->_test << "\t\tpptr3 count:\t" << pptr3.use_count() << '\n';
	shared_ptr<Test> pptr4;
	std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
	std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
	std::cout << "pptr3 value:\t" << pptr3->_test << "\t\tpptr3 count:\t" << pptr3.use_count() << '\n';
	std::cout << "pptr4 value:\t" << pptr4->_test << "\t\tpptr4 count:\t" << pptr4.use_count() << '\n';
	pptr4 = pptr3;
	std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
	std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
	std::cout << "pptr3 value:\t" << pptr3->_test << "\t\tpptr3 count:\t" << pptr3.use_count() << '\n';
	std::cout << "pptr4 value:\t" << pptr4->_test << "\t\tpptr4 count:\t" << pptr4.use_count() << '\n';
	pptr3 = pptr2;
	std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
	std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
	std::cout << "pptr3 value:\t" << pptr3->_test << "\t\tpptr3 count:\t" << pptr3.use_count() << '\n';
	std::cout << "pptr4 value:\t" << pptr4->_test << "\t\tpptr4 count:\t" << pptr4.use_count() << '\n';
	pptr2 = std::move(pptr4);
	std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
	std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
	std::cout << "pptr3 value:\t" << pptr3->_test << "\t\tpptr3 count:\t" << pptr3.use_count() << '\n';
	std::cout << "pptr4 value:\t" << pptr4->_test << "\t\tpptr4 count:\t" << pptr4.use_count() << '\n';
	{
		shared_ptr<Test> pptr5(pptr1);
		std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
		std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
		std::cout << "pptr3 value:\t" << pptr3->_test << "\t\tpptr3 count:\t" << pptr3.use_count() << '\n';
		std::cout << "pptr4 value:\t" << pptr4->_test << "\t\tpptr4 count:\t" << pptr4.use_count() << '\n';
		std::cout << "pptr5 value:\t" << pptr5->_test << "\t\tpptr5 count:\t" << pptr5.use_count() << '\n';
		shared_ptr<Test> pptr6 = std::move(pptr1);
		std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
		std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
		std::cout << "pptr3 value:\t" << pptr3->_test << "\t\tpptr3 count:\t" << pptr3.use_count() << '\n';
		std::cout << "pptr4 value:\t" << pptr4->_test << "\t\tpptr4 count:\t" << pptr4.use_count() << '\n';
		std::cout << "pptr5 value:\t" << pptr5->_test << "\t\tpptr5 count:\t" << pptr5.use_count() << '\n';
		std::cout << "pptr6 value:\t" << pptr6->_test << "\t\tpptr6 count:\t" << pptr6.use_count() << '\n';
	}
	
	std::cout << "pptr1 value:\t" << pptr1->_test << "\t\tpptr1 count:\t" << pptr1.use_count() << '\n';
	std::cout << "pptr2 value:\t" << pptr2->_test << "\t\tpptr2 count:\t" << pptr2.use_count() << '\n';
	std::cout << "pptr3 value:\t" << pptr3->_test << "\t\tpptr3 count:\t" << pptr3.use_count() << '\n';
	std::cout << "pptr4 value:\t" << pptr4->_test << "\t\tpptr4 count:\t" << pptr4.use_count() << '\n';*/


	return 0;
}