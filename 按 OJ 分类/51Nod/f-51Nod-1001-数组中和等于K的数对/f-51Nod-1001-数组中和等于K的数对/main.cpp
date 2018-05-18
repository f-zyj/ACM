//
//  main.cpp
//  f-51Nod-1001-数组中和等于K的数对
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 5e4 + 5;
//
//int A[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    freopen("input.txt", "r", stdin);
//    int K, N;
//    while (cin >> K >> N)
//    {
//        bool tag = false;
//        for (int i = 0; i < N; i++)
//        {
//            scanf("%d", A + i);
//        }
//        sort(A, A + N);
//        int B;
//        int flag = N;
//        for (int i = 0; i < N - 1; i++)
//        {
//            B = K - A[i];
//            for (int j = flag - 1; j > i; j--)
//            {
//                if (B == A[j])
//                {
//                    printf("%d %d\n", A[i], B);
//                    flag = j;
//                    tag = true;
//                    break;
//                }
//                else if (B > A[j])
//                {
//                    flag = j + 1;
//                    break;
//                }
//            }
//        }
//        if (!tag)
//        {
//            puts("No Solution");
//        }
//    }
//    
//    return 0;
//}

#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 50010

struct node
{
    int val, antival;
} a[maxn];

int cmp(node x, node y)
{
    if (x.antival == y.antival)
    {
        return x.val < y.val;
    }
    return x.antival < y.antival;
}

int main()
{
    int n, i, k;
    while (scanf("%d%d", &k, &n) != EOF)
    {
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &a[i].val);
            if (a[i].val < k/2)
            {
                a[i].antival = a[i].val;
            }
            else
            {
                a[i].antival = k - a[i].val;
            }
        }
        sort(a, a + n, cmp);
        bool sign = false;
        for (i = 0; i < n - 1; ++i)
        {
            if (a[i].antival == a[i + 1].antival)
            {
                printf("%d %d\n", a[i].val, a[i + 1].val);
                sign = true;
            }
        }
        if (!sign)
        {
            printf("No Solution\n");
        }
    }
    return 0;
}
