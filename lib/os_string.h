#ifndef __STRING_STREAM_H__
#define __STRING_STREAM_H__

int str_len(const char *str);
int str_copy(char *dst,int dst_len,const char *src,int src_len);
int str_clr(char *str,int len);
int str_cat(char *dst,char dst_len,const char *src);
int str_str(const char *src,const char *sub);

#endif /* __STRING_STREAM_H__ */