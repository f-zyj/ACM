//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-F-丽娃河的狼人传说
//
//  Created by ZYJ on 2017/5/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXK = 1010;

int A[MAXK];

struct section
{
    int l;
    int r;
    int cnt;
} SEC[MAXK];

bool cmp(section a, section b)
{
    if (a.r == b.r)
    {
        return a.l < b.l;
    }
    return a.r < b.r;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int n, m, k, cs = 1;
    while (T--)
    {
        memset(A, 0, sizeof(A));
        
        cin >> n >> m >> k;
        int x;
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &x);
            A[x] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &SEC[i].l, &SEC[i].r, &SEC[i].cnt);
        }
        sort(SEC, SEC + m, cmp);
        
        printf("Case %d: ", cs++);
        
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            int cnt = 0;
            for (int j = SEC[i].l; j <= SEC[i].r; j++)
            {
                if (A[j])
                {
                    cnt++;
                }
            }
            if (cnt < SEC[i].cnt)
            {
                sum += SEC[i].cnt - cnt;
            }
            cnt = SEC[i].cnt - cnt;
            for (int j = SEC[i].r; j >= SEC[i].l && cnt > 0; j--)
            {
                if (A[j] == 0)
                {
                    A[j] = 1;
                    cnt--;
                    if (cnt == 0)
                    {
                        break;
                    }
                }
            }
            if (cnt > 0)
            {
                goto t;
            }
        }
        
        cout << sum << '\n';
        if (false)
        {
        t:
            cout << -1 << '\n';
        }
    }
    
    return 0;
}
