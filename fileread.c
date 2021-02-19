#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#define maxn 1010
char Cun[100][maxn];
struct SListNode* read()
{
    FILE *P=fopen("user_login.txt","r");
    char S[maxn],_S[maxn];
    H* head=Create();
    head=NULL;
    int L=0;
    for(int i=0; i<30; i++)
    {
        fscanf(P,"%s",S);
        int s=strlen(S);
        for(int j=0; j<s; j++)
        {
            if(S[j]==',')
            {
                _S[j]='\0';
                break;
            }
            _S[j]=S[j];
        }
        int f=0;
        for(int j=0; j<L; j++)
        {
            if(!strcmp(_S,Cun[j]))
            {
                f=1;
                break;
            }
        }
        printf("%s\n",_S);
        printf("%d\n",f);
        if(!f)
        {
            strcpy(Cun[L],_S);
            L++;
            head=AddtoListNodeTail(head,_S);
        }
        else
        {
            printf("*%s\n",_S);
            head=ADD(head,_S);
            printf("**%s\n",_S);

        }
    }
    fclose(P);
    return head;
}
//int main()
//{
//
//}
