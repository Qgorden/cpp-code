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
    int i,count = 0,num;//记录链表结点的个数，num进行内部循环
    H *p,*q,*tail;//三个指针，进行冒泡排序
    p = _L;
    while(p->next != NULL)//计算出结点的个数
    {
        count++;//（1）
        p = p->next;
    }
    for(i=0; i < count - 1; i++) //外层循环，跟数组冒泡类似
    {
        num = count - i - 1;//记录内层循环的次数
        q=_L->next;//令q指向第一个结点
        p=q->next;//令p指向后一个结点
        tail=_L;//让tail始终指向q前一个结点，方便交换，也方便进行下一步操作
        while(num--)//内层虚幻 次数和数组冒泡排序一样
        {
            if(q->_data.totalcount < p->_data.totalcount)//该结点的值大于后一个结点，就交换
            {
                q->next=p->next;
                p->next=q;
                tail->next=p;
            }
            tail = tail->next;//（2）
            q=tail->next;
            p=q->next;
        }
    }
    _L=_L->next;
    return _L;
}
