// ʹ�ò���ͷ�ڵ��ѭ�����������Լɪ������

#include <iostream>
#include "Y_ring.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int m, n;
    Y_R P = NULL;
    cout << "������������� ��n��";
    cin >> n ;
    cout << "��������̭���� ��m��";
    cin >> m;
    cout << "\n\n";
    int *DATA = new int[n];
    Init_List(P);
    Insert_Elem(P,n);
    Dele_Out(P,m,DATA);
    int k;
    cout << "���ҵ�K�������˵ı��\n������K = ";
    cin >> k;
    cout << "\n��" << k << "�����ֵ��˵ı��Ϊ��\t" << DATA[k-1]<<std::endl;
    delete [] DATA;
    return 0;
}
