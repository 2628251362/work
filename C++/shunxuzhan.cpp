#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10   //存储空间分配增量
typedef int ElemType;
typedef int Status;
#define OVERFLOW -2
int flag = 0;
typedef struct
{
    ElemType *base; //在栈构造之前和销毁之后，base的值为NULL
    ElemType *top;  //栈顶指针
    int stacksize;  //当前已分配的存储空间，以元素为单位
} Stack;
//初始化栈
Status InitStack(Stack &S)
{
    S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S.base)
        exit(OVERFLOW); //存储分配失败
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    flag = 1;
    return 1;
}
//销毁栈
Status DestroyStack(Stack &S)
{
    if (flag == 1)
    {
        free(S.base);
        S.base = NULL;
        S.top = NULL;
        S.stacksize = 0;
        flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}
//清空栈
Status ClearStack(Stack &S)
{
    if (flag == 1)
    {
        S.top = S.base;
        return 1;
    }
    else
    {
        return 0;
    }
}
//栈判空
Status EmptyStack(Stack S)
{
    if (S.top == S.base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//求栈的长度
Status StackLength(Stack S)
{
    return S.top - S.base;
}
//取栈顶元素
Status GetTop(Stack S, ElemType &e)
{
    if (S.top > S.base)
    {
        e = *(S.top - 1);
        return 1;
    }
    else
    {
        return 0;
    }
}
//入栈
Status Push(Stack &S, ElemType e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (ElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return 1;
}
//出栈
Status Pop(Stack &S, ElemType &e)
{
    if (S.top == S.base)
        return 0;
    e = *--S.top;
    return 1;
}
//遍历栈
Status StackTraverse(Stack S)
{
    if (flag == 1)
    {
        while (S.top > S.base)
        {
            cout << *--S.top << " ";
        }
        cout << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
//进制转换
void conversion(int n, int d)
{
    Stack S;
    InitStack(S);
    int e;
    while (n)
    {
        Push(S, n % d);
        n = n / d;
    }
    while (!EmptyStack(S))
    {
        Pop(S, e);
        cout << e;
    }
    cout << endl;
    DestroyStack(S);
}
int main()
{
    Stack S;
    S.base = NULL;
    S.top = NULL;
    ElemType e;
    int n;
    cout << "1.初始化栈" << endl;
    cout << "2.销毁栈" << endl;
    cout << "3.清空栈" << endl;
    cout << "4.栈判空" << endl;
    cout << "5.求栈长度" << endl;
    cout << "6.获取栈顶元素" << endl;
    cout << "7.插入一个元素" << endl;
    cout << "8.删除一个元素" << endl;
    cout << "9.输出所有元素" << endl;
    cout << "10.进制转换" << endl;
    cout << "输出一个负数退出" << endl;
    do
    {
        cout << endl;
        cout << "请输入你的选择：";
        cin >> n;
        switch (n)
        {
        case 1:
            if ((InitStack(S)) == 1)
            {
                cout << "顺序栈初始化完成" << endl;
            };
            break;
        case 2:
            if (flag == 0)
            {
                cout << "顺序栈未初始化" << endl;
                break;
            }
            else if (DestroyStack(S) == 1)
            {
                cout << "顺序栈销毁完成" << endl;
            }
            else if (DestroyStack(S) == 0)
            {
                cout << "顺序栈销毁失败" << endl;
            };
            break;
        case 3:
            if (flag == 0)
            {
                cout << "顺序栈未初始化" << endl;
                break;
            }
            if (ClearStack(S) == 1)
            {
                cout << "成功清空顺序栈" << endl;
            }
            else if (ClearStack(S) == 0)
            {
                cout << "清空顺序栈失败" << endl;
            };
            break;
        case 4:
            if (flag == 0)
            {
                cout << "顺序栈未初始化" << endl;
                break;
            }
            else if (EmptyStack(S) == 1)
            {
                cout << "顺序栈为空" << endl;
            }
            else if (EmptyStack(S) == 0)
            {
                cout << "顺序栈不为空" << endl;
            };break;
        case 5:
            if (flag == 0)
            {
                cout << "顺序栈未初始化" << endl;
                break;
            }
            else
            {
                cout << "顺序栈的长度为：" << StackLength(S) << endl;
            }
            break;
        case 6:
            if (flag == 0)
            {
                cout << "顺序栈未初始化" << endl;
                break;
            }
            else if (GetTop(S, e) == 1)
            {
                cout << "顺序栈的栈顶元素为：" << e << endl;
            }
            else if (GetTop(S, e) == 0)
            {
                cout << "顺序栈为空" << endl;
            };
            break;
        case 7:
            if (flag == 0)
            {
                cout << "顺序栈未初始化" << endl;
                break;
            }
            cout << "请输入你要插入的元素：";
            cin >> e;
            if (Push(S, e) == 1)
            {
                cout << "元素" << e << "插入成功" << endl;
            }
            else if (Push(S, e) == 0)
            {
                cout << "插入失败" << endl;
            };
            break;
        case 8:
            if (flag == 0)
            {
                cout << "顺序栈未初始化" << endl;
                break;
            }
            if(Pop(S,e)==1)
            {
                cout<<"元素"<<e<<"删除成功"<<endl;
            }
            else if(Pop(S,e)==0)
            {
                cout<<"删除失败"<<endl;
            }
            break;
        case 9:
            if (flag == 0)
            {
                cout << "顺序栈未初始化" << endl;
                break;
            }if(EmptyStack(S)==1){
                cout<<"顺序栈为空"<<endl;
                break;
            }else{
                cout<<"顺序栈中的元素为：";
                StackTraverse(S);
            }
            break;
        case 10:
            int n, d;
            cout << "请输入你要转换的十进制数：";
            cin >> n;
            cout << "请输入你要转换的进制：";
            cin >> d;
            cout<<n<<"的"<<d<<"进制为：";
            conversion(n, d);
            break;

        default:
            break;
        }
    } while (n >= 0);
}
