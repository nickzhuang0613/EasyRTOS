#ifndef __OS_STRING_H__
#define __OS_STRING_H__

/*
 * �������� �� ��ȡ�ַ�������
 * �������� �� str -> ��Ҫ��ȡ���ȵ��ַ���
 * �������� �� �ַ�������
 */
int os_strlen(const char *str);
/*
 * �������� �� �ַ�����������
 * �������� �� dst -> Ŀ���ַ���
 *             src -> Դ�ַ���
 *             src_len -> ��Ҫ�����ĳ���
 * �������� �� ʵ�ʿ����ĳ��ȣ��������
 */
int os_strcopy(char *dst,int dst_len,const char *src,int src_len);
/*
 * �������� �� �ַ����������
 * �������� �� str -> ��Ҫ������ַ���
 *             len -> �ַ�������
 * �������� �� ������
 */
int os_strclr(char *str,int len);
/*
 * �������� �� �ַ������Ӻ���
 * �������� �� dst -> Ŀ���ַ���
 *             src -> Դ�ַ���
 *             dst_len -> Ŀ���ַ����ĳ���
 * �������� �� ʵ�����ӵĳ��ȣ����ӽ��
 */
int os_strcat(char *dst,char dst_len,const char *src);
/*
 * �������� �� �ַ������Һ���
 * �������� �� sub -> ���ַ���
 *             src -> Դ�ַ���
 * �������� �� ���ҽ��
 */
int os_strstr(const char *src,const char *sub);

#endif /* __OS_STRING_H__ */