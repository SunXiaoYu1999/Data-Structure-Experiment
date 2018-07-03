#pragma once
#include<iostream>
#include<string>

typedef std::string Elem;

// 以下为队列的数据结构
typedef struct node {
	int num; // 节点序号
	struct node *next;
} q_node,*Q_Node;

typedef struct QUE {
	Q_Node rear; // 队尾指针
	Q_Node front; // 队头指针
}queue,*QUEUE;
// 以上为队列的数据结构


// 存放边节点的相关信息
typedef struct A_node
{
	int data;// 存放边节点的序号信息
	struct A_node * e_node;// 	Elemtype info 
}e_g, *E_G;

// 存放当前节点数据信息
typedef struct B_node
{
	Elem data; 
	E_G h_node;
}h_g,*H_G;

// 图的结构
typedef struct G
{
	H_G v_list; // 邻接表
	int v = 0; // 节点数
	int e = 0; // 边数
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
	void Visit_Graph_1(h_g p,int *vis,int v); // 递归深度遍历图
	void Delete_Graph();
	void BFS_Graph();
	void BFS_Graph(int n,int *vis);
	void Init_h_Node();
	void text();
};
// 初始化图,所有h_node初始化为空
void Init_Graph(Graph &G);
