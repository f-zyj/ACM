//
//  main.cpp
//  f-CF-Educational Codeforces Round 44 (Rated for Div. 2)-B-Switches and Lamps
//
//  Created by ZYJ on 2018/5/21.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 2222;

int n, m;
char vis[MAXN][MAXN];
int cnt[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n >> m)
    {
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", vis[i] + 1);
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j] == '1')
                {
                    cnt[j]++;
                }
            }
        }
        
        int flag = 0;
        for (int i = 1; i <= m; i++)
        {
            if (cnt[i] == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << "NO\n";
            continue;
        }
        
        for (int i = 1; i <= n; i++)
        {
            int tag = 1;
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j] == '1' && cnt[j] - 1 == 0)
                {
                    tag = 0;
                    break;
                }
            }
            if (tag)
            {
                cout << "YES\n";
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}
