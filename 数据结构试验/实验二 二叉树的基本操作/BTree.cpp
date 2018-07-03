#include "stdafx.h"
#include "BTree.h"
const int MAX_SIZE = 20;// ջ��󳤶�

Tree::Tree()
{
	head = NULL;//��ʼ��ͷָ��Ϊ��
}

// �����ű�ʾ������һ�ö�����
Tree::Tree(const char *& str)
{
	BTree St[MAX_SIZE];
	int top = -1; // ����һ��ջ����ʼ��������
	char get_alp; // ����ȡ���ַ�
	BTree temp = NULL; //tempָ�����������µĽڵ�
	int  flag; // ��������ӻ����Һ���
	int i = 0;
	do {
		get_alp = str[i];//ȡ����i���ַ�	 
		switch (get_alp)
		{
		case '(':
			St[++top] = temp; // �������������ţ�˵��temp�к��ӣ���temp��ջ
			flag = 1; // ��ǽ�����Ϊ����
			break;
		case ')':
			--top;// �������������ţ���ջ
			break;
		case ',':
			flag = 2; // �������������ţ������Һ���
			break;
		case '\0':
			break;
		default :
			temp = new btree; // �����½ڵ�
			temp->data = get_alp;// ����ǰ�ڵ㸳ֵ
			temp->Lchild= NULL; // ���ӳ�ʼ��Ϊ��
			temp->Rchild = NULL; // �Һ��ӳ�ʼ��Ϊ�� 
			if (head == NULL)
				head = temp;
			else {
				switch (flag) {
				case 1:
					St[top]->Lchild = temp;
					break;
				case 2:
					St[top]->Rchild = temp;
					break;
				}
			}
			break;
		}
		i++;
	} while (get_alp != '\0');
}
void Tree::operator=(char *& str)
{
	BTree St[MAX_SIZE];
	int top = -1; // ����һ��ջ����ʼ��������
	char get_alp; // ����ȡ���ַ�
	BTree temp = NULL; //tempָ�����������µĽڵ�
	int  flag; // ��������ӻ����Һ���
	int i = 0;
	do {
		get_alp = str[i];//ȡ����i���ַ�	 
		switch (get_alp)
		{
		case '(':
			St[++top] = temp; // �������������ţ�˵��temp�к��ӣ���temp��ջ
			flag = 1; // ��ǽ�����Ϊ����
			break;
		case ')':
			--top;// �������������ţ���ջ
			break;
		case ',':
			flag = 2; // �������������ţ������Һ���
			break;
		case '\0':
			break;
		default:
			temp = new btree; // �����½ڵ�
			temp->data = get_alp;// ����ǰ�ڵ㸳ֵ
			temp->Lchild = NULL; // ���ӳ�ʼ��Ϊ��
			temp->Rchild = NULL; // �Һ��ӳ�ʼ��Ϊ�� 
			if (head == NULL)
				head = temp;
			else {
				switch (flag) {
				case 1:
					St[top]->Lchild = temp;
					break;
				case 2:
					St[top]->Rchild = temp;
					break;
				}
			}
			break;
		}
		i++;
	} while (get_alp != '\0');
}

// ����һ����
void Tree::Create_Tree_1()
{
	std::cout << "���ڿ�ʼ����һ����\n1)�����밴���˳�����������ڵ���Ϣ��û�е�����#\n2)�ڵ���Ϣ���Կո����\n";
	std::string In;
	getline(std::cin,In);
	int n = 0, k; // k�����洢ÿ���ڵ���Ϣ�ĳ��ȣ�i�ж�In�Ƿ������n�������ڵ�����
	int Num = 0;
	// ����ڵ����
	for (int i = 0; In[i] != '\0'; ++i)
		if (In[i] != ' ' && (In[i + 1] == ' ' || In[i + 1] == '\0'))
			Num++;
	if (Num % 2 == 0) {
		std::cout << "������Ľڵ���Ŀ���󣬳��������";
		return;
	}
	BTree *A = new BTree[Num]; // ����һ��ָ�����飬���ÿ���ڵ��ָ��
	for (int i = 0; In[i] != '\0';) {
		for (; In[i] == ' '; ++i); // ȥ�����пո��
		if (In[i] == '#') {
			A[n] = NULL;
			n++;
			i++;
		}
		else {
			for (k = 0; In[k] != ' '&& In[i+k] != '\0'; ++k);
			char *temp;
			temp = new char[k + 1]; // �������Ԫ��
			int j;
			for (j = 0; In[i] != ' '&& In[i] != '\0'; ++i,++j)
				temp[j] = In[i];
			temp[j] = '\0';
			A[n] = new btree;
			A[n]->data = temp;
			A[n]->Lchild = NULL;
			A[n]->Rchild = NULL;
			n++;
			delete[] temp;
		}
	}
	// ���濪ʼ��������
	for (int i = 0; i < Num; i++) {
		if (A[i] != NULL) {
			if (i + 1 <= Num / 2) {
				A[i]->Lchild = A[2 * (i + 1) - 1];
				A[i]->Rchild = A[2 * (i + 1)];
			}
			else {
				A[i]->Lchild = NULL;
				A[i]->Rchild = NULL;
			}
		}
	}
	head = A[0];
	delete[] A;
}

// �ݹ�������ʶ�����
void Tree::Pre_Order()
{
	Pre_Order(head);
	std::cout << std::endl << std::endl;
}
void Tree::Pre_Order(BTree b)
{
	if (b != NULL) {
		std::cout << b->data << " ";
		Pre_Order(b->Lchild);
		Pre_Order(b->Rchild);
	}
}

// �ݹ�������ʶ�����
void Tree::In_Order()
{
	In_Order(head);
	std::cout << std::endl << std::endl;
}
void Tree::In_Order(BTree b)
{
	if (b != NULL) {
		In_Order(b->Lchild);
		std::cout << b->data << " ";
		In_Order(b->Rchild);
	}
}

// �ݹ������ʶ�����
void Tree::Post_Order()
{
	Post_Order(head);
	std::cout << std::endl << std::endl;
}
void Tree::Post_Order(BTree b)
{
	if (b != NULL) {
		Post_Order(b->Lchild);
		Post_Order(b->Rchild);
		std::cout << b->data << " ";
	}
}

// ��������ǵݹ鷨
void Tree::Pre_Order_Nonrecursive()
{
	BTree St[MAX_SIZE];
	int top = -1;// ��ջ��������ʹ���
	BTree temp; // temp�洢��ջ��Ԫ��
	if (head != NULL) {  // ͷ�ڵ㲻Ϊ��ʱ����
		St[++top] = head;// ���ڵ��ջ
		while (top > -1) {  //ջ����ʱѭ��
			temp = St[top--];// ��ǰ�ڵ��ջ
			std::cout << temp->data << " "; // ���ʵ�ǰ�ڵ�
			if(temp->Rchild != NULL)
				St[++top] = temp->Rchild;// �Һ��ӽ�ջ
			if (temp->Lchild != NULL)
				St[++top] = temp->Lchild;//���ӽ�ջ
		}
		std::cout << std::endl << std::endl;
	}
}

// ��������ǵݹ鷨
void Tree::In_Order_Nonrecursive()
{
	BTree St[MAX_SIZE];
	int top = -1;
	BTree temp = NULL; // �洢��ǰ��ջԪ��
	if (head != NULL) {
		temp = head;
		while (top > -1 || temp != NULL) { // ջ����ʱѭ��
			while (temp != NULL) { // �������ӽ�ջ
				St[++top] = temp;
				temp = St[top]->Lchild;
			}
			if(top > -1){
				temp = St[top--];
				std::cout << temp->data << " ";
				temp = temp->Rchild; //�����Һ���
			}
		}
	}
	std::cout << "\n\n";
}

// ��������ǵݹ鷨
void Tree::Post_Order_Nonrecursive()
{
	BTree *St[MAX_SIZE];
	int top = -1;


}

// ��α���һ����������
void Tree::Ceng_Ci()
{
	List_Queue que = new list_queue;
	que->front = NULL;
	que->rear = NULL;
	Queue temp = new queue;
	temp->Data = head;
	temp->next = NULL;
	que->rear = temp;// ���ڵ����
	que->front = que->rear; // �����׸��ڵ㣬��ͷ��βָ��ͬһ�ڵ�
	while (que->rear != NULL) { // �Ӳ�Ϊ��ѭ��
		Queue pre;
		if (que->front == que->rear && que->front != NULL) { // ��������ֻ��һ��Ԫ��
			pre = que->front;
			que->front = NULL;
			que->rear = NULL;
		}
		else {
			pre = que->front;
			que->front = pre->next;
		}
		std::cout << pre->Data->data << " ";
		if (pre->Data->Lchild != NULL) {
			Queue p = new queue;
			p->Data = pre->Data->Lchild;
			p->next = NULL;
			if (que->rear == NULL) { // ������Ϊ��
				que->rear = p;
				que->front = que->rear;
			}
			else {
				que->rear->next = p;
				que->rear = p;
			}
		}
		if (pre->Data->Rchild != NULL) {
			Queue q = new queue;
			q->Data = pre->Data->Rchild;
			q->next = NULL;
			if (que->rear == NULL) { // ������Ϊ��
				que->rear = q;
				que->front = que->rear;
			}
			else {
				que->rear->next = q;
				que->rear = q;
			}
		}
		delete pre;
	}
	delete que;
	std::cout << "\n";
}

void Tree::Destroy(BTree &b)
{
	if (b != NULL) {
		BTree temp = b;
		Destroy(b->Lchild);
		Destroy(b->Rchild);
		delete temp;
		
	}
}

void Tree::Destroy()
{
	Destroy(head);
}

Tree::~Tree()
{
	Destroy(head);
}
