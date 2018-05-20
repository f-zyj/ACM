#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    
    int ans = n;
    int tmp = 0;
    
    while (n)
    {
        tmp *= 10;
        tmp += n % 10;
        n /= 10;
    }
    
    ans += tmp;
    
    cout << ans << '\n';
    
    return 0;
}
