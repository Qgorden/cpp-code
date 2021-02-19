#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
void write(H *head)
{
    FILE *P=fopen("result.txt","w");
    H* phead=head;
    while(phead!=NULL)
    {
        fprintf(P,"%s,%d\n",phead->_data.name,phead->_data.totalcount);
        phead=phead->next;
    }
    fclose(P);
    return ;
}

