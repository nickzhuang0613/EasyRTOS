#include "os-lib.h"

#if __RING

/*
 * �������� �� ��ʼ��������
 * �������� �� in_ring -> ��Ҫ��ʼ���Ļ�����
 * �������� �� ��
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
 * �������� �� ����������
 * �������� �� in_ring -> ��Ҫ�����Ļ�����
 * �������� �� ��
 */
void ring_recover(ring_data *in_ring)
{
    in_ring->ring_end = in_ring->ring_start;
}

/*
 * �������� �� �������������
 * �������� �� out_ring����Ҫ������ݵĻ�����
 *             get_buff��������ݵ��ڴ���
 * �������� �� ��������ǰ����ʼλ��
 */
int ring_out(ring_data *out_ring,char *get_buff)
{
    int end = 0;
    int index = 0;

    //��ȡ���»�õ����ݳ���
    if(out_ring->ring_buff[0]){
        end = out_ring->ring_end+(RING_MAX-out_ring->ring_start);
        out_ring->ring_buff[0] = 0;
    } else {
        end = out_ring->ring_end-out_ring->ring_start;
    }
    
    //��λ��һ��Ԫ��
    out_ring->ring_start+=1;
    if(out_ring->ring_start > RING_MAX)
    {
        out_ring->ring_start = 1;
    }

    //���Ԫ��
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
 * �������� �� �������������
 * �������� �� in_ring����Ҫ�������ݵĻ�����
 *             dat����Ҫ��ŵ�����
 * �������� �� ��������ǰ�Ľ���λ��
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