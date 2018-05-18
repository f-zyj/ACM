//
//  main.cpp
//  f-51Nod-1714-B君的游戏
//
//  Created by ZYJ on 2016/10/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

typedef unsigned long long ull;

const int MAX_DIG = 64;

//  SG打表
//  f[]:可以取走的石子个数
//  sg[]:0~n的SG函数值
//  hash[]:mex{}
int f[MAX_DIG];
int sg[MAX_DIG];
int hash[MAX_DIG];

void getSG(int n)
{
    memset(sg, 0, sizeof(sg));
    for (int i = 1; i <= n; i++)
    {
        memset(hash, 0, sizeof(hash));
        for (int j = 1; f[j] <= i; j++)
        {
            hash[sg[i - f[j]]] = 1;
        }
        for (int j = 0; j <= n; j++)    //  求mes{}中未出现的最小的非负整数
        {
            if (hash[j] == 0)
            {
                sg[i] = j;
                break;
            }
        }
    }
}

////  DFS
////  注意 S数组要按从小到大排序 SG函数要初始化为-1 对于每个集合只需初始化1遍
////  n是集合s的大小 S[i]是定义的特殊取法规则的数组
//int s[MAX_DIG];
//int sg[MAX_DIG * 100];
//int n;
//
//int SG_dfs(int x)
//{
//    if (sg[x] != -1)
//    {
//        return sg[x];
//    }
//    bool vis[MAX_DIG];
//    memset(vis, 0, sizeof(vis));
//    for (int i = 0; i < n; i++)
//    {
//        if (x >= s[i])
//        {
//            SG_dfs(x - s[i]);
//            vis[sg[x - s[i]]] = 1;
//        }
//    }
//    int e;
//    for (int i = 0; ; i++)
//    {
//        if (!vis[i])
//        {
//            e = i;
//            break;
//        }
//    }
//    return sg[x] = e;
//}

//int sg[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 255, 256, 512,
//    1024, 2048, 3855, 4096, 8192, 13107, 16384, 21845,
//    27306, 32768, 38506, 65536, 71576, 92115, 101470,
//    131072, 138406, 172589, 240014, 262144, 272069,
//    380556, 524288, 536169, 679601, 847140, 1048576,
//    1072054, 1258879, 1397519, 2005450, 2097152, 2121415,
//    2496892, 2738813, 3993667, 4194304, 4241896, 4617503,
//    5821704, 7559873, 8388608, 8439273, 8861366, 11119275,
//    11973252, 13280789, 16777216, 16844349, 17102035,
//    19984054, 21979742, 23734709};
//
//int main()
//{
//    int n;
//    
//    while (scanf("%d", &n) == 1)
//    {
//        ull ans = 0, a;
//        for (int i = 0; i < n; i++)
//        {
//            scanf("%llu\n", &a);
//            int h = 0;
//            ull d = 1;
//            for (int i = 0; i < MAX_DIG; i++)
//            {
//                //  判断二进制位有几个1
//                if ((d << i) & a)
//                {
//                    h++;
//                }
//            }
//            ans ^= sg[h];
//        }
//        if (ans == 0)
//        {
//            puts("L");
//        }
//        else
//        {
//            puts("B");
//        }
//    }
//    return 0;
//}
