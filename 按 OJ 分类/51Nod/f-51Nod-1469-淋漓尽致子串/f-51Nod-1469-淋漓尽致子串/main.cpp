//
//  main.cpp
//  f-51Nod-1469-淋漓尽致子串
//
//  Created by ZYJ on 2017/7/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAGIC = 128;

char arr[MAXN];
int t1[MAXN], t2[MAXN], c[MAXN];
int sa[MAXN], rk[MAXN], height[MAXN];


int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(char str[], int n, int m)
{
    n++;
    int i, j, p, *x = t1, *y = t2;      //  第一轮基数排序,如果s的最大值很大,可改为快速排序
    for (i = 0; i < m; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[x[i] = str[i]]++;
    }
    for (i = 1; i < m; i++)
    {
        c[i] += c[i-1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        sa[--c[x[i]]] = i;
    }
    for (j = 1; j <= n; j <<= 1)
    {
        p = 0;
        //  直接利用sa数组排序第二关键字
        for (i = n - j; i < n; i++)
        {
            y[p++] = i;                 //  后面的j个数第二关键字为空的最小
        }
        for (i = 0; i < n; i++)
        {
            if (sa[i] >= j)
            {
                y[p++] = sa[i] - j;     //  这样数组y保存的就是按照第二关键字排序的结果
            }
        }
        //  基数排序第一关键字
        for (i = 0; i < m; i++)
        {
            c[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            c[x[y[i]]]++;
        }
        for (i = 1; i < m; i++)
        {
            c[i] += c[i - 1];
        }
        for (i = n - 1; i >= 0; i--)
        {
            sa[--c[x[y[i]]]] = y[i];    //  根据sa和x数组计算新的x数组
        }
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++)
        {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
        if (p >= n)
        {
            break;
        }
        m = p;                          //  下次基数排序的最大值
    }
    
    int k = 0;
    n--;
    for (i = 0; i <= n; i++)
    {
        rk[sa[i]] = i;
    }
    for (i = 0; i < n; i++)
    {
        if (k)
        {
            k--;
        }
        j = sa[rk[i] - 1];
        while (str[i + k] == str[j + k])
        {
            k++;
        }
        height[rk[i]] = k;
    }
}

map<char, int> mci;

int solve(int len)
{
    mci.clear();
    int pre = 0;
    int ans = 0;
    bool up = false;
    for (int i = len; i >= 1; i--)
    {
        if (height[i] > pre)
        {
            up = true;
            mci.clear();
            pre = height[i];
            if (sa[i] - 1 >= 0)
            {
                mci[arr[sa[i] - 1]]++;
            }
            if (sa[i - 1] - 1 >= 0)
            {
                mci[arr[sa[i - 1] - 1]]++;
            }
        }
        else if (height[i] == pre)
        {
            pre = height[i];
            if (sa[i - 1] - 1 >= 0)
            {
                mci[arr[sa[i - 1] - 1]]++;
            }
        }
        else if (height[i] < pre)
        {
            pre = height[i];
            if (up == true)
            {
                bool flag = true;
                for (auto it = mci.begin(); it != mci.end(); it++)
                {
                    if (it->second > 1)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    ans++;
                }
                up = false;
                mci.clear();
            }
        }
    }
    
    return ans;
}

int main()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    while (scanf("%s", arr) != EOF)
    {
        int len = (int)strlen(arr);
        arr[len] = 0;
        da(arr, len, MAGIC);

        cout << solve(len) << endl;
    }
    return 0;
}

