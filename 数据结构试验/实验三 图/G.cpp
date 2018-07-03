#include"stdafx.h"
#include "G.h"
#include<string>
// 初始化一个图，把所有的h_node初始化为空
void Init_Graph(Graph &G)
{
	G.v_list = NULL;
}
// 初始化元素数组头结点
void GRAPH::Init_h_Node() {
	for (int i = 0; i < G.v; i++)
		G.v_list[i].h_node = NULL;
}
void GRAPH::text()
{
	E_G pre;
	for (int i = 0; i < G.v; i++) {
		std::cout << G.v_list[i].data << " ";
		pre = G.v_list[i].h_node;
		while (pre != NULL) {
			std::cout << pre->data << " ";
			pre = pre->e_node;
		}
		std::cout << std::endl;
	}
}
// 创建图的第1种方式
void GRAPH::Create_Graph_1()
{
	std::cout << "创建一个图:\n*******************以下为参考输入实例*******************\n4\t    --->顶点个数\nA 2 3 4     --->第一个数据为顶点，后面为它的连通顶点序号\nB 1 3 4\nC 1 2 4\nD 1 2 3\n********************************************************\n请按照以上例子创建一个图\n" << std::endl;
	int n;
	std::cin >> n; // 图的顶点数
	std::cin.get(); // 清除缓冲区的回车符
	G.v = n;
	G.v_list = new h_g[n]; // 创建数组，存放节点信息
	Init_h_Node(); // 初始化元素数组头结点
	Elem temp; 
	for (int i = 0,k; i < n; ++i) {
		getline(std::cin, temp); //整行读取用户输入数据
		for (k = 0; temp[k] != ' ' && temp[k] != '\0'; k++);
		char *t = new char[k + 1];
		for (int j = 0; temp[j] != ' ' && temp[j] != '\0'; j++) {
			t[j] = temp[j];
		}
		t[k] = '\0';
		G.v_list[i].data = t; // 存入当前节点数据
		delete[] t; // 释放t内存
		for ( ; temp[k] != '\0';k++ ) {
			if (temp[k] == ' ')
				for (; temp[k] == ' '; k++);
			E_G p = new e_g;
			p->data = temp[k] - 49; // 从0开始存放节点顺序
			// 头插法插入边节点
			p->e_node = G.v_list[i].h_node;
			G.v_list[i].h_node = p;
			G.e++;
		}
	}

}

// 递归深度遍历图
void GRAPH::Visit_Graph_1()
{
	int *vis = new int[G.v]; // 标记某个顶点是否被访问过
	for (int i = 0; i < G.v; ++i) {
		vis[i] = 0;
	}
	int n;
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "你想从哪个顶点开始进行深度遍历？（请输入顶点序号）：";
	std::cin >> n;
	std::cout << "遍历序列为：\n" <<std::endl;
	int num_of_vis_1 = 0;
	int i;
	Visit_Graph_1(G.v_list[n-1],vis,n-1);
	for (i = 0; i < G.v; i++){
		if(vis[i] == 0)
			Visit_Graph_1(G.v_list[i], vis, i);
	}
	std::cout <<"\n" << std::endl;
	delete[] vis;
}

void GRAPH::Visit_Graph_1(h_g p , int *vis,int v)
{
	E_G pre;
	pre = p.h_node;
	if (vis[v] == 1)
		return;
	vis[v] = 1;
	std::cout << " " << p.data << " ";
	while (pre != NULL) {
		Visit_Graph_1(G.v_list[pre->data], vis, pre->data);
		pre = pre->e_node;
	}
}


// 删除图
void GRAPH::Delete_Graph()
{
	E_G temp;
	E_G pre;
	for (int i = 0; i < G.v; i++){
		temp = G.v_list[i].h_node;
		while (temp != NULL) {
			pre = temp;
			temp = pre->e_node;
			delete pre;
		}
	}
	delete[] G.v_list;
}
// 广度优先遍历
void GRAPH::BFS_Graph()
{
	int *vis = new int[G.v];
	for (int i = 0; i < G.v; i++)
		vis[i] = 0;
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	int n;                       // 存储输入的节点序号
	std::cout << "你想从哪个顶点开始进行广度优先遍历（请输入顶点序号）： ";
	std::cin >> n;
	std::cout << "遍历序列为：\n" << std::endl;
	BFS_Graph(n, vis);
	int i;
	for (i = 0; i < G.v; i++) {
		if (vis[i] == 0)
			BFS_Graph(i + 1, vis);
	}
	std::cout << "\n" << std::endl;
	delete[] vis;
}

void GRAPH::BFS_Graph(int n,int *vis)
{
	QUEUE Q = new queue;         // 创建一个队列
	Q->front = NULL;
	Q->rear = NULL;              // 初始化队头队尾指针为空
	E_G p = NULL;
	Q_Node temp = new q_node, pre;
	temp->num = n - 1;           // 初始节点进队
	temp->next = NULL;
	Q->rear = temp;
	Q->front = temp;             // 初始节点进队
	vis[n - 1] = 1;              // 标记访问
	while (Q->front != NULL) {   // 首先是出队，但是出队分两种情况
		if (Q->front == Q->rear) { // 队列中只有一个元素的情况
			Q->rear = NULL;
		}
		pre = Q->front;
		Q->front = pre->next;
		std::cout << " " << G.v_list[pre->num].data << " "; // 访问当前出队节点
		p = G.v_list[pre->num].h_node;// 然后把出队节点的下一个联通节点进队（没访问过得）
		while (p != NULL) {           // 进队也有两种情况
			if (vis[p->data] == 0) {  // 若节点没被访问过则进队
				temp = new q_node;
				temp->num = p->data;
				temp->next = NULL;
				vis[p->data] = 1;
				if (Q->rear == NULL) { // 队为空的情况
					Q->rear = temp;
					Q->front = temp;
				}
				else {
					Q->rear->next = temp;
					Q->rear = temp;
				}
			}
			p = p->e_node;
		}
		delete pre;
	}
	delete Q;
}

GRAPH::GRAPH()
{
	Init_Graph(G);
}

GRAPH::~GRAPH()
{
	Delete_Graph();
}
