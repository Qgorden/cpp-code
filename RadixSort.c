
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
SDataType A[10010];
int maxd(SDataType v[],int n)
{
    int d=1;
    int m=1;
    for (int i=0; i<n; i++)
    {
        while (v[i].totalcount/m!=0)
        {
            m*=10;
            d++;
        }
    }
    return d-1;
}

void radix_sort(SDataType v[],int n)
{
    int d=maxd(v,n);
    int p=1;
    SDataType mv[12][2000];
    for(int i=0; i<=9; i++)
        mv[i][0].totalcount=1;
    while (d--)
    {
        for (int i=0; i<n; i++)
        {
            int t=((v[i].totalcount/p)%10);
            mv[t][mv[t][0].totalcount++]=v[i];
        }
        int s=0;
        for (int i=0; i<=9; i++)
        {
            for (int t=1; t<mv[i][0].totalcount; t++)
            {
                v[s++]=mv[i][t];
            }
            mv[i][0].totalcount=1;
        }
        p*=10;
    }
}
struct SListNode* RadixSort(H * L)
{
    H*_L=L;
    int n=0;
    while(_L!=NULL)
    {
        A[n++]=_L->_data;
        _L=_L->next;
    }
    radix_sort(A,n);
    _L=L;
    for(int i=n-1; i>=0; i--)
    {
        _L->_data=A[i];
        _L=_L->next;
    }
    return L;
}

