//
//  main.cpp
//  f-PAT-天梯赛习题集-L2-018-多项式A除以B
//
//  Created by ZYJ on 2017/3/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>

using namespace std;

const double ESP = 0.04;

list<pair<int, double> > A, B, Q, R, T;

int E;
double C;
int NA, NB, NQ = 0, NR = 0;

void sub()
{
    T.clear();
    auto i = A.begin(), j = R.begin();
    for (; i != A.end(); i++)
    {
        if (j == R.end())
        {
            break;
        }
        for (; j != R.end(); j++)
        {
            if ((*i).first > (*j).first)
            {
                T.push_back(make_pair((*i).first, (*i).second));
                break;
            }
            else if ((*i).first < (*j).first)
            {
                T.push_back(make_pair((*j).first, -(*j).second));
                continue;
            }
            else
            {
                T.push_back(make_pair((*i).first, (*i).second - (*j).second));
                j++;
                break;
            }
        }
    }
    for (; i != A.end(); i++)
    {
        T.push_back(make_pair((*i).first, (*i).second));
    }
    for (; j != R.end(); j++)
    {
        T.push_back(make_pair((*j).first, -(*j).second));
    }
    swap(A, T);
}

void solve()
{
    if (A.front().first < E)
    {
        return ;
    }
    int tempE = A.front().first - E;
    double tempC = A.front().second / C;
    if (fabs(tempC) > ESP)
    {
        Q.push_back(make_pair(tempE, tempC));
        NQ++;
    }
    A.erase(A.begin());
    R.clear();
    for (auto i = B.begin(); i != B.end(); i++)
    {
        R.push_back(make_pair(tempE + (*i).first, tempC * (*i).second));
    }
    
    //  A = A - R
    sub();
    
    solve();
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int e;
    double c;
    
    cin >> NA;
    for (int i = 0; i < NA; i++)
    {
        scanf("%d%lf", &e, &c);
        A.push_back(make_pair(e, c));
    }
    cin >> NB;
    for (int i = 0; i < NB; i++)
    {
        scanf("%d%lf", &e, &c);
        B.push_back(make_pair(e, c));
    }
    E = B.front().first;
    C = B.front().second;
    B.erase(B.begin());
    
    solve();
    
    if (NQ == 0)
    {
        cout << "0 0 0.0\n";
    }
    else
    {
        cout << NQ << ' ';
        printf("%d %.1f", Q.front().first, Q.front().second);
        auto i = Q.begin();
        i++;
        for (; i != Q.end(); i++)
        {
            printf(" %d %.1f", (*i).first, (*i).second);
        }
        puts("");
    }
    
    R.clear();
    for (auto i = A.begin(); i != A.end(); i++)
    {
        if (fabs((*i).second) > ESP)
        {
            R.push_back(make_pair((*i).first, (*i).second));
            NR++;
        }
    }
    
    if (NR == 0)
    {
        cout << "0 0 0.0\n";
    }
    else
    {
        cout << NR << ' ';
        printf("%d %.1f", R.front().first, R.front().second);
        auto i = R.begin();
        i++;
        for (; i != R.end(); i++)
        {
            printf(" %d %.1f", (*i).first, (*i).second);
        }
        puts("");
    }
    
    return 0;
}
