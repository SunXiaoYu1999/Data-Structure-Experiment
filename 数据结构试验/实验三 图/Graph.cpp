// Graph.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"G.h"
#include<Windows.h>



int main()
{
	GRAPH B;
	B.Create_Graph_1();
	B.Visit_Graph_1();
	B.BFS_Graph();
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	system("pause");
    return 0;
}

/*
4
A 2 3
B 3
C 1 2
D

*/