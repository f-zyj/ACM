//
//  main.cpp
//  f-HDU-1325-Is It A Tree?
//
//  Created by ZYJ on 2016/10/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//#define mem(a, b) memset(a, b, sizeof(a))
//
//using namespace std;
//
//const int MAXN = 100010;
//
//int flag;
//int maxRoom;
//int pre[MAXN];
//int room[MAXN];
//int root;
//
//int find(int x)
//{
//    int r = x;
//    while (pre[r] != r)
//    {
//        r = pre[r];
//    }
//    
//    int i = x, j;
//    while (i != r)
//    {
//        j = pre[i];
//        pre[i] = r;
//        i = j;
//    }
//    return r;
//}
//
//void join(int x, int y)
//{
//    room[x] = room[y] = 1;
//    if (x > maxRoom)
//    {
//        maxRoom = x;
//    }
//    if (y > maxRoom)
//    {
//        maxRoom = y;
//    }
//    
//    int fx = find(x);
//    int fy = find(y);
//    if (fx != fy)
//    {
//        pre[fy] = fx;
//    }
//    else
//    {
//        flag = 0;
//    }
//    
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    int A, B;
//    int key = 1;
//    while (cin >> A >> B, A != -1 || B != -1)
//    {
//        if (A == 0 && B == 0)
//        {
//            cout << "Case " << key++ << " is a tree.\n";
//            continue;
//        }
//        mem(room, 0);
//        
//        for (int i = 0; i <= MAXN; i++)
//        {
//            pre[i] = i;
//        }
//        
//        join(A, B);
//        
//        flag = 1;
//        maxRoom = 0;
//        while (cin >> A >> B, A != 0 || B != 0)
//        {
//            if (!flag)
//            {
//                continue;
//            }
//            join(A, B);
//        }
//        
//        if (!flag)
//        {
//            cout << "Case " << key++ << " is not a tree.\n";
//            continue;
//        }
//        
//        root = 0;
//        for (int i = 0; i <= maxRoom; i++)
//        {
//            if (room[i] && pre[i] == i)
//            {
//                root++;
//            }
//            if (root > 1)
//            {
//                flag = 0;
//                break;
//            }
//        }
//        
//        if (flag)
//        {
//            cout << "Case " << key++ << " is a tree.\n";
//        }
//        else
//        {
//            cout << "Case " << key++ << " is not a tree.\n";
//        }
//    }
//    
//    return 0;
//}

#include <stdio.h>

const int MAXN = 100010;

typedef struct
{
    int num, root, conn;    //  数据、根、入度
} Node;

int NodeNum;
Node node[MAXN];

void init()
{
    NodeNum = 0;
    for (int i = 0; i < MAXN; i++)
    {
        node[i].conn = 0;   //  入度初始化为0
        node[i].root = i;   //  根记录为自身
        node[i].num = 0;    //  标记数字是否被使用过，0:没有被使用过，1:使用过了
    }
}

int find_root(int a)
{
    if (node[a].root != a)
    {
        return node[a].root = find_root(node[a].root);
    }
    return node[a].root;
}

void union_set(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    if (a == b)         //  同一个根，说明是在同一个树下
    {
        return ;
    }
    node[b].root = a;   //  把b的根赋为a的根，此时a已经是根，num==root
}

int main()
{
    int n, m;
    int i = 1;
    bool flag = true;   //  true:是个树，false:不是树
    init();
    while (scanf("%d%d", &n, &m) != EOF && n >= 0 && m >= 0)
    {
        if (n > NodeNum)
        {
            NodeNum = n;
        }
        if (m > NodeNum)
        {
            NodeNum = m;
        }
        if (!flag && n != 0 && n != 0)
        {
            continue;   //  已经确定不是树了，就继续循环
        }
        
        if (n == 0 && m == 0)
        {
            int root_num = 0;
            for (int j = 1; j <= NodeNum;j++)
            {
                //  判断是否为森林，root_num用来记录根的数目
                if (node[j].num && find_root(j) == j)
                {
                    root_num++;
                }
                if (node[j].conn > 1)   //  如果出现某个节点的入度超过1，不是树
                {
                    flag = false;
                    break;
                }
            }
            if (root_num > 1)   //  连通分支大于1，是森林不是树
            {
                flag = false;
            }
            
            if (flag)
            {
                printf("Case %d is a tree.\n", i++);
            }
            else
            {
                printf("Case %d is not a tree.\n",i++);
            }
            
            flag = true;
            init();
            continue;
        }
        
        if (m != n && find_root(n) == find_root(m))
        {
            flag = false;
        }
        else
        {
            //  将m,n，记录为节点
            node[m].num = 1;
            node[n].num = 1;
            node[m].conn++;     //  入度增加一
            union_set(n, m);
        }
    }
    return 0;
}
