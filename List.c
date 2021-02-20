#include"head.h"
#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SListNode* Create()//链表创建函数
{
    H* head = (H*)malloc(sizeof( H));
    return head;
}
int DestroyList(H *head)//销毁链表函数
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
struct SListNode* AddtoListNodeTail(H* head, char* value)//添加一个节点到链表的末尾
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

struct SListNode* RemoveFirstValue(H *head, char *value)//找到第一个含有某个值的节电并删除该节点
{
    if (head == NULL)
        return head;
    H* RemoveNode = NULL;

    //要是删除的是头节点
    if (!strcmp((head->_data).name,value))
    {
        RemoveNode = head;
        head = head->next;
    }
    //要删除的不是头节点
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
    }
    return head;
}
struct SListNode*  ADD( H* head,char *value)//找到相应的节点，计数加一
{
    H *node = head;
    while (node != NULL && strcmp(node->_data.name,value))
    {
        node = node->next;
    }
    node->_data.totalcount++;
    return head;
}
