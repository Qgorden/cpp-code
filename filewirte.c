#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
void write(char *S,H *head)//把链表中的数据写入文件
{
    FILE *P=fopen(S,"w");
    H* phead=head;
    while(phead!=NULL)
    {
        fprintf(P,"%s,%d\n",phead->_data.name,phead->_data.totalcount);
        phead=phead->next;
    }
    fclose(P);
    return ;
}

