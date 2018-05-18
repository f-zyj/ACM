//
//  main.cpp
//  f-51Nod-1534-棋子游戏
//
//  Created by ZYJ on 2016/12/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

int xP, yP, xV, yV;

void solve()
{
    //  如果P的横纵坐标均小等于于V
    if (xP <= xV && yP <= yV)
    {
        puts("Polycarp");
        return ;
    }
    //  如果V的横纵坐标均小于等于P
    if (xV <= xP && yV <= yP)
    {
        puts("Vasiliy");
        return ;
    }
    
    int tempP = xP + yP;    //  P要走的最少步数
    int tempV = max(xV, yV);//  V要走的最少步数
    
    if (tempP <= tempV)
    {
        puts("Polycarp");
    }
    else
    {
        puts("Vasiliy");
    }
}

int main()
{
    cin >> xP >> yP >> xV >> yV;
    solve();
    
    return 0;
}
