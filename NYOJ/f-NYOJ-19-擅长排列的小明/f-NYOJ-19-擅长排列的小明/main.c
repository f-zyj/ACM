//
//  main.c
//  f-NYOJ-19-擅长排列的小明
//
//  Created by ZYJ on 16/5/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//


//dfs
//#include <stdio.h>
//int visited[10];
//int a[10];
//
//void solve(int i, int m, int n)
//{
//    int j, k;
//    if (i > m)
//    {
//        for (k = 1; k <= m; k++)
//        {
//            printf("%d", a[k]);
//        }
//        printf("\n");
//    }
//    else
//    {
//        for (j = 1; j <= n; j++)
//        {
//            if (visited[j] == 0)
//            {
//                visited[j] = 1;
//                a[i] = j;
//                solve(i + 1, m, n);
//                visited[j] = 0;
//            }
//        }
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    scanf("%d", &N);
//    int n, m;
//    
//    while (N--)
//    {
//        scanf("%d %d", &n, &m);
//        solve(1, m, n);
//    }
//
//    return 0;
//}


#include<stdio.h>
#include<math.h>

int a[10];
int visited[10];

void dfs(int n, int m, int number)
{
    if (m == 0)
    {
        printf("%d\n", number);
        return ;
    }
    int i;
    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(n, m - 1, number + i * pow(10.0, m - 1));
            visited[i] = 0;
        }
    }
}

int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int m, n;
        scanf("%d%d", &n, &m);

        int i;
        for (i = 0; i <= n; i++)
        {
            a[i] = i;
            visited[i] = 0;
        }

        dfs(n, m, 0);
    }
    
    return 0;
}