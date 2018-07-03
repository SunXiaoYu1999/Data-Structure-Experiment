#pragma once
#include"stdafx.h"
#include"H_X.h"
#include<iostream>
#include<cmath>

H_X::H_X()
{
	ha_xi = NULL;
}

H_X::~H_X()
{
	delete[] ha_xi;
}

void H_X::Inti_Lize()
{
	int n;
	int m;
	for (int i = 0; i < 25; i++)
		std::cout << "*";
	std::cout << "哈希表";
	for (int i = 0; i < 25; i++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "一共有多少个学生需要录入？" << std::endl;
	std::cin >> n;
	std::cin.get(); // 清除缓冲区里面的回车符
	num_of_elem = n;
	m = n * 2;
	num_of_haxi = m;
	for (int i = m; i >= 1; i--) {
		if (Is_sushu(i)) {
			p = i;
			break;
		}
	}
	ha_xi = new h_x[m];
	for (int i = 0; i < m; i++) {
		ha_xi[i].key = KEY_NULL;
		ha_xi[i].counter= 0;
	}
	Create_HX();
}

void H_X::Create_HX()
{
	std::string *Name = new std::string[num_of_elem];
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	for (int i = 0; i < num_of_elem; i++) {
		std::cout << "请输入第 " << i + 1 << "个学生的名字\t";
		getline(std::cin, Name[i]);
	}
	int key_temp;
	int adr;
	for (int i = 0; i < num_of_elem; i++) {
		key_temp = Get_HX(Name[i]);
		adr = key_temp % num_of_haxi;
		if (ha_xi[adr].key == KEY_NULL || ha_xi[adr].key == KEY_DELETE) {
			ha_xi[adr].key = key_temp;
			ha_xi[adr].counter = 1;
			ha_xi[adr].info = Name[i];
		}
		else {
			int con = 1;
			while (ha_xi[adr].key != KEY_NULL && ha_xi[adr].key != KEY_DELETE) {
				adr = (adr + 1) % num_of_haxi;
				con++;
			}
			ha_xi[adr].key = key_temp;
			ha_xi[adr].counter = con;
			ha_xi[adr].info = Name[i];
		}
	}
	delete[] Name;
}

int H_X::Get_HX(std::string A)
{
	int sum = 0;
	for (int i = 0; A[i] != '\0';i++) {
		sum += A[i];
	}
	return sum;
}

void H_X::Find_Elem()
{
	int key_temp, find = 0, con = 1;
	std::string temp;
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "请输入你要找的名字 : \t";
	getline(std::cin, temp);
	key_temp = Get_HX(temp);
	int adr = key_temp % num_of_haxi;
	if(ha_xi[adr].key == key_temp){
		for (int i = 0; i < 56; i++)
			std::cout << "*";
		std::cout << std::endl;
		std::cout << "找到了!该同学是" << ha_xi[adr].info << std::endl;
		find = 1;
	}
	else {
		while (ha_xi[adr].key != KEY_NULL && ha_xi[adr].key != KEY_DELETE) {
			adr = (adr + 1) % num_of_haxi;
			if (ha_xi[adr].key == key_temp) {
				for (int i = 0; i < 56; i++)
					std::cout << "*";
				std::cout << std::endl;
				std::cout << "找到了!该同学是" << ha_xi[adr].info << std::endl;
				find = 1;
			}
			con++;
		}
	}
	if (find == 0) {
		for (int i = 0; i < 56; i++)
			std::cout << "*";
		std::cout << std::endl;
		std::cout << "没找到该同学，该同学已记录在案\n" << std::endl;
		ha_xi[adr].key = key_temp;
		ha_xi[adr].counter = con;
		ha_xi[adr].info = temp;
	}
}

void H_X::Delete()
{
	int key_temp;
	int find = 0;
	std::string temp;
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "请输入你要删除的元素：";
	getline(std::cin, temp);
	key_temp = Get_HX(temp);
	int adr = key_temp % num_of_haxi;
	if (ha_xi[adr].key == key_temp) {
		for (int i = 0; i < 56; i++)
			std::cout << "*";
		std::cout << std::endl;
		std::cout << "该同学是" << ha_xi[adr].info <<"已删除！"<< std::endl;
		ha_xi[adr].key = KEY_DELETE;
		ha_xi[adr].counter = 0;
		ha_xi[adr].info = "error";
		find = 1;
	}
	else {
		while (ha_xi[adr].key != KEY_NULL && ha_xi[adr].key != KEY_DELETE) {
			adr = (adr + 1) % num_of_haxi;
			if (ha_xi[adr].key == key_temp) {
				for (int i = 0; i < 56; i++)
					std::cout << "*";
				std::cout << std::endl;
				std::cout << "该同学是" << ha_xi[adr].info <<"已删除！"<<  std::endl;
				ha_xi[adr].key = KEY_DELETE;
				ha_xi[adr].counter = 0;
				ha_xi[adr].info = "error";
				find = 1;
			}
		}
	}
	if (find == 0) {
		for (int i = 0; i < 56; i++)
			std::cout << "*";
		std::cout << std::endl;
		std::cout << "没找到该同学" << std::endl;
	}

}


std::ostream & operator<<(std::ostream &os, H_X &P)
{
	for (int i = 0; i < 56; i++)
		std::cout << "*";
	std::cout << std::endl;
	os << " num_of_haxi = " << P.num_of_haxi << std::endl;
	for (int i = 0; i < P.num_of_haxi; i++) {
		os << i + 1 << " " << P.ha_xi[i].key << " " ;
		os << P.ha_xi[i].counter << " " << P.ha_xi[i].info << std::endl;
	}
	return os;
}

bool Is_sushu(int n)
{
	int temp = sqrt((double)n);
	for (int i = 2; i < temp + 1; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}