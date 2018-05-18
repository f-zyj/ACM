//
//  main.cpp
//  f-KMP算法
//
//  Created by ZYJ on 16/6/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//// KMP算法
//
///*
// * next[]的含义，x[i - next[i]...i - 1] = x[0...next[i] - 1]
// * next[i]为满足x[i - z...i - 1] = x[0...z - 1]的最大z值（就是x的自身匹配）
// * 字符串从下标0开始存，最后得到的next数组比常规情况对应每位少1
// * ex: ababaaaba:常规：011234223；非常规：-100123112
// */
//
//void KMP_Pre(char x[], int m, int next[])
//{
//    int i, j;
//    j = next[0] = -1;
//    i = 0;
//    while (i < m)
//    {
//        while (-1 != j && x[i] != x[j])
//        {
//            j = next[j];
//        }
//        next[++i] = ++j;
//    }
//    return ;
//}
//
///*
// * kmpNext[]的意思：next'[i] = next[next[...[next[i]]]]
// * （直到next'[i] < 0或者x[next'[i]] != x[i]）
// * 这样的预处理可以快一些
// * 字符串从下标0开始存，最后得到的next数组比常规情况对应每位少1
// * ex: ababaaaba:常规：011234223；非常规：-100123112
// */
//
//void preKMP(char x[], int m, int kmpNext[])
//{
//    int i, j;
//    j = kmpNext[0] = -1;
//    i = 0;
//    while (i < m)
//    {
//        while (-1 != j && x[i] != x[j])
//        {
//            j = kmpNext[j];
//        }
//        if (x[++i] == x[++j])
//        {
//            kmpNext[i] = kmpNext[j];
//        }
//        else
//        {
//            kmpNext[i] = j;
//        }
//    }
//    return ;
//}
//
///*
// * 返回x在y中出现的次数，可以重叠
// */
//
//int next[10010];
//
//int KMP_Count(char x[], int m, char y[], int n)
//{
//    //x是模式串，y是主串
//    int i, j;
//    int ans = 0;
//    //preKMP(x, m, next);
//    KMP_Pre(x, m, next);
//    i = j = 0;
//    while (i < n)
//    {
//        while (-1 != j && y[i] != x[j])
//        {
//            j = next[j];
//        }
//        i++, j++;
//        if (j >= m)
//        {
//            ans++;
//            j = next[j];
//        }
//    }
//    return ans;
//}
//
//
//
//int main(int argc, const char * argv[])
//{
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}


/*
 *  通过计算返回子串T的next数组
 */

void getNext(char *T, int *next, int len)
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len)
    {
        if (j == -1 || T[i] == T[j])
        {
            next[++i] = ++j;
        }
        else
        {
            j = next[j];    //  若字符不相同，则j值回溯
        }
    }
    return ;
}

/*
 * 返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0
 * T非空，0 ≤ pos ≤ len - 1
 */

int indexKMP(char *S, char *T, int *next, int pos, int lenS, int lenT)
{
    int i = pos;
    int j = 0;
    getNext(T, next, lenT);         //  对串T作分析，得到next数组
    while (i < lenS && j < lenT)    //  若i小于S的长度且j小于T的长度时循环继续
    {
        if (j == -1 || S[i] == T[j])//  两字母相等则继续，与朴素算法相比增加了 j = -1 判断
        {
            i++;
            j++;
        }
        else                        //  指针后退重新开始匹配
        {
            j = next[j];            //  j退回合适的位置，i值不变
        }
    }
    if (j >= lenT)
    {
        return i - lenT;
    }
    else
    {
        return 0;
    }
}
