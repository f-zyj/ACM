//
//  main.cpp
//  f-NYOJ-1252-世界之威
//
//  Created by ZYJ on 2017/5/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;

int pre[MAXN];  //  前驱的数目
int net[MAXN];
int vis[MAXN];

int main(int argc, const char * argv[])
{
    int K;
    cin >> K;
    
    int N;
    while (K--)
    {
        memset(pre, 0, sizeof(pre));
        memset(vis, 0, sizeof(vis));
        memset(net, -1, sizeof(net));
        
        cin >> N;
        int a;
        for (int i = 1; i <= N; i++)
        {
            cin >> a;
            pre[a]++;
            net[i] = a;
        }
        
        int res = 0;
        for (int i = 1; i <= N; i++)
        {
            if (pre[i] == 0)
            {
                int len = 0;
                int nt = i;
                while (nt != -1 && vis[nt] == 0)
                {
                    vis[nt] = 1;
                    len++;
                    nt = net[nt];
                }
                res += len / 2;
                if (len & 1)
                {
                    res++;
                }
            }
        }
        
        for (int i = 1; i <= N; i++)
        {
            if (vis[i] == 0)
            {
                int len = 0;
                int nt = i;
                while (vis[nt] == 0)
                {
                    vis[nt] = 1;
                    len++;
                    nt = net[nt];
                }
                res += len / 2;
                if (len & 1)
                {
                    res++;
                }
            }
        }
        
        cout << N - res << '\n';
    }
    
    return 0;
}
