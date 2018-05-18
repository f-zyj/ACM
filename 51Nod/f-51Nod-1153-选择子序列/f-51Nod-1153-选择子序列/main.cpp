//
//  main.cpp
//  f-51Nod-1153-选择子序列
//
//  Created by ZYJ on 16/8/24.
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
//struct b
//{
//    int B;
//    int order;
//} B[MAXN];
//
//int A[MAXN];
//int N;
//int ans = 0;
//
//bool cmp(b a, b aa)
//{
//    return a.B > aa.B;
//}
//
//void solve(int left, int right, int pos, int K)
//{
//    if (right - left <= 1)
//    {
//        ans = ans > K ? ans : K;
//        return ;
//    }
//    if (K + right - left - 1 <= ans)
//    {
//        return ;
//    }
//    while (B[pos].order > right || B[pos].order < left)
//    {
//        pos++;
//    }
//    solve(left, B[pos].order, pos + 1, K + 1);
//    solve(B[pos].order, right, pos + 1, K + 1);
//    return ;
//}
//
//int main()
//{
//    cin >> N;
//    
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d", A + i);
//        B[i].B = A[i];
//        B[i].order = i;
//    }
//    sort(B, B + N, cmp);
//    
//    solve(0, N - 1, 0, 0);
//    
//    cout << ans << '\n';
//}

#include <stdio.h>

#define MAX 50001

typedef struct
{
    int value;
    int number; //  这个点加入数组后，选择这个点作为B数组的元素时，B数组的最大长度
} node;

node a[MAX];    //  单调栈

int max_(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, max = 0, index = 0, x;
    scanf("%d", &n);
    
    //  第一个结点入栈
    scanf("%d", &x);
    a[0].value = x;
    a[0].number = 1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &x);
        int number = 0;
        while (index >= 0 && x > a[index].value)    //  栈不为空，将所有小于x的结点出队列
        {
            number = max_(number, a[index].number);
            index--;
        }
        index++;
        number++;
        number = max_(index + 1, number);           //  选取栈内剩余点的作为B数组
        max = max_(max, number);                    //  更新结果
        //  将此结点入栈
        a[index].value = x;
        a[index].number = number;
    }
    printf("%d", max);
}