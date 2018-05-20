#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

int n;
int x[MAXN], y[MAXN];
int dis[MAXN], ans[MAXN];

void solve()
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //  每个棋子到聚点的曼哈顿距离
            for (int k = 0; k < n; k++)
            {
                dis[k] = abs(x[i] - x[k]) + abs(y[j] - y[k]);
            }
            sort(dis, dis + n);
            
            tmp = 0;
            for (int k = 0; k < n; k++)
            {
                tmp += dis[k];
                ans[k] = min(ans[k], tmp);
            }
        }
    }
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    
    memset(ans, 0x3f, sizeof(ans));
    
    solve();
    
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    
    return 0;
}
