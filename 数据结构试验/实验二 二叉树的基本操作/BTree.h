#pragma once
#include<iostream>
#include<string> 
typedef std::string Elem;
// 以下为二叉树的结构
typedef struct BNode {
	Elem data; // 二叉树数据
	struct BNode *Lchild; // 二叉数左孩子
	struct BNode *Rchild; // 二叉树右孩子
}btree, *BTree;

// 以下为链队的结构
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
	Tree(const char *& str); // 用括号表示法创建一个二叉树
	void operator=(char *& str);
	// 创建一棵树
	void Create_Tree_1();
	// 中序遍历递归法
	void Pre_Order();
	void Pre_Order(BTree b);
	// 中序遍历递归法
	void In_Order();
	void In_Order(BTree b);
	// 后序遍历递归法
	void Post_Order();
	void Post_Order(BTree b);
	//先序遍历非递归法
	void Pre_Order_Nonrecursive();
	//中序遍历非递归法
	void In_Order_Nonrecursive();
	//后序遍历非递归法
	void Post_Order_Nonrecursive();
	//层次遍历一棵树
	void Ceng_Ci();
	// 销毁一棵树
	void Destroy();
	void Destroy(BTree &b);
	~Tree();

};

