#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int num;
    struct student *next;
}STU;

STU *head1 = NULL;
STU *head2 = NULL;

STU * make_node(num)
{
    STU *temp = (STU *)malloc(sizeof(STU));

    if (NULL == temp)
    {
        printf("malloc failed\n");
	exit(-1);
    }

    temp->num = num;
    temp->next = NULL;

    return temp;
}

int insert_link(STU * node, STU ** temp_head)
{
    if (NULL == node)
    {
        printf("this node is free\n");
	return 0;
    }
    
    node->next = *temp_head;
    *temp_head = node;
    
    return 1;
}

void creat_link1()
{
    int i = 0;
    STU *temp = NULL;

    for (i = 0; i < 10; i++)
    {
       temp = make_node(i);
       insert_link(temp, &head1);
    }
}

void creat_link2()
{
    int i = 0;
    STU *temp = NULL;

    for (i = 10; i < 20; i++)
    {
       temp = make_node(i);
       insert_link(temp, &head2);
    }
}

void traverse(STU * head)
{    
    STU * temp = head;

    while (temp != NULL)
    {
        printf("num %d\n", temp->num);
	temp = temp->next;
    }
}

void digui(STU *head)
{
    if (head->next != NULL)
    { 
        head = head->next;
        digui(head);
	printf("test\n");
    }
    else
    {
        head->next = head2;
    }
}

int main(int argc, const char *argv[])
{
    creat_link1();
    creat_link2();
    
 //   traverse(head1);
   // traverse(head2);
    
    digui(head1);

    traverse(head1);

    return 0;
}
