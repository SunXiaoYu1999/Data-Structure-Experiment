// 哈希表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"H_X.h"
#include<Windows.h>
#include<iostream>

using namespace std;
int main()
{
	H_X a;
	a.Inti_Lize();
	cout << a ;
	a.Find_Elem();
	cout << a;
	a.Find_Elem();
	cout << a;
	a.Delete();
	cout << a;
	system("pause");
    return 0;
}

/*
6
sun yu
ding yang min
bu yuan hao
xiao ming
xiao hong
xiao jun
*/
