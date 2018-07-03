#pragma once
#include<string>

typedef std::string Elem;
#define KEY_NULL -1
#define KEY_DELETE -2

typedef struct
{
	int key;
	int counter; // ������Դ�����ٴ�
	Elem info;
}h_x;

class H_X {
private:
	h_x * ha_xi;
	int num_of_elem;  // Ԫ�ظ���
	int num_of_haxi;  // ��ϣ����
	int p;            // ��pȡ��
public:
	H_X();
	~H_X();
	void Inti_Lize();
	void Create_HX();
	int Get_HX(std::string A);
	void Find_Elem();
	friend std::ostream & operator << (std::ostream &os, H_X  &P);
	void Delete();
};
bool Is_sushu(int n);