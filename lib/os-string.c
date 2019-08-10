#include "os-lib.h"

#if __RING

/*
 * 函数功能 ： 获取字符串长度
 * 函数参数 ： str -> 需要获取长度的字符串
 * 函数返回 ： 字符串长度
 */
int os_strlen(const char *str)
{
    int ret = 0;
    //str合法且*str不为空
    if(str && *str){
        while(*(str+ret)){
            ret++;
        }
        ret++;
    } else {
        ret = 0;
    }
    return ret;
}

/*
 * 函数功能 ： 字符串拷贝函数
 * 函数参数 ： dst -> 目的字符串
 *             src -> 源字符串
 *             src_len -> 需要拷贝的长度
 * 函数返回 ： 实际拷贝的长度，拷贝结果
 */
int os_strcopy(char *dst,int dst_len,const char *src,int src_len)
{
    int ret = 0;
    if(dst && src){
        if(dst_len < src_len){
            ret = -2;               //目标字符串长度太小
        } else {
            while(*(src+ret)){
                dst[ret] = src[ret];
                ret++;
            }
            dst[ret] = src[ret];   //填充字符串结束标志
        }
    } else {
        ret = -1;                  //操作数地址非法
    }
    return ret;
}

/*
 * 函数功能 ： 字符串清除函数
 * 函数参数 ： str -> 需要清除的字符串
 *             len -> 字符串长度
 * 函数返回 ： 清除结果
 */
int os_strclr(char *str,int len)
{
    int ret = 0;
    
    if(str){
        ret = len-1;
        while(len)
        {
            str[len] = '\0';
            len--;
        }
        str[len] = '\0';
    } else {
        ret = -1;                //操作数非法
    }
    
    return ret;
}

/*
 * 函数功能 ： 字符串连接函数
 * 函数参数 ： dst -> 目的字符串
 *             src -> 源字符串
 *             dst_len -> 目的字符串的长度
 * 函数返回 ： 实际连接的长度，连接结果
 */
int os_strcat(char *dst,char dst_len,const char *src)
{
    int ret = 0;
    int index = 0;
    if(dst && src){
        ret = os_strlen(dst);
        if(dst_len >= ret + os_strlen(src)){
            ret -= 1;
            while(src[index]){
                dst[ret] = src[index];
                ret++;
                index++;
            }
            dst[ret++] = '\0';
        } else {
            ret = -2;                    //目标字符串不够长
        }
    } else {
        ret  = -1;
    }

    return ret;
}

/*
 * 函数功能 ： 字符串查找函数
 * 函数参数 ： sub -> 子字符串
 *             src -> 源字符串
 * 函数返回 ： 查找结果
 */
int os_strstr(const char *src,const char *sub)
{
    int ret = 0;
    int index = 0;
    if(src && sub){
        if((os_strlen(src) < os_strlen(sub))||(os_strlen(sub) <= 0)){
            ret = -2;
        } else {
            while(sub[index] && src[ret]){
                while(sub[index] == src[ret+index]){
                    index++;
                }
                if(sub[index]){
                    index = 0;
                    ret++;
                }
            }
            if(src[ret]){
                ret+=src;
            } else {
                ret = -3;
            }
        }
    } else {
        ret = -1;
    }
    return ret;
}

#endif  /* __RING */