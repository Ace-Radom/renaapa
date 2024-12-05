#include"rena/renaapa.h"
#include"rena/renaapa_errcodes.h"
#include"rena/renaapa_exceptions.h"

#include<cassert>
#include<cctype>
#include<cmath>
#include<limits>
#include<regex>
#include<sstream>

#include"builtin/safe_arith.h"

rena::lint::lint(){
    this -> _b_is_positiv = true;
    this -> _v_digits.clear();
    this -> _v_digits.push_back( digit( 0 ) );
    return;
}

rena::lint::lint( long long __ll_v ){
    if ( __ll_v == std::numeric_limits<long long>().min() )
    {
        this -> _b_is_positiv = false;
        long long ll_max = std::numeric_limits<long long>().max();
        this -> _v_digits.clear();
        do {
            this -> _v_digits.push_back( digit( ll_max % 10 ) );
            ll_max /= 10;
        } while ( ll_max > 0 );
        this -> _v_digits[0]++;
        return;
    } // handle long long min
    // long long min's abs value is out of range of long long max

    this -> _b_is_positiv = ( __ll_v >= 0 );
    __ll_v = std::abs( __ll_v );
    this -> _v_digits.clear();
    do {
        this -> _v_digits.push_back( digit( __ll_v % 10 ) );
        __ll_v /= 10;
    } while ( __ll_v > 0 );
    return;
}

rena::lint::lint( const std::string& __c_s_v ){
    if ( !( this -> _is_legal_value_str( __c_s_v ) ) )
    {
        throw exceptions::renaapa_illegal_value( RENA_ERR_ILLEGAL_VALUE_STRING , "illegal value string" );
    }
    this -> _parse_set_value_str( __c_s_v );
    return;
}

std::string rena::lint::to_string( bool __b_positiv_with_sign ) const {
    std::ostringstream oss;
    
    if ( __b_positiv_with_sign || !( this -> _b_is_positiv ) )
    {
        oss << ( this -> _b_is_positiv ? '+' : '-' );
    }
    
    for ( auto it = this -> _v_digits.rbegin() ; it != _v_digits.rend() ; ++it )
    {
        oss << *it;
    } // get digits from back to front

    return oss.str();
}

long long rena::lint::to_longlong() const {
    long long out = 0;

    try {
        for ( auto it = this -> _v_digits.rbegin() ; it != _v_digits.rend() ; ++it )
        {
            out = builtin::safe_mul<long long>( out , 10 );
            out = ( this -> _b_is_positiv ) ? builtin::safe_add<long long>( out , it -> value() )
                                            : builtin::safe_sub<long long>( out , it -> value() );
        }
    }
    catch ( exceptions::renaapa_overflow )
    {
        throw exceptions::renaapa_overflow( 
            RENA_ERR_CONVERT_LARGE_NUMBER_TO_SMALLER_TYPE ,
            "cannot convert a large integer out of limitation of long long to it"
        );
    }
    catch ( ... )
    {
        throw;
    }

    return out;
}

std::size_t rena::lint::size() const noexcept {
    return this -> _v_digits.size();
}

bool rena::lint::is_pos() const noexcept {
    return this -> _b_is_positiv;
}

bool rena::lint::is_zero() const noexcept {
    if ( this -> size() == 1 && this -> _v_digits[0] == 0 )
    {
        return true;
    }
    return false;
}

rena::lint rena::lint::abs() const {
    lint ret = *this;
    ret._b_is_positiv = true;
    return ret;
}

bool rena::lint::_is_legal_value_str( const std::string& __c_s_vstr ) const {
    std::regex re( R"(^[+-]?\d+$)" );
    return std::regex_match( __c_s_vstr , re );
}

void rena::lint::_parse_set_value_str( std::string __s_vstr ){
    assert( this -> _is_legal_value_str( __s_vstr ) );

    if ( __s_vstr[0] == '+' || __s_vstr[0] == '-' )
    {
        this -> _b_is_positiv = ( __s_vstr[0] == '+' );
        __s_vstr.erase( 0 , 1 );
    } // vstr with sign
    else
    {
        this -> _b_is_positiv = true;
    } // vstr with no sign

    for ( auto it = __s_vstr.begin() ; it != __s_vstr.end() && *it == '0' ; )
    {
        it = __s_vstr.erase( it );
    } // erase begining zero

    this -> _v_digits.clear();
    if ( __s_vstr.size() == 0 )
    {
        this -> _v_digits.push_back( digit( 0 ) );
        this -> _b_is_positiv = true;
    } // all digits are zero
    else
    {
        for ( auto it = __s_vstr.rbegin() ; it != __s_vstr.rend() ; ++it )
        {
            this -> _v_digits.push_back( digit( *it - '0' ) );
        }
    }

    return;
}
