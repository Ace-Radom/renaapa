#include<iostream>

#include"rena/renaapa.h"

int main(){
    rena::digit d1;
    if ( !( d1 != 1 ) )
    {
        std::cout << "1" << d1 << std::endl;
        return 1;
    }

    rena::digit d2( 5 );
    if ( !( d2 != 4 ) )
    {
        std::cout << "2" << std::endl;
        return 1;
    }

    rena::digit d3;
    d3 = 1;
    if ( !( d3 == 1 ) )
    {
        std::cout << "3" << std::endl;
        return 1;
    }

    rena::digit d4;
    d4 = rena::digit( 6 );
    if ( d4 > 8 || d4 < 6 || d4 >= 7 || d4 <= 5 )
    {
        std::cout << "4" << std::endl;
        return 1;
    }

    rena::digit d5_1 = 5;
    rena::digit d5_2 = 6;
    if ( !( d5_1 + d5_2 == 11 ) || !( d5_1 - d5_2 == -1 ) || !( d5_1 * d5_2 == 30 ) || !( d5_2 / d5_1 == 1 ) || !( d5_2 % d5_1 == 1 ) )
    {
        std::cout << "5" << std::endl;
        return 1;
    }

    return 0;
}
