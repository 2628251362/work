#include <iostream>
#include <malloc.h>
using namespace std;
typedef int Elemtype;
typedef int Status;
int flag = 0; //初始化判定标记
//定义单链表存储结构
typedef struct Lnode
{
    Elemtype data;
    struct Lnode *next;
} Lnode, *LinkList;
//初始化或重置链表
Status IniList(LinkList &L)
{
    LinkList p;
    p = (LinkList)malloc(sizeof(Lnode));
    if (p == NULL)
    {
        flag = 0;
        return 0;
    }
    else
    {
        p->next = NULL;
        L = p;
        flag = 1;
        return 1;
    }
}
//销毁链表
Status DestoryList(LinkList &L)
{
    Lnode *p;
    while (L != NULL)
    {
        p = L;
        L = L->next;
        free(p); 
    }
    flag = 0; 
    return 1;
}
//清空链表
Status ClearList(LinkList L)
{
    Lnode *p, *q;
    p = L->next;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    return 1;
}
//链表长度
Status ListLength(LinkList L)
{
    Lnode *p;
    p = L->next;
    int i;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}
//指定位置元素的值
Status LocateElem(LinkList L, int i)
{
    int j = 1;
    Lnode *p;
    p = L->next;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i)
    {
        return 0;
    }
    else
    {
        return p->data;
    }
}
//指定元素的位序
Status GetElem(LinkList L, Elemtype e)
{
    Lnode *p;
    int i = 1;
    p = L->next;
    while (p != NULL)
    {
        if (p->data == e)
        {
            return e;
        }
        p = p->next;
        i++;
    }
}
//求前驱
Status PriorElem(LinkList L, Elemtype e)
{
    Lnode *p, *q;
    p = L->next;
    int i = 0;
    while (p != NULL)
    {
        if (e == p->data && i == 0)
        {
            return 0;
        }
        else if (e == p->data && i != 0)
        {
            return q->data;
        }
        q = p;
        p = p->next;
        i++;
    }
    if (p == NULL)
    {
        return -1;
    }
}
//求后继
Status NextElem(LinkList L, Elemtype e)
{
    Lnode *p;
    p = L->next;
    while (p != NULL)
    {
        if (e == p->data)
        {
            if (p->next == NULL)
            {
                return 0;
            }
            else
            {
                return p->next->data;
            }
        }
        p = p->next;
    }
    if (p == NULL)
    {
        return -1;
    }
}

//插入元素
Status InsertElem(LinkList L, int i, Elemtype e)
{
    Lnode *p, *q;
    p = L;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1)
    {
        return 0;
    }
    q = (LinkList)malloc(sizeof(Lnode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}
//删除第i个元素
Status DeleteElem(LinkList L, int i)
{
    Lnode *p, *q;
    p = L;
    int j;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i - 1)
    {
        return 0;
    }
    q = p->next;
    p->next = q->next;
    int a;
    a = q->data;
    free(q);
    return a;
}
//输出链表
Status PutList(LinkList L)
{
    Lnode *p;
    p = L->next;
    if (p == NULL)
    {
        return 0;
    }
    else if (p)
    {
        return 1;
    }
}
//初始化链表并输入元素
Status CreateList(LinkList &L, int num)
{

    LinkList p;
    L = (LinkList)malloc(sizeof(Lnode));
    flag = 1;
    p = L;
    int a;
    for (int i = 0; i < num; i++)
    {
        LinkList q = (LinkList)malloc(sizeof(Lnode));
        cin >> a;
        q->data = a;
        p->next = q;  
        p = q;
    }
    p->next = NULL;
    return 1;
}
//实现单链表的逆序存放
Status ReverseList(LinkList &L)
{
    Lnode *p, *q;
    p = L->next; //p指向第一个结点
    L->next = NULL; //头结点指针域为空
    while (p != NULL)
    {
        q = p->next; //q指向下一个结点
        p->next = L->next; //将p结点插入到头结点之后
        L->next = p; //将p结点插入到头结点之后
        p = q; //p指向下一个结点
    }
    return 1;
}
int main()
{
    LinkList L;
    int n, i, i1;
    cout << "1.初始化或重置链表" << endl;
    cout << "2.销毁链表" << endl;
    cout << "3.清空链表" << endl;
    cout << "4.链表长度" << endl;
    cout << "5.指定位置的元素值" << endl;
    cout << "6.链表已存在元素的位序" << endl;
    cout << "7.求输入元素的直接前驱" << endl;
    cout << "8.求输入元素的直接后继" << endl;
    cout << "9.在第i个位置插入一个元素" << endl;
    cout << "10.删除第i个元素" << endl;
    cout << "11.输出有的链表元素" << endl;
    cout << "12.初始化并用头插法输入元素" << endl;
    cout << "13.实现单链表的逆序存放" << endl;
    cout << "\t退出，输入一个负数！" << endl;
    do
    {
        cout << endl
             << endl;
        cout << "请输入你的选择:";
        cin >> n;
        switch (n)
        {
        case 1:
            if (IniList(L) == 1)
            {
                cout << "初始化链表成功!";
            }
            else if (IniList(L) == 0)
            {
                cout << "初始化链表失败!";
            }
            break;
        case 2:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            else if (DestoryList(L) == 1)
            {
                cout << "销毁链表成功!";
            }
            break;
        case 3:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            else if (ClearList(L) == 1)
            {
                cout << "清空链表成功!";
            }
            break;
        case 4:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            else
            {
                cout << "链表长度为:" << ListLength(L);
                break;
            }
        case 5:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            else
            {
                cout << "请输入要查找的位置:";
                cin >> i;
                if (LocateElem(L, i) == 0)
                {
                    cout << "该位序不存在!";
                    break;
                }
                else
                {
                    cout << "第" << i << "位的值为:" << LocateElem(L, i);
                    break;
                }
            }
        case 6:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            cout << "请输入要查询的元素:";
            Elemtype e;
            cin >> e;
            if (GetElem(L, e) == 0)
            {
                cout << "该链表不存在此元素!";
                break;
            }
            else
            {
                cout << "该元素的位序为:" << GetElem(L, e);
                break;
            }
        case 7:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            cout << "请输入元素:";
            cin >> e;
            if (PriorElem(L, e) == 0)
            {
                cout << "此元素无前驱!";
                break;
            }
            else if (PriorElem(L, e) == -1)
            {
                cout << "当前链表不存在此元素!";
                break;
            }
            else
            {
                cout << "该元素的前驱为:" << PriorElem(L, e);
                break;
            }
        case 8:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            cout << "请输入元素:";
            cin >> e;
            if (NextElem(L, e) == 0)
            {
                cout << "此元素无后继!";
                break;
            }
            else if (NextElem(L, e) == -1)
            {
                cout << "当前链表不存在此元素!";
                break;
            }
            else
            {
                cout << "该元素的后继为:" << NextElem(L, e);
                break;
            }
        case 9:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            cout << "请输入要插入的位置:";
            cin >> i;
            cout << "请输入要插入的元素:";
            cin >> e;
            if (InsertElem(L, i, e) == 0)
            {
                cout << "此位序超出链表长度!";
                break;
            }
            else
            {
                cout << "元素" << e << "在第" << i << "个位置成功插入!";
                break;
            }
        case 10:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            cout << "请输入要删除的位置:";
            cin >> i;
            int a;
            if ((a = DeleteElem(L, i)) == 0)
            {
                cout << "此位序超出链表长度!";
                break;
            }
            else
            {
                cout << "第" << i << "个位置上的元素" << a << "已成功删除!";
                break;
            }
        case 11:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            if (PutList(L) == 0)
            {
                cout << "该链表无元素存在!";
                break;
            }
            else
            {
                cout << "该链表元素为:";
                Lnode *p;
                p = L->next;
                while (p)
                {
                    cout << p->data << " ";
                    p = p->next;
                }
                break;
            }
        case 12:
            int num;
            cout << "请输入要插入的元素个数:";
            cin >> num;
            cout << "请输入元素:";
            CreateList(L, num);
            break;
        case 13:
            if (flag == 0)
            {
                cout << "请先进行初始化!";
                break;
            }
            else if (ReverseList(L) == 1)
            {
                cout << "该链表元素为:";
                Lnode *p;
                p = L->next;
                while (p)
                {
                    cout << p->data << " ";
                    p = p->next;
                }
                break;
            }

        default:
            break;
        }
    } while (n > 0);
}