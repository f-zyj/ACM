#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int n;
int a[MAXN];
deque<int> d;

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    
    int l = 0, r = n - 1, flag = 1;
    d.push_front(a[r--]);
    d.push_back(a[l++]);
    
    while (r > l)
    {
        if (flag)
        {
            d.push_front(a[l++]);
            d.push_back(a[r--]);
        }
        else
        {
            d.push_front(a[r--]);
            d.push_back(a[l++]);
        }
        flag = !flag;
    }
    
    int ans = abs(d[1] - d[0]);
    int len = (n & 1) ? n - 1 : n;
    for (int i = 2; i < len; i++)
    {
        ans += abs(d[i] - d[i - 1]);
    }
    if (r == l)
    {
        if (abs(d[0] - a[l]) > abs(d[len - 1] - a[l]))
        {
            ans += abs(d[0] - a[l]);
        }
        else
        {
            ans += abs(d[len - 1] - a[l]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
