#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<malloc.h>
const int  MAX_SIZE = 40000;

void Write_Data(int n);
void Qsort(int *D,int l, int r);
void In_Data(int *D,int n);
void Write_Result(int *D,int n);
void In_sort(int *D,int L ,int n);
int cmp(const void *a,const void *b);
void Line(int n);
void Qsort_2(int *D,int l, int r);
void Qsort_3(int *D,int l, int r);
int Zhong(int *D,int l, int r);
void Xi_Er(int *D,int n);
void Counter(int *D,int n);
int main()
{
    int *D;
    int n, reply;
    time_t T_1, T_2;
    Line(80);
    printf("一共有多少数据？\t");
    scanf("%d",&n);
    D = (int *)malloc(n*sizeof(int));
    T_1 = time(NULL);
    Write_Data(n);
    T_2 = time(NULL);
    Line(80);

    printf("写入数据 = %d 秒\n",(int)T_2-(int)T_1);
    Line(80);
    printf("程序功能\n0、退出程序\n1、普通快速排序\n2、快速排序2.0\n3、快速排序3.0\n4、系统快排\n5、插入排序\n6、希尔排序\n7、计数排序\n");
    do{
        Line(80);
        printf("请输入你的选择:\t");
        scanf("%d",&reply);
        switch(reply){
        case 1:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("普通快排\n读取数据 = %d 秒\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Qsort(D,0,n-1); // 用数组下表开始
            T_2 = time(NULL);
            printf("快排时间 = %d 秒\n\n",(int)T_2-(int)T_1);
            break;
        case 2:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("快速排序2.0\n读取数据 = %d 秒\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Qsort_2(D,0,n-1);
            T_2 = time(NULL);
            printf("快速排序2.0 = %d 秒\n\n",(int)T_2-(int)T_1);
            break;
        case 3:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("快速排序3.0\n读取数据 = %d 秒\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Qsort_3(D,0,n-1);
            T_2 = time(NULL);
            printf("快速排序3.0 = %d 秒\n\n",(int)T_2-(int)T_1);
            break;
        case 4:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("系统快排\n读取数据 = %d 秒\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            qsort(D,n,sizeof(D[0]),cmp);
            T_2 = time(NULL);
            printf("系统快排 = %d 秒\n\n",(int)T_2-(int)T_1);
            break;
        case 5:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("插入排序\n读取数据 = %d 秒\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            In_sort(D,1,n);
            T_2 = time(NULL);
            printf("插入排序 = %d 秒\n\n",(int)T_2-(int)T_1);
            break;
        case 6:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("希尔排序\n读取数据 = %d 秒\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Xi_Er(D,n);
            T_2 = time(NULL);
            printf("希尔排序 = %d 秒\n\n",(int)T_2-(int)T_1);
            break;
        case 7:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("计数排序\n读取数据 = %d 秒\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Counter(D,n);
            T_2 = time(NULL);
            printf("计数排序 = %d 秒\n\n",(int)T_2-(int)T_1);
            break;
        default:
            break;
        }
    }while(reply != 0);
    T_1 = time(NULL);
    Write_Result(D,n);
    T_2 = time(NULL);
    Line(80);
    printf("写入结果 = %d 秒\n",(int)T_2-(int)T_1);
    free(D);
    return 0;
}

void Qsort(int *D,int l, int r)
{
    int pre = l; // 前指针
	int las = r; // 后指针
	int temp = D[l]; // 取出第一个元素
	if(l < r){
		while(pre < las){
			while( pre < las && D[las] >= temp)
				las--;
			D[pre] = D[las];
			while(pre < las && D[pre] <= temp)
				pre++;
			D[las] = D[pre];
		}
		D[pre] = temp;
		Qsort(D,l,pre-1);
		Qsort(D,pre+1,r);
	}
}

void Write_Data(int n)
{
    srand(time(NULL));
    FILE *p;
    if((p = fopen("Data.txt","w+")) == NULL){
        printf("文件没有正确打开！\n");
        exit(0);
    }
    int temp;
    int i;
    for(i = 0 ; i < n; i++){
        temp = rand()%MAX_SIZE + 1;
        fprintf(p,"%d ",temp);
    }
    fclose(p);
}

void In_Data(int *D,int n)
{
    int i;
    FILE *p;
   if((p = fopen("Data.txt","r")) == NULL){
        printf("文件没有正确打开！\n");
        exit(0);
    }
     for(i = 0 ; i < n; i++)
        fscanf(p,"%d",&D[i]);
    fclose(p);
}

void Write_Result(int *D,int n)
{
    FILE *p;
    if((p = fopen("Result.txt","w+")) == NULL){
        printf("文件没有正确打开！\n");
        exit(0);
    }
    int i;
    for(i = 0 ; i < n; i++){
        fprintf(p,"%d ",D[i]);
    }
    fclose(p);
}
// 从第L个数据到第n个数据进行插入排序
void In_sort(int *D,int L,int n)
{
    int i, j;
    int temp;
    for(i = L; i < n; i++){
        temp = D[i];
        j = i - 1;
        while(j >= L-1 && temp < D[j]){
            D[j + 1] = D[j];
            j--;
        }
        D[j+1] = temp;
    }
}

int cmp(const void *a,const void *b)
{
    return(*(int *)a-*(int *)b);
}

void Line(int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("*");
    printf("\n");
}

void Qsort_2(int *D,int l, int r)
{
    int i_rand, temp;
    int pre = l; // 前指针
	int las = r; // 后指针
	i_rand = Zhong(D,l,r);
	temp = D[l];
	D[l] = D[i_rand];
	D[i_rand] = temp;
    temp = D[l]; // 取出第一个元素
	if(l < r){
		while(pre < las){
			while( pre < las && D[las] >= temp)
				las--;
			D[pre] = D[las];
			while(pre < las && D[pre] <= temp)
				pre++;
			D[las] = D[pre];
		}
		D[pre] = temp;
		Qsort(D,l,pre-1);
		Qsort(D,pre+1,r);
	}
}

void Qsort_3(int *D,int l, int r)
{
    if( (r-l) <= 8){
        In_sort(D,l+1,r+1);
        return;
    }
    else{
        int pre = l; // 前指针
        int las = r; // 后指针
        int temp = D[l]; // 取出第一个元素
        if(l < r){
            while(pre < las){
                while( pre < las && D[las] >= temp)
                    las--;
                D[pre] = D[las];
                while(pre < las && D[pre] <= temp)
                    pre++;
                D[las] = D[pre];
            }
            D[pre] = temp;
            Qsort(D,l,pre-1);
            Qsort(D,pre+1,r);
        }
    }
}


int Zhong(int *D,int l, int r)
{
    int M;
    int i, min = D[l], max = D[l];
    for(i = l+1; i <= r ;i++){
        if(D[i] < min)
            min = D[i];
        if(D[i] > max)
            max = D[i];
    }
    M = (min+max) / 2;

    for(i = l ;i <= r;i++){
            if(D[i] == M)
                return i;
    }
    return l;
}
// 希尔排序
void Xi_Er(int *D,int n)
{
    int i, j,gap ,temp;
    gap = n / 2 ;
    while(gap > 0){
        for(i = gap; i < n;i++){
            temp = D[i];
            j = i - gap;
            while(j >= 0 && temp < D[j]){
                D[j + gap] = D[j];
                j = j - gap;
            }
            D[j + gap] = temp;
        }
        gap = gap / 2;
    }
}

void Counter(int *D,int n)
{
    int i, j;
    int *T = (int*)malloc(MAX_SIZE*sizeof(int));
    for(i = 0 ; i < MAX_SIZE;i++){
        T[i] = 0;
    }
    for(i = 0 ; i < n; i++)
        T[D[i] - 1]++;
    for(i = 0,j = 0;i < MAX_SIZE;i++){
        while(T[i] > 0 ){
                D[j++] = i + 1;
                T[i]--;
        }
    }
    free(T);
}
