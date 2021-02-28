#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
SDataType A[10010];
int partition2(SDataType arr[],int l,int r)
{
    //基准元素设为第一个
    SDataType v = arr[l];
    //i指向基准的下一个元素，j指向最后一个元素
    int i = l+1,j = r;
    while(1)
    {
        while(i <= r && arr[i].totalcount > v.totalcount)
            i++;
        while(j > l && arr[j].totalcount < v.totalcount)
            j--;
            //循环终止条件
        if(i > j)
            break;
        SDataType t = arr[i];
        arr[i] = arr[j];//交换
        arr[j] = t;
        i++;
        j--;
    }
    //将基准元素与arr「j」交换
    SDataType t = arr[l];
    arr[l] = arr[j];
    arr[j] = t;
    //返回基准元素所在位置
    return j;
}
void quick_sort(SDataType arr[],int l,int r)
{
    if(l >= r)
        return;
        //p为快速排序返回的基准的位置
    int p = partition2(arr,l,r);
    //对基准左边的数快速排序
    quick_sort(arr,l,p-1);
    //对基准右边的数进行快速排序
    quick_sort(arr,p+1,r);
}
struct SListNode* Quicksort(H * L)
{
    H*_L=L;
    int n=0;
    while(_L!=NULL)
    {
        A[n++]=_L->_data;
        _L=_L->next;
    }//赋值为数组
    quick_sort(A,0,n-1);//快速排序
    _L=L;
    for(int i=0; i<n; i++)//赋值回链表
    {
        _L->_data=A[i];
        _L=_L->next;
    }
    return L;
}
