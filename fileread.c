#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#define maxn 1010
char Cun[10000][maxn];//储存都出现过的名字
struct SListNode* read()//读取文件内容
{
    FILE *P=fopen("user_login.txt","r");//打开文件
    char S[maxn],_S[maxn];
    H* head=Create();//创建链表
    head=NULL;
    int L=0;
    for(; fscanf(P,"%s",S)==1;)//这里只读取前30个数据
    {
        int s=strlen(S);
        for(int j=0; j<s; j++)//每次只截取逗号前面的自负作为名字
        {
            if(S[j]==',')
            {
                _S[j]='\0';
                break;
            }
            _S[j]=S[j];
        }
//        printf("%s\n",_S);
        int f=0;
        for(int j=0; j<L; j++)//判断该名字是否出现过
        {
            if(!strcmp(_S,Cun[j]))
            {
                f=1;
                break;
            }
        }

        if(!f)//没有出现过直接插入链表
        {
            strcpy(Cun[L],_S);
            L++;
            head=AddtoListNodeTail(head,_S);
        }
        else//出现过则在链表中查找，把数目加一
        {
            head=ADD(head,_S);

        }
    }
    fclose(P);
    return head;
}
//int main()
//{
//
//}
