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
    printf("һ���ж������ݣ�\t");
    scanf("%d",&n);
    D = (int *)malloc(n*sizeof(int));
    T_1 = time(NULL);
    Write_Data(n);
    T_2 = time(NULL);
    Line(80);

    printf("д������ = %d ��\n",(int)T_2-(int)T_1);
    Line(80);
    printf("������\n0���˳�����\n1����ͨ��������\n2����������2.0\n3����������3.0\n4��ϵͳ����\n5����������\n6��ϣ������\n7����������\n");
    do{
        Line(80);
        printf("���������ѡ��:\t");
        scanf("%d",&reply);
        switch(reply){
        case 1:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("��ͨ����\n��ȡ���� = %d ��\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Qsort(D,0,n-1); // �������±�ʼ
            T_2 = time(NULL);
            printf("����ʱ�� = %d ��\n\n",(int)T_2-(int)T_1);
            break;
        case 2:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("��������2.0\n��ȡ���� = %d ��\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Qsort_2(D,0,n-1);
            T_2 = time(NULL);
            printf("��������2.0 = %d ��\n\n",(int)T_2-(int)T_1);
            break;
        case 3:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("��������3.0\n��ȡ���� = %d ��\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Qsort_3(D,0,n-1);
            T_2 = time(NULL);
            printf("��������3.0 = %d ��\n\n",(int)T_2-(int)T_1);
            break;
        case 4:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("ϵͳ����\n��ȡ���� = %d ��\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            qsort(D,n,sizeof(D[0]),cmp);
            T_2 = time(NULL);
            printf("ϵͳ���� = %d ��\n\n",(int)T_2-(int)T_1);
            break;
        case 5:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("��������\n��ȡ���� = %d ��\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            In_sort(D,1,n);
            T_2 = time(NULL);
            printf("�������� = %d ��\n\n",(int)T_2-(int)T_1);
            break;
        case 6:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("ϣ������\n��ȡ���� = %d ��\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Xi_Er(D,n);
            T_2 = time(NULL);
            printf("ϣ������ = %d ��\n\n",(int)T_2-(int)T_1);
            break;
        case 7:
            T_1 = time(NULL);
            In_Data(D,n);
            T_2 = time(NULL);
            Line(80);
            printf("��������\n��ȡ���� = %d ��\n",(int)T_2-(int)T_1);
            T_1 = time(NULL);
            Counter(D,n);
            T_2 = time(NULL);
            printf("�������� = %d ��\n\n",(int)T_2-(int)T_1);
            break;
        default:
            break;
        }
    }while(reply != 0);
    T_1 = time(NULL);
    Write_Result(D,n);
    T_2 = time(NULL);
    Line(80);
    printf("д���� = %d ��\n",(int)T_2-(int)T_1);
    free(D);
    return 0;
}

void Qsort(int *D,int l, int r)
{
    int pre = l; // ǰָ��
	int las = r; // ��ָ��
	int temp = D[l]; // ȡ����һ��Ԫ��
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
        printf("�ļ�û����ȷ�򿪣�\n");
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
        printf("�ļ�û����ȷ�򿪣�\n");
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
        printf("�ļ�û����ȷ�򿪣�\n");
        exit(0);
    }
    int i;
    for(i = 0 ; i < n; i++){
        fprintf(p,"%d ",D[i]);
    }
    fclose(p);
}
// �ӵ�L�����ݵ���n�����ݽ��в�������
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
    int pre = l; // ǰָ��
	int las = r; // ��ָ��
	i_rand = Zhong(D,l,r);
	temp = D[l];
	D[l] = D[i_rand];
	D[i_rand] = temp;
    temp = D[l]; // ȡ����һ��Ԫ��
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
        int pre = l; // ǰָ��
        int las = r; // ��ָ��
        int temp = D[l]; // ȡ����һ��Ԫ��
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
// ϣ������
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
