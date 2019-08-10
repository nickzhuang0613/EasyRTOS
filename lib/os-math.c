#include "os-lib.h"

#if __MATH

/*
 * �������� �� ��m��n�η�
 * �������� �� m -> ����
 *             n -> ָ��
 * �������� �� ������
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