#include <bits/stdc++.h>

using namespace std;

int n;
string res = "";

void solve()
{
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            res += '2';
            n = n / 2 - 1;
        }
        else
        {
            res += '1';
            n = n / 2;
        }
    }
}

int main()
{
    cin >> n;
    
    solve();
    
    reverse(res.begin(), res.end());
    
    cout << res << '\n';
    
    return 0;
}  
