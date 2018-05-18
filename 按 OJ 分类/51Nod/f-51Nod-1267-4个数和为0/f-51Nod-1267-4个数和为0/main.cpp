//
//  main.cpp
//  f-51Nod-1267-4个数和为0
//
//  Created by ZYJ on 16/8/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 1e3 + 10;
//
//int A[MAXN];
//
////  二分查找v[l, h)
//int bs(int l, int h, int v)
//{
//    int m;
//    while (l < h)
//    {
//        m = (l + h) >> 1;
//        if (A[m] == v)
//        {
//            return m;
//        }
//        if (A[m] < v)
//        {
//            l = m + 1;
//        }
//        else
//        {
//            h = m;
//        }
//    }
//    return -1;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    cin >> N;
//    
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", A + i);
//    }
//    sort(A + 1, A + N + 1);
//    
//    for (int i = 1; i < N - 2; i++)
//    {
//        for (int j = i + 1; j < N - 1; j++)
//        {
//            if (-(A[i] + A[j]) > A[N] + A[N - 1])
//            {
//                break;
//            }
//            for (int k = N; k > j; k--)
//            {
//                int v = A[i] + A[j] + A[k];
//                if (-v > A[k - 1])
//                {
//                    break;
//                }
//                int key = bs(j + 1, k, -v);
//                if (key != -1)
//                {
//                    cout << "Yes\n";
//                    return 0;
//                }
//            }
//        }
//    }
//    
//    std::cout << "No\n";
//    return 0;
//}



#include <cstdio>
#include <cstring>

#define rep(i, a, b) for (int i = a; i <= b; i++)

const int MAXM = 1e6 + 10;
const int MAXN = 1e3 + 10;
const int MOD = 1e6 + 7;

int N;
int hash_table[MAXM], hnum;

struct node
{
    int val;
    int nxt;
} Node[MAXM * 2];

int b[MAXN];

void init()
{
    memset(hash_table, -1, sizeof(hash_table));
    hnum = 0;
    return ;
}

int insert_hash(int x)
{
    int h = (int)((1ULL * x * x) % MOD);
    hnum++;
    Node[hnum].val = x;
    Node[hnum].nxt = hash_table[h];
    hash_table[h] = hnum;
    return 0;
}

int check_hash(int x)
{
    int h = (int)((1ULL * x * x) % MOD);
    for (int i = hash_table[h]; i > 0; i = Node[i].nxt)
    {
        if (Node[i].val == x)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &N);
    rep(i, 1, N)
    {
        scanf("%d", &b[i]);
    }
    init();
    
    int flag = 0;
    rep(i, 3, N - 1)
    {
        rep(j, 1, i - 2)
        {
            insert_hash(b[i - 1] + b[j]);
        }
        rep(j, i + 1, N)
        {
            if (check_hash(-(b[i] + b[j])))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (flag)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}