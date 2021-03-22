#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"



static PNode table[MAX_BUCKETS];

PNode walloc(const char *str)
{
    PNode p = (PNode)malloc(sizeof(Node));
    if (p != NULL)
    {
        strcpy(p->_data.name, str);
        p->_data.totalcount = 0;
        p->_PNext = 0;
    }
    return p;
}

unsigned long hashstring(const char *str)
{
    unsigned long hash = 0;
    while (*str)
    {
        hash = hash * MULTIPLIER + *str;
        str++;
    }
    return hash % MAX_BUCKETS;
}

PNode lookup(const char *str)
{
    unsigned long hash = hashstring(str);
    PNode wp = table[hash];
    PNode curr = NULL;
 //   printf("%d\n", hash);
    for (curr = wp; curr != NULL; curr = curr->_PNext)
    {
    //    printf("table[%d]= %s,%d\n", hash, curr->_data.name, curr->_data.totalcount);           
        if (strcmp(curr->_data.name, str) == 0)
        {
         
            return curr;
        }        
    }

    /*if not found and create specified*/

    curr = (PNode)malloc(sizeof(Node));
    strcpy(curr->_data.name, str);
    curr->_data.totalcount = 0;
    curr->_PNext = table[hash];
    table[hash] = curr;

 //   printf("table[%d]= %s,%d\n", hash, curr->_data.name, curr->_data.totalcount);
    return curr;
}

void cleartable()
{
    PNode wp = NULL, p = NULL;
    int i = 0;

    for (i = 0; i < MAX_BUCKETS; i++)
    {
        wp = table[i];
        while (wp)
        {
            p = wp;
            wp = wp->_PNext;
            free(p);
        }
    }
}

void file_read_ht()
{
    FILE *fp = fopen("user_login.txt", "r");
    char word[1024]; /*big enough*/
    char *name;
    PNode wp = NULL;
    int i = 0;

    memset(table, 0, sizeof(table));
    /*read from input*/
    int count = 0;
    while (1)
    {
        if (fscanf(fp, "%s", word) != 1)
            break;
        name = strtok(word, ",");
        wp = lookup(name);
        wp->_data.totalcount++;

        count++;
    }
    printf("%d \n", count);
    fclose(fp);
}

void check_totalcounts()
{
    int i;
    int count = 0;
    PNode wp;
    for (i = 0; i < MAX_BUCKETS; i++)
    {
        for (wp = table[i]; wp != NULL; wp = wp->_PNext)
        {
            count += wp->_data.totalcount;
 //           if (wp->_data.totalcount > 100)
            {
             //   printf("%s-->%ld\n", wp->_data.name, wp->_data.totalcount);
                
            }
        }
    }
    printf("%d\n", count);  
}

void searchHT()
{
 

    char name[LENGTH]; 
    printf("Enter name, 'q' to exit：\n");
    scanf("%s", name);    
     
    while (strcmp(name, "q")) {
        unsigned long hash = hashstring(name);
        PNode wp = table[hash];
        PNode curr = NULL;
    //   printf("%d\n", hash);
        for (curr = wp; curr != NULL; curr = curr->_PNext)
        {
        //    printf("table[%d]= %s,%d\n", hash, curr->_data.name, curr->_data.totalcount);           
            if (strcmp(curr->_data.name, name) == 0)
            {
                printf("exist!, %s,%d\n", curr->_data.name, curr->_data.totalcount);
                break ;
            }        
        }
        if (!curr) 
            printf("Not found!\n");        
        scanf("%s", name);
    }
    cleartable(); 
}




