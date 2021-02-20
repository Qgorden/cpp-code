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
    for(i=0; i < count - 1; i++) 
    {
        num = count - i - 1;
        q=_L->next;
        p=q->next;
        tail=_L;
        while(num--)
        {
            if(q->_data.totalcount < p->_data.totalcount)
            {
                q->next=p->next;
                p->next=q;
                tail->next=p;
            }
            tail = tail->next;
            q=tail->next;
            p=q->next;
        }
    }
    _L=_L->next;
    return _L;
}
