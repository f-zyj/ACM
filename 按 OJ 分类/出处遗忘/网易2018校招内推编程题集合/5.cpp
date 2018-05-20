#include <bits/stdc++.h>

using namespace std;

long long x, f, d, p;

int main()
{
    cin >> x >> f >> d >> p;
    
    if (d > x * f)
    {
        d += f * p;
        cout << d / (x + p) << endl;
    }
    else
    {
        cout << d / x << endl;
    }
    
    return 0;
}
