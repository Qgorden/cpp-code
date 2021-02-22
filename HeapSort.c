
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


