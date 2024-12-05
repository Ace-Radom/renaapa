#include<iostream>

#include"rena/renaapa.h"

int main(){
    rena::lint ln_p1( LN( 73786976294838206464 ) );
    rena::lint ln_p2( LN( 73786976294838206463 ) );
    rena::lint ln_p3( 1024 );
    rena::lint ln_p4( LN( 340282366920938463463374607431768211456 ) );  // 2^128
    rena::lint ln_z;
    rena::lint ln_n1( LN( -73786976294838206464 ) );
    rena::lint ln_n2( LN( -73786976294838206463 ) );
    rena::lint ln_n3( -4096 );
    rena::lint ln_n4( LN( -18446744073709551616 ) );  // 2^64

    if ( !( rena::lint_add( ln_p1 , ln_p2 ) == rena::lint( LN( 147573952589676412927 ) ) ) )
    {
        std::cout << "1" << std::endl;
        return 1;
    }

    if ( !( rena::lint_add( ln_n1 , ln_n2 ) == rena::lint( LN( -147573952589676412927 ) ) ) )
    {
        std::cout << "2" << std::endl;
        return 1;
    }

    if ( !( rena::lint_add( ln_p3 , ln_n3 ) == rena::lint_add( ln_n3 , ln_p3 ) && rena::lint_add( ln_p3 , ln_n3 ) == rena::lint( -3072 ) ) )
    {
        std::cout << "3" << std::endl;
        return 1;
    }

    if ( !( rena::lint_add( ln_p1 , ln_z ) == ln_p1 ) )
    {
        std::cout << "4" << std::endl;
        return 1;
    }

    if ( !( rena::lint_add( ln_n1 , ln_z ) == ln_n1 ) )
    {
        std::cout << "5" << std::endl;
        return 1;
    }

    if ( !rena::lint_add( ln_z , ln_z ).is_zero() )
    {
        std::cout << "6" << std::endl;
        return 1;
    }

    if ( !( rena::lint_sub( ln_n1 , ln_n1 ) == ln_z && rena::lint_sub( ln_n1 , ln_n1 ).is_pos() ) )
    {
        std::cout << "7" << std::endl;
        return 1;
    }

    if ( !( rena::lint_sub( ln_p4 , ln_n4 ) == rena::lint( LN( 340282366920938463481821351505477763072 ) ) ) )
    {
        std::cout << "8" << std::endl;
        return 1;
    }

    if ( !( ++ln_p3 == rena::lint( 1025 ) ) )
    {
        std::cout << "9" << std::endl;
        return 1;
    }

    if ( !( --ln_n3 == rena::lint( -4097 ) ) )
    {
        std::cout << "10" << std::endl;
        return 1;
    }

    return 0;
}
