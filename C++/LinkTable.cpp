#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define LEN sizeof(Lnode)
//�б�ͷ
using namespace std;
static int flag=0;

typedef struct Lnode
{
	int data;
	struct Lnode *next;
} Lnode, *Linklist;

void InitList (Linklist *L)   //����ָ���Ŀ���ǵ�ַ���ݣ���Ϊ�ú���û�з���ֵ���õ�ַ���ݴ���ͷ�ڵ��ַ��
{
	Linklist p;
	p = (Linklist)malloc(sizeof(Lnode));
	if(p == NULL)
		cout <<"�����ڴ�ռ�ʧ�ܡ�" << endl;
	p->next=NULL;
	*L = p;
	flag++;
}//��ʼ��һ���յ�����

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
		cout << "���������١�" << endl;
	}
	else
		cout << "�������ڡ�" << endl;
	return OK;
	flag++;
}//��������

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
	cout << "�����й���" << i << "��Ԫ�ء�" << endl; 	
}//�������ĳ���.

void Creatlist(Linklist L,int n)
{
    int i;	
	Lnode *p,*pt;
	pt=L;
	for(i=1;i<=n;i++)
	{	
		p=(Linklist)malloc(sizeof(Lnode));
		if(p==NULL)
			cout << "�����ڴ�ռ�ʧ�ܡ�" << endl;
		cout << "������������Ԫ�أ�" << endl;
		cin >> p->data;		
		p->next=pt->next;
		pt->next=p;
		pt=p;
	}
	//flag++;
}//��������

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
		cout << "��λ�򲻴��ڡ�" << endl;
	else
	{
		e=p->data;
		cout << "��" << i << "��Ԫ��Ϊ��" << e << endl;
	}
	return OK;
}//��e����L�е�i������Ԫ�ص�ֵ.

void LocateElem(Linklist L,int *e)
{
	Lnode *p;
	int i=1;
	p=L->next;
	while(p!=NULL)
	 { 
		 if(p->data==*e)
		 {
			 cout << "Ԫ��" << *e <<"��λ���ǣ�" << i << endl;
			 break;
		 }
		 p=p->next;
		 i++;
	 }
	if(p==NULL)
		cout << "��Ԫ�ز����ڡ�" << endl;
}//��������������Ԫ�ص�λ��.

void PriorElem(Linklist L,int e)
{
	Lnode *p,*pt;
	int i=0;
	p=L->next;
	while(p!=NULL)
	{ 
		if(p->data==e && i!=0)
		{
			cout << "��Ԫ�ص�ֱ��ǰ���ǣ�" << pt->data << endl;
			break;
		}
		else if(p->data==e && i==0)
		{
			cout << "��Ԫ��û��ֱ��ǰ����" << endl;
			break;
		}
		pt=p;
		p=p->next;
		i++;
	}
	if(p==NULL)
		cout << "��Ԫ�ز����ڡ�" << endl;
}//��Ԫ�ص�ֱ��ǰ��.                    
                                                                                             
void NextElem(Linklist L,int e)
{
	Lnode *p;
	p=L->next;
	while(p!=NULL)
	 { 
		 if(p->data==e)
		 {
			 if(p->next!=NULL)
				 cout << "��Ԫ�ص�ֱ�Ӻ���ǣ�" << p->next->data << endl;
			 else
				 cout << "��Ԫ��û��ֱ�Ӻ�̡�" << endl;
			 break;
		 }
		 p=p->next;
	 }
	if(p==NULL)
		cout << "��Ԫ�ز����ڡ�" << endl;
}//��Ԫ�ص�ֱ�Ӻ�̡�

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
		cout << "�����ڴ�ռ�ʧ�ܡ�" << endl;
	s->data=e;
	s->next=p->next;
	p->next=s;
	cout << "�����Ԫ���ǣ�" << e << endl;
	return OK;
}//�ڵ�i��λ�ò���Ԫ��e

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
		cout << "��λ�򲻴��ڡ�" << endl;
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	cout << "ɾ����Ԫ���ǣ�" << q->data << endl;
    free(q);
	return OK;
}//ɾ����i������Ԫ�ز���e������ֵ.

int ListTraverse(Linklist L)
{
	Linklist p;
	p=L->next;
	if(p==NULL)
	{
		cout << "��������û��Ԫ�ء�" << endl;
		return OK;
	}
	cout << "����Ԫ�����£�" << endl;
	while(p)
	 {
		cout << p->data << endl;
		p=p->next;
	 }
	return OK;
}//���Ԫ��.

void Tips()
{
	cout << "��ִ�в����У�" << endl;
	cout << "*********************************************************" << endl;
	cout << "***************  1.��ʼ������������      ****************" << endl;
	cout << "***************  2.��������              ****************" << endl;
	cout << "***************  3.����������Ԫ�ظ���    ****************" << endl;
	cout << "***************  4.��ָλ���Ԫ��ֵ      ****************" << endl;
	cout << "***************  5.�����Ѵ���Ԫ�ص�λ��  ****************" << endl;
	cout << "***************  6.������Ԫ��,��ֱ��ǰ�� ****************" << endl;
	cout << "***************  7.������Ԫ��,��ֱ�Ӻ�� ****************" << endl;
	cout << "***************  8.�ڵ�i��λ�ò���Ԫ��   ****************" << endl;
	cout << "***************  9.ɾ����i��Ԫ��         ****************" << endl;
	cout << "***************  10.��������������Ԫ�� ****************" << endl;
	cout << "***************  11.��ʼ������������Ԫ�� ****************" << endl;
	cout << "***************  12.�˳�                 ****************" << endl;
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
		cout << "���������ѡ��";
		cin >> i;		
		switch(i)
		{
		case 1:
			{
				InitList(&L);
				cout << "�ɹ���ʼ��һ���յ�����" << endl;
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
					cout << "�������ڡ�" << endl;
				break;
			}
		case 4:
			{
				if(just)
				{
					cout << "��������ҪԪ�ص�λ��";
					cin >> n2;
					Getelem(L,n2);
				}
				else
					cout << "�������ڡ�" << endl;
				break;
			}
		case 5:
			{
				if(just)
				{
					cout << "����������Ҫ���ҵ�Ԫ�أ�";
					cin >> n4;
					LocateElem(L,&n4);
				}
				else
					cout << "�������ڡ�" << endl;
				break;
			}
		case 6:
			{
				if(just)
				{
					cout << "������Ԫ�أ�";
					cin >> m3;
					PriorElem(L,m3);
				}
				else
					cout << "�������ڡ�" << endl;
				break;
			}
		case 7:
			{
				if(just)
				{
					cout << "������Ԫ�أ�";
					cin >> m4;
					NextElem(L,m4);
				}
				else
					cout << "�������ڡ�" << endl;
				break;
			}
		case 8:
			{
				if(just)
				{
					cout << "���������Ԫ�أ�" ;
					cin >> m1;
					cout << "���������Ԫ�ص�λ�ã�" << endl;
					cin >> m2;
					Listinsert(L,m2,m1);
				}
				else
					cout << "�������ڡ�" << endl;
				break;
			}
		case 9:
			{
				if(just)
				{
					cout << "������ɾ��Ԫ�ص�λ�ã�" << endl;
					cin >> n1;
					Listdelete(L,n1);
				}
				else
						cout << "�������ڡ�" << endl;
				break;
			}
		case 10:
			{
				if(just)
					ListTraverse(L);
				else
					cout << "�������ڡ�" << endl;
				break;
			}
		case 11:
			{
				InitList(&L);
				cout << "�����������ȣ�";
				cin >> n5;
				Creatlist(L,n5);
				just=1;
				break;
			}
		case 12:
			{
				cout << "����������" << endl;
				exit(0);
			}
		default:
			{
				cout << "û�и�ѡ�������ѡ��" << endl;
				break;
			}
		}
		system("pause");
	}while(1);
}
