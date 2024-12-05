#include"rena/renaapa.h"

bool rena::operator>( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    if ( __c_li_lhs.is_pos() != __c_li_rhs.is_pos() )
    {
        return __c_li_lhs.is_pos();
    } // ab < 0

    if ( __c_li_lhs.size() > __c_li_rhs.size() )
    {
        return __c_li_lhs.is_pos();
    }
    else if ( __c_li_lhs.size() < __c_li_rhs.size() )
    {
        return !__c_li_lhs.is_pos();
    }
    else
    {
        for ( std::size_t i = __c_li_lhs.size() - 1 ; i >= 0 ; i-- )
        {
            if ( __c_li_lhs._v_digits[i] > __c_li_rhs._v_digits[i] )
            {
                return __c_li_lhs.is_pos();
            }
            else if ( __c_li_lhs._v_digits[i] < __c_li_rhs._v_digits[i] )
            {
                return !__c_li_lhs.is_pos();
            }
        }
    } // same size

    return false;
}

bool rena::operator<( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    if ( __c_li_lhs.is_pos() != __c_li_rhs.is_pos() )
    {
        return !__c_li_lhs.is_pos();
    } // ab < 0

    if ( __c_li_lhs.size() < __c_li_rhs.size() )
    {
        return __c_li_lhs.is_pos();
    }
    else if ( __c_li_lhs.size() > __c_li_rhs.size() )
    {
        return !__c_li_lhs.is_pos();
    }
    else
    {
        for ( std::size_t i = __c_li_lhs.size() - 1 ; i >= 0 ; i-- )
        {
            if ( __c_li_lhs._v_digits[i] < __c_li_rhs._v_digits[i] )
            {
                return __c_li_lhs.is_pos();
            }
            else if ( __c_li_lhs._v_digits[i] > __c_li_rhs._v_digits[i] )
            {
                return !__c_li_lhs.is_pos();
            }
        }
    } // same size

    return false;
}

bool rena::operator>=( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    return ( __c_li_lhs > __c_li_rhs ) || ( __c_li_lhs == __c_li_rhs );
}

bool rena::operator<=( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    return ( __c_li_lhs < __c_li_rhs ) || ( __c_li_lhs == __c_li_rhs );
}

bool rena::operator==( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    if ( ( __c_li_lhs.size() != __c_li_rhs.size() ) || ( __c_li_lhs.is_pos() != __c_li_rhs.is_pos() ) )
    {
        return false;
    }

    for ( std::size_t i = 0 ; i < __c_li_lhs.size() ; i++ )
    {
        if ( __c_li_lhs._v_digits[i] != __c_li_rhs._v_digits[i] )
        {
            return false;
        }
    }

    return true;
}

bool rena::operator!=( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    return !( __c_li_lhs == __c_li_rhs );
}
