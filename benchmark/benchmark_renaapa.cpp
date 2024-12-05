#include<benchmark/benchmark.h>

#include"rena/renaapa.h"
#include"lns.h"

#define ADD_LINT_GOOGLE_BENCHMARK( function_name , operator , dataname , data )     \
    static void _##function_name( benchmark::State& state ){                        \
        rena::lint ln##dataname( data );                                            \
        for ( auto _ : state )                                                      \
        {                                                                           \
            rena::lint sum = operator( ln##dataname , ln##dataname );               \
            benchmark::DoNotOptimize( sum );                                        \
        }                                                                           \
        return;                                                                     \
    }                                                                               \
    BENCHMARK( _##function_name )

ADD_LINT_GOOGLE_BENCHMARK( addition_2exp64 , rena::lint_add , 2exp64 , _2Exp64_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp128 , rena::lint_add , 2exp128 , _2Exp128_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp256 , rena::lint_add , 2exp256 , _2Exp256_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp512 , rena::lint_add , 2exp512 , _2Exp512_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp1024 , rena::lint_add , 2exp1024 , _2Exp1024_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp2048 , rena::lint_add , 2exp2048 , _2Exp2048_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp4096 , rena::lint_add , 2exp4096 , _2Exp4096_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp8192 , rena::lint_add , 2exp8192 , _2Exp8192_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp16384 , rena::lint_add , 2exp16384 , _2Exp16384_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp32768 , rena::lint_add , 2exp32768 , _2Exp32768_ );
ADD_LINT_GOOGLE_BENCHMARK( addition_2exp65536 , rena::lint_add , 2exp65536 , _2Exp65536_ );

BENCHMARK_MAIN();
