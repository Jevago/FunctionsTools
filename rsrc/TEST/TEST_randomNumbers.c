#include <stdio.h>
#include <stdlib.h>
#include <functionstools.h>

float min = 0.0, max = 6.0;

int main( int argc, char ** argv )
{
	unsigned int i = 0;
	initializingRandomNum();
	for( i = 0; i < 10000; i++ ){
		printf("i: %u, float: %f\n", i, ( float )rand()/RAND_MAX ); 
		/*printf("\n\tuint: %u\n", generateRandomUnsignedInt( min, max ) );
		printf("\n\tuintNoMax: %u\n", generateRandomUnsignedIntNoMax( min, max ) );
		printf("\n\tint: %d\n", generateRandomInt( (int)min, (int)max  ) );
		intNoMax = generateRandomIntNoMax( (int)min, (int)max  );
		if( intNoMax == (int)max ) printf("***********************\n");
		else printf("\n\tintNoMax: %d\n", intNoMax );*/
	}

	return 0;
}

