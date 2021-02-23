
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
SDataType A[10010];
void adjust(SDataType a[], int idx,int size)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    while (left < size)
    {
        int maxc = left;  
        if (right< size&&a[right].totalcount<a[maxc].totalcount)
            maxc = right;
        if (a[idx].totalcount > a[maxc].totalcount)
        {
            SDataType F=a[idx];
            a[idx]=a[maxc];
            a[maxc]=F;
//            swap(a[idx], a[maxc]);
            idx = maxc;
            left = 2 * idx + 1;
            right = 2 * idx + 2;
        }
        else
            break;
    }
}

void heapSort(SDataType a[],int size)
{
    int idx = size / 2 - 1; 
    for (int i = idx; i >= 0; i--)    
    {
        adjust(a,i,size);  
    }

    int swapidx = size-1;  
    for (int i = 0; i < size - 1; i++)
    {
        SDataType F=a[0];
        a[0]= a[swapidx];
        a[swapidx--]=F;
        adjust(a, 0, swapidx+1 ); 
    }

}
struct SListNode* Heapsort(H * L)
{
    H*_L=L;
    int n=0;
    while(_L!=NULL)
    {
        A[n++]=_L->_data;
        _L=_L->next;
    }
    heapSort(A,n);
    _L=L;
    for(int i=0; i<n; i++)
    {
        _L->_data=A[i];
        _L=_L->next;
    }
    return L;
}
