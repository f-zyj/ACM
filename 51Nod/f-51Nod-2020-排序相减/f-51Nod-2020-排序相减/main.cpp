//
//  main.cpp
//  f-51Nod-2020-排序相减
//
//  Created by ZYJ on 2017/12/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXAB = 4;

int n, k;
int a[MAXAB], b[MAXAB];

bool cmp(const int &a, const int &b)
{
    return a > b;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n >> k;
        
        while (k--)
        {
            int cnt = 0;
            while (n)
            {
                a[cnt] = b[cnt] = n % 10;
                cnt++;
                n /= 10;
            }
            
            sort(a, a + cnt, cmp);
            sort(b, b + cnt);
            
            int A = 0, B = 0;
            for (int i = 0; i < MAXAB; i++)
            {
                A *= 10;
                A += a[i];
                B *= 10;
                B += b[i];
            }
            
            n = A - B;
        }
        
        cout << n << '\n';
    }
    
    return 0;
}
