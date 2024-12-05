#ifndef __RENALIBS_RENAAPA_H__
#define __RENALIBS_RENAAPA_H__

#include<cstdint>
#include<iostream>
#include<string>
#include<vector>

#define LN( str ) ( #str )  // large number

#ifdef _MSC_VER
    #ifdef __RENALIBS_EXPORT__
        #define __RENALIBS_API__ __declspec( dllexport )
    #else
        #define __RENALIBS_API__ __declspec( dllimport )
    #endif //__RENALIBS_EXPORT__
#else
    #define __RENALIBS_API__
#endif // _MSC_VER

namespace rena {

    class digit {

        public:
            __RENALIBS_API__ digit( uint8_t __u8i_v = 0 );
            __RENALIBS_API__ ~digit(){}

            __RENALIBS_API__ uint8_t value() const noexcept;

            __RENALIBS_API__ digit& operator=( uint8_t __u8i_v );
            __RENALIBS_API__ digit& operator=( const digit& __c_di_v );
            __RENALIBS_API__ digit& operator++();
            __RENALIBS_API__ digit operator++( int );
            __RENALIBS_API__ digit& operator--();
            __RENALIBS_API__ digit operator--( int );

            friend inline bool operator>( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return __c_di_lhs._digit > __c_di_rhs._digit; }
            friend inline bool operator<( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return __c_di_lhs._digit < __c_di_rhs._digit; }
            friend inline bool operator>=( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return __c_di_lhs._digit >= __c_di_rhs._digit; }
            friend inline bool operator<=( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return __c_di_lhs._digit <= __c_di_rhs._digit; }
            friend inline bool operator==( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return __c_di_lhs._digit == __c_di_rhs._digit; }
            friend inline bool operator!=( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return __c_di_lhs._digit != __c_di_rhs._digit; }

            friend inline int operator+( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return static_cast<int>( __c_di_lhs._digit + __c_di_rhs._digit ); }
            friend inline int operator-( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return static_cast<int>( __c_di_lhs._digit - __c_di_rhs._digit ); }
            friend inline int operator*( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return static_cast<int>( __c_di_lhs._digit * __c_di_rhs._digit ); }
            friend inline int operator/( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return static_cast<int>( __c_di_lhs._digit / __c_di_rhs._digit ); }
            friend inline int operator%( const digit& __c_di_lhs , const digit& __c_di_rhs ){ return static_cast<int>( __c_di_lhs._digit % __c_di_rhs._digit ); }
            
            template <class _Elem , class _Traits>
            inline friend std::basic_ostream<_Elem,_Traits>& operator<<( std::basic_ostream<_Elem,_Traits>& __os , const digit& __c_di_v ){
                __os << static_cast<unsigned int>( __c_di_v._digit );
                return __os;
            }

        private:
            uint8_t _digit;

    }; // class digit

    class lint {

        public:
            __RENALIBS_API__ lint();
            __RENALIBS_API__ lint( long long __ll_v );
            __RENALIBS_API__ lint( const std::string& __c_s_v );
            __RENALIBS_API__ ~lint(){}

            __RENALIBS_API__ std::string to_string( bool __b_positiv_with_sign = false ) const;
            __RENALIBS_API__ long long to_longlong() const;

            __RENALIBS_API__ std::size_t size() const noexcept;
            __RENALIBS_API__ bool is_pos() const noexcept;
            __RENALIBS_API__ bool is_zero() const noexcept;

            __RENALIBS_API__ lint abs() const;

            friend __RENALIBS_API__ bool operator>( const lint& __c_li_lhs , const lint& __c_li_rhs );
            friend __RENALIBS_API__ bool operator<( const lint& __c_li_lhs , const lint& __c_li_rhs );
            friend __RENALIBS_API__ bool operator>=( const lint& __c_li_lhs , const lint& __c_li_rhs );
            friend __RENALIBS_API__ bool operator<=( const lint& __c_li_lhs , const lint& __c_li_rhs );
            friend __RENALIBS_API__ bool operator==( const lint& __c_li_lhs , const lint& __c_li_rhs );
            friend __RENALIBS_API__ bool operator!=( const lint& __c_li_lhs , const lint& __c_li_rhs );

            friend __RENALIBS_API__ lint lint_add( const lint& __c_li_lhs , const lint& __c_li_rhs );
            friend __RENALIBS_API__ lint lint_sub( const lint& __c_li_lhs , const lint& __c_li_rhs );

            __RENALIBS_API__ lint& operator++();
            __RENALIBS_API__ lint operator++( int );
            __RENALIBS_API__ lint& operator--();
            __RENALIBS_API__ lint operator--( int );

            friend __RENALIBS_API__ lint operator+( const lint& __c_li_lhs , const lint& __c_li_rhs );
            friend __RENALIBS_API__ lint operator-( const lint& __c_li_lhs , const lint& __c_li_rhs );

        private:
            std::vector<digit> _v_digits;
            bool _b_is_positiv;

            virtual bool _is_legal_value_str( const std::string& __c_s_vstr ) const;
            virtual void _parse_set_value_str( std::string __s_vstr );
            void _trim_pre_zero();

    }; // class lint

#ifndef _MSC_VER // avoiding C4273

    bool operator>( const lint& __c_li_lhs , const lint& __c_li_rhs );
    bool operator<( const lint& __c_li_lhs , const lint& __c_li_rhs );
    bool operator>=( const lint& __c_li_lhs , const lint& __c_li_rhs );
    bool operator<=( const lint& __c_li_lhs , const lint& __c_li_rhs );
    bool operator==( const lint& __c_li_lhs , const lint& __c_li_rhs );
    bool operator!=( const lint& __c_li_lhs , const lint& __c_li_rhs );

    lint lint_add( const lint& __c_li_lhs , const lint& __c_li_rhs );
    lint lint_sub( const lint& __c_li_lhs , const lint& __c_li_rhs );

    lint operator+( const lint& __c_li_lhs , const lint& __c_li_rhs );
    lint operator-( const lint& __c_li_lhs , const lint& __c_li_rhs );

#endif // _MSC_VER

} // namespace rena

#endif // __RENALIBS_RENAAPA_H__
