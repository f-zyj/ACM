//
//  main.cpp
//  f-51Nod-1330-雕像投影
//
//  Created by ZYJ on 2017/5/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 13;
const int DIR[6][3] = {{0, 0, 1}, {0, 0, -1},
                       {0, 1, 0}, {0, -1, 0},
                       {1, 0, 0}, {-1, 0, 0}};

int N, cnt;
int A[MAXN][MAXN][MAXN];
int A_[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
char s1[MAXN][MAXN];
char s2[MAXN][MAXN];
char s3[MAXN][MAXN];

int charge(int x, int y, int z)
{
    if (x < 0 || x >= N)
    {
        return 0;
    }
    if (y < 0 || y >= N)
    {
        return 0;
    }
    if (z < 0 || z >= N)
    {
        return 0;
    }
    if (vis[x][y][z])
    {
        return 0;
    }
    if (A[x][y][z] < 3)
    {
        return 0;
    }
    return 1;
}

void dfs(int x, int y, int z)
{
    for (int i = 0; i < 6; i++)
    {
        int x_ = x + DIR[i][0];
        int y_ = y + DIR[i][1];
        int z_ = z + DIR[i][2];
        if (charge(x_, y_, z_))
        {
            vis[x_][y_][z_] = 1;
            A_[x_][y_][z_] = 3;
            dfs(x_, y_, z_);
        }
    }
}

int charge_()
{
    int flag;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (s1[i][j] == 'Y')
            {
                flag = 1;
                for (int k = 0; k < N; k++)
                {
                    if (A_[i][j][k] == 3)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (s2[i][j] == 'Y')
            {
                flag = 1;
                for (int k = 0; k < N; k++)
                {
                    if (A_[k][i][j] == 3)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (s3[i][j] == 'Y')
            {
                flag = 1;
                for (int k = 0; k < N; k++)
                {
                    if (A_[j][k][i] == 3)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    cin >> T;
    
    while (T--)
    {
        memset(A, 0, sizeof(A));
        memset(vis, 0, sizeof(vis));
        
        cin >> N;
        int flag = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%s", s1[i]);
            for (int j = 0; j < N; j++)
            {
                if (s1[i][j] == 'Y')
                {
                    flag = 1;
                    for (int k = 0; k < N; k++)
                    {
                        A[i][j][k]++;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%s", s2[i]);
            for (int j = 0; j < N; j++)
            {
                if (s2[i][j] == 'Y')
                {
                    flag = 1;
                    for (int k = 0; k < N; k++)
                    {
                        A[k][i][j]++;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%s", s3[i]);
            for (int j = 0; j < N; j++)
            {
                if (s3[i][j] == 'Y')
                {
                    flag = 1;
                    for (int k = 0; k < N; k++)
                    {
                        A[j][k][i]++;
                    }
                }
            }
        }
        
        if (!flag)
        {
            cout << "Possible\n";
            continue;
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    if (!vis[i][j][k] && A[i][j][k] == 3)
                    {
                        memset(A_, 0, sizeof(A_));
                        vis[i][j][k] = 1;
                        A_[i][j][k] = 3;
                        dfs(i, j, k);
                        if (charge_())
                        {
                            cout << "Possible\n";
                            goto cn;
                        }
                    }
                }
            }
        }
        
        cout << "Impossible\n";
    cn:
        ;
    }
    
    return 0;
}
