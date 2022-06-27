#include "macro_redifination.h"

int test_macro1()
{
	int a = 1;
	if (a)
	{
		 printf ("%s\n",__FILENAME__);
	}

 return 0;

}

int test_macro2()
{

	int a = 1;
	if (a)
	{
		 printf ("%d,%f\n",STM0.a,STM0.b);
	}

 return 0;

}