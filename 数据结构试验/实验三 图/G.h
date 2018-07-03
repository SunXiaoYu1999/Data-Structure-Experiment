#pragma once
#include<iostream>
#include<string>

typedef std::string Elem;

// ����Ϊ���е����ݽṹ
typedef struct node {
	int num; // �ڵ����
	struct node *next;
} q_node,*Q_Node;

typedef struct QUE {
	Q_Node rear; // ��βָ��
	Q_Node front; // ��ͷָ��
}queue,*QUEUE;
// ����Ϊ���е����ݽṹ


// ��ű߽ڵ�������Ϣ
typedef struct A_node
{
	int data;// ��ű߽ڵ�������Ϣ
	struct A_node * e_node;// 	Elemtype info 
}e_g, *E_G;

// ��ŵ�ǰ�ڵ�������Ϣ
typedef struct B_node
{
	Elem data; 
	E_G h_node;
}h_g,*H_G;

// ͼ�Ľṹ
typedef struct G
{
	H_G v_list; // �ڽӱ�
	int v = 0; // �ڵ���
	int e = 0; // ����
}Graph;

class GRAPH
{
private:
	Graph G;
public:
	GRAPH();
	~GRAPH();
	void Create_Graph_1();
	void Visit_Graph_1();
	void Visit_Graph_1(h_g p,int *vis,int v); // �ݹ���ȱ���ͼ
	void Delete_Graph();
	void BFS_Graph();
	void BFS_Graph(int n,int *vis);
	void Init_h_Node();
	void text();
};
// ��ʼ��ͼ,����h_node��ʼ��Ϊ��
void Init_Graph(Graph &G);
