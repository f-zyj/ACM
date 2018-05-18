//
//  main.c
//  f-NYOJ-14-会场安排问题
//
//  Created by ZYJ on 16/5/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 10001

typedef struct
{
    int Bi;
    int Ei;
} Party;

//交换L数组r的下标为i和j的值
void swap(Party *P, int i, int j)
{
    int temp = P[i].Bi;
    P[i].Bi = P[j].Bi;
    P[j].Bi = temp;
    temp = P[i].Ei;
    P[i].Ei = P[j].Ei;
    P[j].Ei = temp;
}

//交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置
//此时在它之前（后）的记录均不大于它
int Partition(Party *P, int low, int high)
{
    int pivotkey;
    pivotkey = P[low].Ei;                               //用子表的第一个记录作枢轴记录
    while (low < high)                                  //从表的两端交替向中间扫描
    {
        while (low < high && P[high].Ei >= pivotkey)
        {
            high--;
        }
        swap(P, low, high);                             //将比枢轴记录小的记录交换到低端
        while (low < high && P[low].Ei <= pivotkey)
        {
            low++;
        }
        swap(P, low, high);                             //将比枢轴记录大的记录交换到高端
    }
    return low;                                         //返回枢轴所在位置
}

//对顺序表L中的子序列L->r[low...high]作快速排序
void QSort(Party *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high);  //将L->[low...high]一分为二，算出枢轴值pivot
        QSort(L, low, pivot - 1);         //对低子表递归排序
        QSort(L, pivot + 1, high);        //对高子表递归排序
    }
}

int main(int argc, const char * argv[])
{
    int m, n;
    Party P[MAXSIZE];
    scanf("%d", &m);
    
    while (m--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &P[i].Bi, &P[i].Ei);
        }
        
        QSort(P, 1, n);
        
        int num = 1;
        int flagE = P[1].Ei;
        for (int i = 2; i <= n; i++)
        {
            if (P[i].Bi > flagE)
            {
                flagE = P[i].Ei;
                num++;
            }
        }
        
        printf("%d\n", num);
    }
    
    return 0;
}
