#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
#include"filewirte.h"
#include"BubbleSort.h"
#include"QuickSort.h"
#include"RadixSort.h"
int main()
{
    H *head=read();
    write("result.txt",head);
//    head=Quicksort(head);
//     head=Heapsort(head);
    head=RadixSort(head);
//    head=BubbleSort(head);
    write("sort.txt",head);
    return 0;
}
