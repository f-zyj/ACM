#include <bits/stdc++.h>

using namespace std;

string s;
set<char> v;

int main()
{
    while (cin >> s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            v.insert(s[i]);
        }
        
        int cnt = v.size();
        if (cnt > 2)
        {
            cout << 0 << endl;
        }
        else if (cnt == 2)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    
    return 0;
}
