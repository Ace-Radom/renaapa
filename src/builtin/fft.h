#ifndef __RENALIBS_RENAAPA_BUILTIN_FFT_H__
#define __RENALIBS_RENAAPA_BUILTIN_FFT_H__

#include<cmath>
#include<vector>

#define DO_DFT   1
#define DO_IDFT -1

namespace rena::builtin {

    const double PI = M_PI;

    class complex_num {

        public:
            complex_num( double __d_x , double __d_y ) : d_x( __d_x ) , d_y( __d_y ) {}
            ~complex_num(){}

            friend inline complex_num operator+( const complex_num& __cn_lhs , const complex_num& __cn_rhs ){ 
                return complex_num( __cn_lhs.d_x + __cn_rhs.d_x , __cn_lhs.d_y + __cn_rhs.d_y  );
            }

            friend inline complex_num operator-( const complex_num& __cn_lhs , const complex_num& __cn_rhs ){
                return complex_num( __cn_lhs.d_x - __cn_rhs.d_x , __cn_lhs.d_y - __cn_rhs.d_y  );
            }

            friend inline complex_num operator*( const complex_num& __cn_lhs , const complex_num& __cn_rhs ){
                return complex_num(
                    __cn_lhs.d_x * __cn_rhs.d_x - __cn_lhs.d_y * __cn_rhs.d_y ,
                    __cn_lhs.d_x * __cn_rhs.d_y + __cn_lhs.d_y * __cn_rhs.d_x
                );
            }

            double d_x;
            double d_y;

    }; // class complex_num

    class FFT {

        public:
            static void calc_FFT( std::vector<complex_num>& __v_data , int flag );

        private:
            static void _inverse_transform( std::vector<complex_num>& __v_data );
            static bool _is_power_of_two( unsigned long long __ull_n );

    }; // class FFT

} // namespace rena::builtin

#endif // __RENALIBS_RENAAPA_BUILTIN_FFT_H__
