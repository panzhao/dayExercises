#include <stdio.h>

int main(void)
{
    char a[10] = {0,1,2,3,4,5,6,7,8,9};
    short *p = (short *)(a+2);
    short i = *p;
    printf("%x\n", i);
    printf("%p\n", a);
    printf("%p\n", a + 1);

    return 0;
}
