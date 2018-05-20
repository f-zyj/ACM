#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int n;
int x[MAXN];

string solve()
{
    sort(x, x + n);
    
    int a = x[1] - x[0];
    for (int i = 1; i < n; i++)
    {
        if (a != x[i] - x[i - 1])
        {
            return "Impossible";
        }
    }
    
    return "Possible";
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    
    cout << solve() << endl;
    
    return 0;
}
