#include <stdio.h>
#include"string.h"

void *my_memchr(const void *str, int c, int n)
{
    unsigned char *tempstr = str;
    unsigned char counter =0;
    int returnstate = 0;
    if(NULL == tempstr)
    {
        printf("str is Null pointer !");
    }
    else
    {
        for(counter=0; counter < n; counter++)
        {
            if(*tempstr == c)
            {
                returnstate = tempstr;
                break;
            }
            else
            {
                tempstr++;
            }

        }
    }
    return returnstate;
}
int my_memcmp(const void *str1, const void *str2, int n)
{
    unsigned char counter =0;
    unsigned char *tempstr1 = str1;
    unsigned char *tempstr2 = str2;
    int returnstate=0;
    if((NULL == tempstr1) || (NULL == tempstr2))
    {
        printf("str is Null pointer !");
    }
    else
    {
        if(tempstr1 == tempstr2)
        {
            returnstate = 0;
        }
        else
        {
            for(counter=0; counter < n; counter++)
            {
                if(*tempstr1 != *tempstr2)
                {
                    if(*tempstr1 > *tempstr2)
                    {
                        returnstate = 1;
                    }
                    else if(*tempstr1 < *tempstr2)
                    {
                        returnstate = -1;
                    }
                    break;
                }
                else
                {
                    tempstr1++;
                    tempstr2++;
                }

            }
        }
    }
    return returnstate;

}
void *my_memcpy(void *dest, const void * src, int n)
{
    unsigned char *tempdest = dest;
    unsigned char *tempsrc = src;
    unsigned char counter =0;
    // int returnstate = 0;
    if((NULL == tempsrc) || (NULL == tempdest))
    {
        printf("str is Null pointer !");
    }
    else
    {
        for(counter=0; counter < n; counter++)
        {
            *tempdest = *tempsrc;
            tempdest++;
            tempsrc++;
        }
    }
    return dest;
}
void *my_memmove(void *str1, const void *str2, int n)
{
    unsigned char *tempdest = str1;
    unsigned char *tempsrc = str2;
    unsigned char counter =0;
    if((NULL == tempsrc) || (NULL == tempdest))
    {
        printf("str is Null pointer !");
    }
    else
    {
        for(counter=0; counter < n; counter++)
        {
            *tempdest = *tempsrc;
            tempdest++;
            tempsrc++;
        }
    }
    return str1;
}
void *my_memset(void *str, int c, int n)
{
    unsigned char *tempstr = str;
    unsigned char counter =0;
    if(NULL == tempstr)
    {
        printf("str is Null pointer !");
    }
    else
    {
        for(counter=0; counter < n; counter++)
        {
            *tempstr = c;
            tempstr++;
        }
    }
    return str;
}
char *my_strcat(char *dest, const char *src)
{
    int counter =0;
    int length = my_strlen(dest);
    if((NULL == src) || (NULL == dest))
    {
        printf("str is Null pointer !");
    }
    else
    {
        for(counter =0; src[counter]!='\0'; counter++)
        {
            dest[counter+length]=src[counter];
        }
        dest[counter+length]='\0';
    }
    return dest;
}
int my_strlen(const char *str)
{
    char *tempsrc = str;
    int length =0;
    if((NULL == tempsrc))
    {
        printf("str is Null pointer !");
    }
    else
    {
        while (*(tempsrc+length)!=NULL)
        {
            length++;
        }
    }
    return length;
}
char *my_strncat(char *dest, const char *src, int n)
{
    int counter =0;
    int length = my_strlen(dest);
    if((NULL == src) || (NULL == dest))
    {
        printf("str is Null pointer !");
    }
    else
    {
        for(counter =0; counter < n; counter++)
        {
            dest[counter+length]=src[counter];
        }
        dest[counter+length]='\0';
    }
    return dest;
}
char *my_strchr(const char *str, int c)
{
    my_memchr(str,c,my_strlen(str));
}
int my_strcmp(const char *str1, const char *str2)
{
    my_memcmp(str1,str2,my_strlen(str1));
}
int my_strncmp(const char *str1, const char *str2, int n)
{
    my_memcmp(str1,str2,n);
}
int my_strcoll(const char *str1, const char *str2)
{
    my_memcmp(str1,str2,my_strlen(str1));
}
char *my_strcpy(char *dest, const char *src)
{
    my_memcpy(dest,src,my_strlen(src)+1);
}
char *my_strncpy(char *dest, const char *src, int n)
{
    char *tempsrc = src;
    int counter =0;
    if((my_strlen(src) < my_strlen(dest)))
    {
        for(counter =my_strlen(dest)+1; counter <= my_strlen(src); counter++)
        {
            tempsrc[counter]=NULL;
        }
        my_memcpy(dest,src,n);
    }
    else
    {
        my_memcpy(dest,src,n);
    }

}
int my_strcspn(const char *str1, const char *str2)
{
    int counter1 = 0,counter2 =0;
    int str1length = my_strlen(str1);
    int str2length = my_strlen(str2);
    int returnstate =str1length;
    for(counter1 =0; counter1<str1length ; counter1++)
    {
        for(counter2 =0; counter2<str2length ; counter2++)
        {
            if(str2[counter2]==str1[counter1])
            {
                returnstate--;
            }

        }
    }
    return returnstate;
}
char *my_strerror(int errnum)
{
    return strerror(errnum);
}
char *my_strpbrk(const char *str1, const char *str2)
{
    int counter1 = 0,counter2 =0;
    int str1length = my_strlen(str1);
    int str2length = my_strlen(str2);
    char returnstate = 0;
    if((NULL == str1) || (NULL == str2))
    {
        printf("str is Null pointer !");
    }
    else
    {
        for(counter1 =0; counter1<str1length ; counter1++)
        {
            for(counter2 =0; counter2<str2length ; counter2++)
            {
                if(str1[counter1]==str2[counter2])
                {
                    returnstate= str1[counter1];
                    break;
                }
            }
            if(returnstate != 0)
            {
                break;
            }

        }
        return returnstate;

    }
}
char *my_strrchr(const char *str, int c)
{
    unsigned char counter =0;
    int *returnstate = 0;
    if(NULL == str)
    {
        printf("str is Null pointer !");
    }
    else
    {
        for(counter=my_strlen(str); counter >= 0; counter--)
        {
            if(str[counter] == c)
            {
                returnstate = &str[counter];
                break;
            }
        }
    }
    return returnstate;
}
int my_strspn(const char *str1, const char *str2)
{
    int returnstate =0,counter1 =0,counter2 =0;
    for(counter1 = 0;counter1 < my_strlen(str1);counter1++)
    {
        if(str2[0] == str1[counter1])
        {
                returnstate++;
            for(counter2 = 1;counter2 < my_strlen(str2);counter2++)
            {
                 if(str2[counter2] == str1[counter1+counter2])
                    {
                        returnstate++;
                    }
                else
                    {
                        break;
                    }

            }
            if(returnstate>1)
            {
                break;
            }
        }
    }
    return returnstate;
}
char *my_strstr(const char *haystack, const char *needle)
{
    unsigned char *returnstate =NULL;
    int counter1 =0;
    int haystack_len = my_strlen(haystack);
    int needle_len = my_strlen(needle);

    if (needle_len > haystack_len)
    {
        return NULL;
    }
    for(counter1 = 0;counter1 < haystack_len;counter1++)
    {
        if (my_strncmp(&haystack[counter1], needle, needle_len) == 0)
        {
            returnstate = &((char*)haystack)[counter1];
            break;
        }
    }
    return returnstate;
}
char *my_strtok(char *str, const char *delim)
{
    int counter =0;
    int strlength = my_strlen(str);
    for(counter =0;counter<strlength;counter++)
    {
        if(str[counter] == *delim)
        {
            str[counter]='\n';
        }
    }
    return str;
}
int my_strxfrm(char *dest, const char *src, int n)
{
    my_memcpy(dest,src,n);
    return my_strlen(dest);
}



