/*此题注意前面有空格，中间有多个空格，以及末尾有空格的情况*/
#include <stdio.h>

int main()
{
    char source[128] = " bei jing huan ying nin! ";
    int argc = 0;
    char *argv[16];
    char *str = source;
    
    int i = 0;
    
    /*跳过字符串最前面有空格的情况*/
    while (*str == ' ')
    {
        str++;
    }
    
    argv[i] = str;
    argc++;

    while (*str != '\0')
    {
	if (*str == ' ')
	{  
	  /*跳过中间有多个空格的情况*/
	   while (*str == ' ')
	   {
	       str++;
	   }
           
	   /*检测字符串结束的情况*/
	   if(*str == '\0')
	   {
	       break;
	   }

	   argc++;
       
	   *--str = '\0';
          
	   argv[++i] = ++str;

	   continue;
	}

	str++;
    }

   printf("argc is %d\n", argc);

   for (i = 0; i < argc; i++)
   {
       printf("argv[%d] is: %s\n", i, argv[i]);
   }

   return 0;
}
