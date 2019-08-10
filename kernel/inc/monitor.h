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
    monitor_ctl         ctl;             //0:关闭  1:开启
    monitor_status      status;          //0:初状态 1:溢出 2:初值更新
    unsigned int        max_ts;          //溢出阈值
    unsigned int        current_ts;      //当前计数值
    monitor_callback    callback;        //溢出回调函数
    void                *next;           //下个监听器指针
}t_monitor,*pt_monitor;

/*
 * 函数功能 ： 创建监听器
 * 函数参数 ： monitor   -> 监听器实例
 *             maxtime   -> 监听器超时时间，单位是系统节拍时间，也可以是节拍分频，用户自定义
 *             monitor_cmd -> 监听器是否启动
 *             callback  -> 超时回调事件处理函数
 * 函数返回 ： 当前监听器所在位置
 */
pt_monitor create_monitor(pt_monitor monitor,unsigned int maxtime,monitor_ctl monitor_cmd,monitor_callback callback);
/*
 * 函数功能 ： 启动监听器
 * 函数参数 ： monitor   -> 需要启动的监听器
 * 函数返回 ： 无
 */
void monitor_start(pt_monitor monitor);
/*
 * 函数功能 ： 停止监听器
 * 函数参数 ： monitor   -> 需要停止的监听器
 * 函数返回 ： 无
 */
void monitor_stop(pt_monitor monitor);
/*
 * 函数功能 ： 更新监听器
 * 函数参数 ： monitor   -> 需要停止的监听器
 * 函数返回 ： 无
 */
void monitor_update(pt_monitor monitor);
/*
 * 函数功能 ： 检查监听器运行状态
 * 函数参数 ： monitor   -> 需要检查的监听器
 * 函数返回 ： 1 ->  运行
 *             0 ->  停止
 */
unsigned char is_monitor_run(pt_monitor monitor);
/*
 * 函数功能 ： 运行监听系统
 * 函数参数 ： 无
 * 函数返回 ： 无
 */
//TODO在系统节拍中调用
void monitor_system_run(void);

#endif  /* __MONITOR_H__ */