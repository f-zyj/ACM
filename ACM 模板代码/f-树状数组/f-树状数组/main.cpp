//
//  main.cpp
//  f-树状数组
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//  一维

///*
// *  INIT: ar[]置为0;
// *  CALL: add(i, v): 将i点的值加v; sum(i): 求[1, i]的和;
// */
//const int N = 1010;
//#define typev int   //  type of res
//typev ar[N];        //  index: 1 ~ N
//int lowb(int t)
//{
//    return t & (-t);
//}
//
//void add(int i, typev v)
//{
//    for ( ; i < N; ar[i] += v, i += lowb(i));
//    return ;
//}
//
//typev sum(int i)
//{
//    typev s = 0;
//    for (; i > 0; s += ar[i], i -= lowb(i));
//    return s;
//}


//  二维

/*
 *  INIT: c[][]置为0; Row,Col要赋初值 
 */
const int N = 10000;
int c[N][N];
int Row, Col;
inline int Lowbit(const int &x)
{   //  x > 0
    return x & (-x);
}

int Sum(int i, int j)
{
    int tempj, sum = 0;
    while (i > 0)
    {
        tempj = j;
        while (tempj > 0)
        {
            sum += c[i][tempj];
            tempj -= Lowbit(tempj);
        }
        i -= Lowbit(i);
    }
    return sum;
}

void Update(int i, int j, int num)
{
    int tempj;
    while (i <= Row)
    {
        tempj = j;
        while (tempj <= Col)
        {
            c[i][tempj] += num;
            tempj += Lowbit(tempj);
        }
        i += Lowbit(i);
    }
    return ;
}