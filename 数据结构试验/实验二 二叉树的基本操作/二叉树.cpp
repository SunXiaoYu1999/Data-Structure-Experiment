// 二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BTree.h"

int main()
{
//	const char *p = "A(B(D(H,I),E(J,K)),C(F(L,M),G(N,O)))";
	const char *p = "A(B(D),C(E,F))";
//	Tree B(p);// 初始化二叉树
	Tree A = p; // 重载的 = 来初始化A

//	std::cout << "递归先序访问二叉树:\t";
//	B.Pre_Order(); 
	std::cout << "递归中序访问二叉树:\t";
	A.In_Order();
//	std::cout << "递归后序访问二叉树:\t";
//	B.Post_Order(); 

//	std::cout << "非递归先序访问二叉树:\t";
//	A.Pre_Order_Nonrecursive();
	std::cout << "非递归中序访问二叉树:\t";
	A.In_Order_Nonrecursive();
//	std::cout << "非递归后序访问二叉树:\t";
//	A.Post_Order_Nonrecursive();
	std::cout << "层次遍历二叉树：\t";
	A.Ceng_Ci();
	std::cout << "\n\n";
	Tree B;
	B.Create_Tree_1();
	std::cout << "递归中序访问二叉树:\t";
	B.In_Order();
	std::cout << "非递归中序访问二叉树:\t";
	B.In_Order_Nonrecursive();
	std::cout << "层次遍历二叉树：\t";
	B.Ceng_Ci();

	system("pause");
    return 0;
}

