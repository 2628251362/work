#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define LEN sizeof(Lnode)
//有表头
using namespace std;
static int flag=0;

typedef struct Lnode
{
	int data;
	struct Lnode *next;
} Lnode, *Linklist;

void InitList (Linklist *L)   //二级指针的目的是地址传递，因为该函数没有返回值，用地址传递带回头节点地址。
{
	Linklist p;
	p = (Linklist)malloc(sizeof(Lnode));
	if(p == NULL)
		cout <<"申请内存空间失败。" << endl;
	p->next=NULL;
	*L = p;
	flag++;
}//初始化一个空的链表

int DestroyList(Linklist L)
{
	Lnode *p;
	p=NULL;
	if(L && flag!=0)
	{
		while(L)
		{   
			p=L;
			L=L->next;
			free(p);	
		}
		cout << "链表已销毁。" << endl;
	}
	else
		cout << "链表不存在。" << endl;
	return OK;
	flag++;
}//销毁链表

void ListLength(Linklist L)
{	
	int i=0;
	Linklist p;
	p=L;
	while(p->next!=NULL)
	{ 
		i++;
		p=p->next;
	}
	cout << "链表中共有" << i << "个元素。" << endl; 	
}//输出链表的长度.

void Creatlist(Linklist L,int n)
{
    int i;	
	Lnode *p,*pt;
	pt=L;
	for(i=1;i<=n;i++)
	{	
		p=(Linklist)malloc(sizeof(Lnode));
		if(p==NULL)
			cout << "申请内存空间失败。" << endl;
		cout << "请输入链表中元素：" << endl;
		cin >> p->data;		
		p->next=pt->next;
		pt->next=p;
		pt=p;
	}
	//flag++;
}//创建链表

int Getelem(Linklist L, int i)
{
	Lnode *p;
	int e;
	int j;
	p=L->next;j=1;
	while (p && j<i)
	{
		p=p->next;
		++j;
	}
	if(!p || j>i)
		cout << "该位序不存在。" << endl;
	else
	{
		e=p->data;
		cout << "第" << i << "个元素为：" << e << endl;
	}
	return OK;
}//用e返回L中第i个数据元素的值.

void LocateElem(Linklist L,int *e)
{
	Lnode *p;
	int i=1;
	p=L->next;
	while(p!=NULL)
	 { 
		 if(p->data==*e)
		 {
			 cout << "元素" << *e <<"的位序是：" << i << endl;
			 break;
		 }
		 p=p->next;
		 i++;
	 }
	if(p==NULL)
		cout << "该元素不存在。" << endl;
}//输出与条件相符的元素的位序.

void PriorElem(Linklist L,int e)
{
	Lnode *p,*pt;
	int i=0;
	p=L->next;
	while(p!=NULL)
	{ 
		if(p->data==e && i!=0)
		{
			cout << "该元素的直接前驱是：" << pt->data << endl;
			break;
		}
		else if(p->data==e && i==0)
		{
			cout << "该元素没有直接前驱。" << endl;
			break;
		}
		pt=p;
		p=p->next;
		i++;
	}
	if(p==NULL)
		cout << "该元素不存在。" << endl;
}//求元素的直接前驱.                    
                                                                                             
void NextElem(Linklist L,int e)
{
	Lnode *p;
	p=L->next;
	while(p!=NULL)
	 { 
		 if(p->data==e)
		 {
			 if(p->next!=NULL)
				 cout << "该元素的直接后继是：" << p->next->data << endl;
			 else
				 cout << "该元素没有直接后继。" << endl;
			 break;
		 }
		 p=p->next;
	 }
	if(p==NULL)
		cout << "该元素不存在。" << endl;
}//求元素的直接后继。

int Listinsert(Linklist L,int i,int e)
{
	int j;
	Lnode *p,*s;
	p=L; j=0;
	while(p && j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p || j>i-1)
		return ERROR;
	s=(Linklist)malloc(sizeof(Lnode));
	if(s==NULL)
		cout << "申请内存空间失败。" << endl;
	s->data=e;
	s->next=p->next;
	p->next=s;
	cout << "插入的元素是：" << e << endl;
	return OK;
}//在第i个位置插入元素e

int Listdelete(Linklist L,int i)
{

	int j;
	Lnode *p,*q;
	p=L;j=0;
	while(p->next && j<i-1)
	{	
		p=p->next;
		++j;
	}
	if(!(p->next) || j>i-1)
	{
		cout << "该位序不存在。" << endl;
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	cout << "删除的元素是：" << q->data << endl;
    free(q);
	return OK;
}//删除第i个数据元素并用e返回其值.

int ListTraverse(Linklist L)
{
	Linklist p;
	p=L->next;
	if(p==NULL)
	{
		cout << "该链表中没有元素。" << endl;
		return OK;
	}
	cout << "链表元素如下：" << endl;
	while(p)
	 {
		cout << p->data << endl;
		p=p->next;
	 }
	return OK;
}//输出元素.

void Tips()
{
	cout << "可执行操作有：" << endl;
	cout << "*********************************************************" << endl;
	cout << "***************  1.初始化或重置链表      ****************" << endl;
	cout << "***************  2.销毁链表              ****************" << endl;
	cout << "***************  3.链表中数据元素个数    ****************" << endl;
	cout << "***************  4.所指位序的元素值      ****************" << endl;
	cout << "***************  5.链表已存在元素的位序  ****************" << endl;
	cout << "***************  6.请输入元素,求直接前驱 ****************" << endl;
	cout << "***************  7.请输入元素,求直接后继 ****************" << endl;
	cout << "***************  8.在第i个位置插入元素   ****************" << endl;
	cout << "***************  9.删除第i个元素         ****************" << endl;
	cout << "***************  10.输出所输入的链表元素 ****************" << endl;
	cout << "***************  11.初始化并输入链表元素 ****************" << endl;
	cout << "***************  12.退出                 ****************" << endl;
	cout << "*********************************************************" << endl;
}

int main()
{ 
	Linklist L; 
	int i,n2,n1,n4,n5,m1,m2,m3,m4;
	int just=0;
	do
	{
		system("cls");
		Tips();
		cout << "请输入你的选择：";
		cin >> i;		
		switch(i)
		{
		case 1:
			{
				InitList(&L);
				cout << "成功初始化一个空的链表！" << endl;
				just=1;
				break;
			}
		case 2:
			{
				DestroyList(L);
				just=0;
				break;
			}
		case 3:
			{
				if(just)
					ListLength(L);
				else
					cout << "链表不存在。" << endl;
				break;
			}
		case 4:
			{
				if(just)
				{
					cout << "请输入所要元素的位序：";
					cin >> n2;
					Getelem(L,n2);
				}
				else
					cout << "链表不存在。" << endl;
				break;
			}
		case 5:
			{
				if(just)
				{
					cout << "请输入你所要查找的元素：";
					cin >> n4;
					LocateElem(L,&n4);
				}
				else
					cout << "链表不存在。" << endl;
				break;
			}
		case 6:
			{
				if(just)
				{
					cout << "请输入元素：";
					cin >> m3;
					PriorElem(L,m3);
				}
				else
					cout << "链表不存在。" << endl;
				break;
			}
		case 7:
			{
				if(just)
				{
					cout << "请输入元素：";
					cin >> m4;
					NextElem(L,m4);
				}
				else
					cout << "链表不存在。" << endl;
				break;
			}
		case 8:
			{
				if(just)
				{
					cout << "请输入插入元素：" ;
					cin >> m1;
					cout << "请输入插入元素的位置：" << endl;
					cin >> m2;
					Listinsert(L,m2,m1);
				}
				else
					cout << "链表不存在。" << endl;
				break;
			}
		case 9:
			{
				if(just)
				{
					cout << "请输入删除元素的位置：" << endl;
					cin >> n1;
					Listdelete(L,n1);
				}
				else
						cout << "链表不存在。" << endl;
				break;
			}
		case 10:
			{
				if(just)
					ListTraverse(L);
				else
					cout << "链表不存在。" << endl;
				break;
			}
		case 11:
			{
				InitList(&L);
				cout << "请输入链表长度：";
				cin >> n5;
				Creatlist(L,n5);
				just=1;
				break;
			}
		case 12:
			{
				cout << "操作结束！" << endl;
				exit(0);
			}
		default:
			{
				cout << "没有该选项，请重新选择。" << endl;
				break;
			}
		}
		system("pause");
	}while(1);
}
