//
//  main.cpp
//  f-51Nod-1281-山峰和旗子
//
//  Created by ZYJ on 16/8/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 5e4 + 10;
//
//int point[MAXN];           //  点数据
//int pos = 0;
//
//struct peak
//{
////    int point;
//    int pos;
//} Peak[MAXN / 2];
//
////  正序
//bool order(int k)
//{
//    int res = 1;
//    int tag = 0;
//    for (int i = 1; i < pos; i++)
//    {
//        if (Peak[i].pos - Peak[tag].pos >= k)
//        {
//            res++;
//            tag = i;
//        }
//    }
//    if (res < k)
//    {
//        return false;
//    }
//    return true;
//}
//
////  逆序
////bool inverse(int k)
////{
////    int res = 1;
////    int tag = pos - 1;
////    for (int i = pos - 2; i >= 0; i--)
////    {
////        if (Peak[i].pos - Peak[tag].pos >= k)
////        {
////            res++;
////            tag = i;
////        }
////    }
////    if (res < k)
////    {
////        return false;
////    }
////    return true;
////}
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    cin >> N;
//    
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", point + i);
//    }
//    
//    for (int i = 2; i < N; i++)
//    {
//        if (point[i - 1] < point[i] && point[i + 1] < point[i])
//        {
////            Peak[pos].point = point[i];
//            Peak[pos++].pos = i;
//        }
//    }
//    
//    for (int i = pos; i >= 0; i--)
//    {
//        if (order(i))
//        {
//            cout << i << '\n';
//            break;
//        }
//    }
//    
//    return 0;
//}

#include <stdio.h>

const int MAXN = 5e4 + 10;

int point[MAXN];
int peak_dis[MAXN];

//  获取峰间距并返回间距个数
int get_peak_dis(int n)
{
    int cur_idx = 0;
    int b_len = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        if (point[i - 1] < point[i] && point[i + 1] < point[i])
        {
            if (cur_idx != 0)
            {
                peak_dis[b_len++] = i - cur_idx;
            }
            cur_idx = i;
        }
    }
    return b_len;
}

//  获取peak数目
int get_peak(int n)
{
    int peak_num = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        if (point[i - 1] < point[i] && point[i + 1] < point[i])
        {
            peak_num++;
        }
        
    }
    return peak_num;
}

//  检测是否可以插k+1个旗
bool can_value(int n, int k)
{
    int min_dist = k + 1;   //  最小间距
    int flag_num = 0;       //  第一个峰默认插旗，没有计算入内
    int cur_count = 0;
    for (int i = 0; i < n; ++i)
    {
        cur_count += peak_dis[i];
        if (cur_count >= min_dist)
        {
            flag_num++;
            cur_count = 0;
        }
    }
    return flag_num >= k ? true: false;
}

//  二分查找
int search_value(int n)
{
    int l_bound = 0;
    int r_bound = n - 1;
    while (r_bound - l_bound > 0)
    {
        int mid = (r_bound - l_bound) / 2 + l_bound;
        if (can_value(n, mid))
        {
            l_bound = mid + 1;
        }
        else
        {
            r_bound = mid - 1;
        }
    }
    return can_value(n, l_bound) ? l_bound : l_bound - 1;   //  校验数据
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", point + i);
    }
    
    int peak_len = get_peak(n);
    if (peak_len <= 1)
    {
        printf("%d", peak_len);
    }
    else
    {
        peak_len = get_peak_dis(n);
        int l_bound = search_value(peak_len);
        printf("%d", l_bound + 1);
    }
    return 0;
}