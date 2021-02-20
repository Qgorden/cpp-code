#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include"List.h"
#include"fileread.h"
#include"filewirte.h"
int main()
{
    H *head=read();
    write("result.txt",head);
    return 0;
}
