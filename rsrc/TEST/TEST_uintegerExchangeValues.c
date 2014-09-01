#include <stdio.h>
#include <stdlib.h>
#include <functionstools.h>

float min = 0.0, max = 6.0;

int main( int argc, char ** argv )
{
	unsigned int a = 1, b = 3;

	printf("a: %d, b:%d\n", a, b );
	
	if( uintegerExchangeValues( &a, &b ) ){
		errorPrint( 1, "main()", "error en uintegerExchangeValues()" );
		return 1;
	}

	printf("a: %d, b:%d\n", a, b );
	return 0;
}

