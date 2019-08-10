#include "os-lib.h"

#if __RING

/*
 * 函数功能 ： 初始化缓冲区
 * 函数参数 ： in_ring -> 需要初始化的缓冲区
 * 函数返回 ： 无
 */
void init_ring(ring_data *in_ring)
{
    in_ring->ring_end = 0;
    in_ring->ring_start = 0;
    in_ring->next = NULL;
    in_ring->pre = NULL;
    in_ring->ring_buff[0] = '\0';
}

/*
 * 函数功能 ： 重启缓冲区
 * 函数参数 ： in_ring -> 需要重启的缓冲区
 * 函数返回 ： 无
 */
void ring_recover(ring_data *in_ring)
{
    in_ring->ring_end = in_ring->ring_start;
}

/*
 * 函数功能 ： 输出缓冲区数据
 * 函数参数 ： out_ring：需要输出数据的缓冲区
 *             get_buff：存放数据的内存区
 * 函数返回 ： 缓冲区当前的起始位置
 */
int ring_out(ring_data *out_ring,char *get_buff)
{
    int end = 0;
    int index = 0;

    //获取最新获得的数据长度
    if(out_ring->ring_buff[0]){
        end = out_ring->ring_end+(RING_MAX-out_ring->ring_start);
        out_ring->ring_buff[0] = 0;
    } else {
        end = out_ring->ring_end-out_ring->ring_start;
    }
    
    //定位第一个元素
    out_ring->ring_start+=1;
    if(out_ring->ring_start > RING_MAX)
    {
        out_ring->ring_start = 1;
    }

    //输出元素
    while(index < end){
        get_buff[index++] = out_ring->ring_buff[out_ring->ring_start];
        out_ring->ring_start++;
        if(out_ring->ring_start > RING_MAX){
            out_ring->ring_start = 1;
        }
    }
    get_buff[index] = '\0';

    
    out_ring->ring_start = out_ring->ring_end;

    return out_ring->ring_start;
}

/*
 * 函数功能 ： 输出缓冲区数据
 * 函数参数 ： in_ring：需要输入数据的缓冲区
 *             dat：需要存放的数据
 * 函数返回 ： 缓冲区当前的结束位置
 */
int ring_in(ring_data *in_ring,char dat)
{
    in_ring->ring_end++;
    if(in_ring->ring_end > RING_MAX){
        in_ring->ring_buff[0] = 1;
        in_ring->ring_end = 1;
    } else {

    }
    in_ring->ring_buff[in_ring->ring_end] = dat;

    return in_ring->ring_end;
}

#endif  /* __RING */