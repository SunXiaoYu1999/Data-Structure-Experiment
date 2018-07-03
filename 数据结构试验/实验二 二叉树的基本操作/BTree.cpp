#include "stdafx.h"
#include "BTree.h"
const int MAX_SIZE = 20;// 栈最大长度

Tree::Tree()
{
	head = NULL;//初始化头指针为空
}

// 用括号表示法创建一棵二叉树
Tree::Tree(const char *& str)
{
	BTree St[MAX_SIZE];
	int top = -1; // 创建一个栈来初始化二叉树
	char get_alp; // 用来取出字符
	BTree temp = NULL; //temp指针用来创建新的节点
	int  flag; // 标记是左孩子还是右孩子
	int i = 0;
	do {
		get_alp = str[i];//取出第i个字符	 
		switch (get_alp)
		{
		case '(':
			St[++top] = temp; // 遇到‘（’符号，说明temp有孩子，将temp进栈
			flag = 1; // 标记接下来为左孩子
			break;
		case ')':
			--top;// 遇到‘）’符号，出栈
			break;
		case ',':
			flag = 2; // 遇到‘，’符号，处理右孩子
			break;
		case '\0':
			break;
		default :
			temp = new btree; // 创建新节点
			temp->data = get_alp;// 给当前节点赋值
			temp->Lchild= NULL; // 左孩子初始化为空
			temp->Rchild = NULL; // 右孩子初始化为空 
			if (head == NULL)
				head = temp;
			else {
				switch (flag) {
				case 1:
					St[top]->Lchild = temp;
					break;
				case 2:
					St[top]->Rchild = temp;
					break;
				}
			}
			break;
		}
		i++;
	} while (get_alp != '\0');
}
void Tree::operator=(char *& str)
{
	BTree St[MAX_SIZE];
	int top = -1; // 创建一个栈来初始化二叉树
	char get_alp; // 用来取出字符
	BTree temp = NULL; //temp指针用来创建新的节点
	int  flag; // 标记是左孩子还是右孩子
	int i = 0;
	do {
		get_alp = str[i];//取出第i个字符	 
		switch (get_alp)
		{
		case '(':
			St[++top] = temp; // 遇到‘（’符号，说明temp有孩子，将temp进栈
			flag = 1; // 标记接下来为左孩子
			break;
		case ')':
			--top;// 遇到‘）’符号，出栈
			break;
		case ',':
			flag = 2; // 遇到‘，’符号，处理右孩子
			break;
		case '\0':
			break;
		default:
			temp = new btree; // 创建新节点
			temp->data = get_alp;// 给当前节点赋值
			temp->Lchild = NULL; // 左孩子初始化为空
			temp->Rchild = NULL; // 右孩子初始化为空 
			if (head == NULL)
				head = temp;
			else {
				switch (flag) {
				case 1:
					St[top]->Lchild = temp;
					break;
				case 2:
					St[top]->Rchild = temp;
					break;
				}
			}
			break;
		}
		i++;
	} while (get_alp != '\0');
}

// 创建一棵树
void Tree::Create_Tree_1()
{
	std::cout << "现在开始创建一棵树\n1)首先请按层次顺序从左到右输入节点信息，没有的输入#\n2)节点信息间以空格分离\n";
	std::string In;
	getline(std::cin,In);
	int n = 0, k; // k用来存储每个节点信息的长度，i判断In是否结束，n用来给节点标序号
	int Num = 0;
	// 计算节点个数
	for (int i = 0; In[i] != '\0'; ++i)
		if (In[i] != ' ' && (In[i + 1] == ' ' || In[i + 1] == '\0'))
			Num++;
	if (Num % 2 == 0) {
		std::cout << "你输入的节点数目有误，程序结束！";
		return;
	}
	BTree *A = new BTree[Num]; // 创建一个指针数组，存放每个节点的指针
	for (int i = 0; In[i] != '\0';) {
		for (; In[i] == ' '; ++i); // 去除所有空格符
		if (In[i] == '#') {
			A[n] = NULL;
			n++;
			i++;
		}
		else {
			for (k = 0; In[k] != ' '&& In[i+k] != '\0'; ++k);
			char *temp;
			temp = new char[k + 1]; // 用来存放元素
			int j;
			for (j = 0; In[i] != ' '&& In[i] != '\0'; ++i,++j)
				temp[j] = In[i];
			temp[j] = '\0';
			A[n] = new btree;
			A[n]->data = temp;
			A[n]->Lchild = NULL;
			A[n]->Rchild = NULL;
			n++;
			delete[] temp;
		}
	}
	// 下面开始创建树；
	for (int i = 0; i < Num; i++) {
		if (A[i] != NULL) {
			if (i + 1 <= Num / 2) {
				A[i]->Lchild = A[2 * (i + 1) - 1];
				A[i]->Rchild = A[2 * (i + 1)];
			}
			else {
				A[i]->Lchild = NULL;
				A[i]->Rchild = NULL;
			}
		}
	}
	head = A[0];
	delete[] A;
}

// 递归先序访问二叉树
void Tree::Pre_Order()
{
	Pre_Order(head);
	std::cout << std::endl << std::endl;
}
void Tree::Pre_Order(BTree b)
{
	if (b != NULL) {
		std::cout << b->data << " ";
		Pre_Order(b->Lchild);
		Pre_Order(b->Rchild);
	}
}

// 递归中序访问二叉树
void Tree::In_Order()
{
	In_Order(head);
	std::cout << std::endl << std::endl;
}
void Tree::In_Order(BTree b)
{
	if (b != NULL) {
		In_Order(b->Lchild);
		std::cout << b->data << " ";
		In_Order(b->Rchild);
	}
}

// 递归后序访问二叉树
void Tree::Post_Order()
{
	Post_Order(head);
	std::cout << std::endl << std::endl;
}
void Tree::Post_Order(BTree b)
{
	if (b != NULL) {
		Post_Order(b->Lchild);
		Post_Order(b->Rchild);
		std::cout << b->data << " ";
	}
}

// 先序遍历非递归法
void Tree::Pre_Order_Nonrecursive()
{
	BTree St[MAX_SIZE];
	int top = -1;// 用栈来处理访问过程
	BTree temp; // temp存储出栈的元素
	if (head != NULL) {  // 头节点不为空时进入
		St[++top] = head;// 根节点进栈
		while (top > -1) {  //栈不空时循环
			temp = St[top--];// 当前节点出栈
			std::cout << temp->data << " "; // 访问当前节点
			if(temp->Rchild != NULL)
				St[++top] = temp->Rchild;// 右孩子进栈
			if (temp->Lchild != NULL)
				St[++top] = temp->Lchild;//左孩子进栈
		}
		std::cout << std::endl << std::endl;
	}
}

// 中序遍历非递归法
void Tree::In_Order_Nonrecursive()
{
	BTree St[MAX_SIZE];
	int top = -1;
	BTree temp = NULL; // 存储当前出栈元素
	if (head != NULL) {
		temp = head;
		while (top > -1 || temp != NULL) { // 栈不空时循环
			while (temp != NULL) { // 所有左孩子进栈
				St[++top] = temp;
				temp = St[top]->Lchild;
			}
			if(top > -1){
				temp = St[top--];
				std::cout << temp->data << " ";
				temp = temp->Rchild; //处理右孩子
			}
		}
	}
	std::cout << "\n\n";
}

// 后序遍历非递归法
void Tree::Post_Order_Nonrecursive()
{
	BTree *St[MAX_SIZE];
	int top = -1;


}

// 层次遍历一棵树，链队
void Tree::Ceng_Ci()
{
	List_Queue que = new list_queue;
	que->front = NULL;
	que->rear = NULL;
	Queue temp = new queue;
	temp->Data = head;
	temp->next = NULL;
	que->rear = temp;// 根节点进队
	que->front = que->rear; // 插入首个节点，队头队尾指向同一节点
	while (que->rear != NULL) { // 队不为空循环
		Queue pre;
		if (que->front == que->rear && que->front != NULL) { // 若队列内只有一个元素
			pre = que->front;
			que->front = NULL;
			que->rear = NULL;
		}
		else {
			pre = que->front;
			que->front = pre->next;
		}
		std::cout << pre->Data->data << " ";
		if (pre->Data->Lchild != NULL) {
			Queue p = new queue;
			p->Data = pre->Data->Lchild;
			p->next = NULL;
			if (que->rear == NULL) { // 若队列为空
				que->rear = p;
				que->front = que->rear;
			}
			else {
				que->rear->next = p;
				que->rear = p;
			}
		}
		if (pre->Data->Rchild != NULL) {
			Queue q = new queue;
			q->Data = pre->Data->Rchild;
			q->next = NULL;
			if (que->rear == NULL) { // 若队列为空
				que->rear = q;
				que->front = que->rear;
			}
			else {
				que->rear->next = q;
				que->rear = q;
			}
		}
		delete pre;
	}
	delete que;
	std::cout << "\n";
}

void Tree::Destroy(BTree &b)
{
	if (b != NULL) {
		BTree temp = b;
		Destroy(b->Lchild);
		Destroy(b->Rchild);
		delete temp;
		
	}
}

void Tree::Destroy()
{
	Destroy(head);
}

Tree::~Tree()
{
	Destroy(head);
}
