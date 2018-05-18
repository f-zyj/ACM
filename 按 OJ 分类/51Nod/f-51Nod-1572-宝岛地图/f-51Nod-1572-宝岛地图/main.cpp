//
//  main.cpp
//  f-51Nod-1572-宝岛地图
//
//  Created by ZYJ on 2017/5/17.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int MAXN = 1010;
const int MAX_LETTER = 26;
const int MAX_ORDER = 1e5 + 10;

int n, m, k;
char map[MAXN][MAXN];

struct node
{
    int x, y;
} L[MAX_LETTER];

struct order
{
    char dir;
    int steps;
} O[MAX_ORDER];

set<pair<int, int> > spii;
set<pair<int, int> >::iterator it;

void charge(int x, int y)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < O[i].steps; j++)
        {
            if (O[i].dir == 'N')
            {
                x -= 1;
            }
            else if (O[i].dir == 'S')
            {
                x += 1;
            }
            else if (O[i].dir == 'E')
            {
                y += 1;
            }
            else if (O[i].dir == 'W')
            {
                y -= 1;
            }
            spii.insert(make_pair(x, y));
        }
    }
}

int charge_(int x, int y)
{
    int a, b;
    for (it = spii.begin(); it != spii.end(); it++)
    {
        a = x + it->first;
        b = y + it->second;
        if (a < 0 || a >= n || y < 0 || y >= m || map[a][b] == '#')
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[])
{
    memset(L, -1, sizeof(L));
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", map[i]);
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] >= 'A' && map[i][j] <= 'Z')
            {
                int k = map[i][j] - 'A';
                L[k].x = i;
                L[k].y = j;
            }
        }
    }
    
    cin >> k;
    char dir[3];
    for (int i = 0; i < k; i++)
    {
        scanf("%s%d", dir, &O[i].steps);
        O[i].dir = dir[0];
    }
    
    int x = 0, y = 0;
    spii.insert(make_pair(0, 0));
    charge(x, y);
    
    int flag = 0;
    for (int i = 0; i < MAX_LETTER; i++)
    {
        if (L[i].x != -1)
        {
            if (charge_(L[i].x, L[i].y))
            {
                cout << (char)(i + 'A');
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << "no solution";
    }
    puts("");
    
    return 0;
}
*/

#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010;
const int MAX_LETTER = 26;
const int MAX_ORDER = 1e5 + 10;

struct node
{
    int x, y;
} L[MAX_LETTER];

struct order
{
    char dir;
    int steps;
} O[MAX_ORDER];

int n, m, k;
char s[MAXN];
int map[MAXN][MAXN];

bool ok(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m;
}

int Sum(int a, int b, int c, int d)
{
    return map[a - 1][b - 1] + map[c][d] - map[a - 1][d] - map[c][b - 1];
}

bool charge(int x, int y)
{
    for (int i = 1; i <= k; i++)
    {
        if (O[i].dir == 'N')
        {
            if (!ok(x - O[i].steps, y))
            {
                return 0;
            }
            if (Sum(x - O[i].steps, y, x, y))
            {
                return 0;
            }
            x = x - O[i].steps;
        }
        if (O[i].dir == 'S')
        {
            if (!ok(x + O[i].steps, y))
            {
                return 0;
            }
            if (Sum(x, y, x + O[i].steps, y))
            {
                return 0;
            }
            x = x + O[i].steps;
        }
        if (O[i].dir == 'W')
        {
            if (!ok(x, y - O[i].steps))
            {
                return 0;
            }
            if (Sum(x, y - O[i].steps, x, y))
            {
                return 0;
            }
            y = y - O[i].steps;
        }
        if (O[i].dir == 'E')
        {
            if (!ok(x, y + O[i].steps))
            {
                return 0;
            }
            if (Sum(x, y, x, y + O[i].steps))
            {
                return 0;
            }
            y = y + O[i].steps;
        }
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
        {
            if (s[j] == '#')
            {
                map[i][j] = 1;
            }
            else if (s[j] >= 'A' && s[j] <= 'Z')
            {
                int k = s[j] - 'A';
                L[k].x = i;
                L[k].y = j;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            map[i][j] = map[i][j] + map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
        }
    }
    
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        scanf("%s%d", s, &O[i].steps);
        O[i].dir = s[0];
    }
    
    int flag = 0;
    for (int i = 0; i < MAX_LETTER; i++)
    {
        if (L[i].x && charge(L[i].x, L[i].y))
        {
            putchar(i + 'A');
            flag = 1;
        }
    }
    if (!flag)
    {
        cout << "no solution";
    }
    putchar(10);
    
    return 0;
}
