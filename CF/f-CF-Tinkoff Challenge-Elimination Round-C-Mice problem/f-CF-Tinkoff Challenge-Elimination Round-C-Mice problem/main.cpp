//
//  main.cpp
//  f-CF-Tinkoff Challenge-Elimination Round-C-Mice problem
//
//  Created by ZYJ on 2017/4/24.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
double mtx, mty, mtx_, mty_;
double mx, my, mvx, mvy;

double minT = 0, maxT = 1e5 + 10;

int flag = 0;

void getT(double mx, double mvx, double mtx, double mtx_)
{
    if (mvx == 0)
    {
        if (mtx < mx && mx < mtx_)
        {
            return ;
        }
        else
        {
            flag = 1;
            return ;
        }
    }
    else if (mvx < 0)
    {
        if (mx <= mtx)
        {
            flag = 1;
            return ;
        }
        mx = -mx, mvx = -mvx;
        mtx = -mtx, mtx_ = -mtx_;
        swap(mtx, mtx_);
    }
    else
    {
        if (mx >= mtx_)
        {
            flag = 1;
            return ;
        }
    }

    maxT = min(maxT, (mtx_ - mx) / mvx);
    if (mx <= mtx)
    {
        minT = max(minT, (mtx - mx) / mvx);
    }
}

int main()
{
    cin >> n;
    cin >> mtx >> mty >> mtx_ >> mty_;
    
    for (int i = 0; i < n; i++)
    {
        cin >> mx >> my >> mvx >> mvy;
        getT(mx, mvx, mtx, mtx_);
        if (flag || maxT <= minT)
        {
            cout << "-1\n";
            return 0;
        }
        getT(my, mvy, mty, mty_);
        if (flag || maxT <= minT)
        {
            cout << "-1\n";
            return 0;
        }
    }
    
    if (maxT > minT)
    {
        cout << minT << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
    return 0;
}
