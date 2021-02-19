

#ifndef _LIST_H_
#define _LIST_H_
#include "head.h"
struct SListNode* ADD(H* head,char *value);
int DestroyList(H *head);
struct SListNode* AddtoListNodeTail(H *head, char * value);
struct SListNode* RemoveFirstValue(H *head, char *value);
struct SListNode* Create();
#endif

