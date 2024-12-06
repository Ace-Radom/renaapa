#include"builtin/fft.h"

#include<cassert>

void rena::builtin::FFT::calc_FFT( std::vector<complex_num>& __v_data , int flag ){
    assert( flag == DO_DFT || flag == DO_IDFT );

    _inverse_transform( __v_data );

    std::size_t len = __v_data.size();
    for ( std::size_t n = 2 ; n <= len ; n <<= 1 )
    {
        complex_num wn( std::cos( 2 * PI / n ) , std::sin( flag * 2 * PI / n ) );
        for ( std::size_t i = 0 ; i < len ; i += n )
        {
            complex_num w( 1 , 0 );
            for ( std::size_t j = i ; j < i + n / 2 ; j++ )
            {
                complex_num u = __v_data[j];
                complex_num t = w * __v_data[j+n/2];
                __v_data[j] = u + t;
                __v_data[j+n/2] = u - t;
                w = w * wn;
            }
        }
    }

    if ( flag == DO_IDFT )
    {
        for ( std::size_t i = 0 ; i < len ; i++ )
        {
            __v_data[i].d_x /= len;
        }
    }

    return;
}

void rena::builtin::FFT::_inverse_transform( std::vector<complex_num>& __v_data ){
    std::size_t len = __v_data.size();
    assert( _is_power_of_two( len ) );

    for ( std::size_t i = 1 , j = len / 2 ; i < len - 1 ; i++ )
    {
        if ( i < j )
        {
            std::swap( __v_data[i] , __v_data[j] );
        }
        std::size_t step = len / 2;
        while ( j >= step )
        {
            j -= step;
            step /= 2;
        }
        if ( j < step )
        {
            j += step;
        }
    }

    return;
}

bool rena::builtin::FFT::_is_power_of_two( unsigned long long __ull_n ){
    return ( ( __ull_n > 0 ) && ( ( __ull_n & ( __ull_n - 1 ) ) == 0 ) );
}
