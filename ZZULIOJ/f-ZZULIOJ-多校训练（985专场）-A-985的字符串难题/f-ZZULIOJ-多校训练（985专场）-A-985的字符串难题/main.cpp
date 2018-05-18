//
//  main.cpp
//  f-ZZULIOJ-多校训练（985专场）-A-985的字符串难题
//
//  Created by ZYJ on 16/8/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 10;
const int tk = 26, tb = 'a';    //  tk叉; 起始字母为tb;

char ss[MAXN][7];
int lenSS[MAXN];
char str[7];
int lenStr;

//  Tire树

/*
 *  INIT: init();
 *  注: tree[i][tk]>0时表示单词存在, 当然也可赋予它更多含义;
 */

int top, tree[MAXN][tk + 1];

//  初始化Tire树
void init()
{
    top = 1;
    memset(tree[0], 0, sizeof(tree[0]));
    return ;
}

//  s插入Tire树
void insert(char *s, int rank = 1)
{
    int rt, nxt;
    for (rt = 0; *s; rt = nxt, ++s)
    {
        nxt = tree[rt][*s - tb];
        if (0 == nxt)
        {
            tree[rt][*s - tb] = nxt = top;
            memset(tree[top], 0, sizeof(tree[top]));
            top++;
        }
    }
    tree[rt][tk] = rank;        //  1表示存在0表示不存在,也可以赋予其其他含义
}

//  查询s
int sear(char *s)               //  失败返回0
{
    for (int rt = 0; rt == tree[rt][*s - tb];)
    {
        if (*(++s) == 0)
        {
            return tree[rt][tk];
        }
    }
    return 0;
}

void delt(char *s)          //  只做标记, 假定s一定存在
{
    int rt = 0;
    for (; *s; ++s)
    {
        rt = tree[rt][*s - tb];
    }
    tree[rt][tk] = 0;
    return ;
}

int prefix(char *s)         //  最长前缀
{
    int rt = 0, lv;
    for (lv = 0; *s; ++s, ++lv)
    {
        rt = tree[rt][*s - tb];
        if (rt == 0)
        {
            break;
        }
    }
    return lv;
}

int main(int argc, const char * argv[])
{
    init();
    
    int T;
    cin >> T;
    
    int n, m;
    int x;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", ss[i]);
            lenSS[i] = (int)strlen(ss[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%s %d", str, &x);
            lenStr = (int)strlen(str);
            
            //  六操作
            int res_1 = 0, res_2 = 0, res_3 = 0;
            int res_4 = -1, res_5 = -1, res_6 = -1;
            bool flag_4 = true, flag_5 = true, flag_6 = true;
            for (int j = 0; j < n; j++)
            {
                if (lenSS[j] - lenStr == x)
                {
                    int k = 0;
                    for (int l = 0; l < lenSS[j]; l++)
                    {
                        if (ss[j][l] == str[k])
                        {
                            k++;
                        }
                    }
                    if (k == lenStr)
                    {
                        if (flag_4)
                        {
                            flag_4 = false;
                            res_4 = j + 1;
                        }
                        res_1++;
                    }
                }
                else if (lenSS[j] == lenStr)
                {
                    int k = 0;
                    for (int l = 0; l < lenStr; l++)
                    {
                        if (str[l] != ss[j][l])
                        {
                            k++;
                        }
                    }
                    if (k == x)
                    {
                        if (flag_5)
                        {
                            flag_5 = false;
                            res_5 = j;
                        }
                        res_2++;
                    }
                }
                else if (lenStr - lenSS[j] == x)
                {
                    int k = 0;
                    for (int l = 0; l < lenStr; l++)
                    {
                        if (ss[j][l] == str[k])
                        {
                            k++;
                        }
                    }
                    if (k == lenSS[j])
                    {
                        if (flag_6)
                        {
                            flag_6 = false;
                            res_6 = j;
                        }
                        res_3++;
                    }
                }
            }
            cout << res_1 << ' ' << res_2 << ' ' << res_3 << '\n';
            cout << res_4 << ' ' << res_5 << ' ' << res_6 << '\n';
        }
    }

    return 0;
}
