//
//  main.cpp
//  f-区间最大频率
//
//  Created by ZYJ on 16/7/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  求区间中数出现的最大频率
 *  方法一:线段树.
 *  先离散化。因为序列是升序,所以先将所有值相同的点缩成一点。这样n规模就缩小了。建立一个数据结构
 *  记录缩点的属性:在原序列中的值id,和该值有多少个num比如序列
 *  10
 *  -1 -1 1 1 1 1 3 10 10 10
 *  缩点后为:下标 1 2 3 4
 *          id -1 1 3 10
 *         num  2 4 1 3
 *  然后建树,树的属性有区间最大值(也就是频率)和区间总和。
 *  接受询问的时候。接受的是原来序列的区间[be,ed]我们先搜索一下两个区间分别在离散化区间后的下标。
 *  比如接受[2,3]时候相应下标区间就是[1,2];[3,10]的相应下标区间是[2,4];
 *  处理频率的时候,我们发现两个极端,也就是左右两个端点的频率不好处理。因为它们是不完全的频率
 *  也就是说有部分不在区间内。但是如果对于完全区间,也就是说左右端点下标值完全在所求区间内。
 *  比如上例的[2,3]不好处理。但是如果是[1,6],或是[1,10]就很好处理了,只要像RMQ一样询问区间最大值就可以了。
 *  方法二:RMQ. 
 *  我们可以转化一下问题。将左右端点分开来考虑。
 *  现在对于离散后的询问区间我们可以分成3个部分.左端点,中间完全区间,右端点。
 *  对于中间完全区间线段树或RMQ都能轻松搞定。只要特判一左右的比较一下就得最后解了。
 */
int build(int a, int b);
int query(int index, int a, int b);

const int N = 100010;

struct NODE
{
    int b, e;   //  区间[b, e]
    int l, r;   //  左右子节点下标
    int number; //  区间内的最大频率值
    int last;   //  以 data[e]结尾且与 data[e]相同的个数:data[e-last+1]...data[e]
} node[N * 2 + 1];

int len, data[N];

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        int i, q, a, b;
        scanf("%d", &q);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &data[i]);
        }
        len = 0;    //  下标
        build(0, n - 1);
        while (q--)
        {
            scanf("%d%d", &a, &b);
            printf("%d\n", query(0, a - 1, b - 1)); //  输出区间的最大频率值,而非data[]
        }
    }
    return 0;
}

int build(int a, int b) //  建立线段树
{
    int temp = len, mid = (a + b) / 2;
    node[temp].b = a, node[temp].e = b;
    len++;
    if (a == b)
    {
        node[temp].number = 1;
        node[temp].last = 1;
        return temp;
    }
    node[temp].l = build(a, mid);
    node[temp].r = build(mid + 1, b);
    int left_c = node[temp].l, right_c = node[temp].r, p, lcount = 0, rcount = 0, rec, max = 0;
    rec = data[mid];
    p = mid;
    while (p >= a && data[p] == rec)
    {
        p--, lcount++;
    }
    node[left_c].last = lcount;
    rec = data[mid + 1];
    p = mid + 1;
    while (p <= b && data[p] == rec)
    {
        p++, rcount++;
    }
    node[right_c].last = rcount;
    if (data[mid] == data[mid + 1])
    {
        max = lcount + rcount;
    }
    if (node[left_c].number > max)
    {
        max = node[left_c].number;
    }
    if (node[right_c].number > max)
    {
        max = node[right_c].number;
    }
    node[temp].number = max;
    return temp;
}

int query(int index, int a, int b)
{
    int begin = node[index].b;
    int end = node[index].e;
    int mid = (begin + end) / 2;
    if (a == begin && b == end)
    {
        return node[index].number;
    }
    if (a > mid)
    {
        return query(node[index].r, a, b);
    }
    if (b < mid + 1)
    {
        return query(node[index].l, a, b);
    }
    int temp1, temp2, max;
    if (node[index].l > 0)
    {
        temp1 = query(node[index].l, a, mid);
    }
    if (node[index].r > 0)
    {
        temp2 = query(node[index].r, mid + 1, b);
    }
    max = temp1 > temp2 ? temp1 : temp2;
    if (data[mid] != data[mid + 1])
    {
        return max;
    }
    temp1 = node[node[index].l].last > (mid - a + 1) ? (mid - a + 1) : node[node[index].l].last;
    temp2 = node[node[index].r].last > (b - mid) ? (b - mid) : node[node[index].r].last;
    if (max < temp1 + temp2)
    {
        max = temp1 + temp2;
    }
    return max;
}

