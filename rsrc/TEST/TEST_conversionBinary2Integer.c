#include <stdio.h>
#include <stdlib.h>
#include <functionstools.h>

int main( int argc, char ** argv )
{
	char bin[] = { 1, 1, 1 , 1, 1, 1 };
	unsigned int size = 6, i = 0;

	printf("\nbin: ");
	for( i = 0; i < size; i++ ){
		printf("%d", bin[i] );
	}
	printf( "\nint: %d\n", conversionBinary2Integer( bin, size ) );
	printf( "\nsize char: %lu\n", sizeof( char ) );
	printf( "\nsize bin: %lu\n", sizeof( bin ) );

	return 0;
}
