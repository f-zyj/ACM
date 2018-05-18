//
//  main.cpp
//  f-HDU-5955-Guessing the Dice Roll
//
//  Created by ZYJ on 2017/10/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_LEN = 1010;
const int MAXN = 120;
const int MAXM = 6;
const int MAXF = 15;
const double EPS = 1e-6;
const double MAGIC = 1.0 / 6;

int n, L, sz;
int fp[MAXF];
int tag[MAXN];
int fail[MAXN];
int trie[MAXN][MAXM];
queue<int> qi;

/* *********** Aho *********** */
struct Aho
{
    int root;
    
    int newnode()                           //  静态创建新节点
    {
        memset(trie[sz], -1, sizeof(trie[sz]));
        tag[sz] = 0;
        sz++;
        return sz - 1;
    }
    
    void init()
    {
        sz = 0;
        newnode();
    }
    
    void insert(int s[], int id)            //  插入字符串构建ac自动机，构建trie树
    {
        int len = L, p = 0;
        for (int i = 0; i < len; i++)
        {
            int _id = s[i] - 1;
            if (trie[p][_id] == -1)
            {
                trie[p][_id] = newnode();
            }
            p = trie[p][_id];
        }
        tag[p] = id;                        //  结束标记
        fp[id] = p;
    }
    
    void getfail()                          //  构建自动机fail指针
    {
        while (!qi.empty())
        {
            qi.pop();
        }
        
        fail[root] = root;                  //  root指向root
        for (int i = 0; i < MAXM; i++)
        {
            if (trie[root][i] == -1)        //  第一个字符不存在，指向root
            {
                trie[root][i] = root;
            }
            else                            //  第一个字符的fail指针指向root
            {
                fail[trie[root][i]] = root;
                qi.push(trie[root][i]);     //  并放入队列，待bfs扩展
            }
        }
        
        while (!qi.empty())
        {
            int u = qi.front();             //  取扩展节点
            qi.pop();
            
            if (tag[fail[u]])
            {
                tag[u] = tag[fail[u]];      //  如果之前是tag，直接标记
            }
            for (int i = 0; i < MAXM; i++)  //  遍历所有子节点
            {
                if (trie[u][i] == -1)       //  如果不存在，则子节点直接指向fail[u]节点的对应子节点
                {
                    trie[u][i] = trie[fail[u]][i];
                }
                else                        //  如果存在，则该节点的fail指针指向fail[u]节点对应的子节点
                {
                    fail[trie[u][i]] = trie[fail[u]][i];
                    qi.push(trie[u][i]);    //  继续扩展
                }
            }
        }
    }
} aho;

/* *********** Guass *********** */
int equ, var;
double x[MAXN];
double a[MAXN][MAXN];

int Gauss()
{
    int max_r;
    for (int k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for (int i = k + 1; i < equ; i++)
        {
            if (fabs(a[i][col]) > fabs(a[max_r][col]))
            {
                max_r = i;
            }
        }
        
        if (fabs(a[max_r][col]) < EPS)
        {
            return 0;
        }
        
        if (k != max_r)
        {
            for (int j = col; j < var; j++)
            {
                swap(a[k][j], a[max_r][j]);
            }
            swap(x[k], x[max_r]);
        }
        
        x[k] /= a[k][col];
        for (int j = col + 1; j < var; j++)
        {
            a[k][j] /= a[k][col];
        }
        a[k][col] = 1;
        for (int i = 0; i < equ; i++)
        {
            if (i != k)
            {
                x[i] -= x[k] * a[i][k];
                for (int j = col + 1; j < var; j++)
                {
                    a[i][j] -= a[k][j] * a[i][col];
                }
                a[i][col] = 0;
            }
        }
    }
    return 1;
}

void init_guass(int n, int m)
{
    memset(x, 0, sizeof(x));
    memset(a, 0, sizeof(a));
    var = n;
    equ = m;
}

int son[MAXN];

void build()        // 建立方程组
{
    init_guass(sz, sz);
    
    for (int i = 0; i < sz; i++)
    {
        if (!tag[i])
        {
            for (int j = 0; j < MAXM; j++)
            {
                a[trie[i][j]][i] += MAGIC;
            }
        }
        a[i][i] += -1;
    }
    
    x[0] += -1;     //  虚拟节点以1的概率转移到节点0
}

int name[MAXF][MAXF];

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n >> L;
        
        aho.init();
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < L; j++)
            {
                scanf("%d", name[i] + j);
            }
            aho.insert(name[i], i + 1);
        }
        
        aho.getfail();
        
        build();
        Gauss();
        
        for (int i = 1; i <= n; i++)
        {
            printf("%.6f%c", x[fp[i]], i == n ? '\n' : ' ');
        }
    }
    
    return 0;
}







