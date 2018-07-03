#ifndef Y_RING_H_INCLUDED
#define Y_RING_H_INCLUDED
typedef struct Y_ring
{
        int no;
        struct Y_ring *next;
} y_r,*Y_R;
void Init_List(Y_R &P);  // 初始化单向循环链表
void Insert_Elem(Y_R &P, int n); // 插入元素
void Dele_Out(Y_R &P,int m,int * &DATA);  // 删除元素
#endif // Y_RING_H_INCLUDED
