#include "io_cfg.h"

#if __RING

int str_len(const char *str)
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

int str_copy(char *dst,int dst_len,const char *src,int src_len)
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

int str_clr(char *str,int len)
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

int str_cat(char *dst,char dst_len,const char *src)
{
    int ret = 0;
    int index = 0;
    if(dst && src){
        ret = str_len(dst);
        if(dst_len >= ret + str_len(src)){
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

int str_str(const char *src,const char *sub)
{
    int ret = 0;
    int index = 0;
    if(src && sub){
        if((str_len(src) < str_len(sub))||(str_len(sub) <= 0)){
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