#include"rena/renaapa.h"
#include"rena/renaapa_errcodes.h"
#include"rena/renaapa_exceptions.h"

rena::digit::digit( uint8_t __u8i_v ){
    if ( __u8i_v > 9 )
    {
        throw exceptions::renaapa_out_of_range( RENA_ERR_DIGIT_SET_VALUE_MORE_THAN_ONE_DIGIT , "digit class contains only one digit" );
    }
    this -> _digit = __u8i_v;
    return;
}

rena::digit& rena::digit::operator=( uint8_t __u8i_v ){
    if ( __u8i_v > 9 )
    {
        throw exceptions::renaapa_out_of_range( RENA_ERR_DIGIT_SET_VALUE_MORE_THAN_ONE_DIGIT , "digit class contains only one digit" );
    }
    this -> _digit = __u8i_v;
    return *this;
}

rena::digit& rena::digit::operator=( const rena::digit& __c_di_v ){
    this -> _digit = __c_di_v._digit;
    return *this;
}

bool rena::operator>( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return __c_di_lhs._digit > __c_di_rhs._digit;
}

bool rena::operator<( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return __c_di_lhs._digit < __c_di_rhs._digit;
}

bool rena::operator>=( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return __c_di_lhs._digit >= __c_di_rhs._digit;
}

bool rena::operator<=( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return __c_di_lhs._digit <= __c_di_rhs._digit;
}

bool rena::operator==( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return __c_di_lhs._digit == __c_di_rhs._digit;
}

bool rena::operator!=( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return __c_di_lhs._digit != __c_di_rhs._digit;
}

int rena::operator+( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return static_cast<int>( __c_di_lhs._digit + __c_di_rhs._digit );
}

int rena::operator-( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return static_cast<int>( __c_di_lhs._digit - __c_di_rhs._digit );
}

int rena::operator*( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return static_cast<int>( __c_di_lhs._digit * __c_di_rhs._digit );
}

int rena::operator/( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return static_cast<int>( __c_di_lhs._digit / __c_di_rhs._digit );
}

int rena::operator%( const rena::digit& __c_di_lhs , const rena::digit& __c_di_rhs ){
    return static_cast<int>( __c_di_lhs._digit % __c_di_rhs._digit );
}
