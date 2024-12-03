#include<iostream>

#include"rena/renaapa.h"

int main(){
    rena::lint ln1;
    if ( ln1.to_string() != "0" )
    {
        std::cout << "1" << std::endl;
        return 1;
    }
    
    rena::lint ln2( 1048576 );
    if ( ln2.to_string( true ) != "+1048576" )
    {
        std::cout << "2" << std::endl;
        return 1;
    }

    rena::lint ln3( LN( -1000000000000000000000000000000000000000 ) );
    if ( ln3.to_string() != "-1000000000000000000000000000000000000000" )
    {
        std::cout << "3" << std::endl;
        return 1;
    }

    rena::lint ln4( LN( 00000000000000000000000000001024 ) );
    if ( ln4.to_string() != "1024" )
    {
        std::cout << "4" << std::endl;
        return 1;
    }

    return 0;
}
