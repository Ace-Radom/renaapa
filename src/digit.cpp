#include"rena/renaapa.h"
#include"rena/renaapa_errcodes.h"
#include"rena/renaapa_exceptions.h"

rena::digit::digit( uint8_t __u8i_v ){
    if ( __u8i_v > 9 )
    {
        throw exceptions::renaapa_overflow( RENA_ERR_DIGIT_SET_VALUE_MORE_THAN_ONE_DIGIT , "digit class contains only one digit" );
    }
    this -> _digit = __u8i_v;
    return;
}

uint8_t rena::digit::value() const noexcept {
    return this -> _digit;
}

rena::digit& rena::digit::operator=( uint8_t __u8i_v ){
    if ( __u8i_v > 9 )
    {
        throw exceptions::renaapa_overflow( RENA_ERR_DIGIT_SET_VALUE_MORE_THAN_ONE_DIGIT , "digit class contains only one digit" );
    }
    this -> _digit = __u8i_v;
    return *this;
}

rena::digit& rena::digit::operator=( const rena::digit& __c_di_v ){
    this -> _digit = __c_di_v._digit;
    return *this;
}

rena::digit& rena::digit::operator++(){
    this -> _digit = ( this -> _digit == 9 ) ? 0 : this -> _digit + 1;
    return *this;
}

rena::digit rena::digit::operator++( int ){
    digit tmp = *this;
    this -> _digit = ( this -> _digit == 9 ) ? 0 : this -> _digit + 1;
    return tmp;
}

rena::digit& rena::digit::operator--(){
    this -> _digit = ( this -> _digit == 0 ) ? 9 : this -> _digit - 1;
    return *this;
}

rena::digit rena::digit::operator--( int ){
    digit tmp = *this;
    this -> _digit = ( this -> _digit == 0 ) ? 9 : this -> _digit - 1;
    return tmp;
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
