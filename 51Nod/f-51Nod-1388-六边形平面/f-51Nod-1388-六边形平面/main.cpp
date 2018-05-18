//
//  main.cpp
//  f-51Nod-1388-六边形平面
//
//  Created by ZYJ on 16/9/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 55;
//const int DIR = 6;
//
//char A[MAXN][MAXN];
//bool B[MAXN][MAXN];
//
//int N;
//int res;
//int dirX[] = {-1, -1, 0, 0, 1, 1};
//int dirY[] = {0, 1, -1, 1, -1, 0};
//
//void judge(int x, int y)
//{
//    int key = 0;
//    if (A[x][y] == 'X')
//    {
//        key++;
//    }
//    if (y + 1 < N && A[x][y + 1] == 'X')
//    {
//        key++;
//    }
//    if (x + 1 < N && A[x + 1][y] == 'X')
//    {
//        key++;
//    }
//    else if (x - 1 >= 0 && y + 1 < N && A[x - 1][y + 1] == 'X')
//    {
//        key++;
//    }
//    if (key > res)
//    {
//        res = key;
//    }
//    return ;
//}
//
//void ring(int a, int b, int x, int y, int count)
//{
//    for (int i = 0; i < DIR; i++)
//    {
//        if (x + dirX[i] >= 0 && x + dirX[i] < N && y + dirY[i] >= 0 && y + dirY[i] < N)
//        {
//            if (B[x + dirX[i]][y + dirY[i]])
//            {
//                if (a == x + dirX[i] && b == y + dirY[i] && count > 2)
//                {
//                    if (count % 2)
//                    {
//                        res = 3;
//                        return ;
//                    }
//                }
//                continue;
//            }
//            if (A[x + dirX[i]][y + dirY[i]] == 'X')
//            {
//                B[x + dirX[i]][y + dirY[i]] = true;
//                ring(a, b, x + dirX[i], y + dirY[i], count + 1);
//            }
//        }
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
////    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        cin >> N;
//        for (int i = 0; i < N; i++)
//        {
//            scanf("%s", A[i]);
//        }
//        res = 0;
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = 0; j < N; j++)
//            {
//                judge(i, j);
//                if (res == 3)
//                {
//                    break;
//                }
//            }
//        }
//        //  如果不存在三个粘连在一起的则判断环
//        if (res < 3)
//        {
//            for (int i = 0; i < N; i++)
//            {
//                for (int j = 0; j < N; j++)
//                {
//                    if (A[i][j] == 'X')
//                    {
//                        memset(B, false, sizeof(B));
//                        B[i][j] = true;
//                        ring(i, j, i, j, 1);
//                    }
//                }
//            }
//        }
//        cout << res << '\n';
//    }
//    
//    return 0;
//}

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 55;
const int DIR = 6;

char ch[MAXN][MAXN];
int v[MAXN][MAXN];
int maxX, n;
bool connect, f;
int dir[6][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1}};

void countX(int l, int r)
{
    int x, y, cnt = 1;
    bool con = false;
    int pre = -1;
    for (int i = 0; i < DIR; i++)
    {
        x = l + dir[i][0], y = r + dir[i][1];
        if (x >= 0 && x < n && y >= 0 && y < n)
        {
            if (ch[x][y] == 'X')
            {
                cnt++;
                if (pre != -1)
                {
                    con = true;
                }
                pre = i;
            }
            else
            {
                pre = -1;
            }
        }
        else
        {
            pre = -1;
        }
    }
    x = l + dir[0][0];
    y = r + dir[0][1];
    if (pre != -1 && x >= 0 && x < n && y >= 0 && y < n && ch[x][y] == 'X')
    {
        con = true;
    }
    if (con)
    {
        connect = con;
    }
    if (cnt > maxX)
    {
        maxX = cnt;
    }
    return ;
}

void dfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ch[i][j] == 'X')
            {
                countX(i, j);
            }
        }
    }
    return ;
}

void canFind(int sti, int stj, int tox, int toy, int step)
{
    int x, y;
    v[tox][toy] = step + 1;
    if (f)
    {
        return ;
    }
    
    for (int i = 0; i < DIR; i++)
    {
        x = tox + dir[i][0], y = toy + dir[i][1];
        if (x >= 0 && x < n && y >= 0 && y < n)
        {
            if (ch[x][y] == 'X')
            {
                if (v[x][y] == 0)
                {
                    canFind(sti, stj, x, y, step + 1);
                }
                else if ((step + 1 - v[x][y]) % 2 == 0)
                {
                    f = true;
                    return ;
                }
            }
        }
    }
    return ;
}

void findOddCycle()
{
    f = false;
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n && !f; i++)
    {
        for (int j = 0; j < n && !f; j++)
        {
            if (ch[i][j] == 'X' && !v[i][j])
            {
                int x, y;
                v[i][j] = 1;
                for (int k = 0; k < DIR; k++)
                {
                    x = i + dir[k][0];
                    y = j + dir[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < n)
                    {
                        if (!v[x][y] && ch[x][y] == 'X')
                        {
                            canFind(i, j, x, y, 1);
                        }
                    }
                }
            }
        }
    }
    return ;
}


int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            cin >> ch[i];
        }
        maxX = 0;
        connect = false;
        dfs();
        if (maxX < 3)
        {
            printf("%d\n", maxX);
        }
        else if (connect)
        {
            printf("3\n");
        }
        else
        {
            f = false;
            findOddCycle();
            if (f)
            {
                printf("3\n");
            }
            else
            {
                printf("2\n");
            }
        }
    }
    
    return 0;
}