//
//  main.cpp
//  f-51Nod-1821-最优集合
//
//  Created by ZYJ on 2017/3/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1010;

int m[MAXN];
int temp[MAXN], key[MAXN], tp;
int s[MAXN][MAXN];
int sk[MAXN], top;  //  栈

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
    return true;
}

int exc(int n, int m)
{
    int res = 0;
    
    for (int i = 0; i < m; i++)
    {
        if (s[n][i] <= res + 1)
        {
            res += s[n][i];
        }
        else
        {
            key[n] = i;
            break;
        }
    }
    
    return res;
}

int main(int argc, const char * argv[])
{
    //    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int n;
    scan_d(n);
    
    for (int i = 1; i <= n; i++)
    {
        scan_d(m[i]);
        for (int j = 0; j < m[i]; j++)
        {
            scan_d(s[i][j]);
        }
        sort(s[i], s[i] + m[i]);
        temp[i] = exc(i, m[i]);
    }
    
    int T;
    scan_d(T);
    
    int a, b, k;
    while (T--)
    {
        scan_d(a);
        scan_d(b);
        scan_d(k);
        
        top = 0;
        tp = temp[a];
        int j = 0;
        
        for (int i = key[a]; i < m[a]; i++)
        {
            if (s[a][i] <= tp + 1)
            {
                tp += s[a][i];
            }
            else
            {
                if (!k)
                {
                    break;
                }
                int flag = 1;
                for (; j < m[b]; j++)
                {
                    if (s[b][j] <= tp + 1)
                    {
                        sk[top++] = s[b][j];
                    }
                    else
                    {
                        if (!top)
                        {
                            break;
                        }
                        tp += sk[--top];
                        k--;
                        flag = 0;
                        break;
                    }
                }
                if (flag && k > 0 && top)
                {
                    tp += sk[--top];
                    k--;
                }
                else if (flag)
                {
                    break;
                }
                i--;
            }
        }
        
        while (k > 0 && top)
        {
            tp += sk[--top];
            k--;
        }
        
        printf("%d\n", tp);
    }
    
    return 0;
}
