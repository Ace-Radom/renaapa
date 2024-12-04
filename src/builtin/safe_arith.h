#ifndef __RENALIBS_RENAAPA_BUILTIN_SAFE_ARITH_H__
#define __RENALIBS_RENAAPA_BUILTIN_SAFE_ARITH_H__

#include"rena/renaapa_errcodes.h"
#include"rena/renaapa_exceptions.h"

namespace rena::builtin {

    template<typename T>
    T safe_add( T __lhs , T __rhs ){
        T ans = __lhs + __rhs;
        if ( ( __rhs >= 0 && ans < __lhs ) || ( __rhs < 0 && ans > __lhs ) )
        {
            throw exceptions::renaapa_overflow( RENA_ERR_ARITHMETIC_OVERFLOW , "addition overflow" );
        }
        return ans;
    }

    template<typename T>
    T safe_sub( T __lhs , T __rhs ){
        T ans = __lhs - __rhs;
        if ( ( __rhs >= 0 && ans > __lhs ) || ( __rhs < 0 && ans < __lhs ) )
        {
            throw exceptions::renaapa_overflow( RENA_ERR_ARITHMETIC_OVERFLOW , "subtraction overflow" );
        }
        return ans;
    }

    template<typename T>
    T safe_mul( T __lhs , T __rhs ){
        if ( __lhs == 0 || __rhs == 0 )
        {
            return 0;
        }
        T ans = __lhs * __rhs;
        if ( __lhs && ans / __lhs != __rhs )
        {
            throw exceptions::renaapa_overflow( RENA_ERR_ARITHMETIC_OVERFLOW , "multiplication overflow" );
        }
        return ans;
    }

} // namespace rena::builtin

#endif // __RENALIBS_RENAAPA_BUILTIN_SAFE_ARITH_H__
