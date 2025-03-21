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
	shared_ptr<Test> pptr1(Test(2));
	shared_ptr<Test> pptr2(Test(5));
	pptr1 = std::move(pptr2);
	

	return 0;
}