#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define LENGTH 30

typedef struct SList
{
     char name[LENGTH];
     int count;
    struct SList* next;
}Node, * node;

void Create(node& L);//创建
void Insert(node& L, const char(&usersname)[30], int i);//插入
void Traverse(node L);//遍历
void Delete(node& L, int i);//删除
void Destory(node& L);//销毁
void BubbleSort(node& L, int n);//冒泡
void QuickSort(node L, node s);//快速


int main()
{
	char users[LENGTH];
	char line[LENGTH];

	int i = 0, 
	j = 0;
	int k = 1;

	node L1;

	Create(L1);

	FILE* fp;

	fopen_s(&fp, "D:\\user_login.txt", "r");//打开文件

	while (k <= 100000)
	{
		fscanf_s(fp, "%s", line, 30);

		for (i = 0; i < sizeof(line); ++i)
		{
			if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
			{
				users[j] = line[i];
				j++;
			}
		}

		j = 0;

		Insert(L1, users, k);

		k++;
	}

	Traverse(L1);


    return 0;
}

void Create(node &L)
{
	L = (node)malloc(sizeof(Node));
	L->count = 0;
	L->next = NULL;
}

void Insert(node &L, const char (&usersname)[30], int i)
{
	node p = L;
	node s;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		printf("ERROR!\n");
		return;
	}
	s = (node)malloc(sizeof(Node));
	strcpy(s->name, usersname);
	s->next = p->next;
	p->next = s;
}

void Traverse(node L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%s\n", L->name);
		L = L->next;
	}
}

void Delete(node &L, int i)
{
	node p = L;
	node q;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
	{
		printf("ERROR");
		return;
	}
	q = p->next;
	p->next = q->next;
	free(q);
}

void Destory(node &L)
{
	Traverse(L);
	free(L);
}

void BubbleSort(node &L, int n)
{
	node p, q;
	int temp, i;

	for (p = L, i = 1; i < n; i++, p = p->next)
	{
	  for (q = p->next; q != NULL; q = q->next)
	   {
	       if (p->count < q->count)
		{
			temp = p->count;
			p->count = q->count;
			q->count = temp;
		}
	   }
	}
}

void QuickSort(node L, node s)
{
	if (L->next != s && L->next->next != s)
	{
		node key = L->next;
		node LP = L;
		node RP = key;
		node P = key->next;

		while (P != s)
		{
			if (P->count < key->count)
			{
			  LP = LP->next = P;
			}
			else
			{
			  RP = RP->next = P;
			}
			P = P->next;
		}

		LP->next = key;
		RP->next = s;

		QuickSort(L, key);
		QuickSort(key, s);
	}
}






