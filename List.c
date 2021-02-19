#include"head.h"
#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SListNode* Create()
{
    H* head = (H*)malloc(sizeof( H));
    return head;
}
int DestroyList(H *head)
{
    H *p;
    if(head==NULL)
        return 0;
    while(head)
    {
        p=head->next;
        free(head);
        head=p;
    }
    return 1;
}

struct SListNode* AddtoListNodeTail(H* head, char* value)
{
    H* newNode =( H*)malloc(sizeof( H));
    strcpy(newNode->_data.name,value);
    newNode->_data.totalcount=1;
    newNode->next=NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        H* pNode = head;
        while (pNode->next != NULL)
            pNode = pNode->next;
        pNode->next = newNode;
    }
    return head;
}

struct SListNode* RemoveFirstValue(H *head, char *value)
{
    if (head == NULL)
        return head;
    H* RemoveNode = NULL;

    //Ҫɾ������ͷ�ڵ�
    if (!strcmp((head->_data).name,value))
    {
        RemoveNode = head;
        head = head->next;
    }
    //Ҫɾ���Ĳ���ͷ�ڵ�
    else
    {
        H *node = head;
        while (node->next != NULL && strcmp(node->next->_data.name,value))
        {
            node = node->next;
        }
        if (node->next != NULL &&!strcmp(node->next->_data.name,value))
        {
            RemoveNode = node->next;
            node->next = node->next->next;
        }
    }
    if (RemoveNode != NULL)
    {
        free(RemoveNode);
//        return 1;
//        RemoveNode = NULL;
    }
    return head;
}
struct SListNode*  ADD( H* head,char *value)
{
    H *node = head;
    while (node != NULL && strcmp(node->_data.name,value))
    {
        node = node->next;
    }
    node->_data.totalcount++;
    return head;
}
