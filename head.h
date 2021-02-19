#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef _HEAD_H_
#define _HEAD_H_
#define LENGTH 30
typedef struct  User_login
{
    char name[LENGTH];
    int totalcount;
}SDataType;
typedef struct SListNode
{
    struct User_login _data;
    struct  SListNode *next;
}H;
#endif
