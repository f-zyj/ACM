#include <bits/stdc++.h>

using namespace std;

int len;
string s;
map<string, int> msi;

bool charge(string str)
{
    int tag = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            tag++;
        }
        else
        {
            tag--;
        }
        
        if (tag < 0)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    cin >> s;
    len = s.size();
    
    for (int i = 0; i < len; i++)
    {
        //  抽出第 i 个括号
        string tmp = s.substr(0, i) + s.substr(i + 1, len - i - 1);
        for (int j = 0; j < len; j++)
        {
            string tep = tmp.substr(0, j) + s[i] + tmp.substr(j, len - j - 1);
            if (tep != s && charge(tep))
            {
                msi[tep] = 1;
            }
        }
    }
    
    cout << msi.size() << '\n';
    
    return 0;
}
