//
//  main.cpp
//  f-51Nod-1208-Stars in Your Window
//
//  Created by ZYJ on 2017/9/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>

#define lson (root << 1) + 1
#define rson (root << 1) + 2

using namespace std;

const int MAXN = 90002;

struct node1
{
    int l, r;
    long long max_value, sing_value;
} tree[MAXN << 3];

struct node2
{
    double x, y1, y2;
    int value;
    bool end;
} line[MAXN << 1];

struct sta
{
    int x, y, value;
} star[MAXN];

int cnt_l, cnt_d;
long long N, W, H;
double dy[MAXN << 1];
map<double, int> mdi;

bool cmp_1(double a, double b)
{
    return a < b;
}

bool cmp_2(const node2 a, const node2 b)
{
    if (a.x == b.x)
    {
        return !a.end;
    }
    else
    {
        return a.x < b.x;
    }
}

void build_tree(int root, int L, int R)
{
    tree[root].l = L;
    tree[root].r = R;
    tree[root].max_value = 0;
    tree[root].sing_value = 0;
    
    if (L != R)
    {
        int m = (L + R) >> 1;
        build_tree(lson, L, m);
        build_tree(rson, m + 1, R);
    }
}

void add_tree(int root, int L, int R, int c)
{
    if (tree[root].l == L && tree[root].r == R)
    {
        tree[root].sing_value += c;
        tree[root].max_value += c;
        return ;
    }
    
    int m = (tree[root].l + tree[root].r) >> 1;
    if (R <= m)
    {
        add_tree(lson, L, R, c);
    }
    else if (L >= m + 1)
    {
        add_tree(rson, L, R, c);
    }
    else
    {
        add_tree(lson, L, m, c);
        add_tree(rson, m + 1, R, c);
    }
    tree[root].max_value = max(tree[lson].max_value, tree[rson].max_value)
                         + tree[root].sing_value;
}

int main()
{
    int L1, R1;
    long long ans;
    double xx, yy;
    while (~scanf("%lld%lld%lld", &N, &W, &H))
    {
        xx = W / 2.0;
        yy = H / 2.0;
        mdi.clear();
        cnt_l = 0;
        cnt_d = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d%d", &star[i].x, &star[i].y, &star[i].value);
            
            line[cnt_l].x =  star[i].x - xx;
            line[cnt_l].y1 = star[i].y - yy;
            line[cnt_l].y2 = star[i].y + yy;
            line[cnt_l].value = star[i].value;
            line[cnt_l].end = false;
            cnt_l++;
            
            line[cnt_l].x = star[i].x + xx;
            line[cnt_l].y1 = star[i].y - yy;
            line[cnt_l].y2 = star[i].y + yy;
            line[cnt_l].value = star[i].value;
            line[cnt_l].end = true;
            cnt_l++;
            
            dy[cnt_d++] = star[i].y - yy;
            dy[cnt_d++] = star[i].y + yy;
        }
        
        sort(line, line + cnt_l, cmp_2);
        sort(dy, dy + cnt_d, cmp_1);
        cnt_d = (int)(unique(dy, dy + cnt_d) - dy);
        
        build_tree(0, 0, cnt_d - 1);
        
        for (int i = 0; i < cnt_d; i++)
        {
            mdi[dy[i]] = i;
        }
        
        ans = 0;
        for (int i = 0; i < cnt_l; i++)
        {
            L1 = mdi[line[i].y1];
            R1 = mdi[line[i].y2];
            
            if (!line[i].end)
            {
                add_tree(0, L1, R1, line[i].value);
                ans = max(tree[0].max_value, ans);
            }
            else
            {
                add_tree(0, L1, R1, -1 * line[i].value);
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
