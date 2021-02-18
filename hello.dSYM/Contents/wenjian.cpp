#include<fstream>

#include<iostream>

using namespace std;

#define LENGTH 30
typedef struct User_login{
    char name[LENGTH];//用户名
    int totalcount;//登陆次数

}SDataType;//链表的节点
typedef struct SListNode
{
    SDataType_data;
    struct SListNode*_PNext;

}
Node,*PNode;//封装链表节点和next指针
int main()

{
 ifstream readFile("user_login.txt");

   chartemp[1024] = {0};

   readFile >>temp;           //遇到空格输出停止，空格后的内容无法输出，'\0'是截止符

//可以输出空格，遇到delim符号才截止。 最后一个参数0表示文本框遇到空字符（ASCLL码为32，文本框不可能有空字符）截止符。不加第三个参数0时，表示'\n'为截止符('\n'也是换行符)。如图4所示

   cout << temp<< endl;

   readFile .close();

 

   system("PAUSE");

   return 0;

}