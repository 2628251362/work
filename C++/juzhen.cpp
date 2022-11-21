#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int m;
    cout<<"请输入矩阵的维数：";
    cin>>m;
    int a[m][m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]=0;
        }
    }
    cout<<"请输入二元关系的个数:";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cout<<"请输入第"<<i+1<<"个二元关系(以空格隔开):";
        cin>>x>>y;
        a[x-1][y-1]=1;
    }
    //输出原矩阵
    cout<<"原矩阵为："<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    //自反性判断
    int zflag=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][i]!=1)
            {
                    zflag=0;
                    break;
            }
        }
    }
    if(zflag==0)
    {
        cout<<"该矩阵不自反"<<endl;
    }
    else
    {
        cout<<"该矩阵自反"<<endl;
    }
    //对称性判断
    int dflag=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!=a[j][i])
            {
                dflag = 0;
                break;
            }
        }
        if( dflag == 0)
        {
            cout<<"该矩阵不对称"<<endl;
            break;
        }
        else
        {
            cout<<"该矩阵对称"<<endl;
            break;
        }
    }
    //反对称性判断
    int fdflag=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==-a[j][i])
            {
                fdflag=0;
                break;
            }
        }
    }
    if(fdflag==0)
    {
        cout<<"该矩阵不反对称"<<endl;
    }
    else
    {
        cout<<"该矩阵反对称"<<endl;
    }
    //传递性判断
    int tflag=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(a[i][j]==1&&a[j][k]==1&&a[i][k]!=1)
                {
                    tflag=0;
                    break;
                }
            }
        }
    }
    if(tflag==0)
    {
        cout<<"该矩阵不具有传递性"<<endl;
    }
    else
    {
        cout<<"该矩阵具有传递性"<<endl;
    }
    getchar();
    getchar();
    return 0;
}