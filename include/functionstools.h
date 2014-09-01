#ifndef FUNCTIONSTOOLS_H_INCLUDED
#define FUNCTIONSTOOLS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <limits.h>
#include <float.h>

/*********************************************************************************************************************************/

int   DistanceManhattan     ( int x1, int x2, int y1, int y2                             );
float Distance2D            ( float x1, float x2, float y1, float y2                     );
float Distance3D            ( float x1, float x2, float y1, float y2, float z1, float z2 );

/*********************************************************************************************************************************/

int   randomPoint   ( const float xmin, const float xmax, float *point                                                                         );
int   randomPoint2D ( const float xmin, const float xmax, const float ymin, const float ymax, float *point                                     );
int   randomPoint3D ( const float xmin, const float xmax, const float ymin, const float ymax, const float zmin, const float zmax, float *point );
int   randomPointND ( const float *ranges, const unsigned int dimension, float *point                                                          );

/*********************************************************************************************************************************/

int          initializingRandomNum     ( void                                                       );
float        generateRandomFloat       ( const float min, const float max                           );
float        generateNumberBetween0And1 ( void 														);
int          generateRandomInt         ( const int   min, const int   max                           );
int          generateRandomIntNoMax    ( const int   min, const int   max                           );
unsigned int generateRandomUnsignedInt ( const unsigned int   min, const unsigned int   max         );
unsigned int generateRandomUnsignedIntNoMax ( const unsigned int   min, const unsigned int   max    );

/*********************************************************************************************************************************/

int errorPrint ( const unsigned int idError, const char *nameFunc, const char *descrError );

/*********************************************************************************************************************************/

int   		 mypowInt	                      ( int base, unsigned int potencia                                );
float 		 conversionBinary2Float        	  ( char *chromosome, unsigned int longInBitsPerVar, float *ranges );
double 		 conversionBinary2Double       	  ( char *chromosome, unsigned int longInBitsPerVar, float *ranges );
unsigned int conversionBinary2UnsignedInteger ( const unsigned char *bin, const unsigned int size    );
int          conversionBinary2Integer         ( char *bin, const unsigned int longInBitsPerVar );

/*********************************************************************************************************************************/

int uintegerExchangeValues( unsigned int *A, unsigned int *B );

/*********************************************************************************************************************************/

int uintegerMetodoPuntoMedio ( float min, float max, float val );
int uintegerMetodoOctavos( float min, float max, float val );

/*********************************************************************************************************************************/

int bubbleSortVectors ( int size, float **vector, int **index, int typeSort );

/*********************************************************************************************************************************/



#endif // FUNCTIONSTOOLS_H_INCLUDED




