#include <stdio.h>
#include <string.h>

int test ()
{
  char str[] = "This is a sample string";
  char * pch;
  pch=strrchr(str,'s');
  if (pch){
  printf ("Last occurence of 's' found at %d \n",pch-str+1);
  }
  return 0;
}
