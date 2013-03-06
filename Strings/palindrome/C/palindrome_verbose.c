/*
    James Munns
    Programming Theory
    Palindrome Check
    palindrome_verbose.c
    C
*/

#include <stdio.h>

//Global Defines
#define MAX_STR_SZ ( 100 )

//Prototypes
char determine_palindrome( char * p_str_test, int str_sz );
int get_str_len( char* measure_str );

//Driver
int main( int argc, char *argv[] )
{
//Local Variables
char test_str[ MAX_STR_SZ + 1 ];
int str_sz;

//CLI Parsing
    if( argc < 2 )
    {
        //Prompt the user for input
        printf( "Please Enter String for consideration\nMax Character Length: %d\n>", MAX_STR_SZ );
        fgets( test_str, MAX_STR_SZ, stdin );
    }

    //Size Checking of argument
    str_sz = get_str_len( argv[ 1 ] );

    memcpy( &test_str, argv[ 1 ], ( ( str_sz < MAX_STR_SZ ? str_sz : MAX_STR_SZ ) ) );

    printf( "Result: %s\n", ( determine_palindrome( ( char* )( &test_str ), str_sz ) ? "Yes." : "No. " ) );

    return 0;

}

char determine_palindrome( char * p_str_test, int str_sz )
{
    int i;

    for( i = 0; i < ( str_sz / 2 ); i++ )
    {
        if( p_str_test[ i ] != p_str_test[ ( str_sz - 1) - i ] )
        {
            return 0;
        }
    }

    return 1;
}

int get_str_len( char* measure_str )
{
    int i;

    //Check for bad pointer
    if( measure_str == NULL )
    {
        return 0;
    }

    //Go until string terminator is reached
    for( i = 0; i < MAX_STR_SZ; i++ )
    {
        if( measure_str[ i ] == '\0' )
        {
            break;
        }
    }

    return i;
}