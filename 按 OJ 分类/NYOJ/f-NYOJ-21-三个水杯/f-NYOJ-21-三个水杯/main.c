//
//  main.c
//  f-NYOJ-21-三个水杯
//
//  Created by ZYJ on 16/5/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

typedef struct State
{
    int Ei;
    int Ej;
    int Ek;
    int Step;
} State;

State S[5050];

int V1, V2, V3;
int E1, E2, E3;
int head, tail;

void init()
{
    S[0].Ei = V1;
    S[0].Ej = 0;
    S[0].Ek = 0;
    S[0].Step = 0;
    head = 0;
    tail = 1;
}

int haveSame()
{
    int i;
    for (i = 0; i < tail; i++)
    {
        if (S[i].Ei == S[tail].Ei && S[i].Ej == S[tail].Ej && S[i].Ek == S[tail].Ek)
        {
            return 1;
        }
    }
    return 0;
}

int judge(int Ei, int Ej, int Ek, int Step)
{
    if (Ei == E1 && Ej == E2 && Ek == E3)
    {
        printf("%d\n", Step);
        return 1;
    }
    return 0;
}

//BFS
void solve()
{
    if (judge(S[0].Ei, S[0].Ej, S[0].Ek, S[0].Step))
    {
        return ;
    }
    while (head < tail)
    {
        if (S[head].Ei > 0)
        {
            //第一个杯子往第二个杯子里倒
            if (S[head].Ej < V2)
            {
                S[tail].Ek = S[head].Ek;
                S[tail].Ej = S[head].Ei > V2 - S[head].Ej ? V2 : S[head].Ei + S[head].Ej;
                S[tail].Ei = S[head].Ei > V2 - S[head].Ej ? S[head].Ei - V2 + S[head].Ej : 0;
                S[tail].Step = S[head].Step + 1;
                if (judge(S[tail].Ei, S[tail].Ej, S[tail].Ek, S[tail].Step))
                {
                    return ;
                }
                if (!haveSame())
                {
                    tail++;
                }
            }
            //第一个杯子往第三个杯子里倒
            if (S[head].Ek < V3)
            {
                S[tail].Ej = S[head].Ej;
                S[tail].Ek = S[head].Ei > V3 - S[head].Ek ? V3 : S[head].Ei + S[head].Ek;
                S[tail].Ei = S[head].Ei > V3 - S[head].Ek ? S[head].Ei - V3 + S[head].Ek : 0;
                S[tail].Step = S[head].Step + 1;
                if (judge(S[tail].Ei, S[tail].Ej, S[tail].Ek, S[tail].Step))
                {
                    return ;
                }
                if (!haveSame())
                {
                    tail++;
                }
            }
        }
        if (S[head].Ej > 0)
        {
            //第二个杯子往第一个杯子里倒
            if (S[head].Ei < V1)
            {
                S[tail].Ek = S[head].Ek;
                S[tail].Ei = S[head].Ej > V1 - S[head].Ei ? V1 : S[head].Ej + S[head].Ei;
                S[tail].Ej = S[head].Ej > V1 - S[head].Ei ? S[head].Ej - V1 + S[head].Ei : 0;
                S[tail].Step = S[head].Step + 1;
                if (judge(S[tail].Ei, S[tail].Ej, S[tail].Ek, S[tail].Step))
                {
                    return ;
                }
                if (!haveSame())
                {
                    tail++;
                }
            }
            //第二个杯子往第三个杯子里倒
            if (S[head].Ek < V3)
            {
                S[tail].Ei = S[head].Ei;
                S[tail].Ek = S[head].Ej > V3 - S[head].Ek ? V3 : S[head].Ej + S[head].Ek;
                S[tail].Ej = S[head].Ej > V3 - S[head].Ek ? S[head].Ej - V3 + S[head].Ek : 0;
                S[tail].Step = S[head].Step + 1;
                if (judge(S[tail].Ei, S[tail].Ej, S[tail].Ek, S[tail].Step))
                {
                    return ;
                }
                if (!haveSame())
                {
                    tail++;
                }
            }
            
        }
        if (S[head].Ek > 0)
        {
            //第三个杯子往第一个杯子里倒
            if (S[head].Ei < V1)
            {
                S[tail].Ej = S[head].Ej;
                S[tail].Ei = S[head].Ek > V1 - S[head].Ei ? V1 : S[head].Ek + S[head].Ei;
                S[tail].Ek = S[head].Ek > V1 - S[head].Ei ? S[head].Ek - V1 + S[head].Ei : 0;
                S[tail].Step = S[head].Step + 1;
                if (judge(S[tail].Ei, S[tail].Ej, S[tail].Ek, S[tail].Step))
                {
                    return ;
                }
                if (!haveSame())
                {
                    tail++;
                }
            }//第三个杯子往第二个杯子里倒
            if (S[head].Ej < V2)
            {
                S[tail].Ei = S[head].Ei;
                S[tail].Ej = S[head].Ek > V2 - S[head].Ej ? V2 : S[head].Ek + S[head].Ej;
                S[tail].Ek = S[head].Ek > V2 - S[head].Ej ? S[head].Ek - V2 + S[head].Ej : 0;
                S[tail].Step = S[head].Step + 1;
                if (judge(S[tail].Ei, S[tail].Ej, S[tail].Ek, S[tail].Step))
                {
                    return ;
                }
                if (!haveSame())
                {
                    tail++;
                }
            }
        }
        head++;
    }
    
    printf("-1\n");
    return ;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    while (N--)
    {
        scanf("%d %d %d", &V1, &V2, &V3);
        scanf("%d %d %d", &E1, &E2, &E3);
        
        init();
        solve();
    }
    
    return 0;
}