#ifndef __RING_BUFF_H__
#define __RING_BUFF_H__

struct ring;

#define RING_MAX  512       //缓冲区大小必须大于最大的数据输入长度
#define RIGN_CAP  RING_MAX+1

typedef struct ring{
    short ring_start;
    short ring_end;
    char  ring_buff[RIGN_CAP];    //最低用于溢出标志
    struct ring *next;
    struct ring *pre;
}ring_data,*p_ring_data;


/*
 * 初始化缓冲区
 */
void init_ring(ring_data *in_ring);

/*
 * 重启缓冲区
 */
void ring_recover(ring_data *in_ring);
/*
 * out_ring：需要输出数据的缓冲区
 * get_buff：存放数据的内存区
 */
int ring_out(ring_data *out_ring,char *get_buff);

/*
 * in_ring：存放数据的缓冲区
 * dat：需要存放的数据
 */
int ring_in(ring_data *in_ring,char dat);

#endif /* __RING_BUFF_H__ */