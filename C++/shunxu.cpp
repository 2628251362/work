#include <iostream>
using namespace std;
#define size 100
#define incre 10
typedef int ElemType;
typedef int Status;
//定义结构体
typedef struct
{
    ElemType *elem;
    int Length;
    int ListSize;
} SqList;
SqList l_1; //定义顺序表
SqList l_2; //定义合成后的顺序表
Status IniList(SqList &l_1);
Status DestoryList(SqList &l_1);
Status ClearList(SqList &l_1);
Status JudgeList(SqList l_1);
Status ListLength(SqList l_1);
Status Elem(SqList l_1, int i);
Status position(SqList l_1, int e);
Status pre(SqList l_1, int e, int *pre_e);
Status next(SqList l_1, int e, int *next_e);
Status Insert(SqList &l_1, int i, int e);
Status Delete(SqList &l_1, int i);
Status View(SqList l_1);
int gether(SqList la, SqList lb, SqList &l_2);
int main()
{
    int n, i, e, pre_e, next_e;
    SqList la;
    SqList lb;
    cout << "1.初始化线性表" << endl;
    cout << "2.销毁线性表" << endl;
    cout << "3.清空线性表" << endl;
    cout << "4.判断线性表是否为空" << endl;
    cout << "5.求线性表长度" << endl;
    cout << "6.获取线性表中指定位置的元素" << endl;
    cout << "7.获取线性表元素的位置" << endl;
    cout << "8.求前驱" << endl;
    cout << "9.求后驱" << endl;
    cout << "10.在线性表指定位置插入元素" << endl;
    cout << "11.删除线性表指定位置的元素" << endl;
    cout << "12.显示线性表" << endl;
    cout << "13.合并两个非递减有序的线性表" << endl;
    cout << "\t退出，输入一个负数！" << endl;
    do
    {
        cout << endl;
        cout << "请输入你的选择:";
        cin >> n;
        switch ((n))
        {
        case 1:
            IniList(l_1);
            break;
        case 2:
            DestoryList(l_1);
            break;
        case 3:
            ClearList(l_1);
            break;
        case 4:
            JudgeList(l_1);
            break;
        case 5:
            ListLength(l_1);
            break;
        case 6:
            cout << "请输入要指定的位置:";
            cin >> i;
            Elem(l_1, i);
            break;
        case 7:
            cout << "获取线性表元素的位置:";
            cin >> e;
            position(l_1, e);
            break;
        case 8:
            cout << "输入元素，求前驱：";
            cin >> e;
            pre(l_1, e, &pre_e);
            break;
        case 9:
            cout << "输入元素，求后驱：";
            cin >> e;
            next(l_1, e, &next_e);
            break;
        case 10:
            cout << "输入指定位置：";
            cin >> i;
            cout << "请输入要插入的元素：";
            cin >> e;
            Insert(l_1, i, e);
            break;
        case 11:
            cout << "请输入要输入的元素位置:";
            cin >> i;
            cout << endl;
            Delete(l_1, i);
            break;
        case 12:
            View(l_1);
            break;
        case 13:
            IniList(la);
            IniList(lb);
            l_2.elem = (ElemType *)malloc(size * sizeof(ElemType));
            gether(la, lb, l_2);
            break;
        default:
            cout << "请输入0~13的数";
            break;
        }
    } while (n > 0);
}
//初始化顺序表
Status IniList(SqList &l_1)
{
    l_1.elem = (ElemType *)malloc(size * sizeof(ElemType));
    if (!l_1.elem)
    {
        cout << "初始化失败，请重新初始化";
        return 0;
    }
    else
    {
        l_1.Length = 0;
        l_1.ListSize = size;
        cout << "初始化成功！" << endl;
        return 1;
    }
}
//销毁线性表表
Status DestoryList(SqList &l_1)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！" << endl;
        return 0;
    }
    else
    {
        free(l_1.elem);
        l_1.elem = NULL;
        l_1.Length = 0;
        l_1.ListSize = 0;
        cout << "线性表销毁成功" << endl;
        return 1;
    }
}
//清空线性表
Status ClearList(SqList &l_1)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    else
    {
        l_1.Length = 0;
        cout << "线性表啊清除成功!" << endl;
        return 1;
    }
}
//判断线性表是否为空
Status JudgeList(SqList l_1)
{
    if (l_1.Length == 0)
    {
        cout << "该线性表为空！" << endl;
        return 0;
    }
    else
    {
        cout << "该线性表不为空！" << endl;
        return 1;
    }
}
//求线性表长度
Status ListLength(SqList l_1)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    else
    {
        cout << "线性表长度为:" << l_1.Length << endl;
        return 1;
    }
}
//获取指定位置的元素
Status Elem(SqList l_1, int i)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    else if (i < 1 || i > l_1.Length)
    {
        cout << "请输入长度范围内的数！" << endl;
        return 0;
    }
    else
    {
        cout << "该元素为" << l_1.elem[i - 1] << endl;
        return 1;
    }
}
//获取指定元素的位置
Status position(SqList l_1, int e)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    int flag = 0;
    for (int i = 0; i < l_1.Length; i++)
    {
        if (l_1.elem[i] == e)
        {
            cout << "该元素的位置为:" << i + 1 << endl;
            return 1;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "请输入存在此线性表的元素！" << endl;
        return 0;
    }
}
//求前驱
Status pre(SqList l_1, int e, int *pre_e)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    for (int i = 0; i < l_1.Length; i++)
    {
        if (l_1.elem[i] == e)
        {
            if (i == 0)
            {
                cout << "该元素无前驱" << endl;
                return 0;
            }
            else
            {
                *pre_e = l_1.elem[i - 1];
                cout << "该元素的前驱为:" << *pre_e << endl;
                return 1;
            }
        }
    }
}
//求后继
Status next(SqList l_1, int e, int *next_e)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    for (int i = 0; i < l_1.Length; i++)
    {
        if (l_1.elem[i] == e)
        {
            if (i == l_1.Length - 1)
            {
                cout << "该元素无后继" << endl;
                return 0;
            }
            else
            {
                *next_e = l_1.elem[i + 1];
                cout << "该元素的前驱为:" << *next_e << endl;
                return 1;
            }
        }
    }
}
//插入指定位置元素
Status Insert(SqList &l_1, int i, int e)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    if (i < 1 || i > l_1.Length + 1)
    {
        cout << "请输入线性表长度以内的数" << endl;
        return 0;
    }
    if (l_1.Length >= l_1.ListSize)
    {
        int *newbase;
        newbase = (ElemType *)realloc(l_1.elem, (l_1.ListSize + incre) * sizeof(ElemType));
        l_1.elem = newbase;
        l_1.ListSize += incre;
    }
    int *q;
    q = &(l_1.elem[i - 1]);
    for (int *p = &(l_1.elem[l_1.Length - 1]); p >= q; --p)
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++l_1.Length;
}
//删除指定位置元素
Status Delete(SqList &l_1, int i)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    if (i < 1 || i > l_1.Length + 1)
    {
        cout << "请输入线性表长度以内的数" << endl;
        return 0;
    }
    for (int j = i - 1; j <= l_1.Length; j++)
    {
        l_1.elem[j] = l_1.elem[j + 1];
    }
    l_1.Length--;
    cout << "元素删除成功!" << endl;
    return 1;
}
//显示线性表
Status View(SqList l_1)
{
    if (l_1.elem == NULL)
    {
        cout << "请先进行初始化！";
        return 0;
    }
    cout << "该线性表为:";
    for (int i = 0; i < l_1.Length; i++)
    {
        cout << l_1.elem[i] << " ";
    }
    cout << endl;
    return 1;
}
//合并非递减有序线性表
int gether(SqList la, SqList lb, SqList &l_2)
{
    int num;
    la.elem = (ElemType *)malloc(size * sizeof(ElemType));
    la.Length = 0;
    la.ListSize=size;
    cout << "线性表a初始化成功！" << endl;
    cout << "请输入你要输入的个数:";
    cin >> num;
    cout << "请输入数据:";
    for (int i = 0; i < num; i++)
    {
        cin >> la.elem[i];
        la.Length++;
    }
    lb.elem = (ElemType *)malloc(size * sizeof(ElemType));
    lb.Length = 0;
    lb.ListSize=size;
    cout << "线性表b初始化成功！" << endl;
    cout << "请输入你要输入的个数:";
    cin >> num;
    cout << "请输入数据:";
    for (int i = 0; i < num; i++)
    {
        cin >> lb.elem[i];
        lb.Length++;
    }
    cout<<"线性表a:";
    View(la);
    cout<<"线性表b:";
    View(lb);
    l_2.elem = (ElemType *)malloc(size * sizeof(ElemType));
    if (!l_2.elem)
    {
        cout << "合并线性表C创建失败，请重新创建！" << endl;
    }
    else
    {
        cout << "合并线性表C的内存空间分配成功！" << endl;
        int *pa, *pb, *p_2, *pa_last, *pb_last;
        pa = la.elem;
        pb = lb.elem;
        l_2.Length = la.Length + lb.Length;
        p_2 = l_2.elem = (ElemType *)malloc(size * sizeof(ElemType));
        pa_last = la.elem + la.Length - 1;
        pb_last = lb.elem + lb.Length - 1;
        while (pa <= pa_last && pb <= pb_last) //归并
        {
            if (*pa <= *pb)
            {
                *p_2 = *pa;
                *p_2++;
                *pa++;
            }
            else
            {
                *p_2 = *pb;
                *p_2++;
                *pb++;
            }
        }
        while (pa <= pa_last) //插入la的剩余元素
        {
            *p_2 = *pa;
            *p_2++;
            *pa++;
        }
        while (pb <= pb_last) //插入lb的剩余元素
        {
            *p_2 = *pb;
            *p_2++;
            *pb++;
        }
        for (int i = 0; i <= l_2.Length - 1; i++) //查重，去重复值。
        {
            if (l_2.elem[i] == l_2.elem[i + 1])
            {
                for (int j = i + 1; j <= l_2.Length - 1; j++)
                {
                    l_2.elem[j] = l_2.elem[j + 1];
                }
                l_2.Length--;
            }
        }
        cout << "合并后" << endl;
        View(l_2);
    }
}