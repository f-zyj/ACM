//
//  main.cpp
//  f-HDU-5558-Alice's Classified Message
//
//  Created by ZYJ on 2017/10/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXM = 2e5 + 10;
const int MAXN = 1e5 + 10;
const int MAGIC = 26;

struct Suffix_Automation
{
    struct State
    {
        State *par;
        State *go[MAGIC];
        int val;
        int mi;
        int cnt;
        int right;
        int leftmost;
        
        void init(int _val = 0)
        {
            par = 0;
            val = _val;
            cnt = 0;
            mi = 0;
            right = 0;
            leftmost = 1e9;
            memset(go, 0, sizeof(go));
        }
    };
    
    State *root, *last, *cur;
    State nodePool[MAXM];
    
    State *newState(int val = 0)
    {
        cur->init(val);
        return cur++;
    }
    
    void initSAM()
    {
        cur = nodePool;
        root = newState();
        last = root;
    }
    
    void extend(int w, int head)
    {
        State *p = last;
        State *np = newState(p->val + 1);
        np->right = 1;
        np->leftmost = head;
    
        while (p && p->go[w] == 0)
        {
            p->go[w] = np;
            p = p->par;
        }
        
        if (p == 0)
        {
            np->par = root;
        }
        else
        {
            State *q = p->go[w];
            if (p->val + 1 == q->val)
            {
                np->par = q;
            }
            else
            {
                State *nq = newState(p->val + 1);
                memcpy(nq->go, q->go, sizeof(q->go));
                nq->leftmost = q->leftmost;
                nq->par = q->par;
                q->par = nq;
                np->par = nq;
                
                while (p && p->go[w] == q)
                {
                    p->go[w] = nq;
                    p = p->par;
                }
            }
        }
        last = np;
    }
    
    void solve(char *s)
    {
        initSAM();
        
        int n = (int)strlen(s);
        int now = 0;
        
        while (now != n)
        {
            State *pos = root;
            int deep = 0;
            
            while (now < n && pos->go[s[now] - 'a'] != 0)
            {
                pos = pos->go[s[now] - 'a'];
                deep++;
                extend(s[now] - 'a', now);
                now++;
            }
            
            if (deep == 0)
            {
                extend(s[now] - 'a', now);
                printf("-1 %d\n", s[now++]);
            }
            else
            {
                printf("%d %d\n", deep, pos->leftmost - deep + 1);
            }
        }
    }
};

Suffix_Automation sam;

char s[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int case_ = 1; case_ <= T; case_++)
    {
        printf("Case #%d:\n", case_);
        
        scanf("%s", s);
        
        sam.solve(s);
    }
    
    return 0;
}
