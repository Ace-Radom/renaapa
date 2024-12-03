#ifndef __RENALIBS_RENAAPA_H__
#define __RENALIBS_RENAAPA_H__

#include<cstdint>
#include<iostream>
#include<string>
#include<vector>

#define LN( str ) ( #str )  // large number

namespace rena {

    class digit {

        public:
            digit( uint8_t __u8i_v = 0 );

            digit& operator=( uint8_t __u8i_v );
            digit& operator=( const digit& __c_di_v );
            friend bool operator>( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend bool operator<( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend bool operator>=( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend bool operator<=( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend bool operator==( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend bool operator!=( const digit& __c_di_lhs , const digit& __c_di_rhs );

            friend int operator+( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend int operator-( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend int operator*( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend int operator/( const digit& __c_di_lhs , const digit& __c_di_rhs );
            friend int operator%( const digit& __c_di_lhs , const digit& __c_di_rhs );
            
            template <class _Elem , class _Traits>
            friend std::basic_ostream<_Elem,_Traits>& operator<<( std::basic_ostream<_Elem,_Traits>& __os , const digit& __c_di_v ){
                __os << static_cast<unsigned int>( __c_di_v._digit );
                return __os;
            }

        private:
            uint8_t _digit;

    }; // class digit

    bool operator>( const digit& __c_di_lhs , const digit& __c_di_rhs );
    bool operator<( const digit& __c_di_lhs , const digit& __c_di_rhs );
    bool operator>=( const digit& __c_di_lhs , const digit& __c_di_rhs );
    bool operator<=( const digit& __c_di_lhs , const digit& __c_di_rhs );
    bool operator==( const digit& __c_di_lhs , const digit& __c_di_rhs );
    bool operator!=( const digit& __c_di_lhs , const digit& __c_di_rhs );

    int operator+( const digit& __c_di_lhs , const digit& __c_di_rhs );
    int operator-( const digit& __c_di_lhs , const digit& __c_di_rhs );
    int operator*( const digit& __c_di_lhs , const digit& __c_di_rhs );
    int operator/( const digit& __c_di_lhs , const digit& __c_di_rhs );
    int operator%( const digit& __c_di_lhs , const digit& __c_di_rhs );

    class lint {

        public:
            lint();
            lint( long long __ll_v );
            lint( const std::string& __c_s_v );
            ~lint(){}

            std::string to_string( bool __b_positiv_with_sign = false ) const;

        private:
            std::vector<digit> _v_digits;
            bool _b_is_positiv;

            virtual bool _is_legal_value_str( const std::string& __c_s_vstr ) const;
            virtual void _parse_set_value_str( std::string __s_vstr );

    }; // class lint

} // namespace rena

#endif // __RENALIBS_RENAAPA_H__
