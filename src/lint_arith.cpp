#include"rena/renaapa.h"

rena::lint rena::lint_add( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    lint sum;

    const lint* a = ( __c_li_lhs.size() <= __c_li_rhs.size() ) ? &__c_li_lhs : &__c_li_rhs;
    const lint* b = ( __c_li_lhs.size() > __c_li_rhs.size() ) ? &__c_li_lhs : &__c_li_rhs;
    // a is the pointer to the lint with shorter size

    int8_t carry = 0;
    std::size_t i = 0;
    sum._v_digits.clear();
    for ( i = 0 ; i < a -> size() ; i++ )
    {
        int8_t this_digit_a = ( a -> is_pos() ? 1 : -1 ) * static_cast<int8_t>( a -> _v_digits[i].value() );
        int8_t this_digit_b = ( b -> is_pos() ? 1 : -1 ) * static_cast<int8_t>( b -> _v_digits[i].value() );
        int8_t this_digit_sum = this_digit_a + this_digit_b + carry;
        carry = this_digit_sum / 10;
        sum._v_digits.push_back( digit( std::abs( this_digit_sum % 10 ) ) );
    }
    for ( ; i < b -> size() ; i++ )
    {
        int8_t this_digit_a = 0;
        int8_t this_digit_b = ( b -> is_pos() ? 1 : -1 ) * static_cast<int8_t>( b -> _v_digits[i].value() );
        int8_t this_digit_sum = this_digit_a + this_digit_b + carry;
        carry = this_digit_sum / 10;
        sum._v_digits.push_back( digit( std::abs( this_digit_sum % 10 ) ) );
    }
    if ( carry != 0 )
    {
        sum._v_digits.push_back( digit( std::abs( carry ) ) );
    }
    sum._trim_pre_zero();
    // calc all digits

    if ( a -> is_pos() == b -> is_pos() )
    {
        sum._b_is_positiv = a -> is_pos();
    }
    else if ( sum.is_zero() )
    {
        sum._b_is_positiv = true;
    }
    else
    {
        sum._b_is_positiv = ( a -> abs() > b -> abs() ) ? a -> is_pos() : b -> is_pos();
    }
    // handle sum sign

    return sum;
}

rena::lint rena::lint_sub( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    lint rhs = __c_li_rhs;
    rhs._b_is_positiv = !rhs._b_is_positiv;
    return lint_add( __c_li_lhs , rhs );
}

rena::lint& rena::lint::operator++(){
    *this = lint_add( *this , lint( 1 ) );
    return *this;
}

rena::lint rena::lint::operator++( int ){
    lint tmp = *this;
    *this = lint_add( *this , lint( 1 ) );
    return tmp;
}

rena::lint& rena::lint::operator--(){
    *this = lint_sub( *this , lint( 1 ) );
    return *this;
}

rena::lint rena::lint::operator--( int ){
    lint tmp = *this;
    *this = lint_sub( *this , lint( 1 ) );
    return tmp;
}

rena::lint rena::operator+( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    return lint_add( __c_li_lhs , __c_li_rhs );
}

rena::lint rena::operator-( const lint& __c_li_lhs , const lint& __c_li_rhs ){
    return lint_sub( __c_li_lhs , __c_li_rhs );
}
