#ifndef __MONITOR_H__
#define __MONITOR_H__

typedef void(*monitor_callback)(void);

typedef enum {
    zero = 0,
    over,
    update
}monitor_status;

typedef enum {
    disable = 0,
    enable
}monitor_ctl;

#define monitor_null (void *)0

typedef struct
{
    monitor_ctl         ctl;             //0:�ر�  1:����
    monitor_status      status;          //0:��״̬ 1:��� 2:��ֵ����
    unsigned int        max_ts;          //�����ֵ
    unsigned int        current_ts;      //��ǰ����ֵ
    monitor_callback    callback;        //����ص�����
    void                *next;           //�¸�������ָ��
}t_monitor,*pt_monitor;

/*
 * �������� �� ����������
 * �������� �� monitor   -> ������ʵ��
 *             maxtime   -> ��������ʱʱ�䣬��λ��ϵͳ����ʱ�䣬Ҳ�����ǽ��ķ�Ƶ���û��Զ���
 *             monitor_cmd -> �������Ƿ�����
 *             callback  -> ��ʱ�ص��¼�������
 * �������� �� ��ǰ����������λ��
 */
pt_monitor create_monitor(pt_monitor monitor,unsigned int maxtime,monitor_ctl monitor_cmd,monitor_callback callback);
/*
 * �������� �� ����������
 * �������� �� monitor   -> ��Ҫ�����ļ�����
 * �������� �� ��
 */
void monitor_start(pt_monitor monitor);
/*
 * �������� �� ֹͣ������
 * �������� �� monitor   -> ��Ҫֹͣ�ļ�����
 * �������� �� ��
 */
void monitor_stop(pt_monitor monitor);
/*
 * �������� �� ���¼�����
 * �������� �� monitor   -> ��Ҫֹͣ�ļ�����
 * �������� �� ��
 */
void monitor_update(pt_monitor monitor);
/*
 * �������� �� ������������״̬
 * �������� �� monitor   -> ��Ҫ���ļ�����
 * �������� �� 1 ->  ����
 *             0 ->  ֹͣ
 */
unsigned char is_monitor_run(pt_monitor monitor);
/*
 * �������� �� ���м���ϵͳ
 * �������� �� ��
 * �������� �� ��
 */
//TODO��ϵͳ�����е���
void monitor_system_run(void);

#endif  /* __MONITOR_H__ */