#include<iostream>

#include"rena/renaapa.h"

int main(){
    rena::lint ln_p1( LN( 73786976294838206464 ) );
    rena::lint ln_p2( LN( 73786976294838206463 ) );
    rena::lint ln_p3( 1024 );
    rena::lint ln_z;
    rena::lint ln_n1( LN( -73786976294838206464 ) );
    rena::lint ln_n2( LN( -73786976294838206463 ) );
    rena::lint ln_n3( -4096 );

    if ( !( ln_p1 > ln_p2 ) )
    {
        std::cout << "1" << std::endl;
        return 1;
    }

    if ( !( ln_p1 > ln_p3 ) )
    {
        std::cout << "2" << std::endl;
        return 1;
    }

    if ( !( ln_p1 > ln_z ) )
    {
        std::cout << "3" << std::endl;
        return 1;
    }

    if ( !( ln_n1 < ln_p1 ) )
    {
        std::cout << "4" << std::endl;
        return 1;
    }

    if ( !( ln_n1 < ln_n2 ) )
    {
        std::cout << "5" << std::endl;
        return 1;
    }

    if ( !( ln_z > ln_n3 ) )
    {
        std::cout << "6" << std::endl;
        return 1;
    }

    if ( !( ln_p1 == ln_n1.abs() ) )
    {
        std::cout << "7" << std::endl;
        return 1;
    }

    return 0;
}
