#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;
const int MAXM = 1111;
const int DIR[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int N, M;
char G[MAXN][MAXN];
bool book[MAXN][MAXN][MAXM];

struct node
{
    int x, y, k, step;
    node(int x, int y, int k, int step) : x(x), y(y), k(k), step(step) {}
};

int bfs(int sX, int sY)
{
    queue<node> Q;
    Q.push(node(sX, sY, 0, 0));
    
    while (!Q.empty())
    {
        node head = Q.front();
        Q.pop();
        
        if (G[head.x][head.y] == '3')
        {
            return head.step;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = head.x + DIR[i][0];
            int ny = head.y + DIR[i][1];
            if (nx >= N || nx < 0 || ny >= M || ny < 0 || G[nx][ny] == '0')
            {
                continue;
            }
            
            int key = head.k;
            if ('a'<= G[nx][ny] && G[nx][ny] <= 'z')
            {
                key = key | (1 << (G[nx][ny] - 'a'));
            }
            
            if ('A' <= G[nx][ny] && G[nx][ny] <= 'Z' && (key & (1 << (G[nx][ny] - 'A'))) == 0)
            {
                continue;
            }
            
            if (!book[nx][ny][key])
            {
                book[nx][ny][key] = 1;
                Q.push(node(nx, ny, key, head.step + 1));
            }
        }
    }
    
    return -1;
}

int main()
{
    scanf("%d%d", &N, &M);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%s", G[i]);
    }
    
    memset(book, 0, sizeof(book));
    
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (flag == 1)
        {
            break;
        }
        
        for (int j = 0; j < M; j++)
        {
            if (G[i][j] == '2')
            {
                flag = 1;
                book[i][j][0] = 1;
                printf("%d\n", bfs(i, j));
                break;
            }
        }
    }
    
    return 0;
}
