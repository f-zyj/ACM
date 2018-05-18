//
//  main.cpp
//  f-51Nod-1438-方阵与完全平方数
//
//  Created by ZYJ on 16/9/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 65;
const int MAXM = 1e4;
const int MAXV = 6e4 + 4e5;

int n, tag = 0;
int square_flag[MAXM];
int val_flag[MAXV];

long long val[MAXN][MAXN];

//  查找完全平方数的平方根
long long sear(long long num)
{
    long long i;
    for (i = 2; ; i++)
    {
        if (i * i >= num && ((i < MAXM && !square_flag[i]) || (i >= MAXM)))
        {
            return i;
        }
    }
}

void dfs(int x, int y, long long value)
{
    if (tag == 1)
    {
        return ;
    }
    //  (n, n)位置
    if (x == n && y == n)
    {
        long long i, h, k, sumA = 0, sumB = 0;
        for (i = 1; i <= n - 1; i++)
        {
            sumA += val[i][y];
        }
        for (i = 1; i <= n - 1; i++)
        {
            sumB += val[x][i];
        }
        for (i = 2; ; i++)
        {
            if ((i < MAXM && square_flag[i] == 1))
            {
                continue;
            }
            double g = sqrt(i * i - sumA + sumB);
            
            //  这里并不安全，但是大于MAXM的时候冲突的可能性微乎其微
            if (i * i - sumA > 0 && g == (int)g &&
                ((g < MAXM && square_flag[(int)g] == 0) || g >= MAXM))
            {
                val[x][y] = i * i - sumA;
                for (h = 1; h <= n; h++)
                {
                    for (k = 1; k <= n; k++)
                    {
                        cout << val[h][k] << " ";
                    }
                    cout << endl;
                }
                tag = 1;
                return ;
            }
            long long diff = sumB - sumA;
            if ((i + 1) * (i + 1) - (i * i) > diff)
            {
                long long op, sum_op = 0;
                for (op = 1; op <= n; op++)
                {
                    sum_op += val[op][y - 1];
                }
                square_flag[(int)sqrt(sum_op)] = 0;
                dfs(x, y - 1, value + 1);
                return ;
            }
        }
    }
    //  最后一行
    else if (x == n)
    {
        long long i, sum = 0;
        for (i = 1; i <= n - 1; i++)
        {
            sum += val[i][y];
        }
        i = sear(sum + value);
        while (val_flag[i * i - sum] == 1 || square_flag[i] == 1)
        {
            i++;
        }
        val[x][y] = i * i - sum;
        val_flag[i * i - sum] = 1;
        square_flag[i] = 1;
        
        dfs(x, y + 1, value);
    }
    //  最后一列
    else if (y == n)
    {
        long long i, sum = 0;
        for (i = 1; i <= n - 1; i++)
        {
            sum += val[x][i];
        }
        i = sear(sum + value);
        
        while (val_flag[i * i - sum] == 1)
        {
            i++;
        }
        val[x][y] = i * i - sum;
        val_flag[i * i - sum] = 1;
        square_flag[i] = 1;
        
        dfs(x + 1, 1, value);
    }
    //  其他位置
    else
    {
        val[x][y] = value;
        val_flag[value] = 1;
        if (val_flag[value + 1] == 0)
        {
            dfs(x, y + 1, value + 1);
        }
        else
        {
            while (val_flag[value + 1] == 1)
            {
                value++;
            }
            dfs(x, y + 1, value + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    //  只有n为1的时候，无解
    if (n == 1)
    {
        cout << "No Solution\n" << endl;
    }
    else
    {
        dfs(1, 1, 1);
    }
    
    return 0;
}