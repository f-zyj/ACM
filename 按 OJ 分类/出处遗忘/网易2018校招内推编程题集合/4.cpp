#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
int a[MAXN];

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    if (n & 1)
    {
        for (int i = n; i >= 1; i -= 2)
        {
            printf("%d ", a[i]);
        }
        for (int i = 2; i < n; i += 2)
        {
            printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
        }
    }
    else
    {
        for (int i = n; i > 1; i -= 2)
        {
            printf("%d ", a[i]);
        }
        for (int i = 1; i < n; i += 2)
        {
            printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
        }
    }
    
    return 0;
}
