#include "os-lib.h"

#if __MATH

/*
 * 函数功能 ： 求m的n次方
 * 函数参数 ： m -> 底数
 *             n -> 指数
 * 函数返回 ： 计算结果
 */
int os_pow(int m,int n)
{
    u_int result = 1;
    u_int tmp    = m;

    while(n){
        if(n&1){
            result *= tmp;
        }
        tmp *= tmp;
        n >>= 1;
    }

    return result;
}


#endif /* __MATH */