//
//  main.cpp
//  f-51Nod-1107-斜率小于0的连线数量
//
//  Created by ZYJ on 16/8/20.
//  Copyright ? 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 5e4 + 10;
//
//long long ans = 0;
//
//struct line
//{
//    int x;
//    int y;
//} Line[MAXN];
//
//line L[MAXN];
//
//bool cmp(line a, line b)
//{
//    if (a.x == b.x) //  特殊考虑横坐标相等的情况
//    {
//        return a.y < b.y;
//    }
//    return a.x < b.x;
//}
//
////  归并排序求逆序数
//void MergeSort(int l, int r)
//{
//    int mid, i, j, tmp;
//    if (r > l + 1)
//    {
//        mid = (l + r) / 2;
//        MergeSort(l, mid);
//        MergeSort(mid, r);
//        tmp = l;
//        for (i = l, j = mid; i < mid && j < r;)
//        {
//            if (Line[i].y > Line[j].y)
//            {
//                L[tmp++] = Line[j++];
//                ans += mid - i;
//            }
//            else
//            {
//                L[tmp++] = Line[i++];
//            }
//        }
//        if (j < r)
//        {
//            for (; j < r; j++)
//            {
//                L[tmp++] = Line[j];
//            }
//        }
//        else
//        {
//            for (; i < mid; i++)
//            {
//                L[tmp++] = Line[i];
//            }
//        }
//        for (i = l; i < r; i++)
//        {
//            Line[i] = L[i];
//        }
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
////    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int N;
//    cin >> N;
//    
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d %d", &Line[i].x, &Line[i].y);
//    }
//    sort(Line, Line + N, cmp);
//    
//    MergeSort(0, N);
//    
//    std::cout << ans << '\n';
//    return 0;
//}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 5;

struct node
{
    int x, y;
    inline bool operator < (const node &nd)
    {
        if (this->x == nd.x)
        {
            return this->y > nd.y;
        }
        return this->x > nd.x;
    }
} nums[MAXN];

int bit[MAXN];

inline bool cmp(const node &nd1, const node &nd2)
{
    return nd1.y < nd2.y;
}

inline int sum(int i, int *bit)
{
    int res = 0;
    for (; i > 0; i ^= i & -i)
    {
        res += bit[i];
    }
    return res;
}

inline void add(int i, int adder, int *bit)
{
    for (; i < 50001; i += i & -i)
    {
        bit[i] += adder;
    }
}

int main()
{
    int n, res = 0, last;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &nums[i].x, &nums[i].y);
    }
    //  坐标离散化
    sort(nums, nums + n, cmp);
    last = nums[0].y;
    nums[0].y = 0;
    for (int i = 1; i < n; i++)
    {
        int tmp = nums[i].y;
        nums[i].y = nums[i - 1].y + (last < nums[i].y);
        last = tmp;
    }
    //  对x排序，准备计算
    sort(nums, nums + n);
    for (int i = 0; i < n; i++)
    {
        //  计算目前比y小的点
        res += sum(nums[i].y, bit);
        //  更新bit
        add(nums[i].y + 1, 1, bit);
    }
    printf("%d", res);
    
    return 0;
}
