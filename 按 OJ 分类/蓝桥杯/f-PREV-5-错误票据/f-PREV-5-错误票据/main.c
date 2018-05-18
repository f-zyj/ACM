//
//  main.c
//  f-PREV-5-错误票据
//
//  Created by ZYJ on 16/3/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//
//
#include <stdio.h>
//#include <stdlib.h>
#define _Max 10000
typedef struct
{
    int iID[_Max + 1];
    int length;
}SqList;

//交换L数组r的下标为i和j的值
void swap(SqList *L, int i, int j)
{
    int temp = L->iID[i];
    L->iID[i] = L->iID[j];
    L->iID[j] = temp;
}

//交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置
//此时在它之前（后）的记录均不大于它
int Partition(SqList *L, int low, int high)
{
    int pivotkey;
    pivotkey = L->iID[low];                               //用子表的第一个记录作枢轴记录
    while (low < high)                                  //从表的两端交替向中间扫描
    {
        while (low < high && L->iID[high] >= pivotkey)
        {
            high--;
        }
        swap(L, low, high);                             //将比枢轴记录小的记录交换到低端
        while (low < high && L->iID[low] <= pivotkey)
        {
            low++;
        }
        swap(L, low, high);                             //将比枢轴记录大的记录交换到高端
    }
    return low;                                         //返回枢轴所在位置
}

//对顺序表L中的子序列L->r[low...high]作快速排序
void QSort(SqList *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high);  //将L->[low...high]一分为二，算出枢轴值pivot
        QSort(L, low, pivot - 1);         //对低子表递归排序
        QSort(L, pivot + 1, high);        //对高子表递归排序
    }
}

//对链表L做快速排序
void QuickSort(SqList *L)
{
    QSort(L, 1, L->length);
}

int main(int argc, const char * argv[])
{
    SqList ID;
    int N, m = 0, n = 0, line = 0, flag = 0, j = 0, k = -1, l = 1;
    char cID[_Max];
    scanf("%d", &N);
    fgets(cID, 2, stdin);
    for (; line < N; line++)
    {
        fgets(cID + 1, _Max, stdin);
        cID[0] = ' ';
        flag = 0;
        for (j = 1; cID[j]; j++)
        {
            if (cID[j - 1] == ' ' && cID[j] != ' ')
            {
                k = cID[j] - '0';
                flag = 1;
            }
            else if (cID[j] == ' ')
            {
                if (k != -1)
                {
                    ID.iID[l++] = k;
                }
                flag = 0;
                k = -1;
            }
            else if (cID[j] == '\n')
            {
                if (k != -1)
                {
                    ID.iID[l++] = k;
                }
                flag = 0;
                k = -1;
            }
            else if (flag)
            {
                k = k * 10 + cID[j] - '0';
            }
        }
    }
    //排序部分
    ID.length = l - 1;
    QuickSort(&ID);
    //查找重复的和缺少的
    k = ID.iID[1];
    for (j = 2; j < l; j++)
    {
        if (ID.iID[j] == k + 2)
        {
            m = ID.iID[j] - 1;
        }
        else if (ID.iID[j] == k)
        {
            n = ID.iID[j];
        }
        k = ID.iID[j];
    }
    printf("%d %d\n", m, n);
    return 0;
}


//#include <stdio.h>
//
//int main()
//{
//    int a[10001] = {0}, n, m = 0, min = 100000, max = 0, i = 0;
//    char c;
//    scanf("%d", &n);
//    for (; i < n; i++)
//    {
//        while (1)
//        {
//            scanf("%d", &m);
//            if (m > max)
//            {
//                max = m;
//            }
//            if (m < min)
//            {
//                min = m;
//            }
//            a[m]++;
//            c = getchar();   //获取缓冲区的字符
//            if (c != ' ')    //如果不为空格，则一定是回车字符，跳出这一行输入
//            {
//                break;
//            }
//        }
//    }
//    for (i = min; i <= max; i++)
//    {
//        if (a[i] == 0)
//        {
//            printf("%d ", i);
//        }
//        else if (a[i] == 2)
//        {
//            m = i;
//        }
//    }
//    printf("%d\n", m);
//    return 0;
//}
