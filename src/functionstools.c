#include <functionstools.h>

/*********************************************************************************************************************************/

int   DistanceManhattan     ( int x1, int x2, int y1, int y2                             )
{
    return abs( x1 - x2 ) + abs( y1 - y2 );
}

float Distance2D            ( float x1, float x2, float y1, float y2                     )
{
    return (float)sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
}

float    Distance3D              ( float x1, float x2, float y1, float y2, float z1, float z2 )
{
    return (float)sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2) );
}

/*********************************************************************************************************************************/

int   randomPoint   ( const float xmin, const float xmax, float *point                                                                         )
{
    if( !point ){
        errorPrint( 1, "randomPoint()", "variable \"point\" no reservada" );
        return 1;
    }

    *point = generateRandomFloat( xmin, xmax );

    return 0;
}

int   randomPoint2D ( const float xmin, const float xmax, const float ymin, const float ymax, float *point                                     )
{
    if( !point ){
        errorPrint( 1, "randomPoint2D()", "variable \"point\" no reservada" );
        return 1;
    }

    point[0] = generateRandomFloat( xmin, xmax );
    point[1] = generateRandomFloat( ymin, ymax );

    return 0;
}

int   randomPoint3D ( const float xmin, const float xmax, const float ymin, const float ymax, const float zmin, const float zmax, float *point )
{
    if( !point ){
        errorPrint( 1, "randomPoint3D()", "variable \"point\" no reservada" );
        return 1;
    }

    randomPoint2D( xmin, xmax, ymin, ymax, point );
    point[2] = generateRandomFloat( zmin, zmax );
    return 0;
}

int   randomPointND ( const float *ranges, const unsigned int dimension, float *point                                                          )
{
    unsigned int i = 0, idx = 0;
    unsigned int step = 2;

    if( !point ){
        errorPrint( 1, "randomPointND()", "variable \"point\" no reservada" );
        return 1;
    }

    for( i = 0; i < dimension; i++ ){
        idx = i*step;
        printf("\n\trange: ( %f, %f )\n", ranges[ idx ], ranges[ idx + 1 ] );
        point[i] = generateRandomFloat( ranges[ idx ], ranges[ idx + 1 ] );
    }

    return 0;
}

/*********************************************************************************************************************************/

int          initializingRandomNum     ( void                                                       )
{
    static int flagRAND = 0;

    //printf( "\n\nflagRAND: %d", flagRAND );

    if( !flagRAND ){
        srand( time( NULL ) );
        flagRAND += 1;
    }

    return 0;
}

float        generateRandomFloat       ( const float min, const float max                           )
{
    /**
    *   \brief GENERA UN NUMERO FLOTANT ALEATORIO EN EL RANGO DE [ min, max ]
    *
    */

    return ( (float)rand()/RAND_MAX )*( max - min ) + min;
}

float        generateNumberBetween0And1 ( void                                                      )
{
    /**
    *   \brief GENERA UN NUMERO FLOTANT ALEATORIO EN EL RANGO DE [ 0.0, 1.0 ]
    *
    */

    return (float)( rand()/(double)RAND_MAX );
}

int          generateRandomInt         ( const int   min, const int   max                           )
{
    /**
    *   \brief GENERA UN NUMERO ENTERO ALEATORIO EN EL RANGO DE [ min, max ]
    *
    */

    return rand()%( max - min + 1 ) + min;
}

int          generateRandomIntNoMax    ( const int   min, const int   max                           )
{
    /**
    *   \brief GENERA UN NUMERO ENTERO ALEATORIO EN EL RANGO DE [ min, max )
    *
    */

    return rand()%( max - min ) + min;
}

unsigned int generateRandomUnsignedInt ( const unsigned int   min, const unsigned int   max         )
{
    /**
    *   \brief GENERA UN NUMERO ENTERO SI SIGNO ALEATORIO EN EL RANGO DE [ min, max ]
    *
    */

    return ( unsigned int )( rand()%( max - min + 1 ) + min );
}

unsigned int generateRandomUnsignedIntNoMax ( const unsigned int   min, const unsigned int   max    )
{
    /**
    *   \brief GENERA UN NUMERO ENTERO SIN SIGNO ALEATORIO EN EL RANGO DE [ min, max )
    *
    */
    
    return ( unsigned int )( rand()%( max - min ) + min );
}

/*********************************************************************************************************************************/

int errorPrint ( const unsigned int idError, const char *nameFunc, const char *descrError )
{
    printf("\n\n Error %d en %s, %s\n\n", idError, nameFunc, descrError );

    return 0;
}

/*********************************************************************************************************************************/
int          mypowInt                         ( int base, unsigned int potencia                                )
{
    int sum = 1;
    unsigned int i = 0;

    for( i = 0; i < potencia; i++ ){
        sum *= base;
    }

    return sum;
}

float        conversionBinary2Float           ( char *chromosome, unsigned int longInBitsPerVar, float *ranges )
{
    /**
     *  \brief ESTA FUNCION CONVIERTE UNA CADENA BINARIA EN NUMERO FLOTANTE DENTRO DEL RANGO *ranges
     *
     *  \param *chromosome CADENA BINARIA A CONVERTIR.
     *
     *  \param longInBitsPerVar LONGITUD DE LA CADENA BINARIA A CONVERTIR
     *
     *  \param *ranges RANGO EN EL CUAL VA A ESTAR DIFINIDA LA VARIABLE O CROMOSOMA.
     *
     */

    if( !chromosome ){
        errorPrint( 0, "convesionBinary2Float()", "cadena binaria a convertir no valida" );
        return FLT_MAX;     
    }
    if( ( int )longInBitsPerVar < 1 ){
        errorPrint( 1, "convesionBinary2Float()", "tamanio de la cadena binaria no valido" );
        return FLT_MAX;
    }
    if( !ranges ){
        errorPrint( 2, "convesionBinary2Float()", "vector de rangos no valido" );
        return FLT_MAX; 
    }

    unsigned int i = 0, j = 0;
    int sum = 0;
    int aux = 0;
    int nValores = 0;
    float delta = 0.0;

    nValores = mypowInt( 2, longInBitsPerVar );

    for( i = 0; i < longInBitsPerVar; i++ ){
       aux = 1;
       if( chromosome[i] == 1 ){
           for( j = 0; j < longInBitsPerVar - 1 - i ; j++ ){
               aux *= 2;
           }
           sum += aux;
       }
    }

    delta = ( float )( fabs( ranges[1] - ranges[0] )/( float )nValores );

    return ( float )sum*delta;
}

double       conversionBinary2Double          ( char *chromosome, unsigned int longInBitsPerVar, float *ranges )
{
     /**
     *  \brief ESTA FUNCION CONVIERTE UNA CADENA BINARIA EN NUMERO FLOTANTE DENTRO DEL RANGO *ranges
     *
     *  \param *chromosome CADENA BINARIA A CONVERTIR.
     *
     *  \param longInBitsPerVar LONGITUD DE LA CADENA BINARIA A CONVERTIR
     *
     *  \param *ranges RANGO EN EL CUAL VA A ESTAR DIFINIDA LA VARIABLE O CROMOSOMA.
     *
     */

    if( !chromosome ){
        errorPrint( 0, "convesionBinary2Float()", "cadena binaria a convertir no valida" );
        return FLT_MAX;     
    }
    if( ( int )longInBitsPerVar < 1 ){
        errorPrint( 1, "convesionBinary2Float()", "tamanio de la cadena binaria no valido" );
        return FLT_MAX;
    }
    if( !ranges ){
        errorPrint( 2, "convesionBinary2Float()", "vector de rangos no valido" );
        return FLT_MAX; 
    }

    unsigned int i = 0, j = 0;
    int sum = 0;
    int aux = 0;
    int nValores = 0;
    double delta = 0.0;

    nValores = mypowInt( 2, longInBitsPerVar );
    for( i = 0; i < longInBitsPerVar; i++ ){
       aux = 1;
       if( chromosome[i] == 1 ){
           for( j = 0; j < longInBitsPerVar - 1 - i ; j++ ){
               aux *= 2;
           }
           sum += aux;
       }
    }

    delta = ( double )( fabs( ranges[1] - ranges[0] )/( double )nValores );

    return ( double )sum*delta;
}

unsigned int conversionBinary2UnsignedInteger ( const unsigned char *bin, const unsigned int size    )
{
    /**
    * ESTA FUNCION CONVIERTE UNA CADENA BINARIA EN NUMERO ENTERO SIN SIGNO
    *
    */

    unsigned int i = 0, j = 0, sum = 0, aux = 0;

    if( !bin ){
        errorPrint( 1, "conversionBinary2Integer()", "numero binario a convertir inexistente" );
        return UINT_MAX;
    }

    for( i = 0; i < size; i++ ){
        aux = 1;
        if( bin[i] ){
            for( j = 0; j < i ; j++ ){
                aux *= 2;
            }
            sum += aux;
        }
    }
    return sum;
}

int          conversionBinary2Integer         ( char *bin, const unsigned int longInBitsPerVar )
{
    /**
    * \brief ESTA FUNCION CONVIERTE UNA CADENA BINARIA EN NUMERO ENTERO
    *
    * \param
    *
    *
    *
    *
    * \param
    *
    */

    unsigned int i = 0, j = 0;
    int sum = 0, aux = 0;

    if( !bin ){
        errorPrint( 1, "conversionBinary2Integer()", "numero binario a convertir inexistente" );
        return INT_MIN;
    }

    for( i = 0; i < longInBitsPerVar; i++ ){
        aux = 1;
        if( bin[i] == 1 ){
            for( j = 0; j < longInBitsPerVar - 1 - i ; j++ ){
            //for( j = 0; j < i ; j++ ){
                aux *= 2;
            }
            sum += aux;
        }
    }
    return sum;
}

/*********************************************************************************************************************************/

int uintegerExchangeValues( unsigned int *A, unsigned int *B )
{
    unsigned int aux = 0;

    if( !A ){
        errorPrint( 1, "uintegerExchangeValues()", "parametro \"A\" es null" );
        return 1;
    }

    if( !B ){
        errorPrint( 1, "uintegerExchangeValues()", "parametro \"B\" es null" );
        return 1;
    }

    aux = *A;
    *A = *B;
    *B = aux;

    return 0;
}

/*********************************************************************************************************************************/

int uintegerMetodoPuntoMedio ( float min, float max, float val )
{
    float step = 0.0;
    static int flag = 0;
    static int count = 0;

    if( flag ){
        count = 0;
    }
    if( val - 0.01 < min || val + 0.01 > min || val - 0.01 < max || val + 0.01 < max ){
        count += 1;
        flag = 1;
        return count;
    }

    step = ( abs( min ) + abs( max ) )/2.0 ;
    if( val < step ){
        count += uintegerMetodoPuntoMedio( min, step, val );
    }
    else count += uintegerMetodoPuntoMedio( step, max, val );

    return count;
}

int uintegerMetodoOctavos( float min, float max, float val )
{
    return 0;
}

/*********************************************************************************************************************************/

int bubbleSortVectors ( int size, float **vector, int **index, int typeSort )
{
    /**
     * \brief FUNCION PARA ORDENAR DOS VECTORES DE ENTRADA RELACIONADOS
     *
     *  LA FUNCION UTILIZA EL METODO DE LA BURBUJA PARA ORDENAR LOS DOS VECTORES,
     *  UNO DEL TIPO FLOTANTE Y UNO DEL TIPO ENTERO. LOS VECTORES SE ORDENAN CON RESPECTO AL
     *  VALOR DEL VECTOR DE FLOTENTES.
     *
     *
     * \param size CONTIENE EL TAMANIO DE LOS DOS VECTORES A RODENAR
     *
     *  \param **vector CONTIENE EL VECTOR DE VALORES FLOTANTES A ORDENAR
     *
     *  \param **index CONTIENE EL VECTOR DE LOS VALORES ENTEROS A ORDENAR
     *
     *  \param typeSort ES UNA VARIABLE QUE INDICA EN QUE ORDEN SE VAN A ORDENAR LOS VECTORES, SI ES 1
     *                  LOS VECTORES SE ORDENAN DE MAYOR A MENOR Y SI ES 0 SE ORDENAN DE MENOR A MAYOR.
     *
     *  \return LA FUNCION RETORNA UN 1 SI HUBO ALGUN ERROR Y UN MENSAJE DE ERROR ES MOSTRADO EN PANTALLA,
     *          O RETORNA UN 0 SI NO OCURRIO NADA.
     */

    if( !( *vector ) ){
        errorPrint( 1, "bubbleSortVectors()", "vector de flotantes no valido" );
        return 1;
    }

    if( !( *index ) ){
        errorPrint( 2, "bubbleSortVectors()", "vector de enteros no valido" );
        return 1;
    }
    if( size < 1 ){
        errorPrint( 3, "bubbleSortVectors()", "tamanio de los vectores debe ser mayor o igual a 1" );
        return 1;   
    }
    if( typeSort < 0 || typeSort > 1 ){
        errorPrint( 4, "bubbleSortVectors()", "tipo de ordenamiento no valido, los posibles valores son 1 - Mayor a menor, 0 - Menor a Mayor" );
        return 1;   
    }

    int i = 0;
    int j = 0;
    int flag = 0;
    int aux_i = 0;
    float aux_f = 0.0;

    for( i = 0; i < size - 1; i++ ){
        for( j = i + 1; j < size; j++ ){
//            printf("\ni: %d, j: %d, flag: %d\n", i, j, flag );
            if( typeSort ){
                if( ( *vector )[i] < ( *vector )[j] ){
                    flag = 1;
/*
                    aux_i = ( *index  )[i];
                    aux_f = ( *vector )[i];

                    ( *index  )[i] = ( *index  )[j];
                    ( *vector )[i] = ( *vector )[j];

                    ( *index  )[j] = aux_i;
                    ( *vector )[j] = aux_f;
*/
                }
                else  flag = 0;
            }
            else{
                if( ( *vector )[i] > ( *vector )[j] ){
                    flag = 1;
/*                    
                    aux_i = ( *index  )[i];
                    aux_f = ( *vector )[i];

                    ( *index  )[i] = ( *index  )[j];
                    ( *vector )[i] = ( *vector )[j];

                    ( *index  )[j] = aux_i;
                    ( *vector )[j] = aux_f;
*/
                }
                else flag = 0;
            }
            if( flag ){
                aux_i = ( *index  )[i];
                aux_f = ( *vector )[i];

                ( *index  )[i] = ( *index  )[j];
                ( *vector )[i] = ( *vector )[j];

                ( *index  )[j] = aux_i;
                ( *vector )[j] = aux_f;
            }
        }
    }

    return 0;
}














