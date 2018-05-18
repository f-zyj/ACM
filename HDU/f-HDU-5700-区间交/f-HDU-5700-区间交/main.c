//
//  main.c
//  f-HDU-5700-区间交
//
//  Created by ZYJ on 16/5/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//#pragma GCC optimize("02")
#define MAXSIZE 100005
#define MID (L + R) >> 1
#define LSON tag * 2, L, MID
#define RSON tag * 2 + 1, (MID) + 1, R
#define MAX(a, b) a > b ? a : b

typedef long long LL;
LL A, ans;
LL sum[MAXSIZE] = {0};    //前缀和

typedef struct
{
    int left;
    int right;
}route;
route rou[MAXSIZE];

struct seg
{
    int cover;
}segs[MAXSIZE * 4];

//输入LL
void scanfDiyLL(LL *ret)
{
    char c;
    *ret = 0;
    while((c = getchar()) < '0' || c > '9');
    while(c >= '0' && c <= '9')
        *ret = (*ret) * 10 + (c - '0'), c = getchar();
    return ;
}
//输入int
void scanfDiyInt(int *ret)
{
    char c;
    *ret = 0;
    while((c = getchar()) < '0' || c > '9');
    while(c >= '0' && c <= '9')
        *ret = (*ret) * 10 + (c - '0'), c = getchar();
    return ;
}

int cmp(const void *a, const void *b)
{
    route *aa = (route *)a;
    route *bb = (route *)b;
    if (aa->right != bb->right)
    {
        return aa->right > bb->right ? 1 : -1;
    }
    return 0;
}

void pushUp(int tag)
{
    segs[tag].cover = segs[tag * 2].cover + segs[tag * 2 + 1].cover;
    return ;
}

void buildTree(int tag, int L, int R)
{
    if (L == R)
    {
        segs[tag].cover = 0;    //建树时初始化重叠次数为0
        return ;
    }
    buildTree(LSON);
    buildTree(RSON);
    pushUp(tag);
    return ;
}

//查找并更新
void upDate(int tag, int L, int R, int id)
{
    if (L == R)
    {
        segs[tag].cover++;
        return ;
    }
    if (id <= MID)
    {
        upDate(LSON, id);
    }
    else
    {
        upDate(RSON, id);
    }
    pushUp(tag);
    return ;
}

int query(int tag, int L, int R, int k)
{
    if (L == R)
    {
        return L;
    }
    if (k <= segs[tag * 2].cover)   //左边为最高优先选择
    {
        return query(LSON, k);
    }
    else
    {
        return query(RSON, k - segs[tag * 2].cover);    //左边不足，取左边，剩余不足的取右边
    }
}

int main(int argc, const char * argv[])
{
    int n, k, m;
    
    while (~scanf("%d %d %d", &n, &k, &m))
    {
        buildTree(1, 1, n);
        
        for (int i = 1; i <= n; i++)
        {
            scanfDiyLL(&A);
            sum[i] = sum[i - 1] + A;
        }
        for (int i = 1; i <= m; i++)
        {
            scanfDiyInt(&rou[i].left);
            scanfDiyInt(&rou[i].right);
        }
        
        qsort(rou + 1, m, sizeof(rou[0]), cmp); //右端点由小到大排序
        
//        for (int i = 1; i <= m; i++)
//        {
//            printf("%d %d\n", rou[i].begin, rou[i].end);
//        }
        
        for (int i = m - k + 1; i <= m; i++)    //这一部分右端点可以肯定不会是交区间右端点
        {
            upDate(1, 1, n, rou[i].left);
        }
        
        ans = 0;
        for (int i = m - k + 1; i >= 1; i--)
        {
            int l = query(1, 1, n, k);
            if (l <= rou[i].right)    //以rou[i].end为右端点
            {
                ans = MAX(ans, sum[rou[i].right] - sum[l - 1]);
            }
            upDate(1, 1, n, rou[i - 1].left);  //继续加区间端点
        }
        
        printf("%lld\n", ans);
    }

    return 0;
}