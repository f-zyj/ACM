#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 55;

char val[MAXN][MAXN];

int N;
int edge[MAXN][MAXN];
int vist[MAXN], dis[MAXN];

void init()
{
    memset(vist, 0, sizeof(vist));
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            edge[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        dis[i] = INF;
    }
}

void dijkstra(int pos)
{
    vist[pos] = 1;
    dis[pos] = 0;
    
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (vist[j] == 0 && edge[pos][j] != -1 && dis[pos] + edge[pos][j] < dis[j])
            {
                dis[j] = dis[pos] + edge[pos][j];
            }
        }
        int min_value = INF, min_pos = MAXN;
        for (int j = 1; j <= N; j++)
        {
            if (vist[j] == 0 && dis[j] < min_value)
            {
                min_value = dis[j];
                min_pos = j;
            }
        }
        vist[min_pos] = 1;
        pos = min_pos;
    }
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        
        init();
        
        for (int i = 1; i <= N; i++)
        {
            scanf("%s", val[i] + 1);
            int count = 0;
            for (int j = 1; j <= N; j++)
            {
                if (val[i][j] == 'Y')
                {
                    edge[i][j] = count++;
                }
            }
        }
        
        dijkstra(1);
        
        if (dis[N] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[N] << endl;
        }
    }
    
    return 0;
}