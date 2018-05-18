//
//  main.cpp
//  f-51Nod-1100-斜率最大
//
//  Created by ZYJ on 16/8/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e4 + 10;

struct point
{
    int x, y;
    int number;
} Point[MAXN];

bool cmp_p(point a, point b)
{
    return a.x < b.x;
}

struct line
{
    point Start;
    point End;
} Line[MAXN];

bool cmp_l(line a, line b)
{
    return a.Start.x < b.Start.x;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &Point[i].x, &Point[i].y);
        Point[i].number = i;
    }
    sort(Point + 1, Point + N + 1, cmp_p);
    
    int key = 2;
    double k = (Point[2].y - Point[1].y) * 1.0 / (Point[2].x - Point[1].x);
    Line[1].Start = Point[1];
    Line[1].End = Point[2];
    for (int i = 2; i < N; i++)
    {
        if ((Point[i + 1].y - Point[i].y) * 1.0 / (Point[i + 1].x - Point[i].x) > k)
        {
            k = (Point[i + 1].y - Point[i].y) * 1.0 / (Point[i + 1].x - Point[i].x);
            key = 2;
            Line[1].Start = Point[i];
            Line[1].End = Point[i + 1];
        }
        else if ((Point[i + 1].y - Point[i].y) * 1.0 / (Point[i + 1].x - Point[i].x) == k)
        {
            Line[key].Start = Point[i];
            Line[key++].End = Point[i + 1];
        }
    }
    
    sort(Line + 1, Line + key, cmp_l);
    
    for (int i = 1; i < key; i++)
    {
        cout << Line[i].Start.number << ' ' << Line[i].End.number << '\n';
    }
    
    return 0;
}
