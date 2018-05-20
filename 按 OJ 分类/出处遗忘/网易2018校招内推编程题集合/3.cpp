#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    while (cin >> s)
    {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        
        cout << ans << endl;
    }
    
    return 0;
}
