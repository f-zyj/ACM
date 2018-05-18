//
//  main.cpp
//  f-[kuangbin带你飞]专题二-搜索进阶-C-哈密顿绕行世界问题
//
//  Created by ZYJ on 2017/4/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 20;

int cs;
int map[MAXN + 2][5];
int path[MAXN + 2];
int vis[MAXN + 2];

void print()
{
    printf("%d:  ", cs++);
    for (int i = 1; i <= MAXN; i++)
    {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[1]);
}

void dfs(int pos = 1)
{
    int temp;
    if (pos == MAXN)
    {
        int flag = 0;
        for (int i = 1; i <= 3; i++)
        {
            temp = map[path[MAXN]][i];
            if (temp == path[1])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            return ;
        }
        
        print();
        
        return ;
    }
    
    for (int i = 1; i <= 3; i++)
    {
        temp = map[path[pos]][i];
        if (!vis[temp])
        {
            vis[temp] = 1;
            path[pos + 1] = temp;
            dfs(pos + 1);
            vis[temp] = 0;
        }
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    for (int i = 1; i <= MAXN; i++)
    {
        scanf("%d%d%d", map[i] + 1, map[i] + 2, map[i] + 3);
        sort(map[i] + 1, map[i] + 4);
    }
    
//    int flag = 0;     //  尼玛，坑爹啊~~~
                        //  一直给我报输出格式错误，以为是这里错了，谁知道这个没有报而是
                        //  冒号后边要有俩空格，头一回见这种情况出题人还憋着不吭！！！
    int m;
    while (cin >> m, m != 0)
    {
//        if (flag)
//        {
//            puts("");
//        }
//        flag = 1;
        cs = 1;
        path[1] = m;
        vis[m] = 1;
        dfs();
        vis[m] = 0;
    }
    
    return 0;
}
