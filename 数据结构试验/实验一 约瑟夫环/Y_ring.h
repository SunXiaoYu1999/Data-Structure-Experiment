#ifndef Y_RING_H_INCLUDED
#define Y_RING_H_INCLUDED
typedef struct Y_ring
{
        int no;
        struct Y_ring *next;
} y_r,*Y_R;
void Init_List(Y_R &P);  // ��ʼ������ѭ������
void Insert_Elem(Y_R &P, int n); // ����Ԫ��
void Dele_Out(Y_R &P,int m,int * &DATA);  // ɾ��Ԫ��
#endif // Y_RING_H_INCLUDED
