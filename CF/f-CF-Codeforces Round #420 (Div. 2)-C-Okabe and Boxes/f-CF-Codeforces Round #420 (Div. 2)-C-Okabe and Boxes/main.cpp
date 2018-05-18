//
//  main.cpp
//  f-CF-Codeforces Round #420 (Div. 2)-C-Okabe and Boxes
//
//  Created by ZYJ on 2017/6/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

char str[7];
vector<int> vi;

int n;

int main()
{
    scanf("%d", &n);
    
    int cnt = 1, ans = 0, x;
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%s", str);
        if (str[0] == 'a')
        {
            scanf("%d", &x);
            vi.push_back(x);
        }
        else
        {
            if (vi.empty()) ;
            else if (vi.back() == cnt)
            {
                vi.pop_back();
            }
            else
            {
                ans++;
                vi.clear();
            }
            cnt++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
