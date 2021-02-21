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

