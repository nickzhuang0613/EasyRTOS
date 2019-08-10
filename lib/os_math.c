#include "math.h"

/*
 * 求m的n次方
 * 举例子：
 * 2^13 = 2^4b'1101 = 2^4b'1000 * 2^3b'100 * 2^1b'1
 */
u_int __pow(u_int m,u_int n)
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
