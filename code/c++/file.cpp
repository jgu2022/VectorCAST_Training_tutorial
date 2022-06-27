#include <stdio.h>
#include <stdbool.h>
_Bool isReadWriteable( const char *filename )
{
  FILE *fp = fopen( filename, "w+" );  
  if ( fp != NULL )                            
  {
    int fc=fclose(fp);   	
	if ( !fc  ) //close successfully, return 0
	{
		return true;
	}
	else
	{
		return false; // close fail ,return EOF (-1)
	}
  }
  else                                         
    return false;
}