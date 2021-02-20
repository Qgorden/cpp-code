#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
struct SListNode* BubbleSort(H * L)
{
    H*_L=Create();
    _L->next=L;
    int i,count = 0,num;
    H *p,*q,*tail;
    p = _L;
    while(p->next != NULL)
    {
        count++;
        p = p->next;
    }
    
    return _L;
}
