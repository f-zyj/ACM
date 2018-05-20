#include <bits/stdc++.h>

using namespace std;

int T, N;

int main()
{
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        
        int Odd_cnt = 0;
        int Mul4_cnt = 0;
        int Mul2Not4_cnt = 0;
        int x;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &x);
            if (x & 1)
            {
                Odd_cnt++;
            }
            else if (x % 4 == 0)
            {
                Mul4_cnt++;
            }
            else
            {
                Mul2Not4_cnt++;
            }
        }
        
        if (Mul2Not4_cnt)
        {
            if (Odd_cnt > Mul4_cnt)
            {
                cout << "No" << '\n';
            }
            else
            {
                cout << "Yes" << '\n';
            }
        }
        else
        {
            if (Odd_cnt > Mul4_cnt + 1)
            {
                cout << "No" << '\n';
            }
            else
            {
                cout << "Yes" << '\n';
            }
        }
    }
    
    return 0;
}
