#include <stdio.h>
#include <stdlib.h>
#include <functionstools.h>

int main( int argc, char ** argv )
{
	int i = 0;

	initializingRandomNum();
	for( i = 0; i < 100; i++ ) printf( "\n:%d, Num: %f", i, generateNumberBetween0And1() );

	return 0;
}