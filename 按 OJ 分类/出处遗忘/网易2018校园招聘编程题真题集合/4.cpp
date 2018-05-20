#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int N, L;
int dep[MAXN];

int main()
{
    cin >> N >> L;
    
    int par, mx_dep = 1;
    for (int i = 1; i < N; i++)
    {
        cin >> par;
        dep[i] = dep[par] + 1;
        if (dep[i] > mx_dep)
        {
            mx_dep = dep[i];
        }
    }
    
    if (mx_dep < L)
    {
        int tmp = mx_dep + (L - mx_dep) / 2 + 1;
        if (tmp > N)
        {
            cout << N << '\n';
        }
        else
        {
            cout << tmp << '\n';
        }
    }
    else
    {
        cout << L + 1 << '\n';
    }
    
    return 0;
}
