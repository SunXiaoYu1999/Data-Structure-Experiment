// 使用不带头节点的循环链表来解决约瑟夫环问题

#include <iostream>
#include "Y_ring.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int m, n;
    Y_R P = NULL;
    cout << "请输入参与人数 （n）";
    cin >> n ;
    cout << "请输入淘汰密码 （m）";
    cin >> m;
    cout << "\n\n";
    int *DATA = new int[n];
    Init_List(P);
    Insert_Elem(P,n);
    Dele_Out(P,m,DATA);
    int k;
    cout << "查找第K个出列人的编号\n请输入K = ";
    cin >> k;
    cout << "\n第" << k << "个出局的人的编号为：\t" << DATA[k-1]<<std::endl;
    delete [] DATA;
    return 0;
}
