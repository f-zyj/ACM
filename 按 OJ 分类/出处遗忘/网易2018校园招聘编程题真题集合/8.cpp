#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int n;

struct point
{
    int x, y;
} p[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].x;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].y;
    }
    
    if (n <= 3)
    {
        cout << n << endl;
        return 0;
    }
    
    int ans = 3;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j == i)
            {
                continue;
            }
            
            for (int k = 0; k < n; ++k)
            {
                if (k == i || k == j)
                {
                    continue;
                }
                
                int cnt = 3;
                for (int l = 0; l < n; ++l)
                {
                    if (l == i || l == j || l == k)
                    {
                        continue;
                    }
                    
                    if ((p[l].x - p[i].x) * (p[l].y - p[j].y) == (p[l].y - p[i].y) * (p[l].x - p[j].x))
                    {
                        cnt++;
                    }
                    else if ((p[l].x - p[k].x) * (p[i].x - p[j].x) + (p[l].y - p[k].y) * (p[i].y - p[j].y) == 0)
                    {
                        cnt++;
                    }
                }
                
                ans = max(ans, cnt);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
