#include"rena/renaapa.h"
#include"rena/renaapa_errcodes.h"
#include"rena/renaapa_exceptions.h"

#include<cassert>
#include<cctype>
#include<cmath>
#include<regex>
#include<sstream>

rena::lint::lint(){
    this -> _b_is_positiv = true;
    this -> _v_digits.clear();
    this -> _v_digits.push_back( digit( 0 ) );
    return;
}

rena::lint::lint( long long __ll_v ){
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
