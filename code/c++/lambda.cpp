
#include <iostream>
using namespace std;



int Operation(int x, int y, int (*function)(int, int, int)) {
	int z = x + y;
	int result = function(x, y, z);
	result *= 10;
	return result;
}

int Operation_stub(int x, int y, int (*function)(int, int, int)) ;



int test_lambda()
{
	int x = 2, y = 4;
	int result1= Operation(x, y, [](int x, int y, int z) {return x * y * z; });	
	int result2 = Operation_stub(x, y, [](int x, int y, int z) {return x * y * z; });
	return 0;
}

