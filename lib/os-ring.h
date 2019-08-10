#ifndef __OS_RING_H__
#define __OS_RING_H__

struct ring;

#define RING_MAX  512       //��������С������������������볤��
#define RIGN_CAP  RING_MAX+1

typedef struct ring{
    short ring_start;
    short ring_end;
    char  ring_buff[RIGN_CAP];    //������������־
    struct ring *next;
    struct ring *pre;
}ring_data,*p_ring_data;


/*
 * �������� �� ��ʼ��������
 * �������� �� in_ring -> ��Ҫ��ʼ���Ļ�����
 * �������� �� ��
 */
void init_ring(ring_data *in_ring);
/*
 * �������� �� ����������
 * �������� �� in_ring -> ��Ҫ�����Ļ�����
 * �������� �� ��
 */
void ring_recover(ring_data *in_ring);
/*
 * �������� �� �������������
 * �������� �� out_ring����Ҫ������ݵĻ�����
 *             get_buff��������ݵ��ڴ���
 * �������� �� ��������ǰ����ʼλ��
 */
int ring_out(ring_data *out_ring,char *get_buff);
/*
 * �������� �� �������������
 * �������� �� in_ring����Ҫ�������ݵĻ�����
 *             dat����Ҫ��ŵ�����
 * �������� �� ��������ǰ�Ľ���λ��
 */
int ring_in(ring_data *in_ring,char dat);

#endif /* __OS_RING_H__ */