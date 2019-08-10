#include "os-lib.h"

#if __RING

/*
 * �������� �� ��ȡ�ַ�������
 * �������� �� str -> ��Ҫ��ȡ���ȵ��ַ���
 * �������� �� �ַ�������
 */
int os_strlen(const char *str)
{
    int ret = 0;
    //str�Ϸ���*str��Ϊ��
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
 * �������� �� �ַ�����������
 * �������� �� dst -> Ŀ���ַ���
 *             src -> Դ�ַ���
 *             src_len -> ��Ҫ�����ĳ���
 * �������� �� ʵ�ʿ����ĳ��ȣ��������
 */
int os_strcopy(char *dst,int dst_len,const char *src,int src_len)
{
    int ret = 0;
    if(dst && src){
        if(dst_len < src_len){
            ret = -2;               //Ŀ���ַ�������̫С
        } else {
            while(*(src+ret)){
                dst[ret] = src[ret];
                ret++;
            }
            dst[ret] = src[ret];   //����ַ���������־
        }
    } else {
        ret = -1;                  //��������ַ�Ƿ�
    }
    return ret;
}

/*
 * �������� �� �ַ����������
 * �������� �� str -> ��Ҫ������ַ���
 *             len -> �ַ�������
 * �������� �� ������
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
        ret = -1;                //�������Ƿ�
    }
    
    return ret;
}

/*
 * �������� �� �ַ������Ӻ���
 * �������� �� dst -> Ŀ���ַ���
 *             src -> Դ�ַ���
 *             dst_len -> Ŀ���ַ����ĳ���
 * �������� �� ʵ�����ӵĳ��ȣ����ӽ��
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
            ret = -2;                    //Ŀ���ַ���������
        }
    } else {
        ret  = -1;
    }

    return ret;
}

/*
 * �������� �� �ַ������Һ���
 * �������� �� sub -> ���ַ���
 *             src -> Դ�ַ���
 * �������� �� ���ҽ��
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