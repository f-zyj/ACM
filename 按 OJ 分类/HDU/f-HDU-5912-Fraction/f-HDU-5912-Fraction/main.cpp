//
//  main.cpp
//  f-HDU-5912-Fraction
//
//  Created by ZYJ on 2017/10/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 15;

int n;
int A[MAXN];
int B[MAXN];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T;
    
    for (int ce = 1; ce <= T; ce++)
    {
        cout << "Case #" << ce << ": ";
        
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> B[i];
        }
        
        int p = B[n], q = A[n], t;
        
        for (int i = n; i > 1; i--)
        {
            p += q * A[i - 1];
            t = p;
            p = B[i - 1] * q;
            q = t;
        }
        
        t = gcd(p, q);
        
        cout << p / t << ' ' << q / t << '\n';
    }
    
    return 0;
}

