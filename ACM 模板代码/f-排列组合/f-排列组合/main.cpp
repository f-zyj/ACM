//
//  main.cpp
//  f-排列组合
//
//  Created by ZYJ on 16/7/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  类循环排列

/*
 *  输入样例: 3 2
 *  输出样例:
 *  0 0 0
 *  0 0 1
 *  0 1 0
 *  0 1 1
 *  1 0 0
 *  1 0 1
 *  1 1 0
 *  1 1 1
 */
//#define MAX_N 10
//int n, m;                       //  相当于n重循环,每重循环长度为m
//int rcd[MAX_N];                 //  记录每个位置填的数
//void loop_permutation(int l)
//{
//    int i;
//    if (l == n)                 //  相当于进入了 n 重循环的最内层
//    {
//        for (i = 0; i < n; i++)
//        {
//            cout << rcd[i];
//            if (i < n-1)
//            {
//                cout << " ";
//            }
//        }
//        cout << "\n";
//        return ;
//    }
//    for (i = 0; i < m; i++)     //  每重循环长度为m
//    {
//        rcd[l] = i;             //  在l位置放i
//        loop_permutation(l + 1);  //  填下一个位置
//    }
//}
//
//int main()
//{
//    while (cin >> n >> m)
//    {
//        loop_permutation(0);
//    }
//    return 0;
//}


//  全排列

/*
 *  对输入的n个数作全排列。 
 *  输入样例: 
 *  3
 *  1 2 3
 *  输出样例:
 *  123
 *  132
 *  213
 *  231
 *  312
 *  321
 */
//#define MAX_N 10
//int n;                      //  共n个数
//int rcd[MAX_N];             //  记录每个位置填的数
//int used[MAX_N];            //  标记数是否用过
//int num[MAX_N];             //  存放输入的n个数
//
//void full_permutation(int l)
//{
//    int i;
//    if (l == n)
//    {
//        for (i = 0; i < n; i++)
//        {
//            printf("%d", rcd[i]);
//            if (i < n-1)
//            {
//                printf(" ");
//            }
//        }
//        printf("\n");
//        return ;
//    }
//    for (i = 0; i < n; i++)         //  枚举所有的数(n个),循环从开始
//        if (!used[i])
//        {                           //  若num[i]没有使用过, 则标记为已使用
//            used[i] = 1;
//            rcd[l] = num[i];        //  在l位置放上该数
//            full_permutation(l+1);  //  填下一个位置
//            used[i] = 0;            //  清标记
//        }
//}
//
//int read_data()
//{
//    int i;
//    if (scanf("%d", &n) == EOF)
//    {
//        return 0;
//    }
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &num[i]);
//    }
//    for (i = 0; i < n; i++)
//    {
//        used[i] = 0;
//    }
//    return 1;
//}
//
//int main()
//{
//    while (read_data())
//    {
//        full_permutation(0);
//    }
//    return 0;
//}

//  不重复排列

/*
 *  输入n个数,输出由这n个数构成的排列,不允许出现重复的项。 
 *  输入样例:
 *  3
 *  1 1 2
 *  输出样例:
 *  1 1 2
 *  1 2 1
 *  2 1 1
 */
//#define MAX_N 10
//int n, m;           //  共有n个数,其中互不相同的有m个
//int rcd[MAX_N];     //  记录每个位置填的数
//int used[MAX_N];    //  标记m个数可以使用的次数
//int num[MAX_N];     //  存放输入中互不相同的m个数
//
//void unrepeat_permutation(int l)
//{
//    int i;
//    if (l == n)     //  填完了n个数,则输出
//    {
//        for (i = 0; i < n; i++)
//        {
//            printf("%d", rcd[i]);
//            if (i < n - 1)
//            {
//                printf(" ");
//            }
//        }
//        printf("\n");
//        return ;
//    }
//    for (i = 0; i < m; i++)             //  枚举m个本质不同的数
//    {
//        if (used[i] > 0)                //  若数num[i]还没被用完,则可使用次数减
//        {
//            used[i]--;
//            rcd[l] = num[i];            //  在l位置放上该数
//            unrepeat_permutation(l+1);  //  填下一个位置
//            used[i]++;                  //  可使用次数恢复
//        }
//    }
//}
//
//int read_data()
//{
//    int i, j, val;
//    if (scanf("%d", &n) == EOF)
//    {
//        return 0;
//    }
//    m = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &val);
//        for (j = 0; j < m; j++)
//        {
//            if (num[j] == val)
//            {
//                used[j]++; break;
//            }
//        }
//        if (j == m)
//        {
//            num[m] = val;
//            used[m++] = 1;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    while (read_data())
//    {
//        unrepeat_permutation(0);
//    }
//    return 0;
//}

//  一般组合

/*
 *  输入n个数,从中选出m个数可构成集合,输出所有这样的集合。
 *  输入样例: 
 *  4 3
 *  1 2 3 4
 *  输出样例: 
 *  1 2 3
 *  1 2 4
 *  1 3 4
 *  2 3 4
 */
//#define MAX_N 10
//int n, m;       //  从n个数中选出m个构成组合
//int rcd[MAX_N]; //  记录每个位置填的数
//int num[MAX_N]; //  存放输入的n个数
//
//void select_combination(int l, int p)
//{
//    int i;
//    if (l == m) //  若选出了m个数, 则打印
//    {
//        for (i = 0; i < m; i++)
//        {
//            printf("%d", rcd[i]);
//            if (i < m - 1)
//            {
//                printf(" ");
//            }
//        }
//        printf("\n");
//        return ;
//    }
//    for (i = p; i < n; i++) //  上个位置填的是num[p-1],本次从num[p]开始试探
//    {
//        rcd[l] = num[i];    //  在l位置放上该数
//        select_combination(l + 1, i + 1);   //  填下一个位置
//    }
//}
//
//int read_data()
//{
//    int i;
//    if (scanf("%d%d", &n, &m) == EOF)
//    {
//        return 0;
//    }
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &num[i]);
//    }
//    return 1;
//}
//
//int main()
//{
//    while (read_data())
//    {
//        select_combination(0, 0);
//    }
//    return 0;
//}

//  全组合

/*
 *  输入n个数,求这n个数构成的集合的所有子集。 
 *  输入样例:
 *  3
 *  1 2 3
 *  输出样例:
 *  1
 *  1 2
 *  1 2 3
 *  1 3
 *  2
 *  2 3
 *  3
 */
//#define MAX_N 10
//int n;          //  共n个数
//int rcd[MAX_N]; //  记录每个位置填的数
//int num[MAX_N]; //  存放输入的n个数
//
//void full_combination(int l, int p)
//{
//    int i;
//    for (i = 0; i < l; i++)     //  每次进入递归函数都输出
//    {
//        printf("%d", rcd[i]);
//        if (i < l-1)
//        {
//            printf(" ");
//        }
//    }
//    printf("\n");
//    for (i = p; i < n; i++)             //  循环同样从p开始,但结束条件变为i>=n
//    {
//        rcd[l] = num[i];                //  在l位置放上该数
//        full_combination(l + 1, i + 1); //  填下一个位置
//    }
//}
//
//int read_data()
//{
//    int i;
//    if (scanf("%d", &n) == EOF)
//    {
//        return 0;
//    }
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &num[i]);
//    }
//    return 1;
//}
//
//int main()
//{
//    while (read_data())
//    {
//        full_combination(0, 0);
//    }
//    return 0;
//}

//  不重复组合

/*
 *  输入n个数,求这n个数构成的集合的所有子集,不允许输出重复的项。 
 *  输入样例:
 *  3
 *  1 1 3
 *  输出样例:
 *  1
 *  1 1
 *  1 1 3
 *  1 3
 *  3
 */
#define MAX_N 10
int n, m;           //  输入n个数,其中本质不同的有m个
int rcd[MAX_N];     //  记录每个位置填的数
int used[MAX_N];    //  标记m个数可以使用的次数
int num[MAX_N];     //  存放输入中本质不同的m个数

void unrepeat_combination(int l, int p)
{
    int i;
    for (i = 0; i < l; i++)     //  每次都输出
    {
        printf("%d", rcd[i]);
        if (i < l - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    for (i = p; i < m; i++)     //  循环依旧从p开始,枚举剩下的本质不同的数
    {
        if (used[i] > 0)        //  若还可以用, 则可用次数减
        {
            used[i]--;
            rcd[l] = num[i];    //  在l位置放上该
            unrepeat_combination(l+1, i);   //  填下一个位置
            used[i]++;          //可用次数恢复
        }
    }
}

int read_data()
{
    int i, j, val;
    if (scanf("%d", &n) == EOF)
    {
        return 0;
    }
    m = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        for (j = 0; j < m; j++)
        {
            if (num[j] == val)
            {
                used[j]++;
                break;
            }
        }
        if (j == m)
        {
            num[m] = val;
            used[m++] = 1;
        }
    }
    return 1;
}

int main()
{
    while (read_data())
    {
        unrepeat_combination(0, 0);
    }
    return 0;
}
