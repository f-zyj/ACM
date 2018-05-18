//
//  main.cpp
//  f-51Nod-1753-相似子串
//
//  Created by ZYJ on 2017/9/13.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 3e5 + 10;

typedef long long ll;

const char CHAR_L = '0' - 1;
const char CHAR_R = '9' + 1;

struct FastIO
{
    char A[MAXN];
    char *Pb = A, *Pe = A;
    
    void IO_fread()
    {
        Pb = A;
        Pe = A + fread(A, 1, MAXN, stdin);
    }
    
    void s_read(char *s)
    {
        if (Pb == Pe)
        {
            IO_fread();
        }
        if (Pb == Pe)
        {
            return ;
        }
        
        while (*Pb == '\n' || *Pb == '\r' || *Pb == ' ')
        {
            Pb++;
            if (Pb == Pe)
            {
                IO_fread();
                if (Pb == Pe)
                {
                    return ;
                }
            }
        }
        
        while (*Pb != '\n' && *Pb != '\r')
        {
            *s = *Pb;
            s++;
            Pb++;
            if (Pb == Pe)
            {
                IO_fread();
                if (Pb == Pe)
                {
                    *s = 0;
                    return;
                }
            }
        }
        *s = 0;
    }
    
    char c_read()   //  读取一个字符 不读 空格换行
    {
        if (Pb == Pe)
        {
            IO_fread();
        }
        if (Pb == Pe)
        {
            return -1;
        }
        
        while (*Pb == '\n' || *Pb == '\r' || *Pb == ' ')
        {
            Pb++;
            if (Pb == Pe)
            {
                IO_fread();
                if (Pb == Pe)
                {
                    return -1;
                }
            }
        }
        
        return *(Pb++);
    }
    
    int read()
    {
        int tmp = 0;
        if (Pb == Pe)
        {
            IO_fread();
        }
        if (Pb == Pe)
        {
            return -1;
        }
        while (*Pb == '\n' || *Pb == '\r' || *Pb == ' ')
        {
            Pb++;
            if (Pb == Pe)
            {
                IO_fread();
                if (Pb == Pe)
                {
                    return -1;
                }
            }
        }
        
        while (*Pb > CHAR_L && *Pb < CHAR_R)
        {
            tmp = tmp * 10 + (*Pb - '0');
            Pb++;
            if (Pb == Pe)
            {
                IO_fread();
                if (Pe == Pb)
                {
                    return tmp;
                }
            }
        }
        
        return tmp;
    }
} IO;

const int MOD_1 = 998244353;
const int MOD_2 = 985661441;
const int MOD_3 = 1e8 + 7;
const ll BASE = 1e9 + 7;
const int MAGIC = 26;

//  HASH之间的加减运算及判等
struct HASH
{
    int k1, k2, k3;
    
    HASH(int k1 = 0, int k2 = 0, int k3 = 0) : k1(k1), k2(k2), k3(k3) {}
    
    bool operator == (const HASH &a) const
    {
        return k1 == a.k1 && k2 == a.k2 && k3 == a.k3;
    }
    HASH operator + (const HASH &a) const
    {
        return HASH((k1 + a.k1) % MOD_1, (k2 + a.k2) % MOD_2, (k3 + a.k3) % MOD_3);
    }
    HASH operator - (const HASH &a) const
    {
        return HASH((k1 - a.k1 + MOD_1) % MOD_1, (k2 - a.k2 + MOD_2) % MOD_2, (k3 - a.k3 + MOD_3) % MOD_3);
    }
} H[MAGIC][MAXN];

struct node
{
    int k, d;
    
    node(int k = 0, int d = -1) : k(k), d(d) {};
    
    bool operator < (const node &a) const
    {
        if (k != a.k)
        {
            return k < a.k;
        }
        return d < a.d;
    }
    
    bool operator == (const node &a) const
    {
        return d == a.d;
    }
} B[3][MAXN];

int Pow(int a, int b, int mod)
{
    ll tmp = 1;
    while (b)
    {
        if (b & 1)
        {
            tmp = tmp * a % mod;
        }
        a = (ll)a * a % mod;
        b >>= 1;
    }
    
    return (int)tmp;
}

int iv[3][MAXN];
int po[3][MAXN];

void init()
{
    po[0][0] = po[1][0] = po[2][0] = 1;
    for (int i = 0; i < MAXN; i++)
    {
        B[0][i] = node(po[0][i], i);
        B[1][i] = node(po[1][i], i);
        B[2][i] = node(po[2][i], i);
        iv[0][i] = Pow(po[0][i], MOD_1 - 2, MOD_1);
        iv[1][i] = Pow(po[1][i], MOD_2 - 2, MOD_2);
        iv[2][i] = Pow(po[2][i], MOD_3 - 2, MOD_3);
        if (i + 1 < MAXN) po[0][i + 1] = BASE * po[0][i] % MOD_1;
        if (i + 1 < MAXN) po[1][i + 1] = BASE * po[1][i] % MOD_2;
        if (i + 1 < MAXN) po[2][i + 1] = BASE * po[2][i] % MOD_3;
    }
    sort(B[0], B[0] + MAXN);
    sort(B[1], B[1] + MAXN);
    sort(B[2], B[2] + MAXN);
}

//  并查集
struct bf
{
    int pre[MAGIC];
    
    void clear()
    {
        for (int i = 0; i < MAGIC; i++)
        {
            pre[i] = i;
        }
    }
    
    bf()
    {
        clear();
    }
    
    int find(int a)
    {
        if (a == pre[a])
        {
            return a;
        }
        
        return pre[a] = find(pre[a]);
    }
    
    void merg(int a, int b)
    {
        a = find(a);
        b = find(b);
        pre[a] = b;
    }
} F;

char s[MAXN];
bool vis[MAGIC];
HASH used[2][MAGIC];

int camp(int b)
{
    int k1 = (MOD_1 + used[0][b].k1 - used[1][b].k1) % MOD_1;
    int k2 = (MOD_2 + used[0][b].k2 - used[1][b].k2) % MOD_2;
    int k3 = (MOD_3 + used[0][b].k3 - used[1][b].k3) % MOD_3;
    int d1 = (int)(lower_bound(B[0], B[0] + MAXN, node(k1, -1)) - B[0]);
    if (d1 < MAXN && B[0][d1].k == k1)
    {
        for (int j = d1; j < MAXN && B[0][j].k == B[0][d1].k; j++)
        {
            int d = (int)(lower_bound(B[1], B[1] + MAXN, node(k2, B[0][j].d)) - B[1]);
            if (d >= MAXN || B[1][d].k != k2 || !(B[0][j] == B[1][d]))
            {
                continue;
            }
            
            d = (int)(lower_bound(B[2], B[2] + MAXN, node(k3, B[0][j].d)) - B[2]);
            if (d >= MAXN || B[2][d].k != k3 || !(B[0][j] == B[2][d]))
            {
                continue;
            }
            
            return 1;
        }
    }
    
    k1 = (MOD_1 - k1) % MOD_1;
    k2 = (MOD_2 - k2) % MOD_2;
    k3 = (MOD_3 - k3) % MOD_3;
    d1 = (int)(lower_bound(B[0], B[0] + MAXN, node(k1, -1)) - B[0]);
    if (d1 < MAXN && B[0][d1].k == k1)
    {
        for (int j = d1; j < MAXN && B[0][j].k == B[0][d1].k; j++)
        {
            int d = (int)(lower_bound(B[1], B[1] + MAXN, node(k2, B[0][j].d)) - B[1]);
            if (d >= MAXN || B[1][d].k != k2 || !(B[0][j] == B[1][d]))
            {
                continue;
            }
            
            d = (int)(lower_bound(B[2], B[2] + MAXN, node(k3, B[0][j].d)) - B[2]);
            if (d >= MAXN || B[2][d].k != k3 || !(B[0][j] == B[2][d]))
            {
                continue;
            }
            return 1;
        }
    }
    
    return 3;
}

int main ()
{
     freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    init();
    IO.s_read(s + 1);
    
    for (int i = 0; i < MAGIC; i++)
    {
        for (int j = 1; s[j]; j++)
        {
            if (s[j] - 'a' == i)
            {
                H[i][j] = HASH(po[0][j], po[1][j], po[2][j]);
            }
            H[i][j] = H[i][j - 1] + H[i][j];
        }
    }
    
    char a, b;
    int t, k, l1, l2, r1, r2;
    t = IO.read();
    
    while (t--)
    {
        F.clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < MAGIC; i++)
        {
            used[0][i] = used[1][i] = HASH(0, 0, 0);
        }
        
        k = IO.read(), l1 = IO.read(), r1 = IO.read(), l2 = IO.read(), r2 = IO.read();
        for (int i = 0; i < k; i++)
        {
            a = IO.c_read();
            b = IO.c_read();
            F.merg(a - 'a', b - 'a');
        }
        
        if (r1 - l1 != r2 - l2)
        {
            puts("NO");
            continue;
        }
        
        for (int i = 0; i < MAGIC; i++)
        {
            int u = F.find(i);
            used[0][u] = used[0][u] + H[i][r1] - H[i][l1 - 1];
            used[1][u] = used[1][u] + H[i][r2] - H[i][l2 - 1];
        }
        
        int flag = 0;
        for (int u = 0; u < MAGIC; u++)
        {
            int i = F.find(u);
            if (vis[i])
            {
                continue;
            }
            
            vis[i] = true;
            ll I1 = iv[0][l1 - 1];
            ll I2 = iv[1][l1 - 1];
            ll I3 = iv[2][l1 - 1];
            used[0][i].k1 = I1 * used[0][i].k1 % MOD_1;
            used[0][i].k2 = I2 * used[0][i].k2 % MOD_2;
            used[0][i].k3 = I3 * used[0][i].k3 % MOD_3;
            
            I1 = iv[0][l2 - 1];
            I2 = iv[1][l2 - 1];
            I3 = iv[2][l2 - 1];
            used[1][i].k1 = I1 * used[1][i].k1 % MOD_1;
            used[1][i].k2 = I2 * used[1][i].k2 % MOD_2;
            used[1][i].k3 = I3 * used[1][i].k3 % MOD_3;
            if (used[0][i] == used[1][i])
            {
                continue;
            }
            flag += camp(i);
            if (flag > 2)
            {
                break;
            }
        }
        
        if (flag < 3)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    
    return 0;
}
