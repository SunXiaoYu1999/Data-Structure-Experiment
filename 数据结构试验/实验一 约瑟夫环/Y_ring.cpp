#include<iostream>
#include<stdlib.h>
#include"Y_ring.h"
using std::cout;
using std::cin;
using std::endl;
void Init_List(Y_R &P)
{
    P = new y_r;
    if(P == NULL)
        exit(1);
    else{
        P->no = 1;
        P->next = P; // 初始化时创建一个环
    }
}
void Insert_Elem(Y_R &P, int n)
{
    Y_R temp = NULL;
    for(int i = 2; i <= n; ++i){
        temp = new y_r;
        if(temp == NULL)
            exit(1);
        else{
            temp->no = i;
            temp->next = P->next;
            P->next = temp;
            P = temp;
        }
    }
}
void Dele_Out(Y_R &P,int m,int * &DATA)
{
    Y_R pre = P;
    Y_R temp;
    int flg = 1;
    while(pre->next != pre)
    {
        cout <<"第 "<< flg++<<" 个出局的人是 ";
        for(int i = 1; i < m;++i)
            pre = pre->next;
        temp = pre->next;
        cout << temp->no << " 号\n";
        pre->next = temp->next; // 删除当前节点
        DATA[flg-2] = temp->no; // 保存节点顺序，以方便查找
        delete temp;
    }
    cout <<"最后一个出局的是 ";
    cout << pre->no<<" 号！\n\n";
    DATA[flg-1] = pre->no;
    delete pre;
}
