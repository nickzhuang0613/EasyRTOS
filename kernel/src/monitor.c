#include "os-interface.h"

#if __MONITOR_ENABLE

static pt_monitor monitor_head    = monitor_null;    //监听器链表头部
static pt_monitor monitor_tail    = monitor_null;    //监听器链表头部

/*
 * 函数功能 ： 创建监听器
 * 函数参数 ： monitor   -> 监听器实例
 *             maxtime   -> 监听器超时时间，单位是系统节拍时间，也可以是节拍分频，用户自定义
 *             monitor_cmd -> 监听器是否启动
 *             callback  -> 超时回调事件处理函数
 * 函数返回 ： 当前监听器所在位置
 */
pt_monitor create_monitor(pt_monitor monitor,unsigned int maxtime,monitor_ctl monitor_cmd,monitorCB callback)
{
    monitor->ctl = monitor_cmd;
    monitor->current_ts   = 0;
    monitor->max_ts   = maxtime;
    monitor->status  = init;
    monitor->monitorCallBack = callback;
    //监听器接入监听器链表
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
 * 函数功能 ： 启动监听器
 * 函数参数 ： monitor   -> 需要启动的监听器
 * 函数返回 ： 无
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
 * 函数功能 ： 停止监听器
 * 函数参数 ： monitor   -> 需要停止的监听器
 * 函数返回 ： 无
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
 * 函数功能 ： 更新监听器
 * 函数参数 ： monitor   -> 需要停止的监听器
 * 函数返回 ： 无
 */
void monitor_update(pt_monitor monitor)
{
    if(monitor == monitor_null) {
        return;
    }
    monitor->status = update;
}


/*
 * 函数功能 ： 检查监听器运行状态
 * 函数参数 ： monitor   -> 需要检查的监听器
 * 函数返回 ： 1 ->  运行
 *             0 ->  停止
 */
unsigned char is_monitor_run(pt_monitor monitor) 
{
    if(monitor == monitor_null) {
        return false;
    }
    return monitor->ctl = enable ? 1 : 0;
}


/*
 * 函数功能 ： 运行监听系统
 * 函数参数 ： 无
 * 函数返回 ： 无
 */
//TODO在系统节拍中调用
void monitor_system_run(void)
{
    pt_monitor monitor;
    monitor = monitor_head;
    while(monitor) {
        if(monitor->ctl == enable) {
            if(monitor->status == init) { //计数状态
                monitor->current_ts++;
                if(monitor->current_ts >= monitor->max_ts) {
                   monitor->current_ts = 0;
                   monitor->status = over;
                   (monitor->monitorCallBack)();    //执行超时回调函数
                }
            } else {
                if(monitor->status == update) {   //计数值更新
                    monitor->current_ts = 0;
                    monitor->status = 0;
                }
            }
        }
        //顺序检测所有监听器
        monitor = monitor->next;
    }
}

#endif  /* __MONITOR_ENABLE */