#pragma once
#include<iostream>
#include<string> 
typedef std::string Elem;
// ����Ϊ�������Ľṹ
typedef struct BNode {
	Elem data; // ����������
	struct BNode *Lchild; // ����������
	struct BNode *Rchild; // �������Һ���
}btree, *BTree;

// ����Ϊ���ӵĽṹ
typedef struct QNode {
	BTree Data;
	struct QNode *next;
}queue,*Queue;
typedef struct que{
	Queue rear;
	Queue front;
}list_queue,*List_Queue;


class Tree
{	
private:
	BTree  head;
public:
	Tree();
	Tree(const char *& str); // �����ű�ʾ������һ��������
	void operator=(char *& str);
	// ����һ����
	void Create_Tree_1();
	// ��������ݹ鷨
	void Pre_Order();
	void Pre_Order(BTree b);
	// ��������ݹ鷨
	void In_Order();
	void In_Order(BTree b);
	// ��������ݹ鷨
	void Post_Order();
	void Post_Order(BTree b);
	//��������ǵݹ鷨
	void Pre_Order_Nonrecursive();
	//��������ǵݹ鷨
	void In_Order_Nonrecursive();
	//��������ǵݹ鷨
	void Post_Order_Nonrecursive();
	//��α���һ����
	void Ceng_Ci();
	// ����һ����
	void Destroy();
	void Destroy(BTree &b);
	~Tree();

};

