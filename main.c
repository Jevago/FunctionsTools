#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <functionstools.h>

int main()
{
    float num[] = { 0.0, 1.0, 2.0, 3.0, 114.0, 5.0, 6.0, 7.0 };
    float num1[] = { 1000.0, 115.0, 228.0, 315.0, 1.0, 0.0, 98.0, 0.110 };
    float *pff = NULL;
    int *pfi = NULL;
    int   idx[] = { 52, 36, 98, 47, 25, 36, 45, 87 };
    int i = 0;
   
    for( i = 0; i < 8; i++ ){
    	printf("( %d, %f )\n", idx[i], num1[i] );
    }

    pff = &num1[0];//&num[0];
    pfi = &idx[0];
    assert( !bubbleSortVectors( 8, &pff, &pfi, 0 ) );

    printf("\n\n******** DESPUES DE ORDENAR **************\n\n");
    for( i = 0; i < 8; i++ ){
    	printf("( %d, %f )\n", idx[i], num1[i] );
    }

    printf("Hello world!\n");
    return 0;
}
