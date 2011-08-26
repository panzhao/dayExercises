/*此题注意前面有空格，中间有多个空格，以及末尾有空格的情况*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char source[128] = " bei          jing huan ying nin! ";
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

	   *str = '\0';
	   str++;

	  /*跳过中间有多个空格的情况*/
	   while (*str == ' ')
	   {
	       str++;
	   }
           
	   //*--str = '\0';
          
	   //str++;

	   /*检测字符串结束的情况*/
	   if(*str == '\0')
	   {
	       break;
	   }

	   argc++;
       
	   argv[++i] = str;

	   continue;
	}

	str++;
    }

   printf("argc is %d\n", argc);

   for (i = 0; i < argc; i++)
   {
       printf("argv[%d] is: %s\n", i, argv[i]);
       printf("%d\n", strlen(argv[i]));
   }
   
   int store_len[100] = {0};

   for (i = 0; i < argc; i++)
   {
       store_len[i] = strlen(argv[i]);
   }
   

   int temp = 0;
   int mark = 0;

   for (i = 0; i < argc; i++)
   {
       if (temp < store_len[i])
       {
           temp = store_len[i];
           mark = i;
       }
   }
   
   int store_low[100];
   
   for (i = 0; i < 100; i++)
   {
       store_low[i] = -1;
   }
   
   int count = 0;

   for (i = 0; i < argc; i++)
   {
       if (temp == store_len[i])
       {
           count++;
	   store_low[i] = i;
       }
   }

   printf("There are %d word are longest,", count);
   
   for (i = 0; i < 100; i++)
   {  
      if (store_low[i] != -1)
      {
          printf("size:%d, word:%s\n", temp, argv[store_low[i]]);
      }
   }

   return 0;
}
