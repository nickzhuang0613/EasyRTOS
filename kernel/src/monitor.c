#include "os-interface.h"

#if __MONITOR_ENABLE

static pt_monitor monitor_head    = monitor_null;    //����������ͷ��
static pt_monitor monitor_tail    = monitor_null;    //����������ͷ��

/*
 * �������� �� ����������
 * �������� �� monitor   -> ������ʵ��
 *             maxtime   -> ��������ʱʱ�䣬��λ��ϵͳ����ʱ�䣬Ҳ�����ǽ��ķ�Ƶ���û��Զ���
 *             monitor_cmd -> �������Ƿ�����
 *             callback  -> ��ʱ�ص��¼�������
 * �������� �� ��ǰ����������λ��
 */
pt_monitor create_monitor(pt_monitor monitor,unsigned int maxtime,monitor_ctl monitor_cmd,monitorCB callback)
{
    monitor->ctl = monitor_cmd;
    monitor->current_ts   = 0;
    monitor->max_ts   = maxtime;
    monitor->status  = init;
    monitor->monitorCallBack = callback;
    //�������������������
    if(Endmonitor == monitor_null) {
        monitor_head = monitor;
        monitor->next = monitor_null;
    } else {
        monitor_tail->next = monitor;
        monitor->next = monitor_null;
    }
    monitor_tail = monitor;
    return monitor_tail;
}

/*
 * �������� �� ����������
 * �������� �� monitor   -> ��Ҫ�����ļ�����
 * �������� �� ��
 */
void monitor_start(pt_monitor monitor)
{
    if(monitor == monitor_null) {
        return;
    }
    monitor->ctl = enable;
    monitor->current_ts   = 0;
    monitor->status  = init;
}

/*
 * �������� �� ֹͣ������
 * �������� �� monitor   -> ��Ҫֹͣ�ļ�����
 * �������� �� ��
 */
void monitor_stop(pt_monitor monitor)
{
    if(monitor == monitor_null) {
        return;
    }
    monitor->ctl = disable;
    monitor->current_ts   = 0;
    monitor->status  = init;
}


/*
 * �������� �� ���¼�����
 * �������� �� monitor   -> ��Ҫֹͣ�ļ�����
 * �������� �� ��
 */
void monitor_update(pt_monitor monitor)
{
    if(monitor == monitor_null) {
        return;
    }
    monitor->status = update;
}


/*
 * �������� �� ������������״̬
 * �������� �� monitor   -> ��Ҫ���ļ�����
 * �������� �� 1 ->  ����
 *             0 ->  ֹͣ
 */
unsigned char is_monitor_run(pt_monitor monitor) 
{
    if(monitor == monitor_null) {
        return false;
    }
    return monitor->ctl = enable ? 1 : 0;
}


/*
 * �������� �� ���м���ϵͳ
 * �������� �� ��
 * �������� �� ��
 */
//TODO��ϵͳ�����е���
void monitor_system_run(void)
{
    pt_monitor monitor;
    monitor = monitor_head;
    while(monitor) {
        if(monitor->ctl == enable) {
            if(monitor->status == init) { //����״̬
                monitor->current_ts++;
                if(monitor->current_ts >= monitor->max_ts) {
                   monitor->current_ts = 0;
                   monitor->status = over;
                   (monitor->monitorCallBack)();    //ִ�г�ʱ�ص�����
                }
            } else {
                if(monitor->status == update) {   //����ֵ����
                    monitor->current_ts = 0;
                    monitor->status = 0;
                }
            }
        }
        //˳�������м�����
        monitor = monitor->next;
    }
}

#endif  /* __MONITOR_ENABLE */