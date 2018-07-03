#include"stdafx.h"
#include "G.h"
#include<string>
// ��ʼ��һ��ͼ�������е�h_node��ʼ��Ϊ��
void Init_Graph(Graph &G)
{
	G.v_list = NULL;
}
// ��ʼ��Ԫ������ͷ���
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
// ����ͼ�ĵ�1�ַ�ʽ
void GRAPH::Create_Graph_1()
{
	std::cout << "����һ��ͼ:\n*******************����Ϊ�ο�����ʵ��*******************\n4\t    --->�������\nA 2 3 4     --->��һ������Ϊ���㣬����Ϊ������ͨ�������\nB 1 3 4\nC 1 2 4\nD 1 2 3\n********************************************************\n�밴���������Ӵ���һ��ͼ\n" << std::endl;
	int n;
	std::cin >> n; // ͼ�Ķ�����
	std::cin.get(); // ����������Ļس���
	G.v = n;
	G.v_list = new h_g[n]; // �������飬��Žڵ���Ϣ
	Init_h_Node(); // ��ʼ��Ԫ������ͷ���
	Elem temp; 
	for (int i = 0,k; i < n; ++i) {
		getline(std::cin, temp); //���ж�ȡ�û���������
		for (k = 0; temp[k] != ' ' && temp[k] != '\0'; k++);
		char *t = new char[k + 1];
		for (int j = 0; temp[j] != ' ' && temp[j] != '\0'; j++) {
			t[j] = temp[j];
		}
		t[k] = '\0';
		G.v_list[i].data = t; // ���뵱ǰ�ڵ�����
		delete[] t; // �ͷ�t�ڴ�
		for ( ; temp[k] != '\0';k++ ) {
			if (temp[k] == ' ')
				for (; temp[k] == ' '; k++);
			E_G p = new e_g;
			p->data = temp[k] - 49; // ��0��ʼ��Žڵ�˳��
			// ͷ�巨����߽ڵ�
			p->e_node = G.v_list[i].h_node;
			G.v_list[i].h_node = p;
			G.e++;
		}
	}

}

// �ݹ���ȱ���ͼ
void GRAPH::Visit_Graph_1()
{
	int *vis = new int[G.v]; // ���ĳ�������Ƿ񱻷��ʹ�
	for (int i = 0; i < G.v; ++i) {
		vis[i] = 0;
	}
	int n;
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "������ĸ����㿪ʼ������ȱ������������붥����ţ���";
	std::cin >> n;
	std::cout << "��������Ϊ��\n" <<std::endl;
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


// ɾ��ͼ
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
// ������ȱ���
void GRAPH::BFS_Graph()
{
	int *vis = new int[G.v];
	for (int i = 0; i < G.v; i++)
		vis[i] = 0;
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	int n;                       // �洢����Ľڵ����
	std::cout << "������ĸ����㿪ʼ���й�����ȱ����������붥����ţ��� ";
	std::cin >> n;
	std::cout << "��������Ϊ��\n" << std::endl;
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
	QUEUE Q = new queue;         // ����һ������
	Q->front = NULL;
	Q->rear = NULL;              // ��ʼ����ͷ��βָ��Ϊ��
	E_G p = NULL;
	Q_Node temp = new q_node, pre;
	temp->num = n - 1;           // ��ʼ�ڵ����
	temp->next = NULL;
	Q->rear = temp;
	Q->front = temp;             // ��ʼ�ڵ����
	vis[n - 1] = 1;              // ��Ƿ���
	while (Q->front != NULL) {   // �����ǳ��ӣ����ǳ��ӷ��������
		if (Q->front == Q->rear) { // ������ֻ��һ��Ԫ�ص����
			Q->rear = NULL;
		}
		pre = Q->front;
		Q->front = pre->next;
		std::cout << " " << G.v_list[pre->num].data << " "; // ���ʵ�ǰ���ӽڵ�
		p = G.v_list[pre->num].h_node;// Ȼ��ѳ��ӽڵ����һ����ͨ�ڵ���ӣ�û���ʹ��ã�
		while (p != NULL) {           // ����Ҳ���������
			if (vis[p->data] == 0) {  // ���ڵ�û�����ʹ������
				temp = new q_node;
				temp->num = p->data;
				temp->next = NULL;
				vis[p->data] = 1;
				if (Q->rear == NULL) { // ��Ϊ�յ����
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
