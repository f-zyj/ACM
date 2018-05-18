//
//  main.cpp
//  f-51Nod-1351-吃点心
//
//  Created by ZYJ on 16/9/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 55;

struct dessert
{
    int low;
    int high;
} Dessert[MAXN];

bool cmpA(dessert a, dessert b)
{
    return a.low > b.low;
}

bool cmpB(dessert a, dessert b)
{
    return a.high > b.high;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, C, X;
        cin >> N >> C >> X;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> Dessert[i].low >> Dessert[i].high;
            sum += Dessert[i].high;
        }
        
        int posA = 0, posB = 0;
        long long resA = 0;
        long long resB = C - sum;
        
        sort(Dessert, Dessert + N, cmpA);
        while (resA < X)
        {
            resA += Dessert[posA++].low;
        }
        sort(Dessert, Dessert + N, cmpB);
        while (resB < X)
        {
            resB += Dessert[posB++].high;
        }
        
        if (posA < posB)
        {
            cout << posA << '\n';
        }
        else
        {
            cout << posB << '\n';
        }
    }
    
    return 0;
}
