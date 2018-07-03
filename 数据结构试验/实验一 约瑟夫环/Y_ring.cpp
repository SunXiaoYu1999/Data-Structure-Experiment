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
        P->next = P; // ��ʼ��ʱ����һ����
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
        cout <<"�� "<< flg++<<" �����ֵ����� ";
        for(int i = 1; i < m;++i)
            pre = pre->next;
        temp = pre->next;
        cout << temp->no << " ��\n";
        pre->next = temp->next; // ɾ����ǰ�ڵ�
        DATA[flg-2] = temp->no; // ����ڵ�˳���Է������
        delete temp;
    }
    cout <<"���һ�����ֵ��� ";
    cout << pre->no<<" �ţ�\n\n";
    DATA[flg-1] = pre->no;
    delete pre;
}
