#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;  //  设置点数上限

//  结点
struct point
{
    int x, y;
    
    //  重载运算符以备 sort 时使用
    bool operator < (const point &a) const
    {
        return x < a.x;
    }
};

int n, cnt;         //  n 点数，cnt 最大点集点数
point pts[MAXN];    //  存放初始点集
point res[MAXN];    //  存放最大点集

void solve()
{
    sort(pts, pts + n); //  按照 x 轴进行从小到大排序
    
    res[0] = pts[n - 1];//  最右点绝对在最大点集中
    int mx = res[0].y;  //  记录从右往左扫描过程中最大 y 值
    cnt = 1;
    //  从右往左扫描时，如果当前点 y 值大于历史最大 y 值，该点在最大点集中
    for (int i = n - 2; i >= 0; i--)
    {
        if (pts[i].y >= mx)
        {
            res[cnt++] = pts[i];    //  更新最大点集
            mx = pts[i].y;          //  更新历史最大 y 值
        }
    }
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &pts[i].x, &pts[i].y);
    }
    
    solve();
    
    for (int i = cnt - 1; i >= 0; i--)
    {
        printf("%d %d\n", res[i].x, res[i].y);
    }
    
    return 0;
}
