#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
SDataType A[10010];
int partition2(SDataType arr[],int l,int r)
{
    
    SDataType v = arr[l];
    int i = l+1,j = r;
    while(1)
    {
        while(i <= r && arr[i].totalcount > v.totalcount)
            i++;
        while(j > l && arr[j].totalcount < v.totalcount)
            j--;
        if(i > j)
            break;
        SDataType t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++;
        j--;
    }
    SDataType t = arr[l];
    arr[l] = arr[j];
    arr[j] = t;
    return j;
}
void quick_sort(SDataType arr[],int l,int r)
{
    if(l >= r)
        return;
    int p = partition2(arr,l,r);
    quick_sort(arr,l,p-1);
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
    }
    quick_sort(A,0,n-1);
    _L=L;
    for(int i=0; i<n; i++)
    {
        _L->_data=A[i];
        _L=_L->next;
    }
    return L;
}
