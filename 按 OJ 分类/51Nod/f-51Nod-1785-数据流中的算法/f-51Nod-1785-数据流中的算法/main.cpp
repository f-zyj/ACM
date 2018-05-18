//
//  main.cpp
//  f-51Nod-1785-数据流中的算法
//
//  Created by ZYJ on 2017/2/24.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>

const int MAXN = 1e6 + 10;
const int MAXK = 105;

int n, k, cnt = 0, sum = 0, temp = 0;
int f[MAXN];
int f_[MAXK];

inline void read(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

//  方差
double variance()
{
    double ave = sum * 1.0 / temp;
    
    double var = 0;
    for (int i = cnt; i > cnt - temp; i--)
    {
        var += (f[i] - ave) * (f[i] - ave);
    }
    
    return var / temp;
}

//  中位数
double midNum()
{
    int n = 0, a = -1, b = -1;
    int t = temp / 2, t_ = t + 1;
    
    for (int i = 0; i <= 100; i++)
    {
        n += f_[i];
        if (n >= t && a == -1)
        {
            a = i;
        }
        if (n >= t_ && b == -1)
        {
            b = i;
            break;
        }
    }
    
    if (temp & 1)
    {
        return b;
    }
    else
    {
        return (a + b) * 1.0 / 2;
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    read(n);
    read(k);
    
    int u;
    for (int i = 1; i <= n; i++)
    {
        read(u);
        if (u == 1)
        {
            read(f[++cnt]);
            if (cnt > k)
            {
                f_[f[cnt - k]]--;
                sum -= f[cnt - k];
            }
            f_[f[cnt]]++;
            sum += f[cnt];
            temp = cnt > k ? k : cnt;
        }
        else if (u == 2)
        {
            double num = sum / temp;
            printf("%.2lf\n", num);
        }
        else if (u == 3)
        {
            double var = variance();
            printf("%.2lf\n", var);
        }
        else
        {
            double mid = midNum();
            printf("%.2lf\n", mid);
        }
    }
    
    return 0;
}
