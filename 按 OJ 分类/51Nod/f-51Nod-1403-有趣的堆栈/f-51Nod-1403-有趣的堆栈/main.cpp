//
//  main.cpp
//  f-51Nod-1403-有趣的堆栈
//
//  Created by ZYJ on 2017/6/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 5;

int sta[MAXN];
vector<int> vi;

//  1 push 0 pop
void solve(int l, int r)
{
    if (l > r)
    {
        return ;
    }
    solve(l, r - sta[r] - 1);
    vi.push_back(1);
    solve(r - sta[r], r - 1);
    vi.push_back(0);
}

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

inline void out(int x)
{
    if (x > 9)
    {
        out(x / 10);
    }
    putchar(x % 10 + '0');
}

int main()
{
    int n;
    scan_d(n);
    
    for (int i = 1; i <= n; i++)
    {
        scan_d(sta[i]);
    }
    solve(1, n);
    
    int res = 0;
    bool flag = true;
    for (int i = 0; i < vi.size(); i++)
    {
        if (vi[i] == 1)
        {
            res++;
        }
        else
        {
            if (flag)
            {
                flag = false;
            }
            else
            {
                putchar(32);
            }
            out(res);
        }
    }
    
    return 0;
}
