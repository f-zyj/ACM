#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int A, n;
int max1, max2, max3;
int min1, min2;
int max_neg1, max_neg2, max_neg3;

void check_max(int x)
{
    if (x > max1)
    {
        swap(x, max1);
    }
    if (x > max2)
    {
        swap(x, max2);
    }
    if (x > max3)
    {
        swap(x, max3);
    }
}

void check_min(int x)
{
    if (x < min1)
    {
        swap(x, min1);
    }
    if (x < min2)
    {
        swap(x, min2);
    }
}

void check_max_neg(int x)
{
    if (x > max_neg1)
    {
        swap(x, max_neg1);
    }
    if (x > max_neg2)
    {
        swap(x, max_neg2);
    }
    if (x > max_neg3)
    {
        swap(x, max_neg3);
    }
}

int main()
{
    max1 = max2 = max3 = 0;
    min1 = min2 = 0;
    max_neg1 = max_neg2 = max_neg3 = -INF;
    
    cin >> n;
    if (n < 3)
    {
        cout << "我也不知道该输出啥" << '\n';
        return 0;
    }
    
    int t = n;
    int cnt_pos = 0, cnt_neg = 0;
    while (t--)
    {
        cin >> A;
        if (A < 0)
        {
            cnt_neg++;
            check_min(A);
            check_max_neg(A);
        }
        else if (A > 0)
        {
            cnt_pos++;
            check_max(A);
        }
    }
    
    if (cnt_pos == 0)
    {
        if (cnt_neg < n)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << max_neg1 * max_neg2 * max_neg3 << '\n';
        }
    }
    else if (cnt_pos == 1)
    {
        if (cnt_neg < 2)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << min1 * min2 * max1 << '\n';
        }
    }
    else if (cnt_pos == 2)
    {
        if (cnt_neg < 2)
        {
            if (cnt_neg + cnt_pos < n)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << min1 * max1 * max2 << '\n';
            }
        }
        else
        {
            cout << min1 * min2 * max1 << '\n';
        }
    }
    else
    {
        long long ans1 = 1LL * max1 * max2 * max3;
        long long ans2 = 1LL * min1 * min2 * max1;
        if (ans1 > ans2)
        {
            cout << ans1 << '\n';
        }
        else
        {
            cout << ans2 << '\n';
        }
    }
    
    return 0;
}
