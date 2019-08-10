#ifndef __OS_STRING_H__
#define __OS_STRING_H__

/*
 * 函数功能 ： 获取字符串长度
 * 函数参数 ： str -> 需要获取长度的字符串
 * 函数返回 ： 字符串长度
 */
int os_strlen(const char *str);
/*
 * 函数功能 ： 字符串拷贝函数
 * 函数参数 ： dst -> 目的字符串
 *             src -> 源字符串
 *             src_len -> 需要拷贝的长度
 * 函数返回 ： 实际拷贝的长度，拷贝结果
 */
int os_strcopy(char *dst,int dst_len,const char *src,int src_len);
/*
 * 函数功能 ： 字符串清除函数
 * 函数参数 ： str -> 需要清除的字符串
 *             len -> 字符串长度
 * 函数返回 ： 清除结果
 */
int os_strclr(char *str,int len);
/*
 * 函数功能 ： 字符串连接函数
 * 函数参数 ： dst -> 目的字符串
 *             src -> 源字符串
 *             dst_len -> 目的字符串的长度
 * 函数返回 ： 实际连接的长度，连接结果
 */
int os_strcat(char *dst,char dst_len,const char *src);
/*
 * 函数功能 ： 字符串查找函数
 * 函数参数 ： sub -> 子字符串
 *             src -> 源字符串
 * 函数返回 ： 查找结果
 */
int os_strstr(const char *src,const char *sub);

#endif /* __OS_STRING_H__ */